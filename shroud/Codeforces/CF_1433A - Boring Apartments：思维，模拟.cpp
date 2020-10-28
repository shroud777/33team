//题意：在 1 到 10000 范围内全某个数位全由 x 构成的数被放入了一个集合，按照字典序排列，现在给出集合中的一个数，求在他之前的集合的数的位数的合

//思路：对于每个以 x 组成的数的集合大小为 4，分别为 x,xx,xxx,xxxx，那么之前有 (x-1)*4+log10(x) 个数，位数找规律即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=1e5+10;
 
int n;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		ans+=(n%10-1)*10;
		int t=log10(n)+1;
		for(int i=1;i<=t;i++) ans+=i;
		cout<<ans<<endl; 
	}
	
	return 0;
} 
