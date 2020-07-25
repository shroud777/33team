//题意：最初由 n 个村庄和 n-1 条道路使村庄在一列上两两相连，给出 m 种操作，分别是摧毁一个村庄（同时断开与其他村庄的道路），修复上一个被摧毁的村庄（同时把道路修复），查询某个村庄能连通多少村庄

//思路：线段树的区间合并问题，对于线段树每个区间的 lazy 标记，我们设置 lmax,rmax,ms 分别代表从区间左端点开始的最大连续和，从区间右端点开始的最大连续和，与区间中最大连续子段和。
//首先关于建树，初始化每个叶结点的 lmax,rmax,ms 为 1，对于每次 update 操作，当前区间的 lmax 取决于左子区间的 lmax 是否等于左子区间长度,如果超过就加上右子区间的 lmax。rmax 的值类似，ms 只需要去 lmax,rmax 和中间段的最大值即可
//对于每个 modify，只需要找到正确的单点区间后，修改后并及时 update 即可
//对于每个 query，这是这道题的精髓之一，如果当前要查找的位置 pos，在当前区间的左子区间，那就判断 pos 能否包含在左子区间的 rmax 中，如果包含同时加上右子区间的 lmax。如果不包含，则继续递归左子区间，找到 pos
//如果在右区间也类似，而 ms 的值在这时起到了剪枝的作用，如果当前区间的 ms 值等于 0，说明区间里没有任何村庄剩余了，返回 0 即可，对于每个叶结点，返回叶结点的信息即可

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=5e4+10;
int stack[maxn],tot;
char s[2];
int n,m;
struct node{
	int lmax,rmax,ms;
}tree[maxn<<2];

inline void update(int l,int r,int x){
	int mid=l+r>>1;
	node &root=tree[x],&lc=tree[x<<1],&rc=tree[x<<1|1];
	root.lmax=lc.lmax+(lc.lmax==mid-l+1 ?rc.lmax:0);
	root.rmax=rc.rmax+(rc.rmax==r-mid ?lc.rmax:0);
	root.ms=max(max(rc.ms,lc.ms),lc.rmax+rc.lmax);
}

void build(int l,int r,int x){
	if(l==r){
		tree[x].lmax=tree[x].rmax=tree[x].ms=1;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	update(l,r,x);
}

void modify(int l,int r,int x,int pos,int k){
	if(l==r){
		tree[x].lmax=tree[x].ms=tree[x].rmax=k;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,x<<1,pos,k);
	else modify(mid+1,r,x<<1|1,pos,k);
	update(l,r,x);
}

int query(int l,int r,int x,int pos){
	if(l==r||tree[x].ms==0) return tree[x].ms;
	int mid=l+r>>1;
	if(pos<=mid){
		if(tree[x<<1].rmax>=mid-pos+1) return tree[x<<1].rmax+tree[x<<1|1].lmax;
		return query(l,mid,x<<1,pos);
	}
	else{
		if(tree[x<<1|1].lmax>=pos-mid) return tree[x<<1|1].lmax+tree[x<<1].rmax;
		return  query(mid+1,r,x<<1|1,pos);
	}
}

int main(){
	while(~scanf("%d %d",&n,&m)){
		tot=0;
		build(1,n,1);
		int x;
		while(m--){
			scanf("%s",s);
			if(s[0]=='D'){
				scanf("%d",&x);
				modify(1,n,1,x,0);
				stack[++tot]=x;
			}
			else if(s[0]=='R'){
				x=stack[tot--];
				modify(1,n,1,x,1);
			}
			else{
				scanf("%d",&x);
				printf("%d\n",query(1,n,1,x));
			}
		} 
	}
	return 0;
}
