//题意：给出 n 个字符串，其中包含一个 origin 字符串和 n-1 个普通字符串（origin 不固定，按照要求选择即可），每个字符串除 origin 字符串外都有一个前继（也是不固定）
//一个字符串的花费是指他和他前继字符串的每个位置上不相同字符的总数，请求出所有字符串的花费之和（origin没有花费）

//思路：每个字符串可以看成一个点，然后花费就是两两之间的边，并且题目要求符合树形结构，所以只需按照给定要求构建最小生成树即可

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2005;
int n,m;
char s[maxn][10];
struct node{
	int u,v,w;
	bool operator <(const node other) const{
		return w<other.w;
	}
}g[maxn*maxn/2];

int fa[maxn];
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

inline int check(string s1,string s2){
	int cnt=0;
	for(int i=0;i<7;i++) if(s1[i]!=s2[i]) cnt++;
	return cnt;
}

int main(){
	while(scanf("%d",&n)!=EOF&&n){
		int tot=0;
		for(int i=1;i<=n;i++){
			scanf("%s",&s[i]);
			fa[i]=i;
		}
		for(int i=1;i<=n;i++){
	        for(int j=i+1;j<=n;j++){
	        	int cnt=0;
	           for(int k=0;k<7;k++)
	                cnt+=(s[i][k]!=s[j][k]);
	            g[++tot].u = i;
	            g[tot].v = j;
	            g[tot].w = cnt;
	        }
	    }
		sort(g+1,g+tot+1);
		m=n-1;
		int cnt=0,cost=0;
		for(int i=1;i<=tot;i++){
			int u=g[i].u,v=g[i].v;
			u=find(u);
			v=find(v);
			if(u==v) continue;
			fa[u]=v;
			cost+=g[i].w;
			if(++cnt==m) break; 
		}
		printf("The highest possible quality is 1/%d.\n",cost);
	}
	return 0;
} 
