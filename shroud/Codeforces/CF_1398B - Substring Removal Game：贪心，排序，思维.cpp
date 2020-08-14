//题意：给出一个二进制序列，A 和 B 每次可以拿走一段数字相同的子段，A 先拿，且最后的得分是拿走的 1 的个数

//思路：对所有的连续 1 的子段取出，以他们的长度降序排序，然后从头开始加上相隔一个的长度权值即可得出答案

#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn=5e4+10;
int a[maxn];
vector<int> v;
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		v.clear(); 
		int cnt=0,tot=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				tot++;
				cnt=0;
				while(s[i+cnt]=='0') cnt++;
				i+=cnt-1;
			} 
			else{
				tot++;
				cnt=0;
				while(s[i+cnt]=='1') cnt++;
				i+=cnt-1;
				v.push_back(cnt);
			}
		}
		sort(v.begin(),v.end(),greater<int>());
		int ans=0;
		for(int i=0;i<v.size();i+=2) ans+=v[i];
		cout<<ans<<endl;
	}
	return 0;
}
