//题意：给出 a 和 b，求一个数 x，使得 a异或x+b异或x 的值最小

//思路：异或值要尽可能小，那么相同位尽量使同一个数字，那么对于 a 和 b，如果两个数相同位的数字不同，那么不管 x 这个位置的值是 0 还是 1，总能得到该位的值，如果 a 和 b 相同位相同，则使得 x 该位的值和他们相同
//这样得到的尽可能小，综上就是 a异或b 的值

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d %d",&a,&b);
		cout<<(a^b)<<endl;
	}
	
	
	return 0;
}
