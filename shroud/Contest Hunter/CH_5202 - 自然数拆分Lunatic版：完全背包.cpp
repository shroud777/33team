//题意：给出一个数 n，要求把 n 拆分成若干个正整数相加的形式，参与运算的数可以重复，求拆分的方案书

//思路：完全背包，把 1-n 每个正整数当成一件物品，可以装无限次

#include <bits/stdc++.h>

using namespace std;	
typedef long long ll;
const ll p=2147483648;
const int maxn=4e3+10;

int n;
ll dp[maxn];

int main(){
	scanf("%d",&n);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) dp[j]=(dp[j]+dp[j-i])%p;
	}
	cout<<(dp[n]>0?dp[n]-1:p)<<endl;
	return 0;
} 
