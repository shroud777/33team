//题意：给出一个长度为 n 的序列，下标从 0 开始，你可以 reverse 任意长度和位置的连续子序列，求出序列每个下标为偶数的位置的和的最大值

//思路：首先可以清楚，如果 reverse 的长度为奇数，那么实质上对要求的和毫无影响，因为奇数位置的数还是换到了奇数，偶数位置的数则换到了偶数。
//其次 reverse 可以分为从奇数位置或偶数位置开始
//做法 1：先求出原数组的偶数位置的和，然后想想他每次操作就是把那一段位置的和变动了多少，比如说一个序列 3 1 2 1，原来的和是 5 ，然后你如果 reverse 3 1为 1 3，那么他这一块由这俩组成的值就变成了 1
//本来是 3 ，现在变成了 1 ，那么可以认为操作这一段带来的贡献是 -2 ，那么我们由此可以引申出两个数组分别统计偶数位置开始和奇数位置开始的 reverse 
//那么答案显然就是原来求出的没有 reverse 的和加上贡献值数组中的最大子段和，当然最大子段和要初始化为 0 ，还有根据他起始位置的奇偶，他要统计两次，相当于从两个数组中求出最大子段和。

//做法 2：DP，cnmd这个DP真的是又妙又气人，理解的太tm艰难了，
//这里的 DP 用 dp i,0 表示一直不翻转的最大值， dp i，1 表示翻转当前位置的最大值， dp i,2 表示不翻转当前位置的最大值
//具体来说 dp i,0 很好理解，就是原数组从头开始长度为 i 时的最大值
//dp i,1 意思是一定 reverse 当前位置，并且当前的值是与前面是否进行过 reverse 有关，dp[i+2][1] 与 max(dp[i][1],dp[i][0])有关，如果dp[i][0]比较大就代表着前面不进行 reverse 值比较大
//所以就是从当前这个 i+1 i+2 开始进行 reverse，如果 dp[i][1]比较大就代表之前某个位置（从哪儿开始不一定但他前面一个位置一定进行了 reverse）进行了 reverse ，这也表示这个 reverse 的长度一定是 >=4的
//还有如果当前位置是奇数的话那么他本来是不取的，但是你这一步要 reverse 就应该取了，是偶数则取 i+1 位置、
//状态转移方程 dp[i+2][1]=max(dp[i+2][1] , max(dp[i][1],dp[i][0])+(i&1 ? a[i] :a[i+1));
//然后就是 dp i,2,他其实和 dp i,0 有点相似，但是他的 i-1 前面都是取得三者得出的最优解，然后 i 位置就顺其自然不做 reverse ，
//状态转移方程显见：dp[i+1][2]=max(dp[i+1][2] , max(dp[i][0]，dp[i][1],dp[i][2])+(i&1?0:a[i]));
//总结一下就是 dp i,0 只和未进行任何操作的原序列有关， dp i,1 取决于之前位置的局部最优解，且由于存在两个起始位置的 reverse，所以要考虑 reverse 之后要取哪个，dp i，2 也是如此，但当前部分只要顺其自然即可

//做法1：
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll a[maxn*2],d1[maxn],d2[maxn],cnt1,cnt2,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cnt1=cnt2=ans=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(!(i&1)) ans+=a[i];
		}
		for(int i=0;i<n;i++){
			if(!(i&1)&&i+1<n) d1[++cnt1]=a[i+1]-a[i];
			if(i&1 && i+1<n) d2[++cnt2]=a[i]-a[i+1];
		}
		ll mx=0,now=0;
		for(int i=1;i<=cnt1;i++){
			now+=d1[i];
			if(now<0) now=0;
			else mx=max(now,mx);
		}
		now=0;
		for(int i=1;i<=cnt2;i++){
			now+=d2[i];
			if(now<0) now=0;
			else mx=max(now,mx);
		} 
		cout<<mx+ans<<endl;
	}
	return 0;
} 
//做法2：
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		vector<vector<ll> > dp(n+5,vector<ll>(3));
		for(int i=0;i<n;i++){
			dp[i+1][0]=max(dp[i+1][0],dp[i][0]+(i&1?0:a[i]));
			if(i+2<=n)dp[i+2][1]=max(dp[i+2][1],max(dp[i][0],dp[i][1])+(i&1?a[i]:a[i+1]));
			dp[i+1][2]=max(dp[i+1][2],max(dp[i][0],max(dp[i][1],dp[i][2]))+(i&1?0:a[i]));
		}
		cout<<max(max(dp[n][0],dp[n][1]),dp[n][2])<<endl;
	}
 return 0;
}
