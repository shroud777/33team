//题意：要求构造一个长度为 n 的序列，满足以下条件：
//1.所有的数都在值域 [1,m]
//2.有且恰好有一对数相等
//3.存在一个下标 i，使得 j<i 和 j>=i 的部分都严格递减

//思路：首先我们从 m 个数中取 n-1 个数，然后从 n-2 个数（最大值已经确定，并且最大值不可能作为相等的数对）中选择哪个数作为相对的数对
//这 3 个数已经排列好了，接着我们考虑剩下 n-3 个数排列，无非就是放左边或者放右边，那么就是 2^(n-3)

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
const int p=998244353;

ll n,m,fac[maxn],ifac[maxn];

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
    cin>>n>>m;
    if(n==2){
        puts("0");return 0;
    }
    cout<<C(m,n-1)*(n-2)%p*qpow(2,n-3)%p<<endl;
    return 0;
}
