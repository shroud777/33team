//题意：给出一张 n 个点 m 条边的无向图，求出无向图的一棵最小生成树，且满足 1 号结点的度数不超过 k

//思路：典型的最小k限度生成树，即某个点的度数有限制
//一开始这道题我是想按照 Kruskal 的思想，在建立最小生成树的同时注意 1 号点的度数限制，但是发现这样其实是不正确的，样例存在，尽量往由于贪心的选边，最终导致限度到达上限，但是却没形成生成树
//这道题的正确解是构造 m-限度生成树，m 是去除 1 号点后联通快的数量，然后从 m-限度生成树迭代到 m+1-限度生成树....k-限度生成树
//最开始 m-限度生成树是通过求 m 个联通块内的最小生成树，然后找出每个联通快到 1 号点的最小边
//然后迭代的过程是找从 1 出发的非树边 (1,x,z) ，然后这条边必然能和原来的生成树构成一个环，环就是 1 -> x -> 1,然后从环上找出不与 1 连接（因为选择与 1 链接的会影响当前限度）的最大边
//找出所有这些边的最大差值，然后删除原来的边，增加新边到生成树上，这样迭代 k-m 次，或者某次差值小于等于 0 的时候退出即可
//由于这里判断的内容比较多，每一轮应该用动态规划预处理出最优解
//注意细节，这题码量有点大，细节也多

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=25;
const int maxm=5e3+10;

struct node{
	int u,v,w,id;
	bool operator <(const node &oth)const{
		return w<oth.w;
	}
}a[maxm];
int n;
int head[maxn],to[maxm],nex[maxm],w[maxm],tot=0;
int in[maxm];
int fa[maxn+5];
int mi[maxn],t[maxn];
pii dp[maxn];

inline void add(int u,int v,int d){
	to[++tot]=v;
	w[tot]=d;
	nex[tot]=head[u];
	head[u]=tot;
}

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int Kruskal(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].u==1||a[i].v==1) continue;
		int ru=find(a[i].u),rv=find(a[i].v);
		if(ru==rv) continue;
		in[a[i].id*2]=in[a[i].id*2-1]=1;
		ans+=a[i].w;
		fa[ru]=rv;
	}
	return ans;
}

void bfs(int u,int rt){
	queue<int> q;
	q.push(u);
	fa[u]=rt;
	while(!q.empty()){
		int temp=q.front();
		q.pop();
		for(int i=head[temp];i;i=nex[i]){
			int j=to[i];
			if(fa[j]==-1||fa[j]==rt) continue;
			fa[j]=rt;
			q.push(j);
		}
	}
}

void dfs(int u,int f){
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==f||!in[i]) continue;
		if(u==1){
			dfs(v,u);continue;
		}
		if(dp[v].first<dp[u].first){
			dp[v].first=dp[u].first;
			dp[v].second=dp[u].second;
		}
		if(dp[v].first<w[i]){
			dp[v].first=w[i];
			dp[v].second=i;
		}
		dfs(v,u);
	}
}

inline void modify(int pos,int k){
	if(pos&1) in[pos]=in[pos+1]=k;
	else in[pos]=in[pos-1]=k;
}

map<string,int> mp;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n;
	int m=0,ans=0,s;
	mp["Park"]=++m;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2>>a[i].w;
		a[i].id=i;
		a[i].u=(mp[s1]?mp[s1]:mp[s1]=++m);
		a[i].v=(mp[s2]?mp[s2]:mp[s2]=++m);
		add(a[i].u,a[i].v,a[i].w);
		add(a[i].v,a[i].u,a[i].w);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=maxn;i++) fa[i]=i;
	ans+=Kruskal();
	memset(fa,0,sizeof fa);
	fa[1]=-1;
	int cnt=0;
	for(int i=2;i<=m;i++) if(!fa[i]) bfs(i,++cnt);
	memset(mi,0x3f,sizeof mi);
	for(int i=head[1];i;i=nex[i]){
		int c=fa[to[i]];
		if(w[i]<mi[c]){
			mi[c]=w[i];
			t[c]=i;
		}
	}
	for(int i=1;i<=cnt;i++){
		ans+=mi[i];
		modify(t[i],1);
	}
	cin>>s;
	for(int i=1;i<=s-cnt;i++){
		memset(dp,0,sizeof dp);
		dfs(1,0);
		int res=0,add,del;
		for(int j=head[1];j;j=nex[j]){
			if(in[j]) continue;
			int v=to[j];
			if(res<dp[v].first-w[j]){
				res=dp[v].first-w[j];
				add=j;
				del=dp[v].second;
			}
		}
		if(!res) break;
		modify(add,1);
		modify(del,0);
		ans-=res;
	}
	cout<<"Total miles driven: "<<ans<<endl;
	return 0;
}
