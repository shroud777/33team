//题意：安排 n 对情侣到圆桌上吃饭，要求每队情侣之间不相邻的方案数

//思路：根据正难则反的方式思考，我们计算出所有的总的方案数，然后再减掉不合法的方案数即可
//对于所有的方案数，由于是一个圆桌，所有的方案数就是 (2*n-1)!，想减掉不合法的部分 2*(2*n-2)! C(n,1)，但是其实这种方法会重复减掉一些部分，一些情况会被重复选取，那么这里我们有需要加回来那部分
//因此这里用到容斥原理，预处理带入公式即可

#include <bits/stdc++.h>

using namespace std;	
typedef long long ll;
const int maxn=3e7+10;
const int p=1e9+7;

int n;
int fac[maxn],ifac[maxn];

inline int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=1ll*res*a%p;
		a=1ll*a*a%p;
		b>>=1;
	}
	return res;
}

void init(){
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%p;
	ifac[n]=qpow(fac[n],p-2);
	for(int i=n-1;i>=0;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%p;
}

inline int c(ll n,ll m){
	return 1ll*fac[n]*1ll*ifac[n-m]%p*1ll*ifac[m]%p;
}

int main(){
	scanf("%d",&n);
	if(n==0||n==1){
		puts("0");return 0;
	} 
	init();
	int ans=0,res1=qpow(2,n),res2=fac[n-1];
	for(int i=n;i>=0;res1=1LL*res1*ifac[2]%p,res2=1ll*res2*(2*n-i)%p,i--){
		if(i&1) ans=((1ll*ans-(1ll*c(n,i)*res1%p*1ll*res2%p))%p+p)%p;
		else ans=((1ll*ans+(1ll*c(n,i)*res1%p*1ll*res2%p))%p+p)%p;
	}
	cout<<(ans%p+p)%p<<endl;
} 
