//题意：给出一个长度为 n 的数组，现在有 m 组询问，询问内容分为两种，如下：
//1 x y 将原序列下标为 x 的元素改为 y，即 ax=y
//2 x 找出以 ax 为最小值的连续序列的个数

//思路：对于操作 2，显然就是找小于 a[x] 最近左右端点的位置，然后我们找出这个位置，答案就是 (x-l+1)*(r-x+1)，那么我们如何查询呢？
//显然我们可以发现，以左端最近的小于 a[x] 的值为例，随着这个端点离 x 越来越远，那么区间的最小值会越来越小，也就是说，我们左端能够选的数的个数与最小值呈单调关系
//那么我们显然可以用 二分+线段树check O(logn*logn) 的复杂度，数据 1e5 显然 O(nlognlong) 可以通过
//但是如果数据放到 1e6，这个做法显然不太行了，那么我们来说明 O(nlogn) 的做法
//仍然以左端最近的小于 a[x] 的值为例，我们要查找的是最右边的小于 a[x] 的且在有效区间内即下标小于 x 的值，那么我们用线段树内二分即可，先递归右子树，如果我们的 x 在右子树区间，并且右子树最小值小于 a[x]，就递归右子树
//如果右子树递归出来的下标的值小于 a[x]，显然答案就是这个下标，否则继续看左子树，如果左子树的最小值大于 x，直接返回 l，否则继续递归左子树

//二分+线段树 O(nlognlong)

#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

int n,q,a[maxn];
int tree[maxn<<2],L,R;

inline int min(int x,int y){
    return x<y?x:y;
}

void build(int l,int r,int x){
    if(l==r){
        scanf("%d",&tree[x]);
        a[l]=tree[x];
        return;
    }
    int mid=l+r>>1;
    build(l,mid,x<<1);
    build(mid+1,r,x<<1|1);
    tree[x]=min(tree[x<<1],tree[x<<1|1]);
}

void modify(int l,int r,int x,int pos,int k){
    if(l==r){
        tree[x]=k;
        return;
    }
    int mid=l+r>>1;
    if(pos<=mid) modify(l,mid,x<<1,pos,k);
    else modify(mid+1,r,x<<1|1,pos,k);
    tree[x]=min(tree[x<<1],tree[x<<1|1]);
}

int query(int l,int r,int x){
    if(L<=l&&r<=R) return tree[x];
    int ans=0x3f3f3f3f;
    int mid=l+r>>1;
    if(L<=mid) ans=min(ans,query(l,mid,x<<1));
    if(mid<R) ans=min(ans,query(mid+1,r,x<<1|1));
    return ans;
}

inline bool check1(int x,int idx){
    if(!x) return true;
    L=idx-x,R=idx-1;
    return query(1,n,1)>=a[idx];
}

inline bool check2(int x,int idx){
    if(!x) return true;
    L=idx+1,R=idx+x;
    return query(1,n,1)>=a[idx];
}

int main(){
    scanf("%d %d",&n,&q);
    build(1,n,1);
    int opt;
    int x,y;
    while(q--){
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d %d",&x,&y);
            a[x]=y;
            modify(1,n,1,x,y);
        }
        else{
            scanf("%d",&x);
            int l=0,r=x-1,ansl;
            while(l<=r){
                int mid=l+r>>1;
                if(check1(mid,x)) ansl=mid,l=mid+1;
                else r=mid-1;
            }
            ansl++;
            l=0,r=n-x;
            int ansr;
            while(l<=r){
                int mid=l+r>>1;
                if(check2(mid,x)) ansr=mid,l=mid+1;
                else r=mid-1;
            }
            ansr++;
            printf("%lld\n",ansl*ansr);
        }
    }
    return 0;
}

//线段树里二分 O(nlogn)

#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

int n,q,a[maxn];
int tree[maxn<<2],L,R;

inline int min(int x,int y){
    return x<y?x:y;
}

void build(int l,int r,int x){
    if(l==r){
        scanf("%d",&tree[x]);
        a[l]=tree[x];
        return;
    }
    int mid=l+r>>1;
    build(l,mid,x<<1);
    build(mid+1,r,x<<1|1);
    tree[x]=min(tree[x<<1],tree[x<<1|1]);
}

void modify(int l,int r,int x,int pos,int k){
    if(l==r){
        tree[x]=k;
        return;
    }
    int mid=l+r>>1;
    if(pos<=mid) modify(l,mid,x<<1,pos,k);
    else modify(mid+1,r,x<<1|1,pos,k);
    tree[x]=min(tree[x<<1],tree[x<<1|1]);
}

int lquery(int l,int r,int x,int idx){
    if(l==r) return l;
    int mid=l+r>>1,ans=l;
    if(tree[x<<1|1]<a[idx]&&idx>mid){
        ans=lquery(mid+1,r,x<<1|1,idx);
        if(a[ans]<a[idx]) return ans;
        else ans=l;
    }
    if(tree[x<<1]<a[idx]) ans=lquery(l,mid,x<<1,idx);
    return ans;
}

int rquery(int l,int r,int x,int idx){
    if(l==r) return l;
    int mid=l+r>>1,ans=r;
    if(tree[x<<1]<a[idx]&&idx<=mid){
        ans=rquery(l,mid,x<<1,idx);
        if(a[ans]<a[idx]) return ans;
        else ans=r;
    }
    if(tree[x<<1|1]<a[idx]) ans=rquery(mid+1,r,x<<1|1,idx);
    return ans;
}

int main(){
    scanf("%d %d",&n,&q);
    build(1,n,1);
    int opt;
    int x,y;
    while(q--){
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d %d",&x,&y);
            a[x]=y;
            modify(1,n,1,x,y);
        }
        else{
            scanf("%d",&x);
            int l=lquery(1,n,1,x);
            int r=rquery(1,n,1,x);
            if(a[l]<a[x]) l++;
            if(a[r]<a[x]) r--;
            printf("%lld\n",1ll*(x-l+1)*(r-x+1));
        }
    }
    return 0;
}
