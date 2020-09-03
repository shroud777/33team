//题意：现有 n 个字符串，把 n 个字符串中的每个字母任意分配到新的 n 个字符串的任意位置中，问 n 个新字符是否有可能相等

//思路：n 个字符串相等的意思就是 n 个字符串拥有个数一样的字符，所以如果旧的 n 个字符串中的每种字符个数都能是 n 的倍数，那么他就可以实现。遍历 n 个字符串统计即可

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;

int main(){
	int t;
	scanf("%d",&t);
	map<char,int> mp;
	while(t--){
		scanf("%d",&n);
		string s;
		mp.clear();
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=0;j<s.size();j++) mp[s[j]]++;
		}
		map<char,int>::iterator it;
		int now;
		bool f=1;
		for(it=mp.begin();it!=mp.end();it++){
			now=it->second;
			//cout<<it->first<<" "<<now<<endl;
			if(now%n!=0){
				f=0;break;
			}
		}
		if(!f) puts("NO");
		else puts("YES");
	}
	
	return 0;
}
