//定义 f(n) 是满足 x*y+x*z+y*z+(x+y)+(y+z)+(x+z)=n 且 x,y,z>1 的 (x,y,z)对 的组数,给出 n ,分别列出 f(1),f(2),f(3)......f(n)的结果

//O(n^4)的做法可以优化枚举次数，例如 （1,2,3）这样的解，必定存在其他5个解，对中两个数相等的一共存在 3 个解，三个数全相等显然只有 1 个解。
//O(n^3)的做法直接先预处理得到每一个 n ，于是便可以处理得到 f(n) 可能的结果，然后直接输出 f(n) 。

#include <bits/stdc++.h>
using namespace std;
int c[105][105];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			c[i][j]=(i+j)*(i+j);
		}
	}
	for(int i=1;i<=n;i++){
		int d=i<<1;
		int cnt=0;
		for(int x=1;x<=sqrt(i);x++){
			for(int y=x;y<=sqrt(i);y++){
				for(int z=y;z<=sqrt(i);z++){
					if(c[x][y]+c[x][z]+c[y][z]==d){
						if(x==y&&y==z) cnt++;
						else if(x!=y&&y!=z&&x!=z) cnt+=6;
						else cnt+=3;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
