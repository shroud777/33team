//题意：给出一个树，树上每个点都有一个权值，现在定义一颗树的子链的大小为：这个子链上所有结点的权值和，请在该树中找出一条最大的子链

//设 d[i] 为以 i 为根的最大子链，那么 d[i]=max(d[i],d[v]+w[i]); v 为 i 的子结点，求出树的直径即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;

int n;
int head[maxn],w[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
ll ans,d[maxn];

inline void add(int u,int v){
    to[++tot]=v;
    nex[tot]=head[u];
    head[u]=tot;
}

void dfs(int u,int fa){
    d[u]=w[u];
    ans=max(ans,d[u]);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
        ans=max(ans,d[u]+d[v]);
        d[u]=max(d[u],d[v]+w[u]);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    ans=-1e17;
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
