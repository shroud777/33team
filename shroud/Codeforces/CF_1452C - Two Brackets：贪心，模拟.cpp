//题意：给出一个括号序列，每次可以取出一个合法的括号序列，问最多可以取多少次

//思路：贪心地每次取一个就可以了，那么就是多少个匹配的括号就可以

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=1e5+10;
 
int main(){
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		int cnt1=0,cnt2=0,ans=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='(') cnt1++;
			if(s[i]=='[') cnt2++;
			if(s[i]==')'&&cnt1){
				cnt1--,ans++;
			}
			if(s[i]==']'&&cnt2){
				cnt2--,ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
