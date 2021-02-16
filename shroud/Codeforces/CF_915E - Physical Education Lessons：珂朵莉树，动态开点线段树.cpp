//题意：初始一个序列全部为 1，现在执行如下两种操作：
//1.l r ，把 [l,r] 区间内的全部变成 0
//2.l r ，把 [l,r] 区间内的全部变成 1
//问每次操作后有区间有多少 1 

//思路：首先我们想到用线段树，但是考虑区间值域非常大，我们只能使用动态开点或者离散化线段树，并且使用 lazy-tag 把区间全部变成某个值
//但是这种区间推平操作的题显然可以使用珂朵莉树，我们可以考虑用珂朵莉树维护，并且每次 assgin 操作时可以遍历减去每个要删掉的区间的值，再加上新的大区间的值降低复杂度

//动态开点线段树：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=3e5+10;
const int maxlog=50;

int n,q,L,R,tot,root;
int sum[300005*55],lazy[300005*55];
int lc[300005*55],rc[300005*55];

void down_lazy(int l,int r,int x){
    if(~lazy[x]){
        int mid=l+r>>1;
        if(!lc[x]) lc[x]=++tot;
        sum[lc[x]]=lazy[x]*(mid-l+1),lazy[lc[x]]=lazy[x];
        if(!rc[x]) rc[x]=++tot;
        sum[rc[x]]=lazy[x]*(r-mid),lazy[rc[x]]=lazy[x];
        lazy[x]=-1;
    }
}

void modify(int l,int r,int &x,int k){
    if(!x) x=++tot,lazy[x]=-1;
    if(L<=l&&r<=R){
        sum[x]=(r-l+1)*k;
        lazy[x]=k;
        return;
    }
    int mid=l+r>>1;
    down_lazy(l,r,x);
    if(L<=mid) modify(l,mid,lc[x],k);
    if(mid<R) modify(mid+1,r,rc[x],k);
    sum[x]=sum[lc[x]]+sum[rc[x]];
}

int main(){
    scanf("%d %d",&n,&q);
    int k;
    while(q--){
        scanf("%d %d %d",&L,&R,&k);
        modify(1,n,root,2-k);
        printf("%d\n",n-sum[1]);
    }
    return 0;
}

//珂朵莉树

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define IT set<node> ::iterator

int n,q,ans;

struct node{
    int l,r;
    mutable ll v;
    node(int L,int R=-1,ll V=0):l(L),r(R),v(V){}
    bool operator <(const node &o)const{
        return l<o.l;
    }
};

set<node> s;

IT spilt(int pos){
    IT it=s.lower_bound(node(pos));
    if(it!=s.end()&&it->l==pos) return it;
    it--;
    int l=it->l,r=it->r;
    ll v=it->v;
    s.erase(it);
    s.insert(node(l,pos-1,v));
    return s.insert(node(pos,r,v)).first;
}

void assign(int l,int r,int x){
    IT itr=spilt(r+1),itl=spilt(l),it=itl;
    for(;itl!=itr;itl++){
        ans-=itl->v*(itl->r-itl->l+1);
    }
    s.erase(it,itr);
    s.insert(node(l,r,x));
    ans+=(r-l+1)*x;
}

int main(){
    scanf("%d %d",&n,&q);
    ans=n;
    s.insert(node(1,n,1));
    int l,r,k;
    while(q--){
        scanf("%d %d %d",&l,&r,&k);
        assign(l,r,k-1);
        printf("%d\n",ans);
    }
    return 0;
}
