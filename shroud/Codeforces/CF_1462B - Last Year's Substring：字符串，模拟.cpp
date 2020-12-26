//题意：给出一个字符串，现在你可以执行至多一次如下操作：选择一个区间 [l,r]，并删除范围内的字符串，变成 s1s1...si-1sj+1..sn，问能否得到字符串 "2020"

//思路：首先要明确至多一次上述操作，我们只能对字符串的前缀，后缀做处理或删去中间部分的字符串，这样就代表，要想得到 "2020"，原字符串要么无用字符在前后缀，要么在中间
//那么就只有 5 种情况，2 种 "2020" 在前后缀，还有 3 种情况分别在中间

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
		bool f=0;
		for(int i=0;i<=4;i++){
			string temp=s.substr(0,i)+s.substr(n-4+i,4-i);
			if(temp=="2020"){
				f=1;break;
			}
		}
		if(f) puts("YES");
		else puts("NO");
	}
	
	return 0;
}
