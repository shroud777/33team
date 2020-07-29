//题意：要求输出 n+1 个字符串，满足一个长度为 n 的序列，ai 代表 si 与 si+1 拥有的相同字前缀的个数


//思路：由于只看前缀，我们每次只需要用上一个相同的字符串，在公共前缀的后一位，把他改成不同的字符即可

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int mx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mx=max(mx,a[i]);
		}
		if(mx==0) mx=1;
		string s=string(mx,'a');
		cout<<s<<endl;
		string t;
		t=s;
		for(int i=1;i<=n;i++){
			t[a[i]]=char((t[a[i]]-'a'+1)%26+'a');
			cout<<t<<endl;
		}
	}
	return 0;
}
