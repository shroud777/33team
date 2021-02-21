//题意：现在有 n 种品种的花，每种品种有 ai 朵，现在将 m 朵花困成一束，且同一束花不能是同一品种的，问最多捆多少束花

//思路：一开始不知道从哪里去突破，但就一直感觉很好做，然后逐渐想到只有 1 个品种的 10 朵花，但是一捆至少要 2 个品种以上，那么也只能捆上一捆花
//受到特殊样例的启发可以找到一点突破口了，那就是 1 种品种的花只能对 1 束花做出 1 朵花的贡献，那么我们发现可以二分答案
//假设我们二分的值为 x，那么就代表着最多有 x 束花，那么对于品种 i 的花，我们发现他最多对每一束花贡献一朵，也就是贡献为 min(x,a[i])
//对于上述现象，我们可以用鸽巢原理证明：对于 x 束花，如果我们用品种为 i 的花贡献了大于 x 朵，那么至少有一朵花有 2 朵以上的花

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e8+10;

int n,m;
ll a[maxn];

//扎 x 捧花

bool check(ll x){
    ll res=0;
    for(int i=1;i<=n;i++) res+=min(a[i],x);
    res/=m;
    return res>=x;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ll s=0;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),s+=a[i];
        ll l=0,r=s/m,ans;
        while(l<=r){
            ll mid=l+r>>1;
            if(check(mid)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
