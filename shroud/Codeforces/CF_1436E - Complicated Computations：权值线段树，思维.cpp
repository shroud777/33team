//题意：找到给出长度为 n 个序列的所有子序列的 MEX 值的 MEX 值，MEX 是指不在序列中出现过的最小的正整数

//思路：数据 1e5，O(n^2) 不用考虑，这里我们思考找某个数 x 能不能成为某个子序列的 MEX 值
//这里用到权值线段树和 MEX 的性质，首先那个子序列里不能包含 x，且 1-x-1 都要包含，这里我们想到想到记录每个 pre[x]，即上一个 x 出现的位置，判断 [1,n-1] 这 n-1 个数能否全在 [pre[x]+1,i] 里出现
//出现了则说明，x 可以成为 MEX，然后就可以把他排除掉

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=1e5+10;
 
int n,L,R,tree[maxn<<2],a[maxn],vis[maxn],pre[maxn];
 
void modify(int l,int r,int x,int pos,int k){
	if(l==r){
		tree[x]=k;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,x<<1,pos,k);
	else modify(mid+1,r,x<<1|1,pos,k);
	tree[x]=min(tree[x<<1],tree[x<<1|1]);
}
 
int query(int l,int r,int x){
	if(L<=l&&r<=R) return tree[x];
	int mid=l+r>>1;
	int ans=0x3f3f3f3f;
	if(L<=mid) ans=min(query(l,mid,x<<1),ans);
	if(mid<R) ans=min(query(mid+1,r,x<<1|1),ans);
	return ans;
}
 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) vis[1]=1;
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		if(x>1){
			L=1,R=x-1;
			if(query(1,n,1)>pre[x]) vis[x]=1;
		}
		modify(1,n,1,x,i);
		pre[x]=i; 
	}
	for(int i=2;i<=n+1;i++){
		R=i-1;
		if(query(1,n,1)>pre[i]) vis[i]=1;
	}
	int res=1;
	while(vis[res]) res++;
	cout<<res<<endl;
	return 0;
}
