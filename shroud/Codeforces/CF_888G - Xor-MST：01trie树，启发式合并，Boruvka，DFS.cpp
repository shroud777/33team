//题意：给出 n 个点，每个点有个权值 ai，现在要求给出图的最小生成树，其中边权 w(i,j)=ai*aj

//思路：数据 2e5，边数太多，我们肯定不能光从最小生成树求法去想，这里由于是 Xor 边权，那我们可以想到 01Trie
//可以发现对于两个插入 01Trie 的数，他们的 lca 的深度反映了他们的 Xor 值大小，深度大的 XOr 值一定小，深度相同则不一定，但是我们也能尽量往下深入的时候每一位选择相同的方向（0,1）
//对于每个两个不同的叶子结点，我们发现他们的 lca 是不会重复的，并且 n 个点始终会有 n-1 个 lca，我们这里就延伸除了两种相似但是细节有差异的做法
//首先基于 Boruvka 算法，我们可以想到，我们这个过程相当于每次把深度由深到浅的 lca 左右对应的两个集合合并，具体来说就是往下延伸的时候同一位尽量都是 0 或者 1
//这样我们就相当于 Boruvka 多路增广的过程
//第一种方法是启发式合并，就是把小的子树并到大的子树上，这里不多做介绍了
//第二种方法就是找两个集合最小的路径，那么这里我们可以用 DFS 找 lca，然后找到了就向下递归找


//找 lca 左右孩子的两个集合之间的最小路径
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+10;

int n,trie[2][maxn*32],w[maxn*32],tot=1;

void insert(int x){
	int p=1,t;
	for(int i=31;i>=0;i--){
		w[p]=i;
		t=(1<<i)&x?1:0;
		if(!trie[t][p]) trie[t][p]=++tot;
		p=trie[t][p];
	}
}

ll find(int l,int r){
	//cout<<l<<" "<<r<<endl;
	ll p1=-1,p2=-1;
	if(trie[0][l]&&trie[0][r]) p1=find(trie[0][l],trie[0][r]);
	if(trie[1][l]&&trie[1][r]) p2=find(trie[1][l],trie[1][r]);
	if(~p1&&~p2) return min(p1,p2);
	if(~p1) return p1;
	if(~p2) return p2;
	if(trie[0][l]&&trie[1][r]) p1=find(trie[0][l],trie[1][r])+(1<<w[l]);
	if(trie[1][l]&&trie[0][r]) p2=find(trie[1][l],trie[0][r])+(1<<w[l]);
	//cout<<"test:"<<p1<<" "<<p2<<endl;
	if(~p1&&~p2) return min(p1,p2);
	if(~p1) return p1;
	if(~p2) return p2;
	return 0;
}

ll dfs(int p){
	//cout<<p<<endl;
	ll ans=0;
	if(trie[1][p]&&trie[0][p]){
		ans=find(trie[1][p],trie[0][p])+(1<<w[p]);
		//cout<<(1+w[p])<<" "<<p<<endl;
		return ans+dfs(trie[1][p])+dfs(trie[0][p]);
	}
	if(trie[1][p]) return dfs(trie[1][p]);
	if(trie[0][p]) return dfs(trie[0][p]);
	return 0;
}

int main(){
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++) scanf("%d",&x),insert(x);
	printf("%lld\n",dfs(1));
	return 0;
}
