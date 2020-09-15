//题意：小 A 在 (1,1) 位置出发，小 B 在 (x1,y1) 位置，若小 A 与 小 B 的切比雪夫距离小于等于 d，那么如果小 A 上一秒朝某个方向移动的话，小 A 只能继续朝着那个方向移动或者，小 A 可以暂停一秒
//问小 A 在 t 时刻正好处在 (x2,y2) 位置的方案数？

//思路：dp，考虑当前位置从哪里转移过来即可，如果是正常位置，只需直接转移即可。如果在特殊位置，则需要从该方向上一秒是静止的状态或者相同运动位置的方向转移即可
//dp状态设置为当前时刻 t 处在 (x,y) 位置且上一秒移动方向为 dir
//考虑使用动态数组优化空间


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int p=1e9+7;
int dir[5][2]={1,0,0,1,-1,0,0,-1,0,0};

//dp(i,x,y,dir)
//第 i 时刻 (x,y) 位置是从 dir 方向而来

int n,m,t,X1,Y1,d,X2,Y2;
bool ok[205][205];
ll dp[505][205][205][5];

inline int MAX(int a,int b){
	return a>b?a:b;
}

bool check(int x,int y){
	x-=X1,y-=Y1;
	x=(x>0?x:-x);
	y=(y>0?y:-y);
	return MAX(x,y)<=d;
}

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(check(i,j)) ok[i][j]=1;
			else ok[i][j]=0;
		}
	}
}

int main(){
	cin>>n>>m>>t>>X1>>Y1>>d>>X2>>Y2;
	init();
	dp[0][1][1][4]=1;
	for(int k=1;k<=t;k++){
		int fi=k&1,sc=fi^1;
		memset(dp[fi],0,sizeof dp[fi]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int di=0;di<5;di++){
					int x=i+dir[di][0],y=j+dir[di][1];
					if(x<1||x>n||y<1||y>m) continue;
					if(!ok[x][y]||di==4){
						ll res=0;
						for(int l=0;l<5;l++) res+=dp[sc][x][y][l];
						dp[fi][i][j][di]+=res;
						dp[fi][i][j][di]%=p; 
					}
					else{
						dp[fi][i][j][di]+=dp[sc][x][y][di];
						dp[fi][i][j][di]+=dp[sc][x][y][4];
						dp[fi][i][j][di]%=p;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<5;i++) ans+=dp[t&1][X2][Y2][i];
	ans%=p;
	cout<<ans<<endl;
	return 0;
}
