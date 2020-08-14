//题意：求 Fibonacci 数列第 n 项（n<=1e9）

//思路：递推 O(n) 求肯定会超时，这里将斐波那契数列的关系转化为矩阵的递推关系，利用矩阵乘法优化，并通过矩阵快速幂加速实现 O( 2^3*log2(n) ) 的速度实现

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
const int p=1e4;
struct Matrix{
	int m[5][5];
	Matrix(){
		memset(m,0,sizeof m);
	}
};
//f(n)=( Fi(n),Fi(n+1) )  初始化 f(0)=( Fi(0),Fi(1) )

Matrix mul(Matrix a,Matrix b,int x,int y,int z){
	Matrix res;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			for(int k=0;k<z;k++){
				res.m[i][j]=(res.m[i][j]+a.m[i][k]*b.m[k][j])%p;
			}
		}
	}
	return res;
}

Matrix q_mpow(Matrix a,int n){
	Matrix res;
	for(int i=0;i<2;i++) res.m[i][i]=1;
	while(n){
		if(n&1) res=mul(res,a,2,2,2);
		a=mul(a,a,2,2,2);
		n>>=1;
	}
	return res;
}

int main(){
	int n;
	while(~scanf("%d",&n)&&~n){
		Matrix f,st;
		f.m[0][0]=0;
		f.m[0][1]=1;
		f.m[1][0]=1;
		f.m[1][1]=1;
		st.m[0][0]=0;
		st.m[0][1]=1;
		Matrix res=mul(st,q_mpow(f,n),1,2,2);
		cout<<res.m[0][0]<<endl;
	}
	return 0;
}
