//题意：在数组中有 n 个数，现在定义一个漂亮的序列，为对于任意序对 {i,j}(i!=j) 满足 ai 是 aj 的约数或 aj 是 ai 的约数，问现在最少删除多少个数使序列成为漂亮的序列？

//思路；可以知道一个序列如果递增排序，那么他的质因子的集合也会不断变大，那么我们可以发现其实对于某个数 x，我们要想找到他能与哪些数组合成漂亮序列，那么就是在 x 的基础上乘上倍数即可
//那么我们设 dp[i] 为小于等于 i 的最长的漂亮序列，我们可以知道 dp[i]=max(dp[i],dp[j]+cnt[i]) 其中 j 就是他的约数，我们可以利用埃氏筛的思想，利用现有的数 j 来来找到 j 的倍数 i

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n;
int a[maxn],cnt[maxn],dp[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        memset(cnt,0,sizeof cnt);
        memset(dp,0,sizeof dp);
        int mx=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++,mx=max(mx,a[i]);
        int ans=0;
        for(int i=1;i<=mx;i++){
            if(!cnt[i]) continue;
            dp[i]+=cnt[i];
            for(int j=i+i;j<=mx;j+=i) dp[j]=max(dp[i],dp[j]);
            ans=max(ans,dp[i]);
        }
        cout<<n-ans<<endl;
    }
    return 0;
}
