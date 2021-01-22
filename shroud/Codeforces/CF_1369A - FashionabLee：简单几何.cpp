//题意：给出一个正 n 边形，问是否可以通过旋转使得某两条边同时分别平行 x 轴和 y 轴

//思路：最小的模型是正四边形，那我们从这里入手，如果我们要使得保持性质，我们只能分别在垂直的两条边中加若干条边，所以只要边数是 4 的倍数，那么显然满足条件

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n;

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%4==0) puts("YES");
		else puts("NO");
	}

	return 0;
}
