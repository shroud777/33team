//题意：给出 n 个数，判断当前的数是否存在且只存在三个因子(约数)

//思路：我们都知道质数是只有两个因子（1和它本身的数），那么如果要有三个因子，那么第三个必然是 sqrt(它本身) 了，因为如果这个数是别的，它必然会又多一个质数，a*b=原来的数
//所以我们只需要知道 sqrt(x)*sqrt(x) 是否等于它本身即可，另外还要判断 sqrt(x) 是否为质数，避免产生其他的数，还有就是 1 要特判一下

#include <iostream>
#include <cstring> 
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=1e6+10;

int n;
ll x;

bool vis[maxn];

void sieve(ll n){
	vis[0]=vis[1]=1;
	for(int i=2;i*i<=n;i++){
		if(!vis[i]) for(int j=i*i;j<=n;j+=i) vis[j]=1; 
	}
}

int main(){
	sieve(1000000);
	scanf("%d",&n);
	int cnt=0;
	ll temp;
	for(int i=1;i<=n;i++){
		cin>>x;
		cnt=0;
		temp=sqrt(x);
		if((double)sqrt(x)!=temp){
			puts("NO");
			continue;
		}
		if(!vis[temp]) puts("YES");
		else puts("NO");
	}
	return 0;
}
