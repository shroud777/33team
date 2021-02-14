//题意：在一条长为 L 的桥上，每个可经过的点都可看错数轴上的一串整点 0,1....L，现在有一只青蛙从 0 出发，每次跳跃范围 [s,t]，桥上有 m 颗石头，问青蛙跳过这座桥最少要踩多少石头

//如果忽略 L 的大小，这道题非常简单，显然可以推出状态转移方程 dp[i]=min(dp[j])(s<=i-j<=t)+[i==stone]，但是 L 的数据为 1e9，我们显然无法直接进行状态转移
//但是考虑道 m 的范围很小，也就意味着石头少，但是石头间的间距很大，那么我们其实可以压缩石头间的路径，我们就将路径对 2520 取模，因为 lcm(1,2....10)=2520，任意 s 和 t 的值都能达到 2520
//如果两块石头间的距离超过 2520，那么就先从左边的石头走若干个 2520 后达到一个 <2520 的位置再继续走
//最后答案不是 dp[l]，而是 [l,l+t-1] 的最小值

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e6+10;
const int lcm=2520;

int l,s,t,m;
int a[maxn];
int vis[maxn],dp[maxn];

int main(){
    cin>>l>>s>>t>>m;
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    sort(a+1,a+m+1);
    l=0;
    if(s==t){
        int ans=0;
        for(int i=1;i<=m;i++){
            if(a[i]%s==0) ans++;
        }
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++){
        int d=(a[i]-a[i-1])%lcm;
        l+=d;
        vis[l]++;
    }
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    for(int i=1;i<=l+t;i++){
        for(int j=t;j>=s;j--){
            if(i-j<0) break;
            dp[i]=min(dp[i-j],dp[i]);
        }
        dp[i]+=vis[i];
    }
    int ans=105;
    for(int i=l;i<l+t;i++) ans=min(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
