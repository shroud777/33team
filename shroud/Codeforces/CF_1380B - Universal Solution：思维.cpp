//题意：给出一个字符串由 'R' 'S' 'P' 组成，机器人会从字符串任意一个 pos 作为头开始，进行n轮，每次位置向后一位，如果超过 n 就移动向第 1 位。
//每轮根据当前字符进行操作， 'R' 出拳头, 'S' 出剪刀, 'P' 出布，请你给出一个序列使得机器人从 1~n 作为pos开始的 n 种情况的平均获胜概率最小。

//思路：做做写写就过了。

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
int r,s,p;
int main(){
	int t;
	cin>>t;
    while(t--){
    	string S;
    	cin>>S;
    	r=s=p=0;
    	for(int i=0;i<S.length();i++){
    		if(S[i]=='R') r++;
    		if(S[i]=='S') s++;
    		if(S[i]=='P') p++;
		}
		if(s==r&&r==p){
			cout<<S<<endl;
			continue;
		}
		string ans;
		int mx=max(s,(max(r,p)));
		if(mx==s) ans=string(S.size(),'R');
		else if(mx==r) ans=string(S.size(),'P');
		else ans=string(S.size(),'S');
		cout<<ans<<endl;
	}
	return 0;
} 
