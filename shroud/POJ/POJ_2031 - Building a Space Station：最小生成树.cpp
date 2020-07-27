//题意：给出三维空间上 n 个球的坐标，求出使他们都连通需要花费的最小长度
//以下三种被定义为连通：1. A 和 B 相交或相切或者包含 2. A 和 B 有一条边相连 3. A 和 C 相连，B 和 C 相连，那么由于 C ， A 和 B 也相连

//思路：这道题从集合角度想，更加可以深入认识 kruskal 的本质，首先如果两个球已经连通，那么从图的角度可以看做他们已经有一条边，当然更好的是从集合角度想，他们已经是一个集合
//而连通的本质其实就是把所有点并入一个集合，同时要避免将已经是同一个集合的点再次合并，那么其实这题做法和 kruskal 模板没什么区别，将已经是连通的两个球看成一个球，但是这一个合并的球有很多条来自两个或多个子球的边

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int n,m;
struct node{
	double x,y,z,r;
	bool f;
}v[maxn];

struct edge{
	int from,to;
	double w;
	bool operator <(const edge oth)const{
		return w<oth.w;
	}
}g[maxn*maxn/2];

int fa[maxn];
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
} 

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

inline void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		fa[x]=y;
		m--;
	}
}

double cal(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

int main(){
	while(~scanf("%d",&n)){
		if(!n) break;
		m=n-1;
		init();
		for(int i=1;i<=n;i++) scanf("%lf %lf %lf %lf",&v[i].x,&v[i].y,&v[i].z,&v[i].r);
		int tot=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				double d=cal(v[i],v[j]);
				if(v[i].r+v[j].r>=d) merge(i,j);
				else{
					g[++tot].from=i;
					g[tot].to=j;
					g[tot].w=d-v[i].r-v[j].r;
				}
			}
		}
		sort(g+1,g+tot+1);
		int cnt=0;
		double ans=0;
		for(int i=1;i<=tot;i++){
			int u=g[i].from,v=g[i].to;
			u=find(u),v=find(v);
			if(u==v) continue;
			fa[u]=v;
			cnt++;
			ans+=g[i].w;
			if(cnt==m) break;
		}
		printf("%.3f\n",ans);
	}
}
