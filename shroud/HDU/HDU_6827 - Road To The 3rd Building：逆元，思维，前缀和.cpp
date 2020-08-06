//题意：有 n 个点，每个点有一个权值 si，对于每个计划 p(i,j)(1<=i<=j<=n)= 1/(j-i+1) * (si+s(i+1)+...sj) 的概率相同，求 p(i,j) 的期望

//思路：把相同长度（j-i+1）的计划当成一项一同计算，那么根据推导最后每一项的公式就是：两次前缀和后的 s[n]-s[n-c]-s[c-1]+s[0] / i,转化为逆元即可
//推导过程如下，以 n=5 为例
//原序列 a1 a2 a3 a4 a5
//一次前缀和后的数组 s1 s2 s3 s4 s5
//长度为 1 的项 p(1,1)+p(2,2)+p(3,3)+p(4,4)+p(5,5) = a1+a2+a3+a4+a5 = (s5-s0)
//长度为 2 的项 p(1,2)+p(2,3)+p(3,4)+p(4,5) = (a1+a2)+(a2+a3)+(a3+a4)+(a4+a5) =(s2-s0)+(s3-s1)+(s4-s2)+(s5-s3) = (s5+s4-s1-s0)
//长度为 3 的项 p(1,3)+p(2,4)+p(3,5) = (a1+a2+a3)+(a2+a3+a4)+(a3+a4+a5)=(s3-s0)+(s4-s1)+(s5-s2) = (s5+s4+s3-s2-s1-s0)
//长度为 4 的项 p(1,4)+p(2,5) = (a1+a2+a3+a4)+(a2+a3+a4+a5)=(s4-s0)+(s5-s1) = (s5+s4-s1-s0)
//长度为 5 的项 p(1,5)=a1+a2+a3+a4+a5 = (s5-s0)
//可以看出每个项的结果有对称性，且和前缀和序列的首尾有关，所以只要再求一次前缀和即可，每项的长度由于对称性很好判断
//每一项用逆元防止爆 ll ，同时用快速乘避免爆 ll 同时减少运行时间

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; 
const int p=1e9+7;
const int maxn=2e5+10;

inline ll qpow(ll a,ll b){
    ll ans=1,base=a;
    while(b){
        if(b&1) ans=ans*base%p;
        base=base*base%p;
        b>>=1;
    }
    return ans;
}

inline ll inv(ll a){
    ll inv_a;
    inv_a=qpow(a,p-2);
    return inv_a;
}

inline ll cnm(ll a){
    ll ans=0;
    for(int i=1;i<=a;i++){
        ans=(ans+i)%p;
    }
    return ans;
}

inline ll ksc(ll a,ll b)
{
    a%=p;b%=p;
    ll c=(long double)a*b/p;
    ll ans=a*b-c*p;
    if(ans<0) ans+=p;
    else if(ans>=p) ans-=p;
    return ans;
}

ll a[maxn],s[maxn];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            s[i]=(s[i-1]+a[i])%p;
        }
        ll ans=0;
        ll c;
        for(int i=1;i<=n;i++) s[i]=(s[i]+s[i-1])%p;
        for(int i=1;i<=n;i++){
            c=min((int)n-i+1,i);
            ans=(ans+ksc(s[n]-s[n-c]-s[c-1]+s[0],inv(i))%p)%p;
        }
        cout<<ksc(ans,inv(cnm(n)))%p<<endl;
    }
    return 0;
}
