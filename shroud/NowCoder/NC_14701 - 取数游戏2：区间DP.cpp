//题意：给出两个长度为 n 的序列 A 和 序列 B，现在每次可以从 A 数列的左端或者右端取数，第 i 次取走的数的值为 Ax*Bi，现在取数的最大值

//思路：区间DP，设 DP[i][j] 为区间 [i,j] 的取数最大值，我们只要逆向化那个取数的过程，最后一个取的数就是初始阶段长度为 1 的区间，然后扩展的过程就是逆向取数的过程

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e3+10;

int n;
int a[maxn],b[maxn],dp[maxn][maxn];


int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) dp[i][j]=0;
        }
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int len=1;len<=n;len++){
            for(int i=1;i+len-1<=n;i++){
                int j=i+len-1;
                dp[i][j]=max(dp[i][j-1]+a[j]*b[n-len+1],dp[i+1][j]+a[i]*b[n-len+1]);
            }
        }
        cout<<dp[1][n]<<endl;
    }
}
