//题意：给出一组序列 ai，每次可以交换相邻序号的值，每次交换的 a[x] 和 a[x+1] 的代价是 a[x]+a[x+1]，求使序列递增的最小代价

//思路：本来没看清楚，以为是任意位置交换。后来才发现是相邻位置交换，那么既然是相邻位置交换，我们可以按照序列的顺序来看，首先对于当前的数，肯定是跟前面的交换
//那么要使序列递增，肯定是一个向前换比他他的个数的过程了，所以我们只要看当前位置前面比他大的个数即可，即逆序对，但是我们依旧要使用两个树状数组，一个维护个数，一个维护值
//再说一下为什么这样的方案使最优的呢，首先你每次交换都是必须的，因为要递增，不可能有大的数在前面，同时对于当前位置 x，前面 x-1 个序列已经是递增的了，相当于你要把 x 插入到前 x-1 个有序序列
//不会出现和比自己小的交换之类的问题

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;
int n,tree_2[maxn];
ll tree_1[maxn];

inline int lowbit(int x){
	return x&-x;
}

inline void add(int x,ll k){
	while(x<=maxn){
		tree_1[x]+=k;
		tree_2[x]+=1;
		x+=lowbit(x);
	}
}

inline ll query_1(int x){
	ll ans=0;
	while(x){
		ans+=tree_1[x];
		x-=lowbit(x);
	}
	return ans;
}

inline int query_2(int x){
	int ans=0;
	while(x){
		ans+=tree_2[x];
		x-=lowbit(x);
	}
	return ans;
}

int main(){
	int x;
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		//cout<<query_2(n)<<" "<<query_2(x)<<endl;
		ans+=query_1(n)-query_1(x)+(query_2(n)-query_2(x))*1ll*x;
		add(x,x);
	}
	printf("%lld\n",ans); 
	return 0;
