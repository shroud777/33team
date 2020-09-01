//题意：有 n 个工厂和 m 个工人，第 i 个工厂每天一个工人可以挣得 ai 元，问是否存在一种情况，所有工人被分配到工厂，且每个工厂每天分配的钱价值相等

//思路：第一种思路：我们知道 n 个工厂每日的个人工资已知，那么想让每个工厂的分配钱数相同，必然存在整数人数个数安排，那么我们可以想到，为了使分配的钱相等，我们通过所有工厂的最小公倍数
//这个公倍数使最小总人数得出的使所有工厂价格相同的价格，那么我们通过这些信息得到每个工厂的人数和总人数，如果使它或者它的倍数等于 m，说明存在解，反之不存在
//另外一种情况，求出所有工厂工资的 最大公约数 ，然后我们就是要找一个 倍数*gcd 作为那个每个工厂的应有总分配工资，其实这个做法还是有点牵强的，但是毕竟比赛的时候写出来了，而且也没什么大问题，就这样了

//做法 1：

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


using namespace std;
typedef long long ll;
const int maxn=1e5+10;

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}

ll n,m,a[maxn];


int main(){
	while(~scanf("%lld %lld",&n,&m)){
		ll c=1;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),c=lcm(a[i],c);
		ll res=0;
		for(int i=1;i<=n;i++) res+=c/a[i];
		if(m%res) puts("No");
		else{
			ll temp=m/res;
			puts("Yes");
			for(int i=1;i<=n;i++) printf("%lld%c",temp*c/a[i],i==n?'\n':' ');
		}
	}
	
	return 0;
}

//做法2：

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


using namespace std;
typedef long long ll;
const int maxn=1e5+10;

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
} 

ll n,m,a[maxn];

ll check(ll tempg){
	ll res=0;
	for(int j=1;j<=n;j++) res+=tempg/a[j];
	return res;
}

int main(){
	while(~scanf("%lld %lld",&n,&m)){
		ll g=1;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),g=gcd(g,a[i]);
		ll ans=-1;
		ll l=1,r=m/g+10;
		while(l<=r){
			ll mid=l+r>>1;
			if(check(mid*g)==m){
				ans=mid;break;
			}
			if(check(mid*g)>m) r=mid-1;
			else l=mid+1;
		}
		if(ans==-1) puts("No");
		else{
			puts("Yes");
			for(int i=1;i<=n;i++) printf("%lld%c",ans/a[i],i==n?'\n':' ');
		}
	}
	
	return 0;
}
