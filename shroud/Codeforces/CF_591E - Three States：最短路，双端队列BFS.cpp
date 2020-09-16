//题意：在一个 n*m 的网格图上，存在三个阵营，还有可修建的道路和障碍物，修建道路的花费为 1，现在要使三个阵营相连，其中只能走已存在的阵营和连通的路，求最小花费

//思路：我们从三个阵营分别开始 BFS，求出三个阵营到每个点的最短距离，然后枚举每个点，求出三个阵营到这个点的最短距离即可，注意这里最好使用双端队列BFS，因为这是典型的 01最短路 问题
//已建立的阵营代表 0，其他代表 1

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e3+10;
int d[4][2]={1,0,0,1,0,-1,-1,0};

char g[maxn][maxn];
int dist[4][maxn][maxn];
int n,m;

void bfs(int t){
	deque<pii> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]==t+'0') q.push_back(pii(i,j)),dist[t][i][j]=0;
		}
	}
	while(!q.empty()){
		pii temp=q.front();
		q.pop_front();
		int x=temp.first,y=temp.second;
		for(int i=0;i<4;i++){
			int xx=x+d[i][0];
			int yy=y+d[i][1];
			int res=0;
			if(xx<1||xx>n||yy<1||yy>m||g[xx][yy]=='#') continue;
			if(g[xx][yy]=='.') res=1;
			if(dist[t][xx][yy]>dist[t][x][y]+res){
				dist[t][xx][yy]=dist[t][x][y]+res;
				int fx=q.front().first,fy=q.front().second;
				if(q.empty()){
					q.push_back(pii(xx,yy));
					continue;
				}
				if(dist[t][xx][yy]<dist[t][fx][fy]) q.push_front(pii(xx,yy));
				else q.push_back(pii(xx,yy));
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",g[i]+1);
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=3;i++) bfs(i);
	ll ans=0x3f3f3f3f,res;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			res=0;
			for(int k=1;k<=3;k++) res+=dist[k][i][j];
			if(g[i][j]=='.') res-=2;
			ans=min(res,ans);
		}
	}
	ans>=0x3f3f3f3f?puts("-1"):printf("%lld\n",ans);
	return 0;
}
