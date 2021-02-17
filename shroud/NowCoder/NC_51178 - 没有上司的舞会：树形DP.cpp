//题意：有 n 个人，其中他们的关系像一棵以校长为根的树，父亲就是子节点的直接上司，现在要参加一场宴会，每个人有一个快乐值，并且每个人不能与直接上司同时出现在舞会，求合法的最大快乐值

//思路：树形DP，处理最大独立集问题。
//父亲和儿子是互斥的存在，我们设 dp[i][0] 代表 i 结点参加宴会的最大快乐值，dp[i][1] 代表 i 结点不参加宴会的最大值
//那么状态转移方程非常好写，如果 i 出席宴会，它的子节点全部不能出席，也就是 dp[i][1]=Σdp[u][0]
//如果 i 没有主席，则下面的结点可出席可不出席，所以就是 dp[i][0]=Σmax(dp[u][1],dp[u][0])

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

int n,a[maxn];
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int dp[2][maxn];

//dp[0][u] 不选择 u 参加
//dp[1][u] 选择 u 参加

void add(int u,int v){
    to[++tot]=v;
    nex[tot]=head[u];
    head[u]=tot;
}

void dfs(int u,int fa){
    dp[1][u]=a[u];
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
        dp[1][u]+=dp[0][v];
        dp[0][u]+=max(dp[0][v],dp[1][v]);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int u,v;
    while(~scanf("%d %d",&u,&v)&&u&&v){
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    cout<<max(dp[0][1],dp[1][1])<<endl;
    return 0;
}
