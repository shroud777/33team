//题意：给出一个长度为 n 的序列，你可以花费 1 的代价使序列中的任意元素 加减1 ，问是否存在一个 c，使得原序列第 i 位（i从0开始）变成 c^i 所花费的代价最小

//思路：可以看出如果 n 很大，那么 c 肯定是往 1 选，因为序列中最大的也就 1e9, n 如果大下去，即使 c 只有 2，那么 n=63 的时候就能大于 9e18，还不如全部变成 1，所以我们只需要找到并设定一个边界
//这里就是 n=63 的时候，其实还可以更小，那么这里我们只需要 O(1e5*63) 或 O(1) 验证


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int n;
ll a[maxn];

inline ll qpow(ll a,ll b){  
	ll base=a;
	ll ans=1; 
	while(b){
		if(b&1) ans=ans*base;
		base=base*base;
		b>>=1;
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	ll ans=0;
	if(n>=63) for(int i=1;i<=n;i++) ans+=(a[i]-1);
	else{
		ll temp=0;
		ans=qpow(2,62);
		for(ll i=1;;i++){
			if(qpow(i,n-1)>=a[n]){
				temp=i;
				break;
			}
		}
		ll res;
		for(int i=1;i<=temp;i++){
			res=0;
			for(int j=1;j<=n;j++) res+=max(qpow(i,j-1)-a[j],a[j]-qpow(i,j-1));
			ans=min(res,ans);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
