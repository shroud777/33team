//题意：给出长度为 n 的序列 D 和 S，现在可以选择一个数 k 使得序列所有元素加上 k 和 S 里的相同位置元素相同的最多

//思路：D+k=S，记录每次 S-D 的差值，使得答案为差值出现次数最多即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;

int n,b;
ll x;
ll a[maxn];

map<ll,int> mp;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		mp.clear();
		ll ans=-1e18;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x);
			mp[x-a[i]]++;
			ans=max(1ll*mp[x-a[i]],ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
