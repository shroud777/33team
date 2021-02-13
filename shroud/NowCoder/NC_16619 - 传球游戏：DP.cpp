//题意：n 个同学站成一个圈，每一秒会把球传给相邻两边的某个同学，问初始球在第 1 个同学的手里，过了 m 秒后球传到第 1 个同学手里的方案数有多少种

//思路：dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e6+10;

int n,m;
int dp[55][55];

int main(){
    cin>>n>>m;
    dp[0][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int k1=j-1==0?n:j-1;
            int k2=j==n?1:j+1;
            dp[i][j]+=dp[i-1][k1]+dp[i-1][k2];
        }
    }
    cout<<dp[m][1]<<endl;
}
