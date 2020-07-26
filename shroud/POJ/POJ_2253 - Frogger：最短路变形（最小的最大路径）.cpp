//题意：有两只青蛙在相邻序号的两块石头上，分别是 1，2， 1 号青蛙想到 2 号青蛙的石头上，但是由于跳跃距离不够，他必须借助其他石头跳到 2 号石头，给出 n 块石头的点坐标
//规定从 1 号到 2 号的路径中跳跃的最长路径叫做 frog range ,求出所有 1 到 2 号路径中最短的 frog range

//思路：就是求两点间所有路径的最大边的最小值，可以用最短路求法来求，只不过将松弛操作变成记录最小值操作

#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> pii;
const int N=205;
double g[N][N];
int n;

int x[N],y[N];

void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],max(g[i][k],g[k][j]));
			}
		}
	}
}

int main(){
	int t=0;
	while(cin>>n,n){
		memset(g,0,sizeof g);
		for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++) g[i][j]=g[j][i]=sqrt(double(x[i]-x[j])*(x[i]-x[j])+double(y[i]-y[j])*(y[i]-y[j]));
		}
		floyd();
		cout<<"Scenario #"<<++t<<endl;
		cout<<"Frog Distance = "<<fixed<<setprecision(3)<<g[1][2]<<endl<<endl;
	}
}
