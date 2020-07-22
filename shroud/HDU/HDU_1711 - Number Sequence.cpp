//题意：给定两个数字序列 A,B 求 B 是否为 A 的子串

//思路：KMP

#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int M=1e4+10;
int T[N],P[M];
int Next[M];
int n,m;

void get_Next(){
	Next[0]=-1;
	int i=-1,j=0;
	while(j<m){
		if(i==-1||P[i]==P[j]) Next[++j]=++i;
		else i=Next[i];
	}
}

int KMP(){
	get_Next();
	int i=0,j=0;
	while(i<m&&j<n){
		if(i==-1||P[i]==T[j]){
			i++;j++;
		}
		else i=Next[i];
	}
	if(j==n&&i!=m) return -1;
	return j-m+1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++) cin>>T[i];
		for(int i=0;i<m;i++) cin>>P[i];
		cout<<KMP()<<endl;
	}
	return 0;
}
