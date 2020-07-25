//题意：给定一个字符串 s，求最少增添几个字符使该字符串中有数量大于 1 的循环节

//思路：len 为字符串的长度，当 len-Next[len] 能被 len 整除时，最长循环节长度为 len-Next[len]，那么如果满足条件输出 0 即可
//不满足则可以发现构造最小循环节的最小加入字符串长度应该是 len-Next[len]-len%(len-Next[len])  abccab  最小循环节 abcc,当前 ab 需要添加 cc 使其满足

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int Next[maxn];
int len;
char s[maxn];

void get_Next(){
	Next[0]=-1;
	int i=-1,j=0;
	while(j<len){
		if(i==-1||s[i]==s[j]) Next[++j]=++i;
		else i=Next[i];
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		len=strlen(s);
		get_Next();
		int c=len-Next[len];
		if(c==len){
			cout<<len<<endl;
			continue;
		}
		if(len%c==0) cout<<0<<endl;
		else cout<<c-len%c<<endl;
	}
	return 0;
} 
