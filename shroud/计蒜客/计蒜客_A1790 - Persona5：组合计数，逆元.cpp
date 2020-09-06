//题意：现在有 n 个位置，且存在一个上限，每个位置初始值都为 0，每次可以选择在某个位置加一，如果该位置达到上限则无法操作，问有多少种方法填满所有 n 个位置

//思路；总共操作就是 n 个位置上限的和，那么对于第 i 个人，就是剩余位置中任意选择 ai 个位置操作即可，ai 之间顺序互不影响

#include <iostream>
#include <cstring> 
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int p=1e9+7;

ll c[maxn];

void init(){
	c[1]=1;
	for(int i=2;i<=1000005;i++) c[i]=(c[i-1]*i)%p;
}

ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}

ll cal(ll n,ll m){
	if(n==m) return 1ll;
	return c[n]*qpow(c[m],p-2)%p*qpow(c[n-m],p-2)%p;
}

int n;
ll a[maxn];

int main(){
	init();
	while(~scanf("%d",&n)){
		ll sum=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*cal(sum,a[i])%p;
			sum-=a[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
