//题意：给出一颗 n 个结点的树，每个节点有一个权值，每条边长度为 1，若图中某点对（u,v）距离为 2，则称他们为联合点对，他们会产生 wu*wv 的联合权值，求所有联合权值之和和联合权值的最大值

//思路：距离为 2 这个条件门槛很低，一开始我想到从根到叶结点的单向性，统计每个节点到他父亲的父亲的联合权值，然后还有每个节点的子节点集间两两构成，还有种更简单的想法
//后来发现某个序对中间必然经过一个点，那么我们可以枚举中间点，然后对于中间点相邻的所有点，记录它周围点权值的最大值和和以达到 O(n) 计算联合权值之和和最大值

//dfs

#include <bits/stdc++.h>

using namespace std;	
typedef long long ll;
const int maxn=2e5+10;
const int p=1e4+7;

int n;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
ll w[maxn],mx[maxn],sum[maxn],ans=0,Max=0;

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs(int u,int fa){
	mx[u]=sum[u]=w[fa];
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		Max=max(Max,mx[u]*w[v]);
		ans=(ans+sum[u]*w[v])%p;
		sum[u]=(sum[u]+w[v])%p;
		mx[u]=max(mx[u],w[v]);
		dfs(v,u);
	}
}

int main(){
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	dfs(1,0);
	cout<<Max<<" "<<2*ans%p<<endl;
	return 0;
} 



//中间点方法

#include <bits/stdc++.h>

using namespace std;	
typedef long long ll;
const int maxn=2e5+10;
const int p=1e4+7;

int n;
ll w[maxn];
vector<int> g[maxn];

int main(){
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	ll res_mx,res_sum,mx=0,sum=0;
	for(int i=1;i<=n;i++){
		res_mx=res_sum=0;
		for(int j=0;j<g[i].size();j++){
			ll wg=w[g[i][j]];
			mx=max(mx,res_mx*wg);
			sum=(sum+res_sum*wg)%p;
			res_mx=max(res_mx,wg);
			res_sum=(res_sum+wg)%p;
		}
	}
	cout<<mx<<" "<<sum*2%p<<endl;
	return 0;
}
