//题意：现在要求你构造一个长度为 n 的序列，满足：每个数的取值范围是 [l,r]，序列和是三的倍数，问合法序列的方案数

//思路：一开始我的思路有点偏了，我在考虑组合数学去做，但是想想这里 r 的范围是 1e9，组合数底数显然不可能那么大
//然后我又想到了枚举序列中模数为 0 1 2 的数，显然也要 O(n^2) 并且还要用求排列数
//不过上面的思路倒是启发了我，每个数是多少并不重要，重要的是对 3 取模后的值，那我们首先计算 [l,r] 区间内模数为 0，1,2 的值，这里方法很多，不介绍了
//接着考虑使用 DP 线性时间内完成求解，设 DP[i][j] 代表前 i 个数的和对 3 取模的值为 j 的方案数，那么状态转移方程就很好写了
//具体可以看下面两种代码，分别用循环和直接全部展开

//1.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;
const int p=1e9+7;

int n,l,r;
int cnt[3];
ll dp[3][maxn];

int main(){
    cin>>n>>l>>r;
    cnt[0]=cnt[1]=cnt[2]=(r-l+1)/3;
    for(int i=l+(r-l+1)/3*3;i<=r;i++) cnt[i%3]++;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++) dp[j][i]+=dp[k][i-1]*cnt[(3+j-k)%3]%p;
        }
    }
    cout<<dp[0][n]%p<<endl;
    return 0;
}

//2：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;
const int p=1e9+7;

ll n,l,r,dp[3][maxn];

string s;

int main(){
    cin>>n>>l>>r;
    ll L=(l-1+3)/3;
    ll R=r/3;
    ll cnt0=R-L+1;
    ll cnt2=cnt0-1;
    ll cnt1=cnt0-1;
    if(r%3==2) cnt2++,cnt1++;
    else if(r%3==1) cnt1++;
    if(l%3==2) cnt2++;
    else if(l%3==1) cnt1++,cnt2++;
    dp[0][1]=cnt0;
    dp[1][1]=cnt1;
    dp[2][1]=cnt2;
    for(int i=2;i<=n;i++){
        dp[0][i]=(dp[1][i-1]*cnt2%p+dp[0][i-1]*cnt0%p+dp[2][i-1]*cnt1%p)%p;
        dp[1][i]=(dp[0][i-1]*cnt1%p+dp[1][i-1]*cnt0%p+dp[2][i-1]*cnt2%p)%p;
        dp[2][i]=(dp[2][i-1]*cnt0%p+dp[1][i-1]*cnt1%p+dp[0][i-1]*cnt2%p)%p;
    }
    cout<<dp[0][n]<<endl;
    return 0;
}
