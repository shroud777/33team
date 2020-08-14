//题意：对于一个 4*n 的棋盘，用 1*2 的骨牌填满整个棋盘，问有多少种方案

//思路：可以考虑递推出方案随棋盘大小变化的关系:
//如果前n-1行填满，第n行：两个1*2的竖着放，1种方法；
//如果前n-2行填满（但是前n-1行没满）：横着两个，竖着两个有3种方法，横着四个有1种方法，一共4种；
//如果n-3行填满（前n-1，n-2行没满），有2种情况；
//如果n-4行填满的话，有3种情况；
//n-大于等于3的奇数行填满——2种；
//n-大于等于4的偶数行填满——3种；
//f[n]=f[n−1]+4×f[n−2]+2×(f[n−3]+f[n−5]+f[n−7]+....)+3×(f[n−4]+f[n−6]+f[n−8]+...);
//f[n−2]=f[n−3]+4×f[n−4]+2×(f[n−5]+f[n−7]+....)+3×(f[n−6]+f[n−8]+...);
//以上两个式子相减： f[n] = f[n-1] + 5f[n-2] + f[n-3] - f[n-4]；
//那么得出了递推式我们就可以得出结果，并用矩阵快速幂加速
//f(n)=f(n-1)+5*f(n-2)+f(n-3)-f(n-4) 
//F(n)=(f(n),f(n+1),f(n+2),f(n+3))
//F(1)=(1,5,11,36)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
ll n,p;
struct Matrix{
	int n,m;
	ll M[10][10];
	Matrix(int n,int m):n(n),m(m){memset(M,0,sizeof M);}
	void M_clear(){
		memset(M,0,sizeof M);
	}
	Matrix operator *(const Matrix &b)const {
		Matrix res(n,b.m);
		for(int i=0;i<n;i++){
			for(int j=0;j<b.m;j++){
				for(int k=0;k<m;k++){
					res.M[i][j]=(res.M[i][j]+M[i][k]*b.M[k][j]%p+p)%p;
				}
			}
		}
		return res;
	}
	void M_remain(){
		memset(M,0,sizeof M);
		for(int i=0;i<5;i++) M[i][i]=1;
	}
	void M_print(){ 
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cout<<M[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
};

Matrix q_mpow(Matrix a,int n){
	Matrix res(a.n,a.n);
	res.M_remain();
	while(n){
		if(n&1) res=res*a;
		a=a*a;
		n>>=1;
	}
	return res;
}
//f(n)=f(n-1)+5*f(n-2)+f(n-3)-f(n-4) 
//F(n)=(f(n),f(n+1),f(n+2),f(n+3))
//F(1)=(1,5,11,36)
int main(){
	Matrix F(1,4),C(4,4),ans(1,4);
	F.M_clear(),C.M_clear();
	F.n=1;
	F.m=C.n=C.m=4;
	C.M[0][3]=-1;
	C.M[1][0]=C.M[1][3]=C.M[2][1]=C.M[3][2]=C.M[3][3]=1; 
	C.M[2][3]=5;
	F.M[0][0]=1,F.M[0][1]=5,F.M[0][2]=11,F.M[0][3]=36;
	int t;
	scanf("%d",&t);
	while(t--){
		cin>>n>>p;
		ans=F*q_mpow(C,n-1);
		cout<<ans.M[0][0]<<endl;
	}
	return 0;
} 
