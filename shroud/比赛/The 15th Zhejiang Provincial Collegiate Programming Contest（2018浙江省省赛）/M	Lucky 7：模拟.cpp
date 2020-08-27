//题意：给出 a 序列和一个整数 b，问序列 a 中是否有元素满足+b % 7 == 0

//思路：将序列加上 b 遍历即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;

int n,b,x;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&b);
		bool f=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if((x+b)%7==0) f=1;
		}
		if(f) puts("Yes");
		else puts("No");
	} 
	return 0;
} 
