//题意：现在有若干选修课，每门课有一定的学分，选某些课要先上过该课的先修课，先修课最多只有一门，两门课可能存在同一门先修课，现在要求在选课 m 以内并且满足要求的情况下，学分尽量高

//思路：由于先修课只有一门，最后所有课将会构成一个森林，因为有些课没有先修课，我们为了方便起见，设置一个 “虚拟课程” 1 号课，让其他所有没有先修课的作为它的儿子
//接着就是树形的树上背包模型，我们设以 i 为根的子树选择 j 门课能够获得的最高学分
//dp[i][j]=Σmax(dp[v][c])+w[u]（v∈son[i]，Σci=j-1）

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=355;

int n,m;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int sz[maxn],w[maxn];
int dp[maxn][maxn];

inline void add(int u,int v){
    to[++tot]=v;
    nex[tot]=head[u];
    head[u]=tot;
}

void dfs(int u,int fa){
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
        for(int j=m+1;j;j--){
            for(int k=1;k<j;k++){
                dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
            }
        }
    }
    for(int i=1;i<=m;i++) dp[u][i]+=w[u]; 
}

int main(){
    cin>>n>>m;
    int u;
    for(int i=2;i<=n+1;i++){
        scanf("%d %d",&u,&w[i]);
        if(u) add(u+1,i);
        else add(1,i);
    }
    dfs(1,0);
    cout<<dp[1][m+1]<<endl;
    return 0;
}
