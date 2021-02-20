//题意：给出一棵树，每条边有一个权值，可以切断任何边，现在求使所有叶节点都无法达到根节点的最小代价

//思路：树形DP，我们设 DP[i] 为使 i 结点子树中的叶结点无法到达 i 的最小代价
//dp[i]=Σmin(dp[v],g[v][i])，v 为 i 的子结点

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;

int n,m,s;
int head[maxn],to[maxn<<1],nex[maxn<<1],w[maxn<<1],tot=0;
ll dp[maxn];

inline void add(int u,int v,int d){
    to[++tot]=v;
    nex[tot]=head[u];
    w[tot]=d;
    head[u]=tot;
}

void dfs(int u,int fa){
    ll res=0;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
        if(dp[v]) dp[u]+=min(dp[v],1ll*w[i]);
        else dp[u]+=w[i];
    }
}

int main(){
    cin>>n>>m>>s;
    int u,v,d;
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&d);
        add(u,v,d);
        add(v,u,d);
    }
    dfs(s,0);
    cout<<dp[s]<<endl;
    return 0;
}
