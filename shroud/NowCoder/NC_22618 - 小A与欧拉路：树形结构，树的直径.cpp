//题意：给出一棵树，现在可以复制任意边，即在 e(u,v,w) 上再连一条 e'(u,v,w)，现在问可能形成的新的图的欧拉路的最短长度

//题意：可以发现以任意结点 x 为根，我们得到的欧拉路长度就是 x 到所有的长度的两倍减去某一条边的值，因为必须要重复回到根节点，最后只能某一条边只走一遍
//那么我们只要找到最长的那条树上路径，即树的直径即可，用树形dp来求树的直径，然后得到最优解

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e4+10;
int n,head[maxn],nex[maxn<<1],to[maxn<<1],tot=0;
ll w[maxn<<1],d[maxn],ans=0;

inline void add(int u,int v,ll d){
	to[++tot]=v;
	w[tot]=d;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs(int u,int fa){
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		dfs(v,u);
		ans=max(d[u]+d[v]+w[i],ans);
		d[u]=max(d[u],d[v]+w[i]);
	}
}

int main(){
	scanf("%d",&n);
	int u,v;
	ll d,res=0;
	for(int i=1;i<n;i++){
		scanf("%d %d %lld",&u,&v,&d);
		add(u,v,d);
		add(v,u,d);
		res+=d;
	}
	res<<=1;
	dfs(1,0);
	printf("%lld\n",res-ans);
	return 0;
} 
