//题意：有 n 个人编号从 0-n-1 ，给出 m 个两两之间的关系，问是否每个人都认识且中间的朋友不超过 6 个

//思路：floyd 处理多源最短路，直接 O(n^3) 把所有点的最短路处理出来，然后判断即可

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int n,m;
int g[105][105];

void floyd(){
	int s=1;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			if(g[i][k]!=INF)
			for(int j=0;j<n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		}
	}
}

int main(){
	while(cin>>n>>m){
		int u,v;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) g[i][j]=INF;
		}
		for(int i=1;i<=m;i++){
			cin>>u>>v;
			g[u][v]=1;
			g[v][u]=1;
		}
		floyd();
		bool f=1;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(g[i][j]>7){
					f=0;
					break;
				}
			}
			if(!f) break;
		}
		if(f) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
