//题意：给出一棵 n 个结点的树，每条树边都有一个权值，现在要求所有叶节点无法到达根，并且切除边的总值不超过 m，同时现在要求切除的边的最大值尽可能小

//思路：首先很明显可以由 树形DP 来得到切断所有叶节点通道的最优解，但是这里有一个最大值尽可能小的限制
//可以想象，切除最大值的限制对于我们 树形DP 得到的最优解的影响，通常来说，可能存在这么一种情况，就是我们用比较大的一条边截断了多个最优解之和大于边权，但是最优解中所有边都小于最大边
//也就是说，最大值的大小和最优解的大小呈反比例函数，最大值越小，最优解受限制越大，就会越大；如果最大值很大，想当于对 树形DP 没有限制，最优解肯定会更小
//那么对于这种单调的情况我们完全可以二分最大值，然后跑一个有限制的 树形DP，最后看看总值是否小于等于 m 即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;

int n,m,s;
int head[maxn],to[maxn<<1],w[maxn<<1],nex[maxn<<1],tot=0;
int sz[maxn];
ll dp[maxn];

inline void add(int u,int v,int d){
    to[++tot]=v;
    w[tot]=d;
    nex[tot]=head[u];
    head[u]=tot;
}

void dfs(int u,int fa,int x){
    sz[u]=1;
    dp[u]=0;
    for(int i=head[u];i;i=nex[i]){
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u,x);
        sz[u]+=sz[v];
        dp[u]+=min(dp[v],ll(w[i]<=x?w[i]:0x3f3f3f3f));
    }
    if(sz[u]==1) dp[u]=0x3f3f3f3f;
}

bool check(int x){
    dfs(1,0,x);
    return dp[1]<=m;
}

int main(){
    cin>>n>>m;
    int l=0x3f3f3f3f,r=0;
    int u,v,d;
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&d);
        add(u,v,d);
        add(v,u,d);
        l=min(l,d);
        r=max(r,d);
    }
    int ans=-1;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
