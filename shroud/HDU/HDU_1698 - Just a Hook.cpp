//题意：屠夫佩吉的钩子由 n 节组成，每一节可由金银铜三种材质价值分别为 1，2, 3 组成，每次操作将 [l,r] 范围里的钩子换成某种材质的，求整条钩子的价格

//思路：没啥好说的，线段树区间更新为某个数，注意下细节，练练手

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn=1e5+10;
ll tree[maxn*4],lazy[maxn*4];
int n,q,L,R;
inline void update(int x){
	tree[x]=tree[x<<1]+tree[x<<1|1];
}
void build(int l,int r,int x){
	if(l==r){
		tree[x]=1;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	update(x);
}
void put_lazy(int l,int r,int x,ll k){
	tree[x]=(r-l+1)*k;
	lazy[x]=k;
}
void down_lazy(int l,int r,int x){
	int mid=l+r>>1;
	put_lazy(l,mid,x<<1,lazy[x]);
	put_lazy(mid+1,r,x<<1|1,lazy[x]);
	lazy[x]=0;
}
void modify(int l,int r,int x,ll k){
	if(L<=l&&r<=R){
		put_lazy(l,r,x,k);
		return;
	}
	if(lazy[x]) down_lazy(l,r,x);
	int mid=l+r>>1;
	if(L<=mid) modify(l,mid,x<<1,k);
	if(mid<R) modify(mid+1,r,x<<1|1,k);
	update(x);
}
ll query(int l,int r,int x){
	if(L<=l&&r<=R) return tree[x];
	if(lazy[x]) down_lazy(l,r,x);
	int mid=l+r>>1;
	ll ans=0;
	if(L<=mid) ans+=query(l,mid,x<<1);
	if(mid<R) ans+=query(mid+1,r,x<<1|1);
	return ans;
}
int main(){
	int t,T=0;
	scanf("%d",&t);
	while(t--){
		memset(tree,0,sizeof tree);
		memset(lazy,0,sizeof lazy);
		scanf("%d",&n);
		build(1,n,1);
		scanf("%d",&q);
		while(q--){
			int k;
			scanf("%d %d %d",&L,&R,&k);
			modify(1,n,1,k);
		}
		L=1,R=n;
		printf("Case %d: The total value of the hook is %lld.\n",++T,query(1,n,1));
	} 
	return 0;
}
