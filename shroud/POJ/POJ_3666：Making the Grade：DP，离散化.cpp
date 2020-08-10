//题意：给出一个长度为 n 的序列，每次可以对序列中的某一个数进行 +1/-1 的操作，求使序列变成非递减序列的最小次数

//思路：这题显然可以想到用 DP 来做
//首先来定义状态，我们可以想象到要将数列变为非递增，且次数要少，我们肯定是把某个要改变的数变为他相邻的数，那么每个数肯定是变为原有数列中的某个数
//由于数据很大，我们可以将序列离散化处理，然后状态定义就很清楚了 f[i][j] 代表第 i 个位置变为 v[j](离散化后数组) 的最优解
//那么序列前 i-1 个必然已经要做好，且状态转移要从前 i-1 个来
//那么状态转移方程就是 f[i][j]=min(f[i-1][k],abs(a[i]-v[j]) (1<=k<=j)
//这一步选哪个数已经决定（即第 i 个位置为 v[j]，所以是 abs(a[i]-v[j])），k 的取值只是限制最后得出的序列是递增的
//当然，由于每次都沿用 i-1 的结果，还可以用滚动数组优化

//O(n^2) 二维数组

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector> 

#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
vector<int> v;
int a[maxn];
ll dp[maxn][maxn];
//dp(i,j) 代表第 i 个数选择 v[j] 的最优解
//dp[i][j]=min(dp[i-1][k])+abs(a[i]-v[j]) (1<=k<=j) 
//这一步选哪个数已经决定（即第 i 个位置为 v[j]，所以是 abs(a[i]-v[j])），k 的取值只是限制最后得出的序列是递增的 

inline int find(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin();
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v.pb(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int len=v.size();
	for(int i=1;i<=n;i++){
		ll minn=1e18;
		for(int j=0;j<len;j++){
			minn=min(minn,dp[i-1][j]);
			dp[i][j]=minn+abs(a[i]-v[j]);
		}
	}
	ll ans=1e18;
	for(int i=0;i<len;i++) ans=min(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}


//O(n^2) 滚动数组优化
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector> 

#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
vector<int> v;
int a[maxn];
ll dp[maxn];

inline int find(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin();
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v.pb(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int len=v.size();
	for(int i=1;i<=n;i++){
		ll minn=1e18;
		for(int j=0;j<len;j++){
			minn=min(minn,dp[j]);
			dp[j]=minn+abs(a[i]-v[j]);
		}
	}
	ll ans=1e18;
	for(int i=0;i<len;i++) ans=min(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}
