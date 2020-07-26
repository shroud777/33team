//题意：给定字符串 s ，你可以在 s 中删除任意字符后，随便安排每个字符的位置得到字符串 t ，给出数组 b ，长度与 t 相对应，bi 代表字符串第 i 位与字符串中所有字典序比他大的字符的距离之和
//即 bi 代表字符串 ti （设定字符串下标从 1 开始）与所有 tj（ti < tj）的 |i-j| 的和
//从 s 中得到满足 b 数组的字符串 t

//思路：第一次看到题感觉数据量也很小，打算直接用 DFS 来做，因为刚开始认为 b 数组和 t 上的字符大小有一定关系（确实有关系，但不是绝对单调的关系），然后对升序后的 b 数组，并对 s 中的字符降序排列
//每次将当前最大的那一位字符放到 c 位置，暴力判断可不可行，然后发现这样做事有问题的！！！！！！因为 t 中较小的字符在 b 中的值是取决于比他大的字符的
//举个例子题目中的 例子
/*
ecoosdcefr
10
38 13 24 14 11 5 3 24 17 0
*/
//按照顺序先后放好 s r o 之后发现下一个 r 不能放在当前 b 数组，按照上面的做法我就应该放 f 了，按照最后的结果，f是可以放在这里的，但是由于我之前那个 o 由于他在 b 数组中值在 f 后面，所以他出现在 f 后面
//但在暴力判断 f 放在这个位置可不可行的时候，这个 o 也是要起作用的，所以显然不行
//然后换一种方法，也是正确的第一种方法，这一次过我是没想到的，我从字符位置开始枚举，先把字典序大的找位置塞进去，但是这又会出现一个问题，有些字符是真的不需要的，如果一定要把他放完再放下一个，那就不行可
//这里我又加一个 dfs 入口：dfs(cnt-1,cmp,tot); 这里对于的参数分别是 s中的位置 判断的字符串 已经成功插入的个数， cnt-1 但是这里 tot 不变，代表直接跳过这个字符



//然后还有第二种官方题解做法，这里可以思考，当前 b 数组中肯定会有为 0 的，因为总有最大的，或者几个都相等都等于 0，我们就可以先找出这个为 0 的，他们代表的字符肯定是一样的
//然后想想，那些不是 bi 位置上不等于 0 的，为什么不等于 0 ？因为有比他们大的字符存在，而这其中就存在当前这些是 0 的，这样我们可以先消去这些已经是 0 的位置对其他非 0 位置的贡献
//这里我们肯定可以得出下一批等于 0 的，没有为什么，想想 b 不等于 0，是因为有字符比他们大，那么最大的那批没了，并消除了他们对其他字符串的贡献，次大的那一批肯定会显露出来，这样就清楚了
//这里我用的是 vector<vector<int> > v 的嵌套，内层每一维代表某一个字符他在不同位置的散布
//所以最后我们只需要用 map 统计 s 中字符出现的个数，从最大的开始匹配对应，如果 v[i]代表当前最大的那批字符的位置，我们从后往前遍历 map，最先遍历到的是最大字符的个数，如果 v[i].size() 比当前遍历的字符数少或者相等
//就代表仅用 s 里的字符，就可以填充当前这个位置，反正就是这么回事，看看代码就清楚了，还有 map 的 begin 对于 end  ，rbegin 是逆向迭代器，对应的是 rend

//DFS，没想到1800的题一发就过了，虽然做的有点久，但还是很爽的
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii; 
const int maxn=2e5+10;
string s,sans;
int m,t,vis[55];
pii b[55];
bool check(int mpos,int cnt,string cmp){
	int t=0;
	int pos=b[mpos].second;
	for(int i=0;i<cmp.size();i++){
		t+=(cmp[i]>s[cnt]?abs(pos-i):0);
	}
	if(t==b[mpos].first) return true;
	return false;
}
bool f;
void dfs(int cnt,string cmp,int tot){
	if(tot==m){
		sans=cmp;
		f=1;
		return;
	}
	//cout<<tot<<" "<<cmp<<endl;
	for(int i=1;i<=m;i++){
		if(f) return;
		if(vis[i]) continue;
		if(check(i,cnt,cmp)){
			char temp=cmp[b[i].second];
			cmp[b[i].second]=s[cnt];
			vis[i]=1;
			dfs(cnt-1,cmp,tot+1);
			cmp[b[i].second]=temp;
			vis[i]=0;
			dfs(cnt-1,cmp,tot);
		}
	}
	
}
int main(){
	cin>>t;
	while(t--){
		f=0;
		memset(vis,0,sizeof vis);
		cin>>s>>m;
		int v;
		for(int i=1;i<=m;i++){
			cin>>v;
			b[i]=pii(v,i-1);
		}
		sort(b+1,b+1+m);
		sort(s.begin(),s.end());
		dfs(s.size()-1,string(m,'a'),0);
		cout<<sans<<endl;
	} 
	return 0;
}

//第二种，巧妙一点
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int n,b[55];
int main(){
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s>>n;
		for(int i=1;i<=n;i++) cin>>b[i];
		vector<vector<int> >v;
		while(1){
			vector<int> t;
			for(int i=1;i<=n;i++){
				if(!b[i]) t.push_back(i);
			}
			if(t.empty()) break;
			v.push_back(t);
			for(int i=1;i<=n;i++){
				if(!b[i]) b[i]=INF;
				else {
					for(int j=0;j<t.size();j++){
						b[i]-=abs(i-t[j]);
					} 
				}
			}
		}
		map<char,int> mp;
		for(int i=0;i<s.size();i++) mp[s[i]]++;
		map<char,int>::reverse_iterator it=mp.rbegin();
		string ans=string(n,'!');
		for(int i=0;i<v.size();i++){
			while(it->second<v[i].size()) it++;
			for(int j=0;j<v[i].size();j++){
				ans[v[i][j]-1]=it->first;
			}
			it++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
