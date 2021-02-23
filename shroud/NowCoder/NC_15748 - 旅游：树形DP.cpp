//题意：现在有 n 个城市，第一天在 s 市住宿，并游览与它距离不超过 1 的所有城市，之后的每一天会选择一个城市住一宿，并游览所有与它距离不超过 1 的城市
//现在他要游览所有城市，并且尽可能住的久一点，他们又不想住在一个已经游览过的城市，问最多可以待多少天呢

//思路：树形DP，其实这道题就是 ”没有上司的舞会“ 这道题，父亲与儿子结点不能同时选，那么我们只需要两种状态就可以表示清楚了
//其实也可也用三种状态表示，一个点由子节点选，自己选，父亲选三种状态，我们只要处理好即可
//dp[0][u]+=max(dp[1][v],dp[0][v]);
//dp[1][u]+=max(dp[2][v],dp[0][v]);
//dp[2][u]+=max(dp[0][v],dp[1][v]);

//1.

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;


int n,s;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int dp[3][maxn];

inline void add(int u,int v){
    to[++tot]=v;
    nex[tot]=head[u];
    head[u]=tot;
}

void dfs(int u,int fa){
    dp[1][u]=1;
    int res=0x3f3f3f3f;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
        res=min(res,dp[0][v]-dp[1][v]);
        dp[0][u]+=max(dp[1][v],dp[0][v]);
        dp[1][u]+=max(dp[2][v],dp[0][v]);
        dp[2][u]+=max(dp[0][v],dp[1][v]);
    }
    if(res>0) dp[0][u]-=res;
}

int main(){
    cin>>n>>s;
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dp[0][s]=dp[2][s]=-0x3f3f3f3f;
    dfs(1,0);
    cout<<max(dp[1][1],dp[0][1])<<endl;
    return 0;
}


//2.

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;


int n,s;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int dp[2][maxn];

inline void add(int u,int v){
    to[++tot]=v;
    nex[tot]=head[u];
    head[u]=tot;
}

void dfs(int u,int fa){
    dp[1][u]=1;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
        dp[1][u]+=dp[0][v];
        dp[0][u]+=max(dp[0][v],dp[1][v]);
    }
}

int main(){
    cin>>n>>s;
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dp[0][s]=-0x3f3f3f3f;
    dfs(1,0);
    cout<<max(dp[1][1],dp[0][1])<<endl;
    return 0;
}
