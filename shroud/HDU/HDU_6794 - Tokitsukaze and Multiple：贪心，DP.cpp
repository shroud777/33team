//题意：给出长度为 n 的序列，可以合并任意相邻两元素，问在某次合并之后当前序列中最多可以出现多少个 p 的倍数

//思路：其实题意就是把序列切成若干段，问最多多少段可以的是 p 的倍数，那么很简单，这就变成了区间调度的贪心问题，该贪心思想就是按右端点升序，如果后面的线段能选（左端点大于前一条线段的右端点）就选
//因为如果选了不能选的话，那么它必然会导致前面一条线段的退出，而且还会扩大右边范围，一定不优
//那么我们第一种做法可以用 map 来维护前缀和，如果当前序列出现 p 的倍数，就重置 map，相当于把前面的线段切掉，不再影响后面的
//同时这里 map 运用的思想是，对当前前缀和取模，如果再后面的过程中，前缀和取模得到与当前相同的结果，那么说明这一段中存在的是 p 的倍数，例如 10 3 7，p = 3;
//第一次余数等于 1，第二次余数还是等于 1，说明加上了的这个 3 是 3 的倍数
//通过这种思想我们还可以用 dp 做法来求解

//map 维护
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
typedef long long ll;
using namespace std;


int main(){
	int t;
	scanf("%d",&t);
	ll p;
	int n;
	while(t--){
		map<ll,int> mp;
		scanf("%d %lld",&n,&p);
		mp[0]=1;
		ll sum=0,ans=0,x;
		while(n--){
			scanf("%lld",&x);
			sum=(sum+x)%p;  
			if(mp.count(sum)){
				ans++;
				sum=0;
				mp.clear();
				mp[0]=1;
			}
			else mp[sum]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
} 


//dp 状态转移   dp[i]=max(dp[i],dp[last[sum]]+1);  last[i] 记录的是上个模数出现的地方，如果不是 -1 才可进行状态转移方程

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
typedef long long ll;
using namespace std;
const int maxn=1e5+10;
int a[maxn],last[maxn],dp[maxn];

int main(){
	int t;
	scanf("%d",&t);
	int n,x,p;
	while(t--){
		scanf("%d %d",&n,&p);
		ll sum=0,ans=0;
		memset(last,-1,sizeof last);
		dp[0]=0;
		last[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			sum=(sum+x)%p;
			dp[i]=dp[i-1];
			if(last[sum]!=-1) dp[i]=max(dp[i],dp[last[sum]]+1);
			last[sum]=i;
		}
		cout<<dp[n]<<endl; 
	}
	return 0;
} 
