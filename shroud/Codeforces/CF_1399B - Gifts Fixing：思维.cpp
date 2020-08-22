//题意：有 n 个礼物，每份礼物有 ai 个糖果和 bi 个橘子，为了公平，要使所有人的橘子数相等，糖果数相等，每次可以选择减少一个橘子或一个糖果或一个橘子和一个糖果，求最小操作次数

//思路：肯定是找最小的糖果和最小的橘子，然后对于每份礼物需要进行的数量变更是 ai-mina.bi-minb，我们确实不需要在意具体数量，只需要在意数量变更即可
//那么对于上述变更，我们可以发现两种类型礼物的重叠部分我们可以花费一次操作的代价同时去执行，然后再去解决某一份多出来的部分

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1005;
ll a[maxn],b[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,mina,minb,ans=0;
		mina=minb=1e9+5;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i],mina=min(mina,a[i]);
		for(int i=1;i<=n;i++) cin>>b[i],minb=min(minb,b[i]);
		for(int i=1;i<=n;i++){
			ans+=max(a[i]-mina,b[i]-minb);
		}
		cout<<ans<<endl;
	}	
	return 0;
} 
