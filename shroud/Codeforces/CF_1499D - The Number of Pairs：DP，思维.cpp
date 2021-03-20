/题意：现在有 n 个问题，每个问题存在一个难度 ci=(2^i)，tagi 和 si，且存在一个属性 IQ 初始为 0
//在上一个解决问题为 i 的情况下，只有当 IQ<|ci-cj| 且 tagi!=tagj 的条件下，才能去做问题 j，并且在这以后 IQ 变为 |ci-cj| 并得到 |si-sj| 的分数
//求满足题意条件下得到的最大分数

//思路：一开始没什么方向，但是每个问题的 ci 属性很容易启发到我们，我们从二进制的方向去研究性质
//我们假设每个问题都是一个点，且所有点之间都存在一条边，{i,j} 的边权为 |ci-cj|，那么所有边的边权大小都是不相等的
//因为 |ci-cj| 的二进制数上存在 1 的位置应该是 (i,j)，而所有 {i,j} 对都不同，所以二进制表示都不同，权值也都不同
//那么所有点对之间的权值不同，我们的 DP 转移好像也有了一些可行性，具体研究一下，以 n=5 为例
//二进制数    1-> 2~5   2-> 3~5   3-> 4~5   4-> 5
// 00001      00001     00010     00100    01000
// 00010      00011     00110     01100
// 00100      00111     01110
// 01000      01111
// 10000
//我们可以发现，边权大小 (1,2)<(2,3)<(1,3)<(3,4)<(2,4)<(1,4)
//那么我们发现这个转移的过程其实完全可以用两重循环 O(n^2) 实现，第二重循环倒叙即可，同时注意状态转移是双向的，要用临时变量记录 dp[i] dp[j]

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e3+10;

ll dp[maxn];
int n,t[maxn],s[maxn];

int main(){
    int test;
    cin>>test;
    while(test--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) dp[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&t[i]);
        for(int i=1;i<=n;i++) scanf("%d",&s[i]);
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(t[i]==t[j]) continue;
                ll dpi=dp[i],dpj=dp[j];
                int d=abs(s[i]-s[j]);
                dp[i]=max(dp[i],dpj+d);
                dp[j]=max(dp[j],dpi+d);
            }
        }
        printf("%lld\n",*max_element(dp+1,dp+n+1));
    }
    return 0;
}
