//题意：最小生成树模板

//思路：Boruvka算法求最小生成树

//Boruvka 求最小生成树，是 Prim 和 Kruskal 的结合
//相比于 Prim的单路增广，Boruvka 是多路增广，每次每个连通块都要找到最小花费的连通其他不在生成树里的路径
//边数为 M，每次合并的复杂度为 O(M)，且每次合并的连通块少一半，这样一来总复杂度就是 O(logN*M) 了 
#include <bits/stdc++.h>

using namespace std;
const int maxn=5e3+10;
const int maxm=2e5+10;

int u[maxm],v[maxm],w[maxm];
int fa[maxn],best[maxn],used[maxm];  //best数组代表对于每个连通块来说的最短边，used数组代表某条边是否用过 
int n,m;


void init_DSU(){
	for(int i=1;i<=n;i++) fa[i]=i;
}

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]); 
}

int main(){
	scanf("%d %d",&n,&m);
	init_DSU();
	for(int i=1;i<=m;i++) scanf("%d %d %d",&u[i],&v[i],&w[i]);
	bool f=1;
	int sum=0,cnt=0;
	w[0]=0x3f3f3f3f;
	while(f){
		f=0;
		memset(best,0,sizeof best);
		for(int i=1;i<=m;i++){               //枚举每一条边，如果边两端的连通块未合并，就判断是否用这条边作为两边连通块的最短边
			if(used[i]) continue;
			int ru=find(u[i]),rv=find(v[i]); //连通块找祖宗结点 
			if(rv==ru) continue;
			if(w[best[rv]]>w[i]) best[rv]=i;
			if(w[best[ru]]>w[i]) best[ru]=i;
		}
		//for(int i=1;i<=n;i++) cout<<best[i]<<endl;
		for(int i=1;i<=n;i++){
			if(best[i]&&!used[best[i]]){     //遍历每一个点，这里为什么要这样做首先，如果我们用 used[[best[fa[i]]] 来判断的话显然一个结点会多次判断 
				used[best[i]]=1;			 //这样就需要很多信息去维护，或者我们只遍历连通块也很麻烦，所以我们选择遍历 n 个点 
				cnt++;						 //这样间接地代表我们访问了每个现有的连通块，因为只有祖宗结点有记录 best[i] 
				f=1;
				sum+=w[best[i]];
				fa[find(u[best[i]])]=find(v[best[i]]);
			}
		}
	} 
	if(cnt==n-1) printf("%d\n",sum);
	else puts("orz");
	return 0;
}
