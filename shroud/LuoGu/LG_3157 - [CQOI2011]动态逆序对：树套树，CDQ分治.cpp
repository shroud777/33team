//题意： 给出一个长度为 n 的 1-n 全排列序列，并且给出 m 个数代表从序列中删除的数，求每次删除之前序列逆序对个数

//思路：对于普通逆序对，我们可以用分治或树状数组求出个数，但是这里需要动态修改
//那么这里每次修改涉及到的 O(n*logn) 复杂度显然无法承受，那么我们这里需要用到树套树，用树状数组维护权值线段树即可，每次修改 O(logn*logn)，查询 O(logn*logn)
//每次查询只要找到要修改的数的位置 pos 前面比它大的个数 res1（查询 [1,pos-1] 区间 [1,x-1] 范围内的数的个数），和后面位置比他小的个数 res2（查询 [pos+1,n] 区间 [x+1,n] 范围内的数的个数）
//那么每次答案就是 ans，然后 ans-=res1+res2 即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e5+10;

int n,m;
int a[maxn],p[maxn];
int rt[maxn],lc[maxn*440],rc[maxn*440],tot=0;
ll tree[maxn*440];
int L,R;

inline void update(int x){
	tree[x]=tree[lc[x]]+tree[rc[x]];
}

void modify(int l,int r,int &x,int pos,int k){
	if(!x) x=++tot;
	if(l==r){
		tree[x]+=k;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,lc[x],pos,k);
	else modify(mid+1,r,rc[x],pos,k);
	update(x);
}

void prepare_modify(int x,int k){
	for(int i=x;i<=n;i+=-i&i) modify(1,n,rt[i],a[x],k);
}

ll query(int l,int r,int x){
	if(!x) return 0;
	if(L<=l&&r<=R) return tree[x];
	int mid=l+r>>1;
	int ans=0;
	if(L<=mid) ans+=query(l,mid,lc[x]);
	if(mid<R) ans+=query(mid+1,r,rc[x]);
	return ans; 
}

ll prepare_query(int x){
	int ans=0;
	for(int i=x;i;i-=i&-i) ans+=query(1,n,rt[i]);	
	return ans;
}

int main(){
	ll ans=0;
	scanf("%d %d",&n,&m); 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		L=a[i]+1,R=n;
		if(i!=1) ans+=prepare_query(i-1);
		prepare_modify(i,1);
		p[a[i]]=i;
	} 
	int x;
	for(int i=1;i<=m;i++){
		printf("%lld\n",ans);
		scanf("%d",&x);
		int pos=p[x];
		L=x+1,R=n;
		ans-=prepare_query(pos-1);
		L=1,R=x-1;
		ans-=prepare_query(n)-prepare_query(pos);
		prepare_modify(pos,-1);
	}
	return 0;
}
