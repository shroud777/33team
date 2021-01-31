//题意：给出一个数 x，问能否由若干数位中包含 d 的数相加得到？

//思路：首先可以知道，如果当 x>=10*d，我们可以先用 x 减去 10*d，接着不断减去 d，相当于对 d 取模，得到一个必然是小于 d 的数，我们再把这个结果当成第一次减去的 10*d 的个位因子
//当 x<10*d 的时候，我们发现必须要用带 d 的数字给去除，比如 d，(10+d)，(20+d)+d 等等，我们可以发现无非是 d 和 10 的倍数的组合，并且必须包含 d，这个时候我们可以将 x 不断减去 d，如果剩余数是 10 的倍数，或者可以被 d 整除，说明可以得到
//或者我们还可以以 10*i+d 为物品跑完全背包，求出 <10*d 以下的可行组合方式

//1：


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

ll n,d;

bool check(int n){
    if(n<d) return false;
    if(n==d) return true;
    while(n>0){
        //cout<<n<<endl;
        n-=d;
        if(n%10==0) return true;
    }
    if(n==0) return true;
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>d;
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            if(x>=d*10){
                puts("YES");continue;
            }
            if(check(x)) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}


//2.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int q,d;
int dp[maxn],n;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>q>>d;
        memset(dp,0,sizeof dp);
        int mx=d*10;
        dp[0]=1;
        for(int i=0;i*10+d<=mx;i++){
            int v=10*i+d;
            for(int j=v;j<=mx;j++) dp[j]|=dp[j-v];
        }
        while(q--){
            cin>>n;
            if(n>=mx){
                puts("YES");continue;
            }
            if(dp[n]) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
