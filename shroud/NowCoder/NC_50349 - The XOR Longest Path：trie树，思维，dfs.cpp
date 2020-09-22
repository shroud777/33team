//题意：求一颗树上的最大异或和路径

//思路：我们预处理出从根节点到每个点 x 的异或和数组 d[x]，那么对于两个点 x,y，他们的异或和就是 d[x]^d[y] 了，因为 x 和 y 重复的异或路径可以通过异或去掉
//那么题意就变成找出最大的异或序对值了

#include <bits/stdc++.h>

using namespace std;	
typedef long long ll;
const int maxn=1e5+10;

int n;
int head[maxn],nex[maxn<<1],to[maxn<<1],w[maxn<<1],tot=0;
ll d[maxn];
int trie[maxn*32][2],tot2=1;

inline void add(int u,int v,int len){
	to[++tot]=v;
	w[tot]=len;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs(int u,int fa){
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		d[v]=d[u]^w[i];
		dfs(v,u);
	}
}

void insert(int x){
	int t,p=1;
	for(int i=30;i>=0;i--){
		t=(x&(1<<i)?1:0);
		if(!trie[p][t]) trie[p][t]=++tot2;
		p=trie[p][t];
	}
}

ll get_max(int x){
	int t,p=1;
	ll ans=0;
	for(int i=30;i>=0;i--){
		t=(x&(1<<i)?1:0);
		if(trie[p][t^1]){
			p=trie[p][t^1];
			ans+=(1<<i);
		}
		else p=trie[p][t];
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	int u,v,len;
	for(int i=1;i<n;i++){
		scanf("%d %d %lld",&u,&v,&len);
		add(u,v,len);
		add(v,u,len);
	}
	dfs(1,0);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,get_max(d[i]));
		insert(d[i]);
	}
	cout<<ans<<endl;
	return 0;
} 
