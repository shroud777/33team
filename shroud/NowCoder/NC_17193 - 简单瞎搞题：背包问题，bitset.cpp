//题意：一共有 n个数，第 i 个数是 xi，xi 可以取 [li , ri] 中任意的一个值，设 S=Σxi^2，求 S 的种类数

//思路：跑一个背包，设 DP[i][j] 代表第 i 个数可以取到 j，这里我们只需要要用 bool 来判断是否可以取到即可
//每次转移就是前 i-1 个数的最大值到零这段范围加上当前第 i 个数 [li,ri] 区间
//但是发现题目练 1e8 的 bool 数组都不让开，我们只能用 bitset 优化，开 n 个 bitset 数组或者用滚动数组即可
//每次 dp[i]|=dp[i-1]<<j*j 即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e6+55;
int n;
bitset<maxn> dp[105];

int main(){
    cin>>n;
    int l,r;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        cin>>l>>r;
        for(int j=l;j<=r;j++) dp[i]|=dp[i-1]<<j*j;
    }
    cout<<dp[n].count()<<endl;
    return 0;
}NC_17193 - 简单瞎搞题：背包问题，bitset
