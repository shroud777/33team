//题意：某群里有 n 个成员，A 请教 B 问题，B 成为了 A 的大佬，A 成了 B 的舔狗，大佬的大佬还是大佬，但是大佬的舔狗不能是他的大佬，给出 m 个关系，判断是否合法。

//思路：判断有向无环图即可。。。拓扑排序

#include <iostream>
#include <algorithm>
#include <cstring> 
#include <vector>
#include <queue>
using namespace std;
#define pb push_back
#define INF 0x3f3f3f3f
const int maxn=1e4+10;
vector<int> g[105];
int in[maxn],vis[maxn];
int n,m;
queue<int>q;
int main(){
	int u,v;
	while(cin>>n>>m){
		int cnt=0;
		if(!n&&!m) break;
		for(int i=0;i<n;i++){
			g[i].clear();
			in[i]=0;
		}
		while(m--){
			cin>>u>>v;
			g[u].pb(v);
			in[v]++;
		}
		for(int i=0;i<n;i++){
			if(!in[i]){
				q.push(i);
				cnt++;
			}
		}
		while(!q.empty()){
			int st=q.front();
			q.pop();
			for(int i=0;i<g[st].size();i++){
				int now=g[st][i];
				in[now]--;
				if(!in[now]){
					cnt++;
					q.push(now);
				}
			}
		}
		if(cnt!=n) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
