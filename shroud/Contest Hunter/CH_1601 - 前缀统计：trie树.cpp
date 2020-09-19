//题意：给出 n 个字符串，进行 m 次查询，每次询问给出一个字符串，求 n 个字符串中有多少个字符串是该字符串的前缀

//思路：Trie树模板

#include <bits/stdc++.h>

using namespace std;	
typedef long long ll;
const int maxn=1e6+10;

int trie[maxn][26];
int n,m,tot=1;
char s[maxn];
int ed[maxn];

void insert(char *str){
	int len=strlen(str),p=1;
	for(int i=0;i<len;i++){
		int t=str[i]-'a';
		if(!trie[p][t]) trie[p][t]=++tot;
		p=trie[p][t];
	}
	ed[p]++;
}

int search(char *str){
	int len=strlen(str),p=1,cnt=0;
	for(int i=0;i<len;i++){
		int t=str[i]-'a';
		if(!trie[p][t]) return cnt;
		p=trie[p][t];
		cnt+=ed[p];
	}
	return cnt;
}

int main(){
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		getchar();
		insert(s);
	}
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		getchar(); 
		printf("%d\n",search(s));
	}
	return 0;
}
