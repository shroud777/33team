//题意：给出一个 N*N 的矩阵（行列的编号都是 1-n），有 q 组询问，每组询问包含 row,col ，代表从 row行 ，col列 开始的 b*b 大小的矩阵，使其 max-min 值最大

//思路：二维前缀和，以列为基准，对指定的每一行求 RMQ，可重复贡献问题只需要每一列取 RMQ 即可

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
const int maxn=255;
const int maxlog=8;
int n,b,k;
int mi[maxn][maxn][maxlog];
int mx[maxn][maxn][maxlog];

void init_RMQ(){
	for(int k=1;k<=n;k++){
		for(int j=1;(1<<j)<=n;j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				mx[k][i][j]=max(mx[k][i][j-1],mx[k][i+(1<<j-1)][j-1]);
				mi[k][i][j]=min(mi[k][i][j-1],mi[k][i+(1<<j-1)][j-1]);
			}
		}
	}
} 

int query(int r,int c){
	int d=log2(b);
	int minn=0x3f3f3f3f,maxx=0;
	int left=c,right=c+b-1;
	for(int k=r;k<=r+b-1;k++){
		minn=min(minn,min(mi[k][left][d],mi[k][right-(1<<d)+1][d]));
		maxx=max(maxx,max(mx[k][left][d],mx[k][right-(1<<d)+1][d]));
	}
	return maxx-minn;
}

int main(){
	scanf("%d %d %d",&n,&b,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&mi[i][j][0]);
			mx[i][j][0]=mi[i][j][0];
		}
	}
	init_RMQ();
	int r,c;
	while(k--){
		scanf("%d %d",&r,&c);
		printf("%d\n",query(r,c));
	}
	return 0;
}
