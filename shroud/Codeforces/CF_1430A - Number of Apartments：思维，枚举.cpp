//题意：给出一个数 n，问他能否被若干个 3,5,7 组成，并输出组成方案

//思路：1.枚举，双重循环枚举 3 和 5 组成的数，并判断剩余数能否被 7 整除
//2.我们可以用 3,5,7 作为基础不断加 3，这样只有 1,2,4 不能被组成

#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool f=0;
		for(int i=0;i<=n/3;i++){
			int lim=(n-i*3)/5;
			if(f) break;
			for(int j=0;j<=lim;j++){
				int temp=n-3*i-5*j;
				if(temp%7==0){
					f=1;
					cout<<i<<" "<<j<<" "<<temp/7<<endl;
				}
				if(f) break;
			}
		}
		if(!f) cout<<-1<<endl;
	}
	return 0;
}
