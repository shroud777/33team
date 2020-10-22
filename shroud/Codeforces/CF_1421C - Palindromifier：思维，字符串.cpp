//题意：给出一个字符串 s（下标从 1 开始），现在可以执行两种操作
//第一种：选择一个位置 i，把 2-i 的字符串复制翻转后插入到当前字符串的头部
//第二种：选择一个位置 i，把 i-len-2 的字符串复制翻转后插入到当前字符串的尾部
//问如何操作可以得到回文串

//思路：可以选取的最大长度就是 len-2 除去头尾字符的中间段字符串，我们选择改长度向任意方向翻转都可以得到一个接近回文的字符串，头或尾部差一个字符
//这个时候比如  abcd->abcdcb 想要把尾部的 a 造出来很难，那我们可以想一个办法，要么构造一个  xxxxaa 这样的，然后把 a 翻转到尾部，要么构造一个 xxxxaxa 这样的，翻转后成了 xaxxxx，直接把 a 向左操作即可
//那么我们要构造这样的字符串，其实在一开始把 len-1 位置的字符像右移即可，然后整体像左构造类回文串，最后创造头部字符

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back

string s;

int main(){
	cin>>s;
	int len=s.size();
	cout<<3<<endl;
	cout<<"R "<<len-1<<endl;
	cout<<"L "<<len<<endl;
	cout<<"L "<<2<<endl;
	return 0;
}
