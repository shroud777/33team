//题意：有 n 个点， m 条边，Johnny 要对这些点按照先后顺序染色，每次染色按照规则，相邻的两个点不能染同一种颜色，每次染的颜色必须是除了它已经染色的邻边的颜色的最小值
//给出每个点应该染什么颜色，问能否存在一种染色顺序打到这个目标

//思路：刚开始想着先对这些点按照要染的颜色的大小排序，先把小的点染了，同时每次染一个点的时候遍历他的邻边，判断当前染的这颜色是不是当前这点的除邻边颜色外的最小值
//这个想法应该还是会超时，之后看了题解，发现一种更好的办法。首先，其实不需要保存每个点的信息然后排序，可以直接用邻接表存在他们对应的颜色里，然后按顺序遍历
//然后题解标程中的方法是在是牛，他设置一个 last 数组，用来记录 Last[i] 即第 i 个颜色最后出现在哪儿，他只要遍历一遍当前点 u 的邻点，然后就可以直接更新 last 
//用 ans 数组记录这个点当前染色状态（没染就是 0 ，染了就是对应的颜色），然后 ans[u] 初始值是 1，如果 last[ans[u]] == u ,代表这个点周围已经有点用了这个颜色，ans[u] ++
//最后如果 ans[u] 等于当前要染色的颜色，就没问题了，首先这样判断了当前除邻边外最小颜色是不是 u 的问题，其次还解决了颜色重叠的问题，属实吊

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int maxn=5e5+10;
vector<int> g[maxn];
vector<int> in[maxn];
vector<int> res;
int ans[maxn],last[maxn];
int main(){
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	while(m--){
		scanf("%d %d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	int c;
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		in[c].pb(i);
	}
	int now,near;
	for(int c=1;c<=n;c++){
		for(int i=0;i<in[c].size();i++){
			now=in[c][i];
			for(int j=0;j<g[now].size();j++){
				near=g[now][j];
				last[ans[near]]=now;
			}
			ans[now]=1;
			while(last[ans[now]]==now) ans[now]++;
			if(ans[now]!=c){
				cout<<-1<<endl;
				return 0;
			}
			res.pb(now);
		}
	}
	cout<<res[0];
	for(int i=1;i<res.size();i++) cout<<" "<<res[i];
	cout<<endl;
	return 0;
}
