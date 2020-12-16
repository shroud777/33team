//题意：有一颗 n 个结点的树，每条边代表一个字符，给出一个字符串，问树上是否存在一条简单路径，使得路径上字符构成的字符串中包含给出的字符串（可以不连续）

//思路：树形dp，记录四个状态，
//1.当前子树 u 中，对于给出字符串从左到右最多匹配的字符个数
//2.当前子树 u 中，对于给出字符串从右到左最多匹配的字符个数
//3.当前子树 u 中，对于给出字符串从左到右最多匹配的字符个数的起点
//4.当前子树 u 中，对于给出字符串从右到左最多匹配的字符个数的起点
//那么发现这题变得十分容易，我们只需要判断状态 1 和 2 的数量是否大于等于给出字符串的长度即可
//同时我们需要在更新状态之前判断，不然可能最优状态转移来自同一条链，我们要在未被当前链更新之前判断是否可行

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
 
int n,m,p1,p2;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
char w[maxn<<1];
string s;

struct node{
	int l,r,ls,rs;
}dp[maxn];
 
inline void add(int u,int v,char c){
	to[++tot]=v;
	w[tot]=c;
	nex[tot]=head[u];
	head[u]=tot;
}
 
void dfs(int u,int fa){
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		dfs(v,u);
		int l=dp[v].l+(s[dp[v].l]==w[i]);
		int r=dp[v].r+(s[m-dp[v].r-1]==w[i]);
		if(l+dp[u].r>=m) p1=dp[v].ls,p2=dp[u].rs;
		else if(r+dp[u].l>=m) p1=dp[u].ls,p2=dp[v].rs;
		if(l>dp[u].l) dp[u].l=l,dp[u].ls=dp[v].ls;
		if(r>dp[u].r) dp[u].r=r,dp[u].rs=dp[v].rs;
	}
}

int main(){
	scanf("%d %d",&n,&m);
	int u,v;
	char c;
	for(int i=1;i<n;i++){
		scanf("%d %d %c",&u,&v,&c);
		add(u,v,c);
		add(v,u,c);
		dp[i].ls=dp[i].rs=i; 
	} 
	cin>>s;
	dp[n].ls=dp[n].rs=n; 
	p1=p2=-1;
	dfs(1,0);
	cout<<p1<<" "<<p2<<endl;
	return 0;
}
