//题意：定义调和图：如果 (l,r) (l<=r) 有一条边，那么对于所有 l<m<r，l 到 m 都存在一条边，现在求给出图变成调和图所需要的最小边数

//思路：可以用连通块的思路来做，我们可以找出一个连通分量内的最大最小编号，那么我们将所有的连通块按照最小编号从小到大排序后，我们遍历连通块，维护当前最大的最大编号，并且如果当前最小编号小于最大值，那么就要连一条边
//也可以用并查集做，并查集按照点的序号遍历点，并且一个集合内所有元素都指向最大值，我们遍历一个点，那么找到集合的祖先，然后接着如果遍历到比这个祖先编号小，那么显然要合并这两个元素
//同时我们要注意合并过程中始终要把集合代表元素设置为集合中最大的元素

//连通分量

#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

typedef long long ll;
typedef pair<int,int> pii;

int n,m;
int head[maxn],nex[maxn<<1],to[maxn<<1],tot=0;
int vis[maxn];

vector<pii> res;

inline void add(int u,int v){
    to[++tot]=v;
    nex[tot]=head[u];
    head[u]=tot;
}

void dfs(int u,int &mi,int &mx){
    vis[u]++;
    mx=max(mx,u);
    mi=min(mi,u);
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(vis[v]) continue;
        dfs(v,mi,mx);
    }
}

int main(){
    scanf("%d %d",&n,&m);
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        add(u,v);add(v,u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int l=i,r=i;
            dfs(i,l,r);
            res.push_back(pii(l,r));
        }
    }
    int mx=0,ans=0;
    for(int i=0;i<res.size();i++){
        int l=res[i].first,r=res[i].second;
        if(l<mx) ans++;
        mx=max(mx,r);
    }
    printf("%d\n",ans);
    return 0;
}


// ░░░░░░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░░░░░
// ░░░░░░█░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░█░░░░░
// ░░░░░░█░█░▀░░░░░▀░░▀░░░░█░█░░░░░
// ░░░░░░█░█░░░░░░░░▄▀▀▄░▀░█░█▄▀▀▄░
// █▀▀█▄░█░█░░▀░░░░░█░░░▀▄▄█▄▀░░░█░
// ▀▄▄░▀██░█▄░▀░░░▄▄▀░░░A░░░░░C░░▀▄
// ░░▀█▄▄█░█░░░░▄░░█░░░▄█░░░▄░▄█░░█
// ░░░░░▀█░▀▄▀░░░░░█░██░▄░░▄░░▄░███
// ░░░░░▄█▄░░▀▀▀▀▀▀▀▀▄░░▀▀▀▀▀▀▀░▄▀░
// ░░░░█░░▄█▀█▀▀█▀▀▀▀▀▀█▀▀█▀█▀▀█░░░
// ░░░░▀▀▀▀░░▀▀▀░░░░░░░░▀▀▀░░▀▀░░░░

//并查集

#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

typedef long long ll;

int n,m;
int fa[maxn];

inline int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){ 
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) fa[i]=i;
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        u=find(u),v=find(v);
        if(u==v) continue;
        if(u<v) swap(u,v);
        fa[v]=u; 
    }
    int mx=0,ans=0;
    for(int i=1;i<=n;i++){
        int root=find(i);
        if(i>mx) mx=root;
        else if(i==mx) continue;
        else if(root!=mx){
            ans++;
            if(root>mx) fa[mx]=root,mx=root;
            else fa[root]=mx;
        }
    }
    printf("%d\n",ans);
    return 0;
}
