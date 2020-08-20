//题意：存在 n 个点，m 条边，现在要从 1 到 n 号，并且所进过路途中最多可以选择 k 条边免费，只花费剩余边中最贵的那一条，求最小花费的方案

//思路：首先，我们可以根据题意得知，题目是要我们去找一条路径，使得其第 k+1 大路的边权最小
//这显然是一个比较复杂的问题，且具有后效性，这里有两种方法：
//1.分层图+SPFA
//其实这个做法就是属于 DP 思想，但不是在原图上进行，因为具有后效性，这里我们分层图原理，把图复制成 k+1 份
//我们用 DP[i][j] 表示第 i 个点，使用过 j 次免费后的最优解
//DP 的过程其实是借助 SPFA 迭代扩展的过程，从起点 (1,0) 到 (n,k) ，dp[i][j] 可以从 dp[k][j-1] 或 dp[k][j] 转移过来
//
//2.双端队列BFS+二分
//最少花费的大小和满足要求的路径成单调关系，因此可以是用二分答案，如果路径权值大于 mid，那么这条路花费就等于 1，否则等于 0，然后用 双端队列BFS 求得到 n 点的最短路，大小是否小于等于 k
//注意二分边界即可


//第一种
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
const int maxn=1e3+10;
const int maxm=1e4+10;

int n,m,k;
int dp[maxn][maxn],inq[maxn][maxn];
int head[maxn],to[maxm<<1],nex[maxm<<1],w[maxm<<1],tot=0;

inline void add(int x,int y,int z){
	to[++tot]=y;
	w[tot]=z;
	nex[tot]=head[x];
	head[x]=tot; 
}

void bfs(){
	queue<pii> q;
	q.push(pii(1,0));
	while(!q.empty()){
		pii t=q.front();
		q.pop();
		int u=t.first,cnt=t.second;
		inq[u][cnt]=0;
		for(int i=head[u];i;i=nex[i]){
			int v=to[i],d=w[i];
			if(dp[v][cnt]>max(dp[u][cnt],d)){
				dp[v][cnt]=max(dp[u][cnt],d);
				if(!inq[v][cnt]) inq[v][cnt]=1,q.push(pii(v,cnt));
			}
			if(cnt+1<=k&&dp[v][cnt+1]>dp[u][cnt]){
				dp[v][cnt+1]=dp[u][cnt];
				if(!inq[v][cnt+1]) inq[v][cnt+1]=1,q.push(pii(v,cnt+1));
			}
		}
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	int x,y,z;
	while(m--){
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	memset(dp,0x3f,sizeof dp);
	dp[1][0]=0;
	bfs();
	cout<<(dp[n][k]==INF?-1:dp[n][k])<<endl;
	return 0;
}

//第二种

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e3+10;
const int maxm=1e4+10;
int n,m,k;
int head[maxn],to[maxm<<1],nex[maxm<<1],w[maxm<<1],tot=0;
int dist[maxn];

inline void add(int x,int y,int z){
	to[++tot]=y;
	w[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
}

bool bfs_check(int x){
	memset(dist,0x3f,sizeof dist);
	deque<int> q;
	q.push_back(1);
	dist[1]=0;
	while(!q.empty()){
		int t=q.front();
		q.pop_front();
		for(int i=head[t];i;i=nex[i]){
			if(w[i]>x&&dist[to[i]]>dist[t]+1){
				dist[to[i]]=dist[t]+1;
				q.push_back(to[i]);
			}
			if(w[i]<=x&&dist[to[i]]>dist[t]){
				dist[to[i]]=dist[t];
				q.push_front(to[i]);
			}
		}
	}
	return dist[n]<=k;
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	int x,y,z;
	while(m--){
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	//mid 代表第 k+1 根电线的价格，比它贵的都要免费
	//如果免费的数量超过 k 就不可以 
	int l=0,r=1e6+5;
	int ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(bfs_check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	
	return 0;
} 
