//题意：有 n 个学生的成绩，有两种操作，1.查询 [l,r] 区间内的最高学生成绩。 2.修改 x 号学生的成绩

//思路：线段树模板，单点修改，区间查询，维护内容为最大值

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll tree[maxn<<2];
int n,L,R,m;

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
	int a,b;
	while(~scanf("%d %d",&n,&m)){
		build(1,n,1);
		char ch[2];
		int pos,k;
		while(m--){
			scanf("%s",ch);
			if(ch[0]=='U'){
				scanf("%d %lld",&pos,&k);
				modify(1,n,1,pos,k);
			}
			else{
				scanf("%d %d",&L,&R);
				printf("%d\n",query(1,n,1));
			}
		}
		//printf("\n");
	}
	return 0;
}
