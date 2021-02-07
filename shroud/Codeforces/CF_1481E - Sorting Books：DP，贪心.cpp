//题意：给出 n 本书颜色分别为 ai，可以执行一次操作将某本书放到最右边，现在问所有相同颜色的书相邻所需要的最小操作个数

//思路：可以先把问题转化为最多几本书不动来达成目的，一般情况，我们可以想到一种贪心思路，就是对于颜色为 x 的书，在 x 之间的不同与 x 的颜色的书的个数小于 x 的个数的书，那么我们肯定希望把这些不同颜色的书移走
//这种局部贪心的思路给了我们 DP 的启发，我们可以先预处理出每种颜色出现的左右区间端点为 li 和 ri
//我们可以逆序DP，DP[i] 代表 [i,n] 之间最多的不用移动的书的个数，那么对于一个 i==l[a[i]] 的情况，我们显然可以移动区间 [l,r] 中除了 ai 颜色的书本，dp[i]=dp[r[x]+1]+cnt[x]
//如果 i>l[a[i]] 我们不能直接这样转移，因为这样可能会导致区间重叠，所以我们要把所有的除 a[i] 元素转移过去
//并且对于 dp[i] 我们还可以选择将当前 a[i] 直接往后仍，那就是 dp[i]=dpp[i-1]

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn],l[maxn],r[maxn],dp[maxn];
int cnt[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) r[a[i]]=i;
    for(int i=n;i;i--) l[a[i]]=i;
    for(int i=n;i;i--){
        int x=a[i];
        cnt[x]++;
        dp[i]=dp[i+1];
        if(i==l[x]) dp[i]=max(dp[i],dp[r[x]+1]+cnt[x]);
        else dp[i]=max(dp[i],cnt[x]);
    }
    cout<<n-dp[1]<<endl;
    return 0;
}
