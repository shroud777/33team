//题意：给出一棵 n 个结点的树，每个结点有一个值 k[i]，每个点都有一个颜色，初始的时候所有的点都为白色
//现在可以进行操作，选择一个白色的结点 i，从 i 到根上所有与 i 结点距离小于 k[i] 的结点都变黑，问最少使用几次操作可以把整棵树变黑

//思路：首先要读清楚题意，我们只能自下而上染色，那么我们发现叶节点只能由自己来染色
//这道题我们可以发现，从叶节点开始，然后会不断延申，我们来维护一个动态的蔓延过程，用 f[i] 表示 i 结点被染色后最后能向上延申多少，f[i]=max(f[v]-1)，如果 f[i] 为 0，那么就要额外染色
//接着我们可以发现，如果 f[i] 为 0，也不一定是由他自己来染色，可能子树中存在 k[i] 较大并且能足够蔓延到 i 结点的结点，所有我们还需要维护一个 g[i] 数组
//g[i]=max(k[i],g[v]-1)，如果当前动态染色 f[i] 没有染到，我们就需要用 g[i] 去染它

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e5+10;

int n;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int k[maxn],f[maxn],g[maxn],ans=0;

void inline add(int u,int v){
    to[++tot]=v;
    nex[tot]=head[u];
    head[u]=tot;
}

void dfs(int u,int fa){
    g[u]=k[u];
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
        f[u]=max(f[u],f[v]-1);
        g[u]=max(g[u],g[v]-1);
    }
    if(!f[u]) f[u]=g[u],ans++;
}

int main(){
    scanf("%d",&n);
    int x;
    for(int i=2;i<=n;i++) scanf("%d",&x),add(x,i);
    for(int i=1;i<=n;i++) scanf("%d",&k[i]);
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
