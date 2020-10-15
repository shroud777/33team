//题意：有一个长度为 n 的全排列，现在可以合并两个数 a,b 使他们成为一个数 (a+b)/2（向上取整），问经过 n-1 次操作后，剩下的最后一个数的最大值可能是多少

//思路：最后合成的值最小也只能是 2，并且如果要得到 2，就要采取贪心策略，每次合并最大的两个数即可。

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=2e5+10;
 
int n,k,a[maxn];
int res[maxn],tot;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			cout<<2<<endl<<1<<" "<<2<<endl;
			continue;
		}
		cout<<2<<endl;
		cout<<n-2<<" "<<n<<endl;
		cout<<n-1<<" "<<n-1<<endl;
		for(int i=n-3;i>=1;i--){
			printf("%d %d\n",i,i+2);
		}
	}
	return 0;
}
