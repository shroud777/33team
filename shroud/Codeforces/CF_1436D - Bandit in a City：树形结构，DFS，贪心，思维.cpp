//题意：给出一个有 n 个结点的树，n-1 条边都是单向边，且每个结点上会存在一定数量的居民，现在 1 号根节点有一群强盗，每个点的居民都会顺着单向边走到子树去（每个方向去的人不固定）
//最后所有的居民都无法移动了，强盗也顺着单向边到某个叶结点，并且捕获那里最多的居民，保证强盗和居民的策略都是最优策略，问现在强盗最少抓到的居民个数是多少

//思路：首先强盗在最后行动，那么最后选取的肯定是所有叶节点中所包含居民最多的结点，问题就变成了使叶节点人数最大的最小。那么我们来想想，根据鸽巢原理，如果所有的人数都集中到 1 号结点上
//那么我们最后的答案肯定是 (ceil)(总人数/叶子节点的个数)，但是我们在实际情况中会受到限制，比如我们想要平均分配人数，但是某个子节点的人数特别多，我们肯定不会再往那个子节点分配了
//根据贪心的思想，那个最大的子节点就是我们的答案了，因为我们肯定不会再往那个子节点分配人数，肯定尽量往其他地方分，那么答案似乎已经很明显了
//我们对于每颗子树，尽量平均地往每个子节点分配人数，但是如果每个结点的人数已经特别多了，且下面只有一个叶节点，无法向别人分配，那么我们就以它为准则，其他叶节点分配的人数肯定也不会大于平均值


#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=2e5+10;
int n;
 
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
ll a[maxn],leaf[maxn],sum[maxn],mx[maxn];
 
inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}
 
void dfs(int u,int fa){
	sum[u]=mx[u]=a[u];
	if(!head[u]){
		leaf[u]=1;
		return;
	}
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		dfs(v,u);
		sum[u]+=sum[v];
		leaf[u]+=leaf[v];
		//mx[u]=max[mx[v]]
	}
}
 
int main(){
	scanf("%d",&n);
	int v;
	for(int i=2;i<=n;i++){
		scanf("%d",&v);
		add(v,i);
	}
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(1,0);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll temp=(ceil)(1.0*sum[i]/leaf[i]);
		//cout<<sum[i]<<" "<<leaf[i]<<endl;
		ans=max(ans,temp);
	}
	printf("%lld\n",ans);
	return 0;
}
