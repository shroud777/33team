//题意：在一个 m*n 的矩阵中，每个格子上有一个权值，现在求两条从左上角 （1,1） 到右下角 （m,n）的路，使得经过地方的权值之和最大，且重复经过的格子只算一次

//思路：DP，根据曼哈顿距离可以描述当前的运动阶段从 [2,n+m] ，同时描述状态还需要两条路的当前末端的坐标，但是如果用五维来表示复杂度无法承受，我们可以想到由于每次 x+y=i 
//那么我们如果直接表示横纵坐标必然属于状态信息冗余，所以我们只需要分别表示两个点的 x1 和 x2 即可
//dp[i][x1][x2]  i 的范围 [2,n-m-1]
// x1+y1=x2+y2=i;
//以下是在不同格子的情况，如果两者都在同一格子，那么只加一个格子的值即可 
//dp[i][x1][x2]=min(dp[i][x1][x2],dp[i-1][x1][x2]+a[x1][i-x1]+a[x2][i-x2]);
//dp[i][x1][x2]=min(dp[i][x1][x2],dp[i-1][x1][x2-1]+a[x1][i-x1]+a[x2][i-x2]);
//dp[i][x1][x2]=min(dp[i][x1][x2],dp[i-1][x1-1][x2]+a[x1][i-x1]+a[x2][i-x2]);
//dp[i][x1][x2]=min(dp[i][x1][x2],dp[i-1][x1-1][x2-1]+a[x1][i-x1]+a[x2][i-x2]);


#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;
int a[55][55];
int dp[105][55][55];

//dp[i][x1][x2]  i 的范围 [2,n-m-1]
// x1+y1=x2+y2=i;
//以下是在不同格子的情况，如果两者都在同一格子，那么只加一个格子的值即可 
//dp[i][x1][x2]=min(dp[i][x1][x2],dp[i-1][x1][x2]+a[x1][i-x1]+a[x2][i-x2]);
//dp[i][x1][x2]=min(dp[i][x1][x2],dp[i-1][x1][x2-1]+a[x1][i-x1]+a[x2][i-x2]);
//dp[i][x1][x2]=min(dp[i][x1][x2],dp[i-1][x1-1][x2]+a[x1][i-x1]+a[x2][i-x2]);
//dp[i][x1][x2]=min(dp[i][x1][x2],dp[i-1][x1-1][x2-1]+a[x1][i-x1]+a[x2][i-x2]);

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	memset(dp,0,sizeof dp);
	//dp[2][1][1]=0;
	int y1,y2;
	for(int i=3;i<=n+m;i++){
		for(int x1=1;x1<=min(m,i-1);x1++){
			for(int x2=1;x2<=min(m,i-1);x2++){
				for(int A=-1;A<=0;A++){
					for(int B=-1;B<=0;B++){
						//if(dp[i-1][x1+A][x2+B]==-1) continue;
						int temp=a[x1][i-x1];
						if(x1!=x2) temp+=a[x2][i-x2];
						dp[i][x1][x2]=max(dp[i][x1][x2],dp[i-1][x1+A][x2+B]+temp);
					}
				}
			}
		}
	}
	cout<<dp[n+m][m][m]<<endl;
	return 0;
} 
