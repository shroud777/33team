//题意：现在有 n 级天梯分别位于高度 hi 的位置，开始处在第一级台阶，可以按照如下规则攀登天梯
//1.可以直接登上比当前位置高1个单位高度的天梯。
//2.可以从当前阶梯往下退一级天梯（第一级天梯除外）
//3.在连续退k步后，跳跃一次，跳跃的高度不超过2^k。比如说你现在位于第i级天梯，且之前从第i+k级天梯退下来，此时你可以跳到高度不超过(当前高度+ 2^k)的任何一级天梯。每一次跳跃只算一次移动

//思路：DP 或者搜索都可以
//状态定义有两种，可以定义 DP[i] 代表到第 i 阶台阶的最小移动次数
//那么 dp[i]=dp[i-1]+1(a[i]=a[i-1]+1) 
//     dp[i]=min(dp[d+j]+d+1,dp[i])（j 代表从 d+j 阶台阶往下退 d 阶，然后再跳上 i，计算保证 d 是最小的需要的从 j 到 i 台阶的下退步数，并且满足单调性）
//或者设 DP[i][j] 代表第 i 阶台阶并且已经下退 j 级的最小移动次数
//那么 dp[i][k] 由 dp[i+k][0] 转移而来，dp[i][0]=min(dp[i][0],dp[j][d]+1)，d 同样代表 i 到 j 所需要的最小后退步数

//1：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=205;

int n,a[maxn],dp[maxn];

int get(int x){
    if(x==(x&-x)) return log2(x);
    int pos=0;
    while(x){
        pos++;
        x>>=1;
    }
    return pos;                                        
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,0x3f,sizeof dp);
    dp[1]=0;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]+1) dp[i]=dp[i-1]+1;
        for(int j=1;j<i;j++){
            int d=get(a[i]-a[j]);
            if(d+j>=i) continue;
            dp[i]=min(dp[d+j]+d+1,dp[i]);
        }
        if(dp[i]==0x3f3f3f3f){
            cout<<-1<<endl;
            return 0;
        }
    }
    //for(int i=1;i<=n;i++) cout<<dp[i]<<endl;
    cout<<dp[n]<<endl;
    return 0;
}


//2：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=205;

int n,a[maxn],dp[maxn][35];

int get(int x){
    if(x==(x&-x)) return log2(x);
    int pos=0;
    while(x){
        pos++;
        x>>=1;
    }
    return pos;                                        
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,0x3f,sizeof dp);
    dp[1][0]=0;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]==1) dp[i][0]=dp[i-1][0]+1;
        for(int j=1;j<i;j++){
            int d=get(a[i]-a[j]);
            dp[i][0]=min(dp[i][0],dp[j][d]+1);
        }
        if(dp[i][0]==0x3f3f3f3f){
            cout<<-1<<endl;
            return 0;
        }
        for(int j=1;i-j;j++) dp[i-j][j]=dp[i][0]+j;
    }
    cout<<dp[n][0]<<endl;
    return 0;
}
