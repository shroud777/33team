//题意：给出 n 个长度为 m 的字符串，问能否得出一个字符串使其与每个字符串最多有一个位置的字符不相同

//思路：数据很小， n 和 m 都小于 10 ，然后我们可以枚举某一个字符串只改变一个位置的所有情况，然后暴力判断即可得到答案，因为若答案存在，答案肯定和被枚举的那个字符串相等或某个位置差 1 
//那么枚举的字符串里肯定有答案。或者换个思路，这些枚举出来的字符串对原字符串来说已经是答案了，答案也必在这个集合里，只要判断是否可行即可

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[15];
int n,m;
bool check(string s1,string s2){
	int cnt=0;
	for(int i=0;i<m;i++){
		if(s1[i]!=s2[i]) cnt++;
	}
	if(cnt<=1) return true;
	return false; 
} 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		string ans;
		bool f=0;
		for(int i=1;i<=n;i++) cin>>s[i];
		for(int i=0;i<m;i++){
			if(f) break;
			for(char j='a';j<='z';j++){
				string t=s[1];
				t[i]=j;
				//cout<<t<<endl;
				f=1;
				for(int k=2;k<=n;k++){
					if(!check(s[k],t)){
						f=0;
						break;
					}
				}
				if(f){
					ans=t;
					break;
				}
			} 
		}
		if(f) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
}
