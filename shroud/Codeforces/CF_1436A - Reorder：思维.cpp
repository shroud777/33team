//题意：给出一个长度为 n 的序列，问 ∑i 1-n ∑ j i-n (aj/j) 是否等于 m？

//思路：序列中的每个元素 ai，被放在第 i 个位置则，ai/i 被计算 i 次，那么显然最后序列的和与排列方式无关，只需要判断序列之和是否等于 m 即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=1e5+10;
 
int n,m,x;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>x;
			sum+=x;
		}
		if(sum==m) puts("YES");
		else puts("NO");
	}
	
	
	return 0;
}
