//题意：给出一个长度为 n 的数组 a，一个长度为 m 的数组 b，b 序列递增，现在要将 a 数组划分为 m 个区间使得第 i 个子区间的最小值等于 bi，问有多少种划分情况

//思路：我们倒序处理两个数组，因为如果正着处理的话，可能没法判断第一个区间的边界，可能后面 ai 的数全比 bj 大，但是实际上属于 j 的区间早就过了，因为 j+1 需要一定区间
//那么我们倒叙处理规则是这样的：首先对于第 bm，我们先从 an 开始找第一个不大于 bm 的数，如果这个位置的数不等于 bm（小于 bm）那么说明不存在方案，不然的话区间从这个位置开始，设这个位置为 r
//那么我们往前找，找到第一个小于 bm 的位置 l，那么答案就是 r-l，并且这种方法不存在扩展区间过大的情况，因为 bm-1 < bm，所以如果存在这样的解，l 必然不会超过 bm-1

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;
const int p=998244353;

int n,m,a[maxn],b[maxn];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	reverse(b+1,b+m+1);
	ll ans=1;
	bool f=1;
	int pos=n;
	for(int i=1;i<=m;i++){
		while(a[pos]>b[i]&&pos>=1) pos--;
		if(a[pos]!=b[i]){
			f=0;break;
		}
		int r=pos;
		while(a[pos]>=b[i]&&pos>=1) pos--;
		if(pos>=1) ans=1ll*ans*(r-pos)%p;
	}
	if(pos!=0||!f) cout<<0<<endl;
	else cout<<ans<<endl;
	return 0;
}
