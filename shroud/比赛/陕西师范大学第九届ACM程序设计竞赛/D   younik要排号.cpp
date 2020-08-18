//题意：依次给出 n 个字符串，问 “Younik” 处于第几个字符串，之前重复出现的字符串只算一次

//思路：map 记录字符串出现的次数，防止重复出现

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;
int a[maxn];

int main(){
	int n;
	string s;
	cin>>n;
	int cnt=0,ans;
	map<string,int> mp;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(!mp[s]) cnt++;
		mp[s]++;
		if(s=="younik") ans=cnt;
	}
	cout<<ans<<endl;
	return 0;
}
