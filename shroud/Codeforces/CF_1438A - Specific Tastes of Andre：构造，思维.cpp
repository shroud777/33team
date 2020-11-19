//题意：请你构造一个长度为 n 的数列，使得他的所有子序列之和能被子序列长度整除

//思路：序列每个元素都为 1 即可

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cout<<1<<" ";
		cout<<endl;
	}
	return 0;
}
