//题意：给出 n 首歌的持续时间(s)，问能否选取若干首歌曲正好播放整小时？

//思路：可以考虑 01 背包，题目数据 n=1e5，s=[1,1e9]，我们可以只考虑 3600 的模数，所以 s 相当于降到 [0,3600)，但是考虑到 T 组数据，依旧会超时
//那么我们这里其实可以转化为多重背包，一共就 3600 组物品，接下来二进制分解优化即可
//同时这里我们可以使用 bitset 优化 01 背包也是可行的，并且其实这里 n 大于等 3600 的都是只要输出 YES 的，证明如下：
//根据抽屉原理，我们在 n 个数中，一定能找到若干连续的数使得他们的和为 n 的倍数，设 si 代表前 i 项的前缀和
//如果对于 i∈(1,n)，存在 n|si，符合题意
//如果对于 i∈(1,n)，若不存在 n|si，说明 si%n 都不等于 0，由于模 n 一共由 [0,n-1] n 个数，那么这里肯定有至少两个前缀和取模相同，那这两个前缀和作差的答案一定是 n 的倍数

//01背包+bitset 优化：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;
const int p=3600;

int n,a[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]%=p;
        }
        bitset<7500> dp;
        for(int i=1;i<=n;i++){
            dp|=(dp<<a[i])|((dp<<a[i])>>3600);
            dp[a[i]]=1;
        }
        if(dp[0]) puts("YES");
        else puts("NO");
    }
    return 0;
}

//多重背包：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e3+10;
const int p=3600;

int n,x,cnt[p],a[maxn],dp[2][p];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            cnt[x%3600]++;
        }
        if(cnt[0]){
            memset(cnt,0,sizeof cnt);
            puts("YES");continue;
        }
        n=0;
        for(int i=1;i<3600;i++){
            if(!cnt[i]) continue;
            int base=1;
            while(base<=cnt[i]){
                a[++n]=i*base;
                cnt[i]-=base;
                base<<=1;
            }
            if(cnt[i]){
                a[++n]=i*cnt[i];
                cnt[i]=0;
            }
        }
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            if(dp[0][0]>1) break;
            for(int j=0;j<3600;j++){
                dp[1][j]=dp[0][((j-a[i])%p+p)%p];
            }
            for(int j=0;j<3600;j++){
                dp[0][j]+=dp[1][j];
                dp[1][j]=0;
            }
        }
        if(dp[0][0]>1) puts("YES");
        else puts("NO");
    }
    return 0;
}
