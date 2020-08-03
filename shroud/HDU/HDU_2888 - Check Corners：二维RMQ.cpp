//题意：给出一个 m*n 的矩阵，有 q 组询问，每组询问给出一个矩形的左上角和右下角坐标，问构成的这个子矩形中的最大值是否在矩形的四个角出现过？如果是只要一行或一列或只有一个可以只看一部分

//思路：二维RMQ，注意细节！！细节！！！还有他的 m 和 n 都是不同寻常都是反过来的

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=305;
int n,m,q;
int f[maxn][maxn][10];

void init_RMQ(){
	for(int k=1;k<=m;k++){
		for(int j=1;(1<<j)<=n;j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				f[k][i][j]=max(f[k][i][j-1],f[k][i+(1<<j-1)][j-1]);
			}
		}
	}
} 

int query(int r1,int c1,int r2,int c2){
	int d=log2(c2-c1+1),maxx=0;
	for(int r=r1;r<=r2;r++){
		maxx=max(maxx,max(f[r][c1][d],f[r][c2-(1<<d)+1][d]));
	}
	return maxx;
}


int main(){
	while(~scanf("%d %d",&m,&n)){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&f[i][j][0]);
			}
		}
		init_RMQ();
		scanf("%d",&q);
		int r1,r2,c1,c2;
		while(q--){
			scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
			int maxx=query(r1,c1,r2,c2);
			printf("%d ",maxx);
			if(maxx==f[r1][c1][0]||maxx==f[r1][c2][0]||maxx==f[r2][c1][0]||maxx==f[r2][c2][0]) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
