//题意：给出一个长度为 n 的二进制串，要求构造一个长度相同的新二进制串，原理如下：给出整数 x，对于新二进制串的 i 位置，如果原串 i-x/i+x 的数字是 1，那么这个位置的新串字符就是 1，反之是 0
//现在给你一个新构造出的字符串，问原来的字符串是否存在合法的解

//思路：这道题反着来想，如果一个新的位置为 0，那么说明原字符串里 i+x 和 i-x 位置一定为 0，这些都是可以确定的，为 1 的部分没有强制要求，那么我们只需要通过现有的 0 构造出原字符串
//然后再检查新字符串的 '1' 能不能通过刚刚构造出的原字符串产生即可，如果发生冲突则说明这个新字符串无法满足，无法构造，反之输出即可

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
 
int n;
int a[maxn],b[maxn];
ll p,f,cnts,cntw,w;
string s; 
int x;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s>>x;
		int sz=s.size();
		string temp=string(sz,'1');
		for(int i=0;i<sz;i++){
			if(s[i]=='0'){
				if(i-x>=0) temp[i-x]='0';
				if(i+x<sz) temp[i+x]='0'; 
			}
		}
		bool f=1;
		bool ok;
		for(int i=0;i<sz;i++){
			if(s[i]=='1'){
				ok=0;
				if(i-x>=0&&temp[i-x]=='1') ok=1;
				if(i+x<sz&&temp[i+x]=='1') ok=1;
				if(!ok){
					f=0;
					break;
				}
			}
		}
		if(f) cout<<temp<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
