//题意：给出一个 01 串，对于 s[i]='1',s[i+1]='0' 这样的连续串，可以消除其中的一个字符，并且操作后字符串会变短
//现在要求在作若干次操作后，字符串在尽量短的情况下字典序最小，求最后的结果

//思路：首先要明确，根据题意，我们无法对非递减的字符串作任何操作，那么答案就是原字符串本身
//接着我们可以发现我们无法处理前导 '0' 和所有的连续后缀 '1'，那么对于原字符 s，我们把他抽象成 s="00000"+ s' + "111111"
//对于中间的 s'，必然是 '1' 开头，'0' 结尾，那么我们可以根据题意，把他们全部剔除，最后只剩下 "10"，根据题意我们只需要剩下 '0' 即可
//所以最后的字符串就是 "00000"+ '0' + "111111"
//直接找第一位 1 和最后一位 0 的位置即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n;
string s;

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>s;
		int l=n,r=-1;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				l=i;break;
			}
		}
		for(int i=n-1;i>=0;i--){
			if(s[i]=='0'){
				r=i;break;
			}
		}
		string ans;
		if(l<r) ans=s.substr(0,l)+s.substr(r,n-r);
		else ans=s;
		cout<<ans<<endl;
	}

	return 0;
}
