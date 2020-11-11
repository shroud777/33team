//题意：
//如题，你需要维护这样的一个长度为 N 的数组，支持如下几种操作
//1.在某个历史版本上修改某一个位置上的值
//2.访问某个历史版本上的某一位置的值
//此外，每进行一次操作（对于操作2，即为生成一个完全一样的版本，不作任何改动），就会生成一个新的版本。版本编号即为当前操作的编号（从1开始编号，版本0表示初始状态数组）

//思路：可持久化线段树模板
//https://github.com/shroud777/33team/blob/patch-2/shroud/%E6%80%9D%E8%80%83%E6%80%BB%E7%BB%93/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%BA%BF%E6%AE%B5%E6%A0%91/%E5%8F%AF%E6%8C%81%E4%B9%85%E5%8C%96%E7%BA%BF%E6%AE%B5%E6%A0%91.md


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;
const int lg=20;

int a[maxn],n,q;
int rt[maxn],tree[maxn*lg<<1],lc[maxn*lg<<1],rc[maxn*lg<<1],tot=0;
int L,R;

void build(int l,int r,int &x){
	x=++tot;
	if(l==r){
		tree[x]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,lc[x]);
	build(mid+1,r,rc[x]);
}

void modify(int l,int r,int &x,int pos,int k,int p){
	x=++tot;
	tree[tot]=tree[p];
	lc[tot]=lc[p];
	rc[tot]=rc[p];
	if(l==r){
		tree[x]=k;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,lc[x],pos,k,lc[p]);
	else modify(mid+1,r,rc[x],pos,k,rc[p]);
}

int query(int l,int r,int x,int pos){
	if(l==r) return tree[x];
	int mid=l+r>>1;
	if(pos<=mid) return query(l,mid,lc[x],pos);
	return query(mid+1,r,rc[x],pos); 
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,n,rt[0]);
	int vi,opt,pos,w;
	for(int i=1;i<=q;i++){
		scanf("%d %d %d",&vi,&opt,&pos);
		if(opt==1){
			scanf("%d",&w);
			modify(1,n,rt[i],pos,w,rt[vi]);
		}
		else{
			rt[i]=rt[vi];
			printf("%d\n",query(1,n,rt[vi],pos));
		}
	}
	return 0;
}
