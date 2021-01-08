//题意：有一个长度为 n 的序列，现在执行如下操作：
//可以选择一个下标 i 作为起点，若 i>n 则中止，并且将 ai 加入当前分数，并且 i 变成 i+ai
//现在问操作可能得到的最大分数

//思路：题意很明确，按照题意模拟即可，但是很显然如果我们纯暴力模拟，如果每个 ai 都等于 1，n = 2e5，显然复杂度会爆炸，我们发现重复计算的部分非常多，那么这里我们就借鉴记忆化搜索的技巧，设置一个数组
//数组 f 记录选中 i 位置的值，如果 f[i] 值为空，那么我们递归执行，否则直接返回 f[i] 的值即可
//或者我们可以倒序记录，因为我们直到第 i 个位置跳到第 i+a[i] 个位置，但是不知道 i 是从哪儿跳过来的，所以我们只需要倒序记录即可

//做法1：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn],f[maxn];

ll solve(int pos,ll sum){
	if(pos>n) return 0;
	sum+=a[pos];
	pos+=a[pos];
	if(pos>n) return sum;
	if(f[pos]) return f[pos]+sum;
	ll temp=solve(pos,0);
	f[pos]=temp;
	return sum+temp;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n+5;i++) f[i]=0;
		ll ans=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) ans=max(ans,solve(i,0));
		printf("%lld\n",ans);
	}
	return 0;
} 

//做法2：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn];
ll dp[maxn];

int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),dp[i]=a[i];
		ll ans=0;
		for(int i=n;i;i--){
			if(i+a[i]<=n) dp[i]+=dp[i+a[i]];
			ans=max(ans,dp[i]);		
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
