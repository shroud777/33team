//题意：给出一个序列，每次可以对一个数进行 +1/-1 操作，问最少进行多少次可以使序列递增

//思路：这道题和 POJ_3666 几乎一样，但是 POJ_3666 要求的是非严格单调序列，这样根据一个引理（序列中的每个数都会变成原先序列中的某个数），我们可以做出改变，将序列中第 i 个元素减去 i
//这样就变得和 POJ_3666 一模一样了，同时可以用滚动数组优化，用离散化处理较大的数和重复的数

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e3+10;
int a[maxn];
ll dp[maxn];
int n;
vector<int> v; 

//dp[i][j] 为第 i 个数变为 v[j] 的最优解
//dp[i][j]=min(dp[i-1][k])+abs(a[i]-v[j]) (1<=k<j)

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]-=i,v.push_back(a[i]);
	sort(v.begin(),v.end());	
	v.erase(unique(v.begin(),v.end()),v.end());
	int len=v.size();
	
	for(int i=0;i<=n;i++) dp[i]=0;
	for(int i=1;i<=n;i++){
		ll minn=1e18;
		for(int j=0;j<len;j++){
			minn=min(minn,dp[j]);
			dp[j]=minn+abs(a[i]-v[j]);	
		}
	}
	ll ans=1e18;
	for(int i=0;i<len;i++) ans=min(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}
