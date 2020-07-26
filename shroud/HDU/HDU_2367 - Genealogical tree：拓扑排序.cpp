//题意：某家族有 n 个成员，给出第 i 个成员的若干个儿女，求一个序列满足长辈在子女前面

//思路：拓扑排序。。。他要求最老的先出现，最后出现的显然是最年轻的孩子，这个时候只要先找那些没有妈妈的结点就可以了，然后再把他们剔除，又有一些结点没了妈妈

#include <iostream>
#include <algorithm>
#include <cstring> 
#include <vector>
#include <queue>
using namespace std;
#define pb push_back
#define INF 0x3f3f3f3f
const int maxn=105;
vector<int> g[maxn];
int in[maxn];
int n;
queue<int>q;
vector<int> ans;
int main(){
	while(cin>>n){
		for(int i=1;i<=n;i++){
			g[i].clear();
			in[i]=0;
		}
		ans.clear();
		for(int i=1;i<=n;i++){
			int v;
			while(cin>>v,v){
				g[i].pb(v);
				in[v]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(!in[i]) q.push(i);
		}
		while(!q.empty()){
			int st=q.front();
			q.pop();
			ans.pb(st);
			for(int i=0;i<g[st].size();i++){
				int now=g[st][i];
				in[now]--;
				if(!in[now]) q.push(now);
			}
		}
		cout<<ans[0];
		for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
		cout<<endl;
	}
	return 0;
}
