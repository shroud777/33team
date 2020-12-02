//题意：给出一个 n，要求输出一个长度为 n，且每个位置 ai!=i 的序列

//思路：错位输出即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,t,a[maxn];

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			if(i==n) printf("1\n");
			else printf("%d ",i+1);
		}
	}
	
	return 0;
} 
