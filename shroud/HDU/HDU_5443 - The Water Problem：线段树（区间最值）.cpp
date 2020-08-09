//题意：给出 n 个序列，每次询问要求 [l,r] 区间内的最大值

//思路：线段树区间最值，水题

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=1005;
ll tree[maxn<<2];
int n,L,R,q;

inline void update(int x){
	tree[x]=max(tree[x<<1],tree[x<<1|1]);
}

void build(int l,int r,int x){
	if(l==r){
		scanf("%lld",&tree[x]);
		return;
	}
	int mid=l+r>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	update(x);
} 

void modify(int l,int r,int x,int pos,ll k){
	if(l==r){
		tree[x]=k;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,x<<1,pos,k);
	else modify(mid+1,r,x<<1|1,pos,k);
	update(x);
}

inline ll query(int l,int r,int x){
	if(L<=l&&r<=R) return tree[x];
	int mid=l+r>>1;
	ll ans=0;
	if(L<=mid) ans=max(ans,query(l,mid,x<<1));
	if(mid<R) ans=max(ans,query(mid+1,r,x<<1|1));
	return ans;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		build(1,n,1);
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&L,&R);
			printf("%d\n",query(1,n,1));
		}
	}
	return 0;
}
