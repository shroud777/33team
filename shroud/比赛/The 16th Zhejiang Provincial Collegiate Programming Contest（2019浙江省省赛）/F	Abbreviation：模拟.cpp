//题意：给出一些小写字母组成的单词，其中有些字母在非词首的地方不能出现，输出处理后的单词

//思路：用 map 记录一下不能出现的字母，然后一个字母一个字母遍历即可

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;

string s;

map<char,int> mp;

int main(){
	mp['a']++;
	mp['e']++;
	mp['i']++;
	mp['y']++;
	mp['o']++;
	mp['u']++;
	int t;
	scanf("%d",&t);
	while(t--){
		cin>>s;
		string ans;
		ans+=s[0];
		for(int i=1;i<s.size();i++) if(!mp[s[i]]) ans+=s[i];
		cout<<ans<<endl;
	}
	return 0;
}
