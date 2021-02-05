//题意：在一个 n*m 的格子上进行游戏，有 p 个玩家，每个玩家在格子上至少占有一个堡垒，然后游戏一轮轮的进行，每一轮从编号小的玩家开始
//对于当前玩家，他的每个堡垒能占领所有没有其他玩家堡垒和路障的能在 si 步能达到的堡垒
//直到所有没有玩家再占领格子，游戏结束，问每个玩家占领的格子数量

//思路；注意题意即可，这道题要求每个格子达到所有 si 步能到的地方
//这里我们使用多源点BFS，以当前玩家所有占领的格子作为起点（上一轮到占领的即可，做一些优化），我们可以使用 p 个队列，每个队列维护第 i 个玩家的某一轮游戏
//然后根据广搜的性质，直到出现了超过当前可达到的格子，说明能到达的已经全部达到了，这时候不用弹出队列了，我们继续下一个队列即可，并且外层循环某一轮游戏截止于所有玩家的队列都是空的（即无法再占领就结束了）

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

int d[4][2]={1,0,0,1,0,-1,-1,0};

int n,m,p,s[15];
char ch[1005][1005];
int vis[1005][1005],cnt[1005][1005],res[1005][1005],ans[1005];

queue<pii> q[15];


void print(int a[][1005]){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
        cout<<endl; 
    }
    cout<<endl;
}

void bfs(){
    bool f=1;
    for(int base=1;;base++){
        if(!f) break;
        f=0;
        for(int j=1;j<=p;j++){
            while(!q[j].empty()){
                f=1;
                pii temp=q[j].front();
                int x=temp.first,y=temp.second;
                if(cnt[x][y]==base*s[j]) break;
                q[j].pop();
                for(int i=0;i<4;i++){
                    int rx=x+d[i][0];
                    int ry=y+d[i][1];
                    if(rx<1||rx>n||ry<1||ry>m||ch[rx][ry]=='#'||vis[rx][ry]) continue;
                    vis[rx][ry]=vis[x][y];
                    cnt[rx][ry]=cnt[x][y]+1;
                    q[j].push(pii(rx,ry));
                }
            }
        }
    }
}

int main(){
    cin>>n>>m>>p;
    vector<pii> v[15];
    for(int i=1;i<=p;i++) cin>>s[i];
    for(int i=1;i<=n;i++){
        scanf("%s",ch[i]+1);
        for(int j=1;j<=m;j++){
            if(ch[i][j]<='9'&&ch[i][j]>='1'){
                vis[i][j]=ch[i][j]-'0';
                q[vis[i][j]].push(pii(i,j));
                res[i][j]=1;
            }
        }
    }
    bfs();
    //print(vis);
    //print(cnt);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans[vis[i][j]]++;
        }
    }
    for(int i=1;i<=p;i++) printf("%d%c",ans[i],i==p?'\n':' ');
    return 0;
}
/*
10 10 4
1 2 3 4
1........2
..........
..........
..........
..........
..........
..........
..........
..........
3........4
*/
