//题意：给出一个长度为 n 的 01 串，串中 '1' 和 '0' 的数量各为 n/2（n为偶数），现在可以对字符串作如下操作，选择一个区间 [l,r] 使得区间内的字符翻转，问最少进行多少次可以使得该 01 串变成 01 不连续的串

//思路：一般我们会想到把 "00" 和 "11" 这样的串作为基准来翻转，变成 "01" "01"，那么对于这些连续的 01 位置我们都可以这样操作，使得字符串达到要求，但是对于某些，例如 "0110" 这样的串
//连续的 '0' 和连续的 '1' 的数量不相同，那么我们只要去其中的最大值即可，再做几次翻转，那么答案就是 max(cnt1,cnt0)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;

int t,n,cnt[2];
string s;

int main(){
	scanf("%d",&t);
	while(t--){
		cin>>n>>s;
		cnt[0]=cnt[1]=0;
		for(int i=1;i<s.size();i++){
			if(s[i]==s[i-1]) cnt[s[i]-'0']++;
		}
		cout<<max(cnt[0],cnt[1])<<endl;
	}
	return 0;
}
