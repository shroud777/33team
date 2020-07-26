//题意：https://ac.nowcoder.com/acm/problem/19798  

//思路：ans=
//      f(1,1)+f(1,2)+f(1,3)+...+f(1,n) =w1*a1 + w2*(a1+a2) + w3*(a1+a2+a3) + ...wn*(a1+a2+..+an)
//             f(2,2)+f(2,3)+...+f(2,n) =        w1*a2 + w2*(a2+a3) +....wn-1*(a2+..an)
//                    f(3,3)+...+f(3,n) =         ....
//                           ...                  ....
//                               f(n,n) =         ....
// 以下用 fi 代表前 i 项的和
//     ans(1)=fn-f0;
//     ans(2)=fn+f(n-1)-f1-f0;
//     ans(3)=fn+f(n-1)+f(n-2)-f2-f1-f0;
//     ans(i)=fn+f(n-1)+...f(n-i+1)-f(i-1)-f(i-2)-...f(0);
//求两次前缀和即可，注意取模，注意可能出现负数因此要  (x+p) %p

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
const int p=1e9+7;
ll a[maxn],sum[maxn],w[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=(sum[i-1]+a[i])%p;
	}
	for(int i=1;i<=n;i++) sum[i]=(sum[i]+sum[i-1])%p;
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+(w[i]*(sum[n]-sum[n-i]-sum[i-1]+p)%p)%p)%p;
	}
	cout<<ans<<endl;
	return 0;
}
