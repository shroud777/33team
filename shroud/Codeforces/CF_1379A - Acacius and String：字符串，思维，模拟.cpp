//题意：给出一个长度为 n 的字符串，字符串中包含小写字母和 '?' ，'?' 可以变成任何小写字母，问字符串能否变为所有子串只有一个等于 "abacabc"

//思路：首先字符串中要包含 "abacaba" ，那么我们至少要保证他出现在其中，并且若字符串不修改 '?' 已经具有 1 个或以上的模式串，结果已经不可以改变。
//那么我们来想想对于不包含模式串的字符串，我们可以把 '?' 替换成符合题意的字母，然后检查完成后的字符串是否只包含一个
//其实两步骤可以合在一起，变成枚举每个 s.substr(i,7) 看他是否能变成模式串，如果能变成那么其他位置是否包含别的模式串

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const string T="abacaba";


int n;
string s,ss;


int count(string s){
	int cnt=0;
	for(int i=0;i+6<s.size();i++){
		if(s.substr(i,7)==T) cnt++;
	}
	return cnt;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>s;
		bool ok=0;
		for(int i=0;i+6<n;i++){
			ss=s;
			bool f=1;
			for(int j=0;j<7;j++){
				if(ss[i+j]!='?'&&ss[i+j]!=T[j]){
					f=0;break;
				}
				ss[i+j]=T[j];
			}
			if(f&&count(ss)==1){
				for(int i=0;i<ss.size();i++) if(ss[i]=='?') ss[i]='z';
				cout<<"Yes"<<endl<<ss<<endl;
				ok=1; 
				break;
			}
		}
		if(!ok) cout<<"No"<<endl;
	}
	return 0;
}
