//题意：现在有一个树形的水系，有 n-1 条河道和 n 个结点，有一个节点是水系的发源点，除了源点之外所有度数 1 的节点都是入海口，可以吸收无限多的水，水源从源点出发流向各个汇点，但是水流流过河道会受到限制
//现在整个水系的流量就是稳定后单位时间从源点流出的水量，求哪个点作为源点时，整个水系的流量最大

//思路：如果对于某个源点来说，我们只需要 O(n) 进行一次树形DP，就可以找到答案。状态转移方程 f[i]=Σmin(f[v],w)，如果 v 的度数为 1，那么 f[i]=w
//但是由于题目中不知道是哪个节点作为源点，所以我们需要找到所有源点的流量，那么这时候我们要用到 二次扫描与换根法 来在 O(n) 时间内求出所有源点的
//具体来说，我们设 g[i] 为以 i 为源点的流量，显然 g[root]=f[root]，接着对于每个 v，g[v]=f[v]+min(g[u]-min(w[i],f[v]),w[i])，只需要改变 v 与 i 那条边的流向即可，就代表 v 流向 i
//同时如果 i 的度数为 1，那么要直接加上 w


#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

int n;
int head[maxn],nex[maxn<<1],to[maxn<<1],tot=0;
int in[maxn],w[maxn<<1],f[maxn],g[maxn];

inline void add(int u,int v,int d){
    to[++tot]=v;
    w[tot]=d;
    nex[tot]=head[u];
    head[u]=tot;
}

void dfs_1(int u,int fa){
    f[u]=0;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs_1(v,u);
        if(in[v]==1) f[u]+=w[i];
        else f[u]+=min(w[i],f[v]);
    }
}

void dfs_2(int u,int fa){
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        if(in[u]==1) g[v]=f[v]+w[i];
        else g[v]=f[v]+min(g[u]-min(w[i],f[v]),w[i]);
        dfs_2(v,u);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        tot=0;
        for(int i=1;i<=n;i++) head[i]=in[i]=0;
        int u,v,d;
        for(int i=1;i<n;i++){
            scanf("%d %d %d",&u,&v,&d);
            in[u]++;
            in[v]++;
            add(u,v,d);
            add(v,u,d);
        }
        dfs_1(1,0);
        g[1]=f[1];
        dfs_2(1,0);
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,g[i]);
        printf("%d\n",ans);
    }
    return 0;
}
