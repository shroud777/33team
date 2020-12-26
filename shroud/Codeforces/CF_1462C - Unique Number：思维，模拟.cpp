//题意：给出一个数 x，现在要求你输出一个数，使得这个数的所有数位之和等于 x，且 x 每个数位上的数字都不同，并且 x 尽量小

//思路：首先很明确 Σ1-9 = 45，那么 45 以上的数字我们肯定没法表示出来
//那么 45 一下的一定都可以用 1-9 不重复的数字表示，然后数位越少，显然数字越小，那么我们可以使每一位的数字尽可能大实现数位更少，所以只要从大到小贪心取数位即可

#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
 
int n,vis[15];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(vis,0,sizeof vis);
		if(n>45){
			puts("-1");
			continue;
		}
		for(int i=9;i>=1;--i){
			if(n>=i) n-=i,vis[i]=1;
		}
		for(int i=1;i<=9;i++) if(vis[i]) cout<<i;
		cout<<endl; 
	}	
	return 0;
