//题意：有 n 个点， m 条边，请你给每一条边确定一个新的边权，使得在新图上的任意 u 到 v 的最短路和原图上的最短路上的点相同且顺序不变

//思路：建立一个超级源点和每一个点练一条权值为 0 的边，跑一遍 SPFA，对于 u 和 v 的最短路即是 dist[u]-dist[v]+w[u][v]
//证明如下：首先根据最短路的放缩原理 dis[v]>=dis[u]+w 所以 dis[u]−dis[v]+w >=0成立。即上述最短路边权非负
//然后我们再看为什么在新图上最短路径不会改变：
//假设原图里 u−>v 的最短路径为 u−>x1−>x2−>x3−>v
//最短路也就是  w(u,x1)+w(x1,x2)+w(x2,x3)+w(x3,v)
//然后我们更改了边权最短路变为：dis[u]−dis[x1]+w(u,x1)+dis[x1]−dis[x2]+w(x1,x2)+dis[x2]−dis[x3]+w(x2,x3)+dis[x3]−dis[v]+w(x3,v)
//然后化简一下就变为：  w(u,x1)+w(x1,x2)+w(x2,x3)+w(x3,v)+dis[u]−dis[v]
//多出来了一个 dis[u]−dis[v] 这是一个定值，所以这里我们希望上述 w+dis[u]-dis[v] 中 w 越短越好，所以只要在原图里是最短路径，在新图里也会同样是最短路径。

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e3+10;
const int M=4e3+10;
#define INF 0x3f3f3f3f
struct node{
    int from,to,w,next;
}g[M];
int head[N],tot=0;
int dist[N];
bool inq[N];
int n,m;
 
void init(){
    tot=0;
    for(int i=0;i<=n;i++) head[i]=-1;
    for(int i=1;i<=m+n;i++) g[i].next=-1;
}
 
void add(int u,int v,int w){
    g[++tot].to=v;
    g[tot].from=u;
    g[tot].w=w;
    g[tot].next=head[u];
    head[u]=tot;
}
 
void SPFA(){
    for(int i=0;i<=n;i++){
        dist[i]=INF;
        inq[i]=false;
    }
    dist[0]=0;
    inq[0]=1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        inq[t]=0;
        for(int i=head[t];~i;i=g[i].next){
            int j=g[i].to;
            if(dist[j]>dist[t]+g[i].w){
                dist[j]=dist[t]+g[i].w;
                if(!inq[j]){
                    q.push(j);
                    inq[j]=1;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    init();
    int u,v,w;
    int t=m;
    while(t--){
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
    }
    for(int i=1;i<=n;i++) add(0,i,0);
     
    SPFA();
    for(int i=1;i<=m;i++){
        int u=g[i].from,v=g[i].to,w=g[i].w;
        cout<<u<<" "<<v<<" "<<dist[u]-dist[v]+w<<endl;
    }
    return 0;
}
