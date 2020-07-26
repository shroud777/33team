//题意：有 n 个人，给定 m 个人他们的单向关系，即 A 比 B 强，问有几个人能确定排名顺序

//思路：一开始想拓扑排序，后来发现可以通过 Floyd 求闭包，即传递他们的关系，只要一个点和其他所有点都有关系，即可确定顺序，我一开始还用 Floyd 求最短路，其实也是可以的，因为只要两点间有距离也代表他们有关系

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int g[105][105];
int n,m;

void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			if(g[i][k]==0) continue;
			for(int j=1;j<=n;j++)
				if(g[i][k]&&g[k][j])
					g[i][j]=1;
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) g[i][j]=0;
	}
	while(m--){
		cin>>u>>v;
		g[u][v]=1;
	}
	floyd();
	int cnt=0;
	for(int i=1;i<=n;i++){
		bool f=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(!g[i][j]&&!g[j][i]){
				f=0;
				break;
			}
		}
		if(f) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
