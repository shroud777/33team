//题意：给出一个由二进制数字符串，求把他分成不存在连续 1 或者 0 的子字符串的最少数量

//思路：模拟即可，遍历字符串，分别用两个容器储存上一个最后一个字符串为 0 或者 1 的子字符串的编号，然后如果当前字符是 0，就延续上一个最后一个字符是 1 的字符，反之亦然。

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;
vector<int> pos0,pos1;
int ans[maxn];

int main(){
	int t,n;
	cin>>t;
	string s;	
	while(t--){
		cin>>n>>s;
		int mx=0;
		pos1.clear(),pos0.clear();		
		int temp;
		for(int i=0;i<s.size();i++){
			temp=pos1.size()+pos0.size();
			if(s[i]=='0'){
				if(pos1.empty()){
					pos0.push_back(temp);
				}
				else{
					temp=pos1.back();
					pos1.pop_back();
					pos0.push_back(temp);
				}
			}
			else{
				if(pos0.empty()){
					pos1.push_back(temp);
				}
				else{
					temp=pos0.back();
					pos0.pop_back();
					pos1.push_back(temp);
				}
			}
			ans[i]=temp;
			mx=max(mx,ans[i]);
		}
		cout<<mx+1<<endl;
		for(int i=0;i<s.size();i++){
			if(i) cout<<" "<<ans[i]+1;
			else cout<<ans[i]+1;
		}
		cout<<endl;
	}
	
	
	return 0;
} 
