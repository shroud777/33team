//题意：给出一定数量的有向边的两端，在结束后判断最后构成的是不是树？

//思路；首先构成树的话所有点要联通，然后只有一个根，即只要一个点的入度为 0，其他点的入度都为 1，同时不能存在环一类的
//其实这些都能用并查集和边和点都关系来判断，首先对于自环或者入度大于 2 的点，我们完全可以只依靠并查集，因为这两种情况都会出现 find(u)==find(v) 的情况
//然后就是构成树的情况，是不是只要一个根，我们只要看 边数是否等于点数 -1 即可，因为类似森林或其他情况都是不满足此条件，同时因为上述并查集的存在，不会存在特殊情况
//最后大小为 0 的树判断一下即可

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+10;

int n;
int fa[maxn];

inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

set<int> s;

int main(){
	int u,v,T=0;
	bool f=1;
	int cnt=0;
	for(int i=1;i<=maxn;i++) fa[i]=i;
	while(scanf("%d %d",&u,&v)){
		if(u==-1&&v==-1) break;
		if(u==0&&v==0){
			if(cnt+1!=s.size()&&cnt!=0) f=0;
			if(f) printf("Case %d is a tree.\n",++T);
			else printf("Case %d is not a tree.\n",++T);
			for(int i=1;i<=maxn;i++) fa[i]=i; 
			f=1;
			cnt=0;
			s.clear();
			continue;
		}
		if(!f) continue;
		s.insert(u),s.insert(v);
		u=find(u),v=find(v);
		if(u==v){
			f=0;continue;
		}
		fa[u]=v;cnt++;
	}
	return 0;
} 
