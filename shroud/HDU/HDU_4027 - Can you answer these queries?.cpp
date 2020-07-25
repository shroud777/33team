//题意：有 n 艘船，每艘船都有一个生命值 ai，有 m 此操作。操作分为两种，一种是把给定区间内所有战船的生命值取平方根，第二种是查询区间内所有船的生命值

//思路：线段树维护区间和，由于每次区间操作都是取根号，显然没法用 lazy-tag 记录区间信息，那么我们只能做单点更新，并且我们可以知道，一个数去一定次数的平方根后最后一定为 1
//那么显然我们可以通过判断区间信息来减少递归更新的次数，如果区间和等于区间里的点数，说明每个点都是 1，那么我们直接跳过即可，因为继续操作平方根也会得到同样的值

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll tree[maxn*4];
int n,L,R; 

inline void update(int x){
	tree[x]=tree[x<<1]+tree[x<<1|1];
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

void modify(int l,int r,int x){
	if(tree[x]==r-l+1) return;
	if(l==r) return void (tree[x]=sqrt(tree[x]));
	int mid=l+r>>1; 
	if(L<=mid) modify(l,mid,x<<1);
	if(mid<R) modify(mid+1,r,x<<1|1);
	update(x);
}

ll query(int l,int r,int x){
	if(r<L||l>R) return 0;
	if(L<=l&&r<=R) return tree[x];
	int mid=l+r>>1;
	return query(l,mid,x<<1)+query(mid+1,r,x<<1|1);
}


int main(){
	int T=0;
	while(~scanf("%d",&n)){
		printf("Case #%d:\n",++T);
		build(1,n,1);
		int q;
		scanf("%d",&q);
		int t;
		while(q--){
			scanf("%d %d %d",&t,&L,&R);
			if(L>R) L^=R^=L^=R;
			if(!t) modify(1,n,1);
			else printf("%lld\n",query(1,n,1));
		}
		printf("\n");
	}
	return 0;
} 
