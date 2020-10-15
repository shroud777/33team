//题意：有一个长度为 n 的序列，现在可以执行 k 次操作，每次操作都可以把一个数全部加到另一个数上面去，问现在可以得到的最大的最大数和最小数之差

//思路：序列的最小值就是 0，最大值最大则是最大的 k 个数之和

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=2e5+10;
 
int n,k,a[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1,greater<int>());
		ll ans=0;
		for(int i=1;i<=k+1;i++) ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
}
