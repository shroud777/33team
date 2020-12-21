//题意：给出一个长度为 n 的序列，现在要支持两种操作：
//1.Q l r k 表示查询下标在区间 [l,r] 中的第 k 小的数
//2.C x y 表示将 a[x] 改为 y

//思路：首先对于第一种操作，就是静态区间第 k 小问题，用主席树很容易维护
//但是第二种操作，实际上是支持修改的主席树，这里我们就要用到树套树维护序列
//用树状数组维护权值线段树前缀，这是我们由静态区间第 k 小引申出来的，因为对 a[x] 位置的修改要涉及到 O(n*logn) 的修改，[x,n] 每颗线段树都需要 logn 的单点修改复杂度
//那么我们把每颗线段树想象成一个点，我们很容易想到维护前缀和的好东西-树状数组：O(logn) 的修改，O(logn) 的查询
//那么对于 x 位置的线段树的修改，不再是 O(n) 的修改复杂度，而是 O(logn) 对于树状数组序列的修改维护即可
//然后对于区间第 k 小的查询，我们也不再是对第 r 棵线段树的左子树和第 l-1 棵线段树的左子树作差了，我们是 [1,r] 对应的 logr 棵线段树的左子树与 [1,l-1] 对应的 logl-1 棵线段树的左子树作差
//然后就和之前一样，如果这个差值小于等于 k，就往左子树递归，反之像右子树递归，并且变成查询 k-sum 小
//但是要注意！和 log 棵线段树作差对应的，我们这里要 log 棵线段树全部递归才行
//其他注意些细节即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e5+10;

int n,m,a[maxn],o[maxn<<1],len=0;
int rt[maxn],lc[maxn*440],rc[maxn*440],tree[maxn*440],tot=0;
int cnt[2],temp[2][22];
struct node{
	int op,x,y,k;
}q[maxn];

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
	int pos=lower_bound(o+1,o+len+1,a[x])-o;
	for(int i=x;i<=n;i+=-i&i) modify(1,len,rt[i],pos,k);
}

int query(int l,int r,int k){
	if(l==r) return l;
	int res=0;
	for(int i=1;i<=cnt[1];i++) res+=tree[lc[temp[1][i]]];
	for(int i=1;i<=cnt[0];i++) res-=tree[lc[temp[0][i]]];
	int mid=l+r>>1;
	//cout<<l<<"  "<<mid<<" "<<res<<" "<<k<<endl;
	if(res>=k){
		for(int i=1;i<=cnt[1];i++) temp[1][i]=lc[temp[1][i]];
		for(int i=1;i<=cnt[0];i++) temp[0][i]=lc[temp[0][i]];
		return query(l,mid,k);
	}
	else{
		for(int i=1;i<=cnt[1];i++) temp[1][i]=rc[temp[1][i]];
		for(int i=1;i<=cnt[0];i++) temp[0][i]=rc[temp[0][i]];
		return query(mid+1,r,k-res);
	}
}

int prepare_query(int l,int r,int k){
	cnt[1]=cnt[0]=0;
	for(int i=l-1;i;i-=i&-i) temp[0][++cnt[0]]=rt[i];
	for(int i=r;i;i-=i&-i) temp[1][++cnt[1]]=rt[i];
	return query(1,len,k);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),o[++len]=a[i];
	char ch[2];
	for(int i=1;i<=m;i++){
		scanf("%s",ch);
		if(ch[0]=='Q'){
			q[i].op=1;
			scanf("%d %d %d",&q[i].x,&q[i].y,&q[i].k);
		}
		else {
			q[i].op=0;
			scanf("%d %d",&q[i].x,&q[i].y);
			o[++len]=q[i].y;
		}
	}
	sort(o+1,o+len+1);
	len=unique(o+1,o+len+1)-o-1;
	for(int i=1;i<=n;i++) prepare_modify(i,1);
	for(int i=1;i<=m;i++){
		if(q[i].op) printf("%d\n",o[prepare_query(q[i].x,q[i].y,q[i].k)]);
		else{
			prepare_modify(q[i].x,-1);
			a[q[i].x]=q[i].y;
			prepare_modify(q[i].x,1); 
		}
	}
	return 0;
} 
