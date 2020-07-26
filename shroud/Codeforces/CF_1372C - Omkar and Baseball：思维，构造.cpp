//题意：给出一个 1~n 的顺序不定的全排列，可以进行 special exchange 这一操作，每次操作都是对连续子串进行，使操作后的子串每个元素的所在位置与之前不同，问操作几次可以使序列变成升序全排列

//思路：任意子串最多进行两次即可符合题意要求，具体证明看  https://codeforces.ml/blog/entry/79974  
//然后已经符合要求的显然不用说，可以想象如果一个不满足要求的初始序列，他所有元素和他的下标都不对应，比如 5 4 2 1 3，他一次 special exchange 即可变成 1 2 3 4 5
//而类似于 2 1 3 4 5     1 2 5 3 4 只要不满足条件的下标组成的序列是连续的即可在一次内完成，其他按照上述需要两次来完成

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int num,cnt=0;
		for(int i=1;i<=n;i++){
			cin>>num;
			if(num==i) cnt++;
		}
		if(cnt==n) cout<<0<<endl;
		else{
			if(!cnt) cout<<1<<endl;
			else cout<<2<<endl;
		}
	}
  return 0;
}
