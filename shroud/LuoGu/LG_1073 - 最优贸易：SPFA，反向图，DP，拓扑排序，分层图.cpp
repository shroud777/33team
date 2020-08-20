//题意：给出一个图，存在 n 个点，m 条边（可能单向也可能双向），每个点有一个物价，商人要从 1 号点走到 n 号点，他可以在路途中按照物价购买一个水晶球，在之后经过的某个点卖掉它赚取差价，求最大差价

//思路：这题做法很多，先介绍一种：
//1.反向建图后进行正反两次 SPFA 分别得到某个点的最大和最小值（正向 SPFA 求最小，反向 SPFA 求最大），然后枚举点得到最大差值
//
//2.分层图思想，分成三层图，第一层走到第二层代表买入一个东西，第二层到第三层代表卖出一个东西，同时要将第一层的  n 和 第三层的 n 相连，代表没有买东西直接走的情况，然后跑最大路，找出最佳方案


//做法1

	head_1[u]=tot1;
}

inline void add_2(int u,int v){
	to_2[++tot2]=v;
	nex_2[tot2]=head_2[u];
	head_2[u]=tot2;
}

void SPFA_1(){
	memset(mi,0x3f,sizeof mi);
	queue<int> q;
	q.push(1);
	mi[1]=a[1];
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head_1[u];i;i=nex_1[i]){
			int v=to_1[i];
			if(mi[v]>min(mi[u],a[v])){
				mi[v]=min(mi[u],a[v]);
				q.push(v);
			}
		}
	}
} 

void SPFA_2(){
	memset(mx,0,sizeof mx);
	queue<int> q;
	q.push(n);
	mx[n]=a[n];
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head_2[u];i;i=nex_2[i]){
			int v=to_2[i];
			if(mx[v]<max(mx[v],a[v])){
				mx[v]=max(mx[v],a[v]);
				q.push(v);
			}
		}
	}
}


int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int u,v,k;
	while(m--){
		scanf("%d %d %d",&u,&v,&k);
		if(k==1){
			add_1(u,v);
			add_2(v,u);
		}
		else{
			add_1(u,v);
			add_1(v,u);
			add_2(u,v);
			add_2(v,u);
		}
	}
	SPFA_1();
	SPFA_2();
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,mx[i]-mi[i]);
	cout<<ans<<endl;
	return 0;
}


//做法2
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+10;
const int maxm=5e5+10;
int head[maxn*4],to[maxm*15],w[maxm*15],nex[maxm*15],tot=0;
int a[maxn];
int dist[maxn*4],inq[maxn*4];
int n,m;

void SPFA(){
	memset(dist,-0x3f,sizeof dist);
	queue<int> q;
	q.push(1);
	dist[1]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];i;i=nex[i]){
			int v=to[i];
			if(dist[v]<dist[u]+w[i]){
				dist[v]=dist[u]+w[i];
				pre[v]=u;
				if(!inq[v]){
					q.push(v);
					inq[v]++;
				}	
			}
		} 
	}
} 

inline void add(int u,int v,int d){
	to[++tot]=v;
	w[tot]=d;
	nex[tot]=head[u];
	head[u]=tot;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int u,v,k;
	while(m--){
		scanf("%d %d %d",&u,&v,&k);
		if(k==1){
			for(int i=0;i<3;i++) add(u+i*n,v+i*n,0);
			add(u,v+n,-a[v]);
			add(u+n,v+n*2,a[v]);
		}
		else{
			for(int i=0;i<3;i++) add(u+i*n,v+i*n,0),add(v+i*n,u+i*n,0),
			add(u,v+n,-a[v]);
			add(v,u+n,-a[u]);
			add(u+n,v+2*n,a[v]);
			add(v+n,u+2*n,a[u]);
		}
	}
	add(n,n*3,0);
	SPFA();
	cout<<dist[n*3]<<endl;
	return 0;
}
