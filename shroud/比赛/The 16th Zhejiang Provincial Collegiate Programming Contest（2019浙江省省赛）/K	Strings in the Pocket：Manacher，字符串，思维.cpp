//题意：给出两个字符串，问在仅翻转其中一个字符串一个区间内的字符时，有多少种区间选择的方法使得两个字符串相等

//思维：首先对于两个字符串，如果不相等，那么我们要考虑那一块不相等的区间，由于只能翻转一次，那么我们以整个不相等的区间，整个反转，如果反转后字符串相等，说明至少有一种方法
//然后像两边扩展，如果是两边的字符相等就又多了一种方法，满足两边回文，一直这样扩展下去
//如果刚开始两个字符串就像等，就变成了找回文串的数量，那么可以用 Manacher 实现 O(n) 的查找数量

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e6+10;

string a,b;
ll ans;

void Manacher(string s){
	int slen=s.size();
	string t="$#";
	for(int i=0;i<slen;i++) t+=s[i],t+='#';
	t+='@';
	int tlen=t.size(),mx=0,c=0;
	vector<int> p(tlen,0);
	for(int i=1;i<tlen;i++){
		p[i]=mx>i?min(p[c*2-i],mx-i):1;
		while(t[i+p[i]]==t[i-p[i]]) p[i]++;
		if(i+p[i]>mx){
			mx=i+p[i];c=i;
		}
		ans+=p[i]/2;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>a>>b;
		if(a==b) Manacher(a);
		else{
			int l=0,r=a.size()-1;
			for(l; ;l++) if(a[l]!=b[l]) break;
			for(r; ;r--) if(a[r]!=b[r]) break;
			reverse(a.begin()+l,a.begin()+r+1);
			string t1=a.substr(l,r-l+1);
			string t2=b.substr(l,r-l+1);
			if(t1==t2){
				int i=1;
				while((l-i>=0)&&(r+i<a.size())&&a[l-i]==a[r+i]) i++;
				ans+=i;
			} 
		}
		cout<<ans<<endl;
	} 
	
	
	return 0;
} 
