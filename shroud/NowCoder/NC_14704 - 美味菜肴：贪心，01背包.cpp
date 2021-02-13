//题意：现在有 m 道菜肴，完成第 i 道菜肴需要 ci 的时间，并且如果在 t 时刻完成第 i 道菜肴，美味度为 ai-t*bi，现在要求 T 时间内能得到的最大美味度

//思路：经典题，首先看到题目都想到可以用 01背包 做，但是这道题有一个时间尺度，先进背包和后进背包是由差异的
//如果第 i 道菜比第 j 道菜先做，那么必然要满足 ai-ci*bi+aj-(ci+cj)*bj>aj-cj*bj+ai-(ci+cj)*bi，最后化简得到 bj*ci<cj*bi
//所以我们排序决定优先级后再做 01背包 决定放还是不放即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e6+10;

int n,m,T;
int b[55];
ll dp[maxn];

struct node{
    int a,b,c;
    bool operator <(const node &oth)const{
        return c*oth.b<oth.c*b;
    }
}a[maxn];


int main(){
    cin>>n>>m>>T;
    for(int i=1;i<=n;i++) cin>>b[i];
    int idx;
    for(int i=1;i<=m;i++){
        cin>>idx>>a[i].a>>a[i].c;
        a[i].b=b[idx];
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=T;i++) dp[i]=-1e17;
    for(int i=1;i<=m;i++){
        for(int j=T;j>=a[i].c;j--){
            dp[j]=max(dp[j],dp[j-a[i].c]+a[i].a-1ll*j*a[i].b);
        }
    }
    ll ans=-1e17;
    for(int i=1;i<=T;i++) ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
