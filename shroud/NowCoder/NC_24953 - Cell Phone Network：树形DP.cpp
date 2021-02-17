//题意：现在有 n 个信号站，有 n-1 个线连接，并且保证任意两点都可以到达，现在每个信号站都可以通电，然后和它相连的信号站都可以连到信号，问使所有 n 个信号站都有信号的最小代价

//思路：这道与所有边被联通的树形DP不同，因为一条边仅仅只要考虑儿子与父亲谁来练，而一个点可以由自己也可以由它的父亲或儿子来连接
//如果仅用 2 个状态显然无法表示清楚，那么我们用 3 个状态
//dp[0][i] 选中点 i 的儿子，i 点没选
//dp[1][i] 选中点 i
//dp[2][i] 选中点 i 的父亲

//dp[0][i]=Σmin(dp[1][u],dp[0][u])+res;
//dp[1][i]=1+Σmin(dp[1][u],dp[0][u],dp[2][u]);
//dp[2][i]=Σmin(dp[1][u],dp[0][u]);

//可以知道，对于点 i 来说，如果选中它的儿子，那么我们就不用选点 i，但是一定要选一个或多个儿子结点，我们再对 dp[1][u],dp[0][u] 取 min 的过程中，可以发现如果我们的 min 全部取再 dp[0][u]
//那么 i 点的所有儿子都没有被选上，那么我们就要选出 dp[1][i]-dp[0][i] 最小的点，这样让他选中的代价最小
//并且对于没有儿子节点的点来说，它的 dp[0][i] 一点是无穷大的
//如果 i 点选了，那么显然它儿子父亲选不选都无所谓
//如果 i 点没选，但是依靠父亲结点来联通它，那么儿子结点选和不选也就无所谓了

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

int n;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int dp[3][maxn];

inline void add(int u,int v){
    to[++tot]=v;
    nex[tot]=head[u];
    head[u]=tot;
}

void dfs(int u,int fa){
    dp[1][u]=1;
    bool f=0;
    int d=0x3f3f3f3f;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        sz++;
        dfs(v,u);
        if(dp[1][v]<=dp[0][v]) f=1;
        d=min(d,dp[1][v]-dp[0][v]);
        dp[0][u]+=min(dp[1][v],dp[0][v]);
        dp[1][u]+=min(dp[0][v],min(dp[1][v],dp[2][v]));
        dp[2][u]+=min(dp[0][v],dp[1][v]);
    }
    if(!f) dp[0][u]+=d;
}

int main(){
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    cout<<min(dp[1][1],dp[0][1])<<endl;
    return 0;
}
