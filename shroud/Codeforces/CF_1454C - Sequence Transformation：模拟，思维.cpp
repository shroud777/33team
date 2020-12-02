//题意：给出一个长度为 n 的序列，现在可以选择一个 x，然后任意选择一个区间 [l,r]，且区间中的数不等于 x，这个操作可以执行任意次数直到序列全部为 x，问可能存在的最小次数是多少

//思路：形如  oxoxoxo 一类的，我们只需要清楚把 x 之间的，以及头尾的 o 清除即可，那么其实答案就是 x 块的个数（连续的 x 算一个块）-1，然后判断头尾是不是 x 就行了

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
		mp.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=a[i-1]) mp[a[i]]++;
		}
		map<int,int> ::iterator it;
		int ans=0x3f3f3f3f;
		for(it=mp.begin();it!=mp.end();it++){
			int id=it->first,cnt=it->second;
			cnt++;
			if(a[1]==id) cnt--;
			if(a[n]==id) cnt--;
			ans=min(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
