//题意：有 n 个客栈，每个客栈由某一种颜色装饰，总共有 k 种颜色，且每家客栈有一个最低消费 p，现在要找两家颜色相同的客栈，且两家客栈之间（包含这两家客栈）至少有一家客栈最低消费低于 p

//思路：只要两家客栈中间存在一个小于等于 p 的值，那么就可以选择这两家客栈，我们枚举右端点 p，那么我们接着维护当前位置最近的小于等于 p 的值，那么小于这个位置的所有左端客栈都可以和他组合

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=2e5+10;

int n,k,p,color,cost;
int cnt1[55],last[maxn],cnt2[maxn][55];

int main(){
	scanf("%d %d %d",&n,&k,&p);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&color,&cost);
		cnt1[color]++;
		for(int j=0;j<k;j++) cnt2[i][j]=cnt1[j];
		if(cost<=p) last[i]=i,ans--;
		else last[i]=last[i-1];
		ans+=cnt2[last[i]][color];
	}
	cout<<ans<<endl;	
}
