//题意：有四种 ci 面值的硬币，某人去商店买东西，去了 tot 次，每次带 d 枚 ci 硬币，买价值 s 的东西，请问每次有多少种付款方法

//思路：如果跑 tot 次多重背包显然会 tle，tot 过大。那么我们考虑完全背+容斥原理来解决这个问题，先跑出硬币无限的货币的方案树
//然后排出不合法的方案数，这里首先是只有第一种货币有限制的方案数，其他货币同理，但是这样我们会重复减掉两种不合法货币数量的方案
//所以我们要用容斥原理减去多余部分，然后两项的会减多了，再加减加减即可

#include <bits/stdc++.h>

using namespace std;	
typedef long long ll;
const int maxn=1e5+10;

int c[5],d[5],n,s;
ll dp[maxn];

void init(){
	dp[0]=1;
	for(int i=1;i<=4;i++){
		for(int j=c[i];j<=100000;j++) dp[j]+=dp[j-c[i]];
	}
}

int main(){
	for(int i=1;i<=4;i++) cin>>c[i];
	init();
	cin>>n;
	while(n--){
		for(int i=1;i<=4;i++) cin>>d[i];
		cin>>s;
		ll ans=dp[s];
		for(int i=1;i<(1<<4);i++){
			ll temp=0,res=0;
			for(int j=1;j<=4;j++){
				if(1<<(j-1)&i) res^=1,temp+=c[j]*(d[j]+1);
			}
			if(s>=temp) ans=res?ans-dp[s-temp]:ans+dp[s-temp];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
