//题意：给出一个 l,r  问斐波那契第 l 项到第 r 项的和的奇偶性

//思路：斐波那契数列从 1 开始每一项的奇偶性具有周期性，周期为 3，每个周期为 1 1 0
//那么我们可以看出他的和的奇偶性就取决于周期的端点落在什么位置（周期的相对位置），如果端点内奇数个数为奇数，那么就是奇数，反之所有情况都是偶数

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int n;
string s[5];
ll ans[5];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		cin>>s[1]>>s[2];
		for(int j=1;j<=2;j++){
			ans[j]=0;
			for(int i=0;i<s[j].size();i++) ans[j]+=s[j][i]-'0';
			ans[j]=ans[j]%3;
		}
		if((ans[1]==1&&ans[2]==1)||(ans[1]==2&&(ans[2]==2||ans[2]==0))||(ans[1]==0&&ans[2]==1)) puts("1");
		else puts("0");
	}
 	return 0;
}
