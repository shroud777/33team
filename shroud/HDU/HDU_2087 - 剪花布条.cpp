//题意：给出字符串 A,B ，问能从 A 中切下多少个 B

//思路：KMP，匹配成功后直接主串下一位即可

#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int N=1e6+10;
string T,P;
int Next[1005];

void get_Next(){
	int plen=P.size();
	Next[0]=-1;
	int i=-1,j=0;
	while(j<plen){
		if(i==-1||P[i]==P[j]) Next[++j]=++i;
		else i=Next[i];
	}
}

int KMP(){
	int cnt=0;
	get_Next();
	int plen=P.size();
	int tlen=T.size();
	int i=0,j=0;
	while(j<tlen){
		if(i==-1||P[i]==T[j]){
			i++;j++;
			if(i==plen){
				cnt++;
				i=0;
			}
		}
		else i=Next[i];
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>T){
		if(T=="#") break;
		cin>>P;
		cout<<KMP()<<endl;
	}
	return 0;
}
