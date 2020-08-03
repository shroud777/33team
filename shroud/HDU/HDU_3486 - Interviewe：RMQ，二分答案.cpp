//题意：有 n 个人，每个人有一个能力值，将他们分为 m 组，每组 ceil[n/m] 个人，队列从前往后开始多余的人忽略，公司的能力值定义为每组中能力值最高的人的和，问能力值比 k 大 m 最小可以变成多少？

//思路：公司的能力值随 m 的变化具有单调性，显然可以考虑二分查找，同时如果每次二分 check 用 O(n) 遍历也会过慢，我们这里选择用ST表维护，每次 O(n/m) 的查询check函数
//注意二分的收束条件和结束条件，同时不能只模拟把 n 个人分成 m 组，还要注意只能有 m 组，比如 11 个人分成 10 组，那么虽然每组是 1 个人，但多余的 1 个人是不能取的
//注意很多细节，思路什么的都没问题，因为这些东西 wa 了好几次，太不值的


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int maxlog=22;
int f[maxn][maxlog+5];
int n,k;

void init_RMQ(){
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
}

inline int query(int l,int r){
	int d=log2(r-l+1);
	return max(f[l][d],f[r-(1<<d)+1][d]);
}

bool check(int m){
	int res=0,p=n/m,cnt=1;
	for(int i=1;i+p-1<=n&&cnt<=m;i+=p,cnt++){
		res+=query(i,i+p-1);
		if(res>k) return true;
	}
	return false;
	//return res;
}


int Binary_search(){
	int l=1,r=n,mid;
	while(l<r){
		mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	return l; 
}

int main(){
	while(~scanf("%d %d",&n,&k)){
		if(n<0&&k<0) return 0;
		for(int i=1;i<=n;i++) scanf("%d",&f[i][0]);
		init_RMQ();
		if(!check(n)) printf("-1\n");
		//for(int i=1;i<=n;i++) cout<<i<<" "<<check(i)<<endl;
		else printf("%d\n",Binary_search());
	}
	return 0;
}
