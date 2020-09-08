//题意：给定一张 n 个点，m 条边的图，每条边 e 都有一个长度 le 和花费 ce，求该图的一棵生成树，是的生成树各边的花费之和闭上长度之和最小

//思路：根据 01 分数规划模型建图即可，每条边的权值变成 ce-mid*le,在图中求得最小生成树找得 sigma(ce)/sigma(le) 的最小值
//如果最小生成树之和大于 0，说明最小值比 mid 大，l 变成 mid，反之 r 变成 mid
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<double,int> pdi;
#define eps 1e-6 
#define INF 0x3f3f3f3f
const int maxn=1e3+10;

int n;
struct edge{
	double l,c;
}g[maxn][maxn];

struct node{
	int x,y,z;
}a[maxn];
int vis[maxn];
double d[maxn];

double cal(int x1,int x2,int y1,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double prim(double x){
	fill(d,d+maxn,INF);
	memset(vis,0,sizeof vis);
	double res=0;
	d[1]=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&(u==0||d[j]<d[u])) u=j;
		}
		vis[u]=1;
		res+=d[u];
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			d[j]=min(d[j],g[u][j].c-g[u][j].l*x);
		}
	}
	return res;
}
// c/l = temp

int main(){
	while(scanf("%d",&n)&&n){
		for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				g[i][j].l=g[j][i].l=cal(a[i].x,a[j].x,a[i].y,a[j].y);
				g[i][j].c=g[j][i].c=abs(a[i].z-a[j].z);
			}
		}
		double l=0,r=1e4,ans;
		while(r-l>eps){
			double mid=(l+r)/2.0;
			if(prim(mid)>=0) l=mid;
			else r=mid;
		}
		printf("%.3f\n",l);
	}
	return 0;
}
