//题意：有一颗 n 个结点的树，现在要求给 n-1 条边赋值，要求如下：n-1 条边的乘积为 k，权值为 1 的边的数量尽可能小
//现在要求 n 个结点每个结点 u 到其他结点 (u+1,n) 的长度为值最大，并且 k 是以质因子的形式给出

//思路：首先必须得明确，一条边它在上述求和过程中出现得次数越多，那么它的权值应该越大，那么我们可以想到，上述求和过程其实是对所有点和点之间距离的求和
//那么实际上对于一条边它重复的次数就是 一端的子树大小*另一端的子树大小，我们只需要 dfs 求出一半子树大小，另一半就是 n-sz 了
//于是我们根据上述思想按照贡献比重依次对边排序，然后题目要求权值为 1 的边数量尽量小，那么下面分出两种情况
//第一种：质因子的数量 m <= 树边 n-1 ，那么我们可以得知，把质因子分给每个树边，它能无法保证每条边有权值，所以剩下的树边分配为 1 即可，并且为了满足和尽可能大，我们把大的质因子分配给贡献大的边
//这里就是运用到 a>b,c>d  a*c+b*d>a*d+b*c 了，证明略
//第二种，质因子的数量 m > 树边 n-1，为了满足乘积为 k，我们把多出来的 m-n+1 条边压缩到最大的一条边上，那 m-n+1 条边都要保证是最大的，原理如上，总之就是大的结合在一起会更大更优，然后
//按照第一种情况，把 n-2 条边一次赋上质因子的值即可

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;

int n,m;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot;
ll sz[maxn],d[maxn<<1],p[maxn];

void init(){
	tot=0;
	for(int i=1;i<=n;i++) head[i]=0,sz[i]=1;
	for(int i=1;i<=2*n;i++) d[i]=0;
}

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs(int u,int fa,int e){
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		dfs(v,u,i);
		sz[u]+=sz[v];
	}
	if(e) d[e]=1ll*sz[u]*(n-sz[u]);
} 

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		init();
		int u,v;
		for(int i=1;i<n;i++) scanf("%d %d",&u,&v),add(u,v),add(v,u);
		dfs(1,0,0);
		sort(d+1,d+n*2+1,greater<ll>());
		scanf("%d",&m);
		for(int i=1;i<=m;i++) scanf("%lld",&p[i]);
		sort(p+1,p+m+1,greater<ll>());
		ll ans=0;
		if(m>n-1){
			ll t=1;
			for(int i=1;i<=m-n+2;i++) t=(t*p[i])%mod;
			ans=(ans+t*d[1]%mod)%mod; 
			int j;
			for(int i=m-n+3,j=2;i<=m;i++,j++) ans=(ans+d[j]*p[i]%mod)%mod;
		}
		else{
			for(int i=1;i<=m;i++) ans=(ans+d[i]*p[i]%mod)%mod;
			for(int i=m+1;i<=n;i++) ans=(ans+d[i]%mod)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
