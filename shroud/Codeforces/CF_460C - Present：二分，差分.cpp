//题意：有一个长度为 n 的序列，现在执行 m 次操作，每次操作选择长度为 w 的连续区间，使得区间内的数全部加一，问 m 次操作后的序列的最小值最大可能是多少？

//思路：最小值最大，显然我们可以用二分答案，用线段树或者差分数组维护当前验证的序列即可

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+10;

int n,m,w;
ll a[maxn],d[maxn];

bool check(ll x){
	for(int i=1;i<=n;i++) d[i]=0;
	ll temp=0,cnt=m;
	for(int i=1;i<=n;i++){
		d[i]+=d[i-1];
		temp=a[i]+d[i];
		if(temp<x){
			if(cnt<x-temp) return false;
			cnt-=x-temp;
			d[i]+=x-temp;
			d[min(i+w,n+1)]-=x-temp;
		}
	}
	return true; 
}

int main(){
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll l=1,r=1e11,ans;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
} 
