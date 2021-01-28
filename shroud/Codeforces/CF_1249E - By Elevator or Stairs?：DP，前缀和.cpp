//题意：有一层 n 楼的建筑，现在从 i 楼走楼梯到 i+1 楼需要 ai 的时间，坐电梯需要 bi 的时间，但是每次启动电梯需要 c 的时间（坐上电梯之后不需要启动时间），问到每一楼的最短时间

//思路：DP，有多种状态定义方法
//首先第一种：定义 dp[i] 为到 i 层的最短时间，我们可以发现第 i 层要么是从 i-1 层走上来的，要么是从 j<i 层坐电梯上来的，并且由于电梯存在启动时间，我们不能直接从 i-1 层转移，因为这样代表多次启动电梯，无法达到最优解
//那么我们先用前缀和维护 bi，那么我们从 x 层到 y 层需要的时间就是 c+p[y-1]-p[x-1]
//那么状态转移方程就是：dp[i]=min(dp[i],c+dp[j]+p[i-1]-p[j-1]) 和  dp[i]=min(dp[i],dp[i-1]+a[i-1]);
//我们发现第一个转移方程的 dp[j]-p[j-1] 是从前几个状态得出的，相当于这个集合越来越大，我们可以用一个变量来维护这个集合的值，这样就可以避免再用一重循环去得到这个问题的解
//第二种方法：我们分别定义 dp[0][i] 为第 i 层走楼梯和 dp[1][i] 为第 i 层坐电梯，那么状态转移方程如下：
//dp[0][i]=min(dp[1][i-1],dp[0][i-1])+a[i-1];
//dp[1][i]=min(dp[1][i-1],dp[0][i-1]+c)+b[i-1];

//第一种：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

int n,c;
ll dp[maxn],a[maxn],b[maxn],p[maxn],pa[maxn];

int main(){
    cin>>n>>c;
    for(int i=1;i<n;i++) scanf("%lld",&a[i]),dp[i]=1e17;
    for(int i=1;i<n;i++) scanf("%lld",&b[i]),p[i]=p[i-1]+b[i];
    dp[1]=0;
    dp[n]=1e17;
    ll mi=0;
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i],dp[i-1]+a[i-1]);
        dp[i]=min(dp[i],c+mi+p[i-1]);
        mi=min(mi,dp[i]-p[i-1]);
    }
    for(int i=1;i<=n;i++) printf("%lld%c",dp[i],i==n?'\n':' ');
    return 0;
}


//做法2：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

int n,c;
ll dp[2][maxn],a[maxn],b[maxn];

int main(){
    cin>>n>>c;
    for(int i=1;i<n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<n;i++) scanf("%lld",&b[i]);
    dp[0][1]=0,dp[1][1]=c;
    printf("0");
    for(int i=2;i<=n;i++){
        dp[0][i]=min(dp[1][i-1],dp[0][i-1])+a[i-1];
        dp[1][i]=min(dp[1][i-1],dp[0][i-1]+c)+b[i-1];
        printf(" %d",min(dp[0][i],dp[1][i]));
    }
    puts("");
    return 0;
}
