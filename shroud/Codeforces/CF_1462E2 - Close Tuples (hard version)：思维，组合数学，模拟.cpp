//题意：给出一个长度为 n 的序列，现在要求一个 m 元组 (ai,aj,ak...ai+m)，使得 max(ai,aj,ak...ai+m)-min(ai,aj,ak...ai+m) <= k，问这样存在的 m 元组的个数

//思路：这道题和他的 eazy version 一样做，枚举左端点，然后确定一个差值小于等于 k 的区间，然后利用组合数学计算 C(r-l,m-1) 即可

#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
const int p=1e9+7;
 
int n,m,k,a[maxn];
ll fac[maxn],ifac[maxn];
 
inline ll qpow(ll a,ll b){
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
	for(int i=1;i<=2e5;++i) fac[i]=fac[i-1]*i%p;
	ifac[200000]=qpow(fac[200000],p-2);
	for(int i=2e5-1;i>=0;--i) ifac[i]=ifac[i+1]*(i+1)%p;
}
 
inline ll c(int n,int m){
	return fac[n]*ifac[n-m]%p*ifac[m]%p;
}
 
int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int l=1,r=m;
		ll ans=0;
		while(l<=n){
			while(a[r]-a[l]<=k&&r<=n) r++;
			if(a[r]-a[l]>k||r>n) r--;
			//cout<<l<<" "<<r<<endl;
			if(r-l<m-1){
				l++;continue;
			}
			//cout<<r-l<<" "<<m-1<<endl;
			ans=(ans+c(r-l,m-1))%p;
			l++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
