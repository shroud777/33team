//题意：给出 01 字符串 s 和 f，现在有 q 天，每天白天要查询 [li,ri] 区间内是否字符都相等，晚上可以对 [li,ri] 区间内修改任意数量严格小于一半的字符，问 q 天后能否使得 s==f，并且每一天白天的查询都符合要求？

//思路：如果从前往后想，我们可以发现很难制定决策，即每天晚上怎么修改，到底要不要改
//但是如果从前往后想，可以发现变得很简单，因为对于一个区间 [li,ri]，由于白天有查询，那么它必然是由同种字符组成的，那么对于现在来说他只要区间内 0 和 1 的数量不相等，他就能改变，否则根据题意说明不合法
//所以就变成了区间查询与区间修改，我们只要使用 lazy-tag 即可，并且 lazy 数组不代表加上多少数，而是区间内变为这个数
//最后我们还要结果 q 次修改的字符串 f 是否与 s 相等即可，运用线段树递归区间的性质查询即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

char s[maxn],f[maxn];
int n,q,l[maxn],r[maxn];
int sum[maxn<<2],lazy[maxn<<2],L,R;

inline void update(int x){
    sum[x]=sum[x<<1]+sum[x<<1|1];
}

void build(int l,int r,int x){
    lazy[x]=-1;
    if(l==r){
        sum[x]=f[l-1]-'0';
        return;
    }
    int mid=l+r>>1;
    build(l,mid,x<<1);
    build(mid+1,r,x<<1|1);
    update(x);
}

inline void put_lazy(int l,int r,int x,int k){
    lazy[x]=k;
    sum[x]=(r-l+1)*k;
}

inline void down_lazy(int l,int r,int x){
    int mid=l+r>>1;
    put_lazy(l,mid,x<<1,lazy[x]);
    put_lazy(mid+1,r,x<<1|1,lazy[x]);
    lazy[x]=-1;
}

void modify(int l,int r,int x,int k){
    if(L<=l&&r<=R){
        put_lazy(l,r,x,k);
        return;
    }
    if(~lazy[x]) down_lazy(l,r,x);
    int mid=l+r>>1;
    if(L<=mid) modify(l,mid,x<<1,k);
    if(mid<R) modify(mid+1,r,x<<1|1,k);
    update(x);
}

int query(int l,int r,int x){
    if(L<=l&&r<=R) return sum[x];
    if(~lazy[x]) down_lazy(l,r,x);
    int mid=l+r>>1,ans=0;
    if(L<=mid) ans+=query(l,mid,x<<1);
    if(mid<R) ans+=query(mid+1,r,x<<1|1);
    return ans;
}

bool check(int l,int r,int x){
    if(l==r){
        return sum[x]==s[l-1]-'0';
    }
    if(~lazy[x]) down_lazy(l,r,x);
    int mid=l+r>>1;
    return check(l,mid,x<<1)&&check(mid+1,r,x<<1|1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d %d %s %s",&n,&q,s,f);
        build(1,n,1);
        for(int i=1;i<=q;i++) scanf("%d %d",&l[i],&r[i]);
        bool f=1;
        for(int i=q;i>=1;i--){
            L=l[i],R=r[i];
            int res=query(1,n,1);
            if((R-L)&1&&(R-L+1)>>1==res){
                f=0;break;
            }
            if(res>(R-L+1)>>1) modify(1,n,1,1);
            else modify(1,n,1,0);
            L=1,R=1;
        }
        if(f&&check(1,n,1)) puts("YES");
        else puts("NO");
    }
    return 0;
}
