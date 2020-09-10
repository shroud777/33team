//题意：有 n 个同学要做校车，第 i 个同学在第 ti 时刻上车，一趟车来回需要 m 分钟，并且校车随时都可以发车，求所有同学最小的等待时间

//思路：枚举每个上车的时刻，记忆化搜索降低复杂度
//如果枚举 t 个时刻的上车时刻，复杂度显然过大，所以我们要转变思路，其实每个同学的等待时间不会超过 m
//我们以 n 个同学的上车时刻为下标，注意几个原则：1.当前时刻发一趟车，肯定会带走之前所有没有上车的同学。2.如果下一个 m 时段没人上车，那么我们只需要调整到下一位同学的等待时刻.3.是立刻发车还是等下几位同学，我们去min值即可

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=1e3+10;

int n,m,t[505];
int dp[maxn][maxn];

//已经装走 x 个人，当前时刻为 time 
int dfs(int x,int time){
	if(x==n) return 0;
	if(t[x+1]>time) return dfs(x,t[x+1]);
	if(dp[x+1][time-t[x+1]]) return dp[x+1][time-t[x+1]];
	int sum=0,i;
	for(i=x+1;(i<=n)&&t[i]<=time;i++) sum+=t[i];
	int res=(i-x-1)*time-sum+dfs(i-1,time+m);
	for(i;i<=n;i++){
		sum+=t[i];
		res=min(res,(i-x)*t[i]-sum+dfs(i,t[i]+m));
	}
	return dp[x+1][time-t[x+1]]=res;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	sort(t+1,t+n+1);
	cout<<dfs(0,0)<<endl;
	return 0;
} 
