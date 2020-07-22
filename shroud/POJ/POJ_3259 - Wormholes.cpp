//每个农场上有 n 个点，m 条双向边，有 w 条单向负权边，问能否从一个点走到别的地方，再走到自己，使走过的权值为负数

//判断负环即可,用 Floyd 的话把 g[i][i] 初始化为零即可，只要它出现小于 0 的情况，即出现负权环

#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <cstdio>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> pii;
const int N=505;
int g[N][N];
int n,m,w;

int x[N],y[N];

bool floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				if(g[i][j]>g[i][k]+g[k][j]){
					g[i][j]=g[i][k]+g[k][j];
					if(i==j&&g[i][j]<0) return true;
				}
 		}
	}
	return false;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&m,&w);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) g[i][j]=0;
				else g[i][j]=INF;
			}
		}
		int u,v,t;
		while(m--){
			scanf("%d %d %d",&u,&v,&t);
			if(t<g[u][v]) g[u][v]=g[v][u]=t;
		}
		while(w--){
			scanf("%d %d %d",&u,&v,&t);
			g[u][v]=-t;
		}
		if(floyd()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
