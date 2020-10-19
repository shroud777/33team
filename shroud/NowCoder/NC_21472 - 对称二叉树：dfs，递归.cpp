//题意：给出一颗二叉树，问交换所有结点的左右子树后，所有子树的结构和位置和之前相同最大的子树大小

//思路：枚举每个结点，递归求左右子树是否对称构成回文，叶结点满足条件直接返回，同时判断是否为完美二叉树

 #include <bits/stdc++.h>

using namespace std;
const int maxn=1e6+10;

int n,v[maxn],sz[maxn];
struct node{
	int l,r;
}a[maxn];


void dfs(int u){
	int lc=a[u].l,rc=a[u].r;
	if(~lc) dfs(lc);
	if(~rc) dfs(rc);
	sz[u]+=sz[lc]+sz[rc];
}

bool check(int lc,int rc){
	if(lc==-1&&rc==-1) return true;
	if(lc==-1||rc==-1) return false;
	if(v[lc]!=v[rc]) return false;
	return check(a[lc].r,a[rc].l)&&check(a[lc].l,a[rc].r);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=1;i<=n;i++) scanf("%d %d",&a[i].l,&a[i].r),sz[i]=1;
	dfs(1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(check(a[i].l,a[i].r)) ans=max(ans,sz[i]);
	}
	printf("%d\n",ans);
	return 0;
} 
