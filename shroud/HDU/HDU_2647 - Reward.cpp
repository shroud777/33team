//题意：有 n 个员工，他们有 m 个愿望，就是 A 的工资比 B 高，最低工资起步是 888，求满足这些员工的最低工资和是多少

//思路：拓扑排序，先找没有任何比别人工资高想法的员工，即找没有前驱结点的结点，然后把所有通向它的结点的出度 -1，然后最后判断一下，如果还有点没有进拓扑排序就说明他们的愿望互相矛盾，不是 DAG

#include <iostream>
#include <algorithm>
#include <cstring> 
#include <vector>
#include <queue>
using namespace std;
#define pb push_back
#define INF 0x3f3f3f3f
const int maxn=1e4+10;
int n,m;
int vis[maxn],out[maxn];
vector<int> g[maxn];
queue<int> q;
int main(){
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			out[i]=vis[i]=0;
			g[i].clear();
		}
		int u,v;
		while(m--){
			cin>>u>>v;
			g[v].pb(u);
			out[u]++;
		}
		for(int i=1;i<=n;i++){
			if(!out[i]){
				q.push(i);
				vis[i]=1;
			}
		}
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(int i=0;i<g[now].size();i++){
				v=g[now][i];
				out[v]--;
				if(!vis[v]&&!out[v]){
					vis[v]=vis[now]+1;
					q.push(v);
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				ans=-1;
				break;
			}
			ans+=vis[i]+888-1; 
		}
		cout<<ans<<endl;
	} 
	return 0;
}
