//题意：在 [1,m] 选出一个长度为 n 的整数序列，使得序列中有且仅有一对相同的元素，并且在序列中存在一个位置，使其位置前面的序列严格递增，后面的序列严格递减

//思路；一开始我是想先在 [1,m] 中选出那个最大的数，但是那样对于之后每个数的选择，又是一个很大的困难
//这里可以选出序列由哪 n-1 个数组成的(以为有2个相同)，然后再选出相同的那一对，但是这里最大的不可能相同，所以有 n-1-1 个选择，然后剩余 n-3 个数，
//他们再序列中的位置，无非就是再最大值的左边或者右边，所以是 2^(n-3) 种选择
//最后注意乘法逆元和 n==2 的情况不存在即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=3e5+10;
const ll p=998244353;

//C(n-1,m) * (n-2) * (2^(n-3)) 

int n,m;

ll qpow(ll a,ll b){
	a%=p,b%=p;
	ll res=1,base=a;
	while(b){
		if(b&1) res=(res*base)%p;
		base=(base*base)%p; 
		b>>=1;
	}
	return res;
}

ll cal(ll n){
	ll res=1;
	for(int i=1;i<=n;i++) res=res*i%p;
	return res;
}

ll c(ll n,ll m){
	if(n<m) return 0;
	if(n==m) return 1;
	return cal(n)*qpow((cal(m)*cal(n-m)%p),p-2)%p;
}


int main(){
	scanf("%d %d",&n,&m);
	if(n==2) return 0;
	cout<<c(m,n-1)*(n-2)%p*qpow(2,n-3)%p<<endl;
	return 0;#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=3e5+10;
const ll p=998244353;

//C(n-1,m) * (n-2) * (2^(n-3)) 

int n,m;

ll qpow(ll a,ll b){
	a%=p,b%=p;
	ll res=1,base=a;
	while(b){
		if(b&1) res=(res*base)%p;
		base=(base*base)%p; 
		b>>=1;
	}
	return res;
}

ll cal(ll n){
	ll res=1;
	for(int i=1;i<=n;i++) res=res*i%p;
	return res;
}

ll c(ll n,ll m){
	if(n<m) return 0;
	if(n==m) return 1;
	return cal(n)*qpow((cal(m)*cal(n-m)%p),p-2)%p;
}


int main(){
	scanf("%d %d",&n,&m);
	if(n==2){
        cout<<0<<endl;
        return 0;
    }
	cout<<c(m,n-1)*(n-2)%p*qpow(2,n-3)%p<<endl;
	return 0;
}
