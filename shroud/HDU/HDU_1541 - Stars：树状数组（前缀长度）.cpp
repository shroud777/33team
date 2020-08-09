//题意：给出 n 个点在二维平面上的坐标 (xi,yi)（以 yi 为第一关键字升序，xi 为第二关键字升序给出），规定每个点的 level 为所有 xi<=x，yi<=y 的点的个数，分别输出 level 为 0-n-1 的个数

//思路：首先题目中给出的坐标是排序后的，不过即便不是如此，我们也要对数据进行排序，可以这样想：
//某个点的 level 与那些 x 和 y 坐标值都小于它的点的数量有关，其实就是一个 (0,0)-(x,y) 的矩形内的点的个数，那么我们只需要在递增的 x 和 y 序列，不断记录点和统计当前矩形内的点的个数即可
//因为是坐标大小是递增的，后放的肯定进不了前放的的矩形中，也就和前面的 level 没关系了，同时这个看似是二维，其实就是一个一维的区间和统计，因为后放的对当前统计的区间不可能有影响，后放的y 相同的话 x 肯定大于当前的，y 不同的话肯定更不用说了
//所以直接树状数组维护，线段树也可以，但是这题其实没必要，常数大而且写起来麻烦多

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=4e4+10;
int n,x[maxn>>1],y,maxx;
int tree[maxn],cnt[maxn>>1];

inline int lowbit(int x){
	return x&(-x);
}

inline void add(int x,int k){
	while(x<=maxx){
		tree[x]+=k;
		x+=lowbit(x);
	}
}

inline int query(int x){
	int ans=0;
	while(x){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}

#define max(i,j) i>j?i:j

int main(){
	while(~scanf("%d",&n)&&n){
		maxx=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&x[i],&y);
			x[i]+=1;
			maxx=max(x[i],maxx);
		}
		for(int i=1;i<=maxx;i++) tree[i]=0;
		for(int i=0;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++){
			cnt[query(x[i])]++;
			add(x[i],1);
		}
		for(int i=0;i<n;i++) printf("%d\n",cnt[i]);
	}
	
	return 0;
}
