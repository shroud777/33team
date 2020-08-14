//题意：给出一个长度为 n 的序列，问存在多少连续子序列满足子序列的和等于子序列的长度

//思路：可以想到这道题多多少少和前缀和有点关系，可以先想到如果记录当前缀和，那么每次 s[j]-s[i]=j-i 时说明 [i,j] 这段序列满足条件，根据这个式子得到 s[j]-j=s[i]-i
//那么我们可以得知只要满足 s[j]-j=s[i]-i 就代表这一段满足，所以我们只需要用 map 记录 s[j]-j 即可，与之前的 s[i]-i 想匹配

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=5e4+10;
 
int main(){
	int t;
	cin>>t;
	int n;
	string s;
	while(t--){
		map<ll,int> mp;
		cin>>n>>s;
		mp[0]=1;
		ll sum=0,ans=0;
		for(int i=0;i<n;i++){
			sum+=s[i]-'0';
			ans+=mp[sum-i-1];
			mp[sum-i-1]++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
