//题意：对一个长度为 n 的 1-n 的无序全排列数组进行冒泡排序（从后往前的升序排序），问每个数在排序过程中出现的最左位置和最右位置的差

//思路：可以想到，从右往左的升序冒泡，就是把小的元素往左边冒，而对于一个在 pos 位置的数 p[pos]，我们可以想到他在最右的位置肯定是被所有在他右边且比他小的数交换后，也就是当前位置+右边比他小的数的个数
//那么最左位置就是他最开始的位置或是他应该去的位置（由于是1-n全排列，那么他是几就在第几个位置）的最小值，我们最需要用上述最右位置减去两个可能的最左位置即可
//我们可以选择用树状数组维护，从后往前遍历，每次在对应位置 +1，记录出现的数的个数和位置，这也是权值线段树的操作，这里为了方便就选择树状数组维护了，一个道理

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;
int tree[maxn],a[maxn],ans[maxn];
int n;

inline lowbit(int x){
	return x&-x;
}

inline void add(int x,int k){
	while(x<=n){
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

int main(){
	int t;
	scanf("%d",&t);
	int x;
	for(int T=1;T<=t;T++){
		memset(tree,0,sizeof tree);
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=n;i>=1;i--){
			ans[a[i]]=(i+query(a[i])-min(a[i],i));
			add(a[i],1);
		} 
		
		printf("Case #%d:",T);
		for(int i=1;i<=n;i++) printf(" %d",ans[i]);
		printf("\n");
	}
	
	return 0;
} 
