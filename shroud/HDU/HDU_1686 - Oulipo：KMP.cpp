//题意：给出字符串 A，B 求 B 在 A 中出现的子串的数量

//思路：KMP，如果每次匹配成功，主串指针回溯到 t-plen+1 位置，肯定会超时
//但是根据 Next 数组，如果当前匹配成功了，那么其实这一段的最长公共真前后缀已经确定了，主串的指针依旧不用动，直接将模式串指针回溯到 Next[i] 位置即可，极端情况就直接回到模式串最后一位。

#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int N=1e6+10;
string T,P;
int Next[maxn];
int cnt;

void get_Next(){
	Next[0]=-1;
	int i=-1,j=0;
	int plen=P.size();
	while(j<plen){
		if(i==-1||P[i]==P[j]) Next[++j]=++i;
		else i=Next[i];
	}
}

void KMP(){
	cnt=0;
	get_Next();
	int tlen=T.size(),plen=P.size();
	int i=0,j=0;
	while(j<tlen){
		if(i==-1||P[i]==T[j]){
			i++;j++;
			if(i==plen){
				cnt++;
				i=Next[i];
			}
		}
		else i=Next[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>P>>T;
		KMP();
		cout<<cnt<<endl;
	}
	return 0;
}
