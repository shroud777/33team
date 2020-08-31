//题意：给出一个长度为 n 的序列，每次操作可以把某个元素放到序列的最前面，问最少多少次可以使序列非递减

//思路：首先我们肯定是将那些破坏非递减性质的元素往前移动，这样使改变后的那段序列满足性质。
//但是可以发现如果移动的元素比序列头部元素大，那么又要经过几次移动，那么我们不妨现总结下规律
//首先那些不符合要求的需要移动，选出一系列不满足要求的元素，然后再按照顺序一次插入队首，使刚插入的元素和后面原始序列满足两短非递减
//但是这个过程我们想想需要修改的因素有哪些：1.在序列中不符合非递减。2.由于别的元素插入队首，导致其移动
//那么我们可以想到第一次移动中存在一个最大的元素，原序列中所有小于他的不管有没有满足顺序，肯定都要移动啊。那我们其实要移动的就是破坏非递减的最大元素个数+原序列中所有比最大元素小的个数
//最后按照顺序一次移动到队首即可

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e6+10;

int a[maxn],b[maxn],n,t;

int main(){
	a[0]=0;
	scanf("%d",&t);
	while(t--){
		int mx=0,cnt=0;
		scanf("%d",&n);
		int last=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]<last){
				if(a[i]>mx) mx=a[i],cnt=1;
				else if(a[i]==mx) cnt++;
			}
			if(a[i]>last) last=a[i];
		}
		sort(a+1,a+n+1);
		int ans=lower_bound(a+1,a+n+1,mx)-a-1+cnt;
		printf("%d\n",ans);
	}
}
