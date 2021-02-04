//题意：现在有 n 个通讯机器，每个机器有 mi 个模式，每个机器只能选择一个模式，并且每个模式存在一个宽带长度 bj 和价格 pj，现在要求宽带的最小值与价格的和之比最大

//思路：设 DP[i][j] 为选了第 i 个物品，并且最小宽带为 j 的最小价格之和
//状态转移方程为：dp[i][temp]=min(dp[i][temp],dp[i-1][k]+p[i][j]) temp=min(b[i][j],k) 第 i 个机器的第 j 种模式

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define INF 0x3f3f3f3f
typedef long long ll;

const int maxn=2e5+10;

int n,m;
int b[105][105],p[105][105];
int dp[105][1050];

//dp[i][j] 代表选了 i 个物品 b 的最小值为 j 的最小 p 值

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>m;
            for(int j=1;j<=m;j++) cin>>b[i][j]>>p[i][j];
        }
        memset(dp,0x3f,sizeof dp);
        dp[0][1005]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=0;k<=1005;k++){
                    if(dp[i-1][k]==INF) continue;
                    int temp=min(k,b[i][j]);
                    dp[i][temp]=min(dp[i][temp],dp[i-1][k]+p[i][j]);
                }
            }
        }
        double ans=0;
        for(int i=0;i<1005;i++){
            ans=max(ans,i*1.0/dp[n][i]);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
