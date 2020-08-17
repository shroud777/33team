//题意：在一个 n*n 的矩阵中，从 （1,1） 位置出发到 （n，n）位置，其中每个格子有一个区域值，如果区域值为 0 说明无法通行，求区域值最小的路径

//思路：BFS 搜索即可，初始化到每个格子的距离为无穷大，如果 BFS 到下一个格子的距离，比之前到下一个格子的距离短，就更新路径长度

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int maxn=2e5+10;
int vis[105][105],mp[105][105],dis[105][105];
int d[4][2]={1,0,-1,0,0,1,0,-1};
int n;

void bfs(){
	memset(dis,0x3f,sizeof dis);
	queue<pii> q;
	q.push(pii(1,1));
	vis[1][1]=1;
	dis[1][1]=mp[1][1];
	while(!q.empty()){
		pii t=q.front(),now;
		q.pop();
		int x,y;
		for(int i=0;i<4;i++){
			x=t.first+d[i][0];
			y=t.second+d[i][1];
			if(x<1||x>n||y<1||y>n||mp[x][y]==0) continue;
			if(dis[x][y]>dis[t.first][t.second]+mp[x][y]){
				dis[x][y]=dis[t.first][t.second]+mp[x][y];
				q.push(pii(x,y));
			}
		}	
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>mp[i][j];
	bfs();
	if(dis[n][n]==0x3f3f3f3f) cout<<0<<endl;
	else cout<<dis[n][n]<<endl;
	return 0;
}
