//题意:给出一个只有 '+' 和  '-' 的字符串，有一个值cur初始值为0，遍历字符串，若某一位置 '+'的数量-'-'的数量+cur<0，则从头开始遍历，cur++，求遍历每个字符的次数。 

//思路:暴力模拟必然超时，然而只需要遍历字符串一遍即可，用res='+'的数量- '-'的数量    当前位置如果res<0，只需要ans+=i+1就代表重新从头开始并且cur已经+1了因此这个位置的res变成了0。

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	string s;
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		ll res=0,ans=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='+') res++;
			else res--;
			if(i==s.size()-1){
				ans+=s.length();
			}
			if(res<0){
				ans+=i+1;
				res++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
