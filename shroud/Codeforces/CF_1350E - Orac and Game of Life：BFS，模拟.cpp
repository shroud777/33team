//题意：给出 n*m 由 01 组成的格子，初始时为第 0 秒，之后每一秒对于每个格子，若周围没有相同的格子，那么它将保持当前的数字，否则则翻转，0 变 1，1 变 0，现在有 t 组询问，询问第 p 秒时 (x,y) 格子的状态

//思路：规律模拟题，只要找到格子变化的规律就能破解奥秘
//首先我们发现，对于那些不变化的格子，如果他周围有变化的格子，那么下一秒变化的格子将会和他变成相同的数字状态，那么这个不变化的格子将会融入变化的格子
//所以我们可以发现，只要有变化的格子，那么所有 n*m 个格子始终会变化，我们设置 f(i,j) 为第 i 行 j 列个格子开始变化所需要的最早的时间
//连通量大于 1 的格子初始 f(i,j) = 0，而对于其他那些不变化的格子，我们只要通过多个变化格子作为源点的 BFS，即可找到 f(i,j)
//对于每组查询，如果 p<f(x,y)，那么说明格子还没有开始变化，输出原来状态即可，否则就输出变化奇偶次的结果即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e3+10;

int d[4][2]={1,0,-1,0,0,1,0,-1};

int n,m,t;
char a[maxn][maxn];
int vis[maxn][maxn],f[maxn][maxn];

queue<pii> q;

void bfs(){
    while(!q.empty()){
        pii t=q.front();
        q.pop();
        int x=t.first;
        int y=t.second;
        for(int i=0;i<4;i++){
            int dx=x+d[i][0];
            int dy=y+d[i][1];
            if(dx<1||dx>n||dy<1||dy>m) continue;
            if(vis[dx][dy]<=vis[x][y]+1) continue;
            vis[dx][dy]=vis[x][y]+1;
            q.push(pii(dx,dy));
        }
    }
}

inline bool check(int x,int y){
    if(a[x][y]==a[x-1][y]||a[x][y]==a[x+1][y]||a[x][y]==a[x][y-1]||a[x][y]==a[x][y+1]) return true;
    return false;
}

int main(){
    cin>>n>>m>>t;
    bool ff=0;
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    memset(vis,0x3f,sizeof vis);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check(i,j)) q.push(pii(i,j)),vis[i][j]=1;
        }
    }
    if(q.empty()) ff=1;
    else bfs();
    int x,y;
    ll p;
    while(t--){
        scanf("%d %d %lld",&x,&y,&p);
        ll ans=a[x][y]-'0';
        if(ff){
            printf("%lld\n",ans);
            continue;
        }
        if(vis[x][y]==1) printf("%lld\n",ans^(p&1));
        else{
            if(p<vis[x][y]) printf("%lld\n",ans);
            else{
                if(vis[x][y]&1) printf("%lld\n",ans^(p&1));
                else printf("%lld\n",ans^((p+1)&1));
            }
        }
    }
    return 0;
}
