//题意：给出一颗 n 个结点的树，n-1 条树边都存在一个权值，你每次操作可以选择任意一条树边使其权值变为 w/2（向下取整），问最少经过几次操作能使得根节点（1号）到所有叶结点的边权值之和小于等于 S

//思路：这道题显然是用贪心的思想去思考，既然是对每条边进行操作，那么我们肯定优先去选择边权贡献比重比较大的，但是怎么去判断他的贡献呢？
//我们发现从根节点到叶结点肯定会经过一些边，那么一条边的子树的叶结点也就是他对于题目要求的和的贡献次数，那么可以知道他的贡献就是 w*cnt（边权大小*子树中叶结点的数量）
//但是这里的贡献不能这样判断，因为我们是优先对每次操作能削减更多的贡献，由于每次操作是取一半并且是向下取整的，那么贡献与叶结点的数量和边权大小都有关系
//那么我们只要得出每次操作所产生的的影响，即使我们所要找的贡献，即 w*cnt-w/2*cnt，利用优先队列维护，每次找出最大贡献的边，然后操作后再放入堆中维护，直到边权总和小于等于 S

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;

int head[maxn],to[maxn<<1],nex[maxn<<1],sz[maxn],tot=0;
ll w[maxn<<1],s,res;
int n;

struct node{
	int num;
	ll weight,val;
	node(int a,ll b){
		num=a,weight=b,val=(weight-(ll)(weight/2))*num;
	}
	bool operator <(const node &oth)const{
		return val<oth.val;
	}
};

inline void add(int u,int v,ll d){
	to[++tot]=v;
	w[tot]=d;
	nex[tot]=head[u];
	head[u]=tot;
}

priority_queue<node> q;

void dfs(int u,int fa){
	int cnt=0; 
	for(int i=head[u];i;i=nex[i]){
		if(to[i]==fa) continue;
		cnt++;
		dfs(to[i],u);
		sz[u]+=sz[to[i]];
		q.push(node(sz[to[i]],w[i]));
		res+=sz[to[i]]*w[i];
	}
	if(!cnt) sz[u]=1;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++) head[i]=0,sz[i]=0;
		tot=0;
 		scanf("%d %lld",&n,&s);
		int u,v;
		ll d;
		for(int i=1;i<n;i++){
			scanf("%d %d %lld",&u,&v,&d);
			add(u,v,d);
			add(v,u,d);
		}
		res=0;
		ll cnt=0;
		dfs(1,0);
		while(res>s){
			node temp=q.top();
			q.pop();
			cnt++;
			res-=temp.val;
			temp.weight/=2;
			temp.val=(temp.weight-(ll)(temp.weight/2))*temp.num;
			q.push(temp);
		}
		cout<<cnt<<endl;
	}
	return 0;
}
