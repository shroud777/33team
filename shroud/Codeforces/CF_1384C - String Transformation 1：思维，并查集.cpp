//题意：给出两个字符串，每次操作可以将第一个字符串所有相同的字符变为大于它的同一种字符，问从第一个字符串变到第二个至少需要多少次

//思路：首先可以知道如果在同一位置第一个字符串的字符比第二个字符串大，那么说明肯定无法转换。否则第一种方法我们可以进行模拟，可以这么想，那些相同的 unfixed 字符至少要花一次变成各自的字符串
//那么他们首先都可以变成当前所有 unfixed 的目标里最小的那个，这样可以进行最优的模拟
//另一种做法就是并查集

//模拟做法
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	int n;
	string s1,s2;
	vector<int> g[25];
	while(t--){
		for(int i=0;i<21;i++) g[i].clear();
		cin>>n>>s1>>s2;
		bool f=1;
		for(int i=0;i<n;i++){
			if(s1[i]>s2[i]){
				cout<<"-1"<<endl;
				f=0;
				break;
			}
			if(s1[i]<s2[i]) g[s1[i]-'a'].push_back(s2[i]-'a');	
		}
		if(!f) continue;
		int ans=0;
		for(int i=0;i<20;i++){
			if(!g[i].size()) continue;
			int mi=0x3f3f3f3f;
			for(int j=0;j<g[i].size();j++) mi=min(mi,g[i][j]);
			for(int j=0;j<g[i].size();j++){
				if(g[i][j]==mi) continue;
				g[mi].push_back(g[i][j]);
			}
			ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 

//并查集
#include <bits/stdc++.h>
using namespace std;
int fa[26];
 
void init(){
	for(int i=0;i<20;i++) fa[i]=i;
}
 
inline find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]); 
}
 
int main(){
	int t;
	cin>>t;
	int n;
	string s1,s2;
	while(t--){
		init();
		cin>>n>>s1>>s2;
		bool f=1;
		int ans=0;
		for(int i=0;i<n;i++){
			if(s1[i]>s2[i]){
				f=0;break;
			}
			int a=find(s1[i]-'a');
			int b=find(s2[i]-'a');
			if(a!=b){
				fa[a]=b;
				ans++;
			}
		}
		if(!f) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
} 
