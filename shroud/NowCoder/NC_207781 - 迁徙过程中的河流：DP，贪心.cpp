//题意：有 n 个人要过河，有一条船，每次只能上两个人，每个人都有一个渡河时间 T，每次渡河的时间为较慢的那个人的渡河时间，现在问 n 个人全部达到对岸的最小时间
//注意：到了对岸还可以回来

//思路：两种做法：
//1.贪心：渡河时间受到最慢的人的限制，那么我们可以想到尽量少让慢的人当舵手，并且运输过程尽量由速度快的人来担任，那么我们发现无非有四种情况：
// 1 个人的时候，2 个人的时候，3 个人的时候，以及更多个人的时候，前三种情况的策略都是固定的，而多个人的时候思路都是先移除最后两个人
//而这最后两个人要么由第 1 个人承担舵手，要么由第 2 个人过去然后等最后的两个人到了再把船开回来
//根据情况讨论并贪心即可
//2.DP：设 DP[i] 为 i 个人到对岸的最小时间，那么结合上述贪心思路，我们可以得到状态转移方程，即送一个人过去和送两个人过去

//1.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

ll n,a[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n==1){
        cout<<a[1]<<endl;
        return 0;
    }
    ll ans=0;
    while(n){
        if(n==2){
            ans+=a[2];break;
        }
        if(n==3){
            ans+=a[3]+a[1]+a[2];break;
        }
        ans+=min(a[n]+2*a[2]+a[1],a[n]+a[n-1]+2*a[1]);
        n-=2;
    }
    cout<<ans<<endl;
    return 0;
}

//2.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

ll n,a[maxn],dp[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    dp[1]=a[1],dp[2]=a[2];
    for(int i=3;i<=n;i++){
        dp[i]=min(dp[i-1]+a[1]+a[i],dp[i-2]+a[1]+a[i]+2*a[2]);
    }
    cout<<dp[n]<<endl;
    return 0;
}
