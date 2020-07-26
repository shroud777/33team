//题意：给出 n 个城市和 m 条路，每条路是双向的且有速度要求，从一条路到另一条路可以瞬间 提速/降速，给出起点和终点，找到那条最高速度和最低速度差值最小的路，若不能到达贼输出 -1

//思路：刚开始想用 DFS 来遍历每条路，但超时了，这里 1000 条路，DFS是指数级别的，显然不可以。这道题正确做法是讲路径速度升序后,以序列当前位置的边为起点，不断往其中加边，用并查集判断两个点是否连通
//其实这个做法和kruskal建最小生成树的过程有点像，这里就是不断枚举建立不同最小生成树，然后找到差值

#include <iostream>
#include <algorithm>
#include <cstring> 
#include <vector>
using namespace std;
#define pb push_back
#define INF 0x3f3f3f3f
const int maxn=1005;
int n;
struct node{
	int from,to,w;
	bool operator <(const node other){
		return w<other.w;
	}
}g[maxn];
int fa[210];
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(x==fa[x]) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y) fa[y]=x;
}
int main(){
	int m,u,v,s,q;
	while(cin>>n>>m){
		for(int i=1;i<=m;i++) cin>>g[i].from>>g[i].to>>g[i].w;
		sort(g+1,g+1+m);
		int q;
		cin>>q;
		while(q--){
			cin>>u>>v;
			int ans=INF;
			for(int i=1;i<=m;i++){
				init();
				for(int j=i;j<=m;j++){
					merge(g[j].from,g[j].to); 
					if(find(u)==find(v)){
						ans=min(ans,g[j].w-g[i].w);
						break;
					}
				}
			}
			if(ans==INF) cout<<-1<<endl;
			else cout<<ans<<endl;
		}
	}
	return 0;
}
