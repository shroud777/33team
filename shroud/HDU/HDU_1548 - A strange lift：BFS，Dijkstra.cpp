//题意：有一个电梯可以在 1~n 层活动，每一层有一个权值 ki，你可以在该层按按钮选择上升 ki 层，或下降 ki 层，问从 a 到 b 最少要按多少次按钮。

//思路：BFS/Dijkstra  
//  Dijkstra做法还没写

#include <iostream>
#include <algorithm>
#include <cstring> 
#include <vector>
#include <queue>
using namespace std;
#define pb push_back
#define INF 0x3f3f3f3f
const int maxn=105;
int a[205],vis[205];
int n,s,e;
int bfs(){
	queue<int> q;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int st=q.front();
		if(st==e) return vis[st]-1;
		q.pop();
		if(st+a[st]<=n){
			if(!vis[st+a[st]]){
				q.push(st+a[st]);
				vis[st+a[st]]=vis[st]+1;
			}
		}
		if(st-a[st]>=1){
			if(!vis[st-a[st]]){
				q.push(st-a[st]);
				vis[st-a[st]]=vis[st]+1;
			}
		}
	}
	return -1;
}
int main(){
	while(cin>>n,n){
		cin>>s>>e;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			vis[i]=0;
		}
		cout<<bfs()<<endl;
	}
	return 0;
}
