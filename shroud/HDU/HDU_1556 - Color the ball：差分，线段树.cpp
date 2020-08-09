//题意：有 n 个气球 [1,n]，进行 n 次对 [a,b] 区间内的气球涂色，最后问每个气球被涂过几次颜色

//思路：差分数组维护即可，每次涂色对 d[a]++,d[b+1]--,最后询问只要进行一次前缀加即可，或者无聊点用线段树维护，但是最后每次都是单点查询？那也太麻烦了 O(log2n)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=1e5+10;
int tree[maxn];
int n;

int main(){
	int a,b;
	while(scanf("%d",&n)&&n){
		for(int i=1;i<=n;i++) tree[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&a,&b);
			tree[a]++;
			tree[b+1]--;
		}
		for(int i=1;i<=n;i++){
			tree[i]+=tree[i-1];
			if(i==1) printf("%d",tree[i]);
			else printf(" %d",tree[i]);
		}
		printf("\n");
	}
	return 0;
}
