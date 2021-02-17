//题意：给出一棵树，找出树的平衡点和删除平衡点后的最大子树的结点数，如果结点相同就输出编号小的

//思路：找树的重心顺便记录删除 u 后的最大子树 w[u] 即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

int n,sz[maxn],w[maxn],ans,tot=0;
int head[maxn],to[maxn<<1],nex[maxn<<1];

inline void add(int u,int v){
    to[++tot]=v;
    nex[tot]=head[u];
    head[u]=tot;
}

void dfs(int u,int fa){
    sz[u]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        w[u]=max(w[u],sz[v]);
    }
    w[u]=max(n-sz[u],w[u]);
    if(w[u]==w[ans]){
        if(u<ans) ans=u;
    }
    if(w[u]<w[ans]) ans=u;
}

int main(){
    w[0]=0x3f3f3f3f;
    while(cin>>n){
        int u,v;
        for(int i=1;i<=n;i++) head[i]=0;
        for(int i=1;i<n;i++) scanf("%d %d",&u,&v),add(u,v),add(v,u);
        dfs(1,0);
        cout<<ans<<" "<<w[ans]<<endl;
    }
    return 0;
}
