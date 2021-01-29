//题意：给出一个长度为 n 的序列，现在要求从中选择 k 个数，使得和最大，问有多少方案？
//例如 [1 1 2 3] 中要选择 3 个数，那有下标为 {1,3,4} {2,3,4} 两种选法

//思路：我们设选的最小的数为 x，那么那些大于 x 的数肯定全选，我们设大于 x 的数有 m 个，那么我们就必选这 m 个，其他就在 cnt[x] 中选择 k-m 个
//那么答案就是 C(cnt[x],k-m)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;
const int p=1e9+7;

ll n,k,cnt[1005];
ll fac[maxn],ifac[maxn];

ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}

void init(){
    fac[0]=1;
    for(int i=1;i<=2e5;i++) fac[i]=fac[i-1]*i%p;
    ifac[200000]=qpow(fac[200000],p-2);
    for(int i=2e5-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%p;
}

inline ll C(int n,int m){
    if(n<m) return 0;
    return fac[n]*ifac[m]%p*ifac[n-m]%p;
}

int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<=1000;i++) cnt[i]=0;
        cin>>n>>k;
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            cnt[x]++;
        }
        for(int i=1000;i;i--){
            if(k-cnt[i]<=0){
                cout<<C(cnt[i],k)<<endl;
                break;
            }
            k-=cnt[i];
        }
    }
    return 0;
}
