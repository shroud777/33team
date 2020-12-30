//题意：给出一个长度为 n 的字符串序列，包含一个且仅一对 '(' ')' 与 n-2 个 '?'，问能否改变 '?' 变为 '(' or ')'，使得这个序列变成合法括号序列

//思路：首先如果字符串长度为奇数，显然没有答案。字符串长度为偶数的情况下，假设 ')' 在任意除第 1 个位置，'(' 在任意除第 n 个位置，我们可以发现就算 ')' 在 '(' 前面，我们只需要把第 1 个位置变成 '('，第 n 个位置变成 ')' 即可
//所以我们只要判断字符串长度是否为奇数，字符串首尾是什么字符即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

string s;

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		if(s[0]==')'||s[s.size()-1]=='('||s.size()&1) puts("NO");
		else puts("YES");
	}
	return 0;
}
