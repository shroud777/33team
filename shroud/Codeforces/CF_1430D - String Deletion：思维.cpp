//题意：给出一个 01 串，现在可以执行某种操作，操作分为两部分，第一部分选择任意一个下标位置的数并删除，第二部分将串最左端的连续字符删除，问现在最多做多少次上述操作使得字符串为空

//思路：处理按照如下原则：
//1.如果有连续的字符，下次操作下半部分肯定要把这一连续的字符串全部删除，所以选择第一部分的操作也从连续字符中开始
//2.最左端只要一个连续字符，那么选择右边连续的 01 子串来执行第一部分的操作，因为连续的到后面也是要一次全部清除的，现在选择可以更多次使用

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e6+10;
int n;
string s;

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>s;
		int cnt1=1,cnt2=0;
		for(int i=1;i<n;i++){
			if(s[i]!=s[i-1]) cnt1++;
			else{
				cnt2=min(++cnt2,cnt1); 
			}
		}
		cout<<(cnt1+cnt2+1)/2<<endl;
	}
	return 0;
}
