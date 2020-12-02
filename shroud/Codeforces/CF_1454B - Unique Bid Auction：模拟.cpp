//题意：给出一个长度为 n 的序列，现在要求输出一个序列中最小的且独一无二的数

//思路：记录每个数出现个数，然后从小到大遍历即可，如果有出现一次的就输出并记录存在解

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
 
int n,t,a[maxn],vis[maxn];
map<int,int> mp;
 
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		bool f=0;
		mp.clear();
		int mx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mp[a[i]]++;
			vis[a[i]]=i;
			mx=max(mx,a[i]);
		}
		for(int i=1;i<=n;i++){
			if(mp[i]==1){
				cout<<vis[i]<<endl;
				f=1;break;
			}
		}
		if(!f) cout<<-1<<endl;
	}
	
	return 0;
} 
