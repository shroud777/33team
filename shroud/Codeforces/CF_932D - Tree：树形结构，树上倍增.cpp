//题意：给出一颗初始只有一个权值为 0 的结点 1，当前有两种操作。第一种操作，新建一个 权重为 r 的 cnt+1 结点(cnt 代表当前树上结点个数)，第二种操作，查询 r 结点树链上的最长权重之和不超过 x 的非递减序列
//并且 r 向上找到第一个比它大的就要加入序列中

//思路；先从查询 1 入手，我们必然要找到第一个向上的比他大的祖先结点，如果暴力向上，那么复杂度会存在一些问题，我们要换一种思路，如果上一个结点比当前结点权值大，那么说明可以直接以它为序列下一个
//我们用倍增处理父节点关系，并且这里的父节点并不是单纯上一个结点，只是第一个权值比他大的祖先，那么如果当前插入结点比上一个结点小，那么我们就通过这个小的结点已经处理好的倍增信息向上找
//我们向上找，如果比插入的结点的权值小，就跳到那一个结点，因为说明这段路径上不可能存在权值比当前结点大的，一直倍增往上即可
//然后查询 2，我们在之前处理倍增信息的时候顺便预处理树上前缀和，这样我们用倍增和前缀和信息作为限制条件不断向上找界限即可

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
typedef long long ll;
const int maxn=4e5+10;
const int maxlog=22;
 
int q;
ll f[maxn][maxlog],w[maxn],nex[maxn],s[maxn];
 
 
int main(){
	scanf("%d",&q);
	ll opt,node,x,cnt=1,last=0;
	memset(f,-1,sizeof f);
	f[1][0]=0;
	while(q--){
		scanf("%lld %lld %lld",&opt,&node,&x);
		node=node^last,x=x^last;
		//cout<<node<<" "<<x<<endl;
		if(opt==1){
			nex[++cnt]=node;
			w[cnt]=x;
			int fa=node;
			if(w[fa]<w[cnt]){
				for(int i=19;~i;i--){
					if(f[fa][i]!=-1&&f[fa][i]!=0&&w[f[fa][i]]<x) fa=f[fa][i];
				}
				fa=f[fa][0];
			}
			f[cnt][0]=fa;
			s[cnt]=s[fa]+x;
			int i=1;
			while(~f[f[cnt][i-1]][i-1]){
				f[cnt][i]=f[f[cnt][i-1]][i-1];
				i++;
			}
		}
		else{
			int ans=0;
			for(int i=19;i>=0;i--){
				//cout<<node<<" "<<i<<" "<<f[node][i]<<" "<<s[node]-s[f[node][i]]<<endl;
				if(f[node][i]!=-1&&s[node]-s[f[node][i]]<=x){
					ans+=(1<<i);
					x-=s[node]-s[f[node][i]];
					node=f[node][i];
				}
			}
			printf("%lld\n",last=ans);
		}
	}
	return 0;
}
