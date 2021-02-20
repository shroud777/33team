//题意：现在有一颗二叉树，它的边上会有权值们，现在给出最多能剩余的边数，问保留的最大权值

//思路：由于这棵树是个二叉树，并且要么有两个子节点，要么一个都没有，那么我们可以直接先求出左右儿子，然后设 DP[i][j] 代表以 i 为根节点的子树保留 j 个结点，然后枚举左儿子的结点用记忆化搜索实现树形DP即可
//还可以通过类似树上背包的思想，这种方法同样适用于多叉树，这里我们遍历到第 i 个孩子，那么对于左边 i-1 个孩子形成了一个类似于背包的左子树，用背包的方法跑一边即可

//树上背包

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=155;

int n,m;
int head[maxn],to[maxn<<1],w[maxn<<1],nex[maxn<<1],tot=0;
int dp[maxn][maxn];
int g[maxn][maxn],sz[maxn];

inline void add(int u,int v,int d){
    to[++tot]=v;
    w[tot]=g[u][v]=g[v][u]=d;
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
        for(int j=m;j;j--){
            for(int k=j-1;k>=0;k--){
                dp[u][j]=max(dp[u][j],dp[u][k]+dp[v][j-k-1]+w[i]);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    int u,v,d;
    for(int i=1;i<n;i++) scanf("%d %d %d",&u,&v,&d),add(u,v,d),add(v,u,d);
    dfs(1,0);
    cout<<dp[1][m]<<endl;
    return 0;
}

//枚举结点数+记忆化搜索：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=105;

int n,m;
int dp[maxn][maxn],lc[maxn],rc[maxn],len[maxn];
int head[maxn],to[maxn<<1],nex[maxn<<1],w[maxn][maxn],tot=0;

//dp[i][j] 以 i 为根的子树保留 j 个结点

inline void add(int u,int v,int d){
    to[++tot]=v;
    nex[tot]=head[u];
    w[u][v]=w[v][u]=d;
    head[u]=tot;
}

void dfs_1(int u,int fa){
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs_1(v,u);
        if(!lc[u]) lc[u]=v;
        else rc[u]=v;
        len[v]=w[u][v];
    }
}

int dfs_2(int u,int m){
    if(!u) return 0;
    if(dp[u][m]) return dp[u][m];
    int res=0;
    for(int i=0;i<m;i++){
        res=max(res,dfs_2(lc[u],i)+dfs_2(rc[u],m-i-1)+len[u]);
    }
    return dp[u][m]=res;
}

int main(){
    cin>>n>>m;
    int u,v,d;
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&d);
        add(u,v,d);
        add(v,u,d);
    }
    dfs_1(1,0);
    cout<<dfs_2(1,m+1)<<endl;
    return 0;
}
