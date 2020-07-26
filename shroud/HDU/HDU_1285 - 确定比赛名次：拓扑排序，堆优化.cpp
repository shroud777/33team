//题意：有 n 只队伍进行比赛，只知道 m 次比赛（某两只队伍）的结果，确定各队伍的排名，若排名不唯一，讲编号小的排在前面

//思路：拓扑排序，同时把由于编号小的要放在前面，可以用优先队列代替普通队列，每次找入度结点为 0 的，然后把他的后续结点的入度 -1 即可。

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
const int maxn=1005;
int n;
vector<int> g[maxn];
vector<int> ans;
int in[maxn],vis[maxn];
void init(){
	ans.clear();
	for(int i=1;i<=n;i++){
		g[i].clear();
		in[i]=0;
		vis[i]=0;
	}
}
priority_queue<int,vector<int>, greater<int> > q; 
int main(){
	int m,x,y;
	while(cin>>n>>m){
		init();
		while(m--){
			cin>>x>>y;
			g[x].pb(y);
			in[y]++;
		}
		for(int i=1;i<=n;i++){
			if(!in[i]){
				q.push(i);
				vis[i]++;
			}
		}
		while(!q.empty()){
			int now=q.top();
			ans.pb(now);
			q.pop();
			for(int i=0;i<g[now].size();i++){
				in[g[now][i]]--;
				if(!vis[g[now][i]]&&!in[g[now][i]]){
					q.push(g[now][i]);
					vis[g[now][i]]++;
				}
			}
		}
		cout<<ans[0];
		for(int i=1;i<ans.size();i++){
			cout<<" "<<ans[i];
		}
		cout<<endl;
	}	
	return 0;
}
