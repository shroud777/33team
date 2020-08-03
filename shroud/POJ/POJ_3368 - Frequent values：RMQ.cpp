//题意：给出一个非递减序列，有 q 组询问，每次询问要求回答 [l,r] 区间内最长的相同连续序列

//思路：和普通 RMQ 思路差不多，每个位置记录当前位置某个数连续的个数，然后用st表维护区间中出现次数最多的数，但是有一点要注意，由于左区间可能会把连续的序列给阻断，那么最左区间记录的就不一定是该区间内出现次数最多的值了
//比如 1 1 1 1 4
//询问 [4,5] f[4][0]的值是4，但是他在 [4,5] 中只出现了一次，所以我们还需要从区间最左扫过去判断一下，右边的数就不会有这种情况了，有多少个最大值就是多少个
//RMQ 方程 max(tl-l,max(tl,r))

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+10;
const int maxlog=22;
int n,q;
int a[maxn],f[maxn][maxlog+5];

void init_RMQ(){
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
}


int query(int x,int y){
	int d=log2(y-x+1);
	return max(f[x][d],f[y-(1<<d)+1][d]);
} 


int main(){
	while(scanf("%d",&n)&&n){
		scanf("%d",&q);
		for(int i=1;i<=n;i++){
		 	scanf("%d",&a[i]);
		 	if(i==1){f[i][0]=1;continue;}
		 	if(a[i]==a[i-1]) f[i][0]=f[i-1][0]+1;
		 	else f[i][0]=1;
		}
		init_RMQ();
		int l,r,st;
		while(q--){
			scanf("%d %d",&l,&r);
			st=l;
			while(st<=r&&a[st]==a[st-1]) st++;
			if(r==st-1) printf("%d\n",st-l);
			else
			printf("%d\n",max(st-l,query(st,r)));
		}
	}
	return 0;
}

