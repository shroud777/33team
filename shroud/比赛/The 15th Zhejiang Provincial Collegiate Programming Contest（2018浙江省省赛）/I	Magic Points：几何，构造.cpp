//题意：有 4*n-4 个点，他们处于 0<=x<n && y=0,0<=x<n && y=n-1,x=0 && 0<=y<=n,x=n-1 && 0<=y<n，问在这些点中取任意两点连成 n 条线，使得他们的斜率不相同，且不与 x 轴，y 轴平行
//问直线间两两相交点最多的连线方法

//思路：构造体，可以观察得 (i,n+i) 对很好地满足了上述性质，另外最后一个点的安放是难点，经过观察可以安放于 (n-1,3*n-4) 或 (n-1,3*n-2)

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e4+10;

int n;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==2){
			printf("0 2 1 3\n");continue;
		}
		for(int i=0;i<n-1;i++) printf("%d %d ",i,i+n); 
		printf("%d %d\n",n-1,3*n-4);
	}
	return 0;
} 
