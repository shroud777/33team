//题意：给出一个顾客可能会购买的物品数量区间[l,r]，问能否决定一个打包物品数量 a，使得顾客想要购买的任意物品数量 x 满足 x % a >= a/2

//思路：使得 a=2*l，那么只要 r<a，即 r<2*l 即可满足条件

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=2e5+10;
 
int l,r,t;
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&l,&r);
		if(l*2>r) puts("YES");
		else puts("NO");
	}
	return 0;
}
