//题意：有 n 道菜，吃每道菜需要花一定的价格并能得到一定的欢乐值，同一道菜吃第 i 次得到的欢乐值会减少为原欢乐值 - 2^(i-1)，现在有 m 元，问能得到的最大欢乐值是多少？

//思路：把每道菜欢乐值大于 0 的情况全部加入序列，然后通过 01背包 的思想得到最优解
//这里说说为什么 01背包 可行，因为价格相同欢乐值不同的两份菜，他肯定会先吃欢乐值多的再吃少的

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1e6+10;
int n,m,tot;
ll w[maxn],v[maxn];
ll dp[maxn];


int main(){
	tot=0;
	cin>>n>>m;
	while(n--){
		++tot;
		scanf("%d %d",&w[tot],&v[tot]);
		int cnt=0,temp=w[tot],temp2=v[tot];
		while(temp-(1<<cnt)>0){
			w[++tot]=temp-(1<<cnt);
			v[tot]=temp2;
			cnt++;
		}
	}
	memset(dp,-1e18,sizeof dp);
	dp[0]=0;
	ll ans=0;
	for(int i=1;i<=tot;i++){
		for(int j=m;j>=v[i];j--){
			if(dp[j]<dp[j-v[i]]+w[i]) dp[j]=dp[j-v[i]]+w[i];
			if(dp[j]>ans) ans=dp[j];
		}
	}
	cout<<ans<<endl; 
}
