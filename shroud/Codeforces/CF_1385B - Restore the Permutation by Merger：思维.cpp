//题意：给出一个长度为 n 的全排列，再复制一个完全相同的全排列，不改变原先顺序的情况下将第二个插入到第一个，长度为 2*n ，求原本的全排列是什么

//思路：不改变原本的顺序，那么他这个 2*n 的序列里每次第一次出现的元素肯定就是原本的序列

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int maxn=5e5+10;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map<int,int> mp;
		vector<int> ans;
		int num;
		for(int i=1;i<=2*n;i++){
			cin>>num;
			if(!mp[num]){
				ans.pb(num);
				mp[num]++;
			}
		}
		cout<<ans[0];
		for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
		cout<<endl;
	}
	return 0;
}
