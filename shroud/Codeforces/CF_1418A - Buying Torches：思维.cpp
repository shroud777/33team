//题意：刚开始你有 1 根棍子，并且你要换得 k 个手电筒，1 个手电筒需要 1 个棍子和 1 个煤，现在你可以执行两种操作：
//1.用 1 根棍子换取 x 根棍子
//2.用 y 根棍子换取 1 个煤
//问最少可以用多少次操作换取 k 个手电筒

//思路：按照题意下去就行了，首先 k 个手电筒必然需要极其 k 根棍子和 k 个煤来换取，而初始状况下只有 1 根棍子，那么总共就需要 k*y+k-1 根棍子
//那么我们的操作 1 相当于得到 x-1 根棍子，所以总体就需要 ceil-((k*y+k-1)/(x-1))+k 种操作了

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=5e5+10;

int main(){
	int t;
	cin>>t;
	ll x,y,k;
	while(t--){
		cin>>x>>y>>k;
		cout<<(y*k+k-1)*1ll/(x-1)+(1ll*(y*k+k-1)%(x-1)!=0)+k<<endl;
		//cout<<ceil((y*k+k-1)*1.0/(x-1))+k<<endl;
	}
	return 0;
}
