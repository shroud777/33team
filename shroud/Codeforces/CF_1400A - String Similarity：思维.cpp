//题意：给出 n 和长度为 2*n-1 的二进制字符串，我们称两个字符串相似当他们长度相同，并且某一个位置上的字符相等
//求出一个字符串使得它和 s[1..n] , s[2..n+1], s[3..n+2], ..., s[n..2n−1] 等 n 个原字符串的子字符串都相似

//思路：只要让第一个字符的第一个，第二个字符串的第二个，第i个字符串的第i个相同即可

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
 
int n;
int a[maxn],b[maxn];
string s;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>s;
		string ans;
		for(int i=0;i<n;i++){
			ans+=s[i+i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
