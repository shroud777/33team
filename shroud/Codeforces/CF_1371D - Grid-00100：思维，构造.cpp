//题意：在一个 n*n 的矩阵A，A 每个 A i,j（第 i 行，第 j 列）由 0 或 1 组成，且要 A 中要存在 k 个 1
//Ri=Ai,1 + Ai,2 +..+ Ai,n (for all 1≤i≤n).
//Cj=A1,j + A2,j +...+ An,j (for all 1≤j≤n).  所以 sum(A)=R1+R2+...+Rn or C1+C2+...+Cn;
//max(X)是 X 序列中的最大值，min为最小值
//求出 f(A)=(max(R)−min(R))^2+(max(C)−min(C))^2 的最小值

//思路：题目要求最小值，显然是所有行列之前的差值尽量小，这些有权值的点尽量均匀的分配给每一行每一列，A i,j 的贡献就是对 i 行和 j 列，所以我们首先可以想到对角线，每次分配都很均匀
//然后通过对角线扩展到上下各斜线，一条斜线长度要到达 n，即如果溢出就想象把这个矩阵复制到右边
//比如一个 4,4 的方阵，第二条斜线可以是 1,2  2,3  3,4  4,1 
//所以我们可以得出如果 k 是 n 的倍数，那么他肯定能完美的填充这些斜线，所以答案是0，另外，由于对角线每次均匀的分配，即使不满足最后一条长度为 n，他的贡献最多也只有 1
//最后根据对角线填充矩阵即可，注意一些小细节

#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<vector<int> >v(n+2,vector<int> (n+2));
		if(k%n==0) cout<<0<<endl;
		else cout<<2<<endl;
		for(int i=1;i<=k/n;i++){
			int x=1,y=i;
			while(x<=n){
				y=(y<=n?y:y%n);
				v[x][y]++;
				x++,y++;
			}
		}
		int x=1,y=k/n+1; 
		while(x<=k%n){
			y=(y<=n?y:y%n);
			v[x][y]++;
			x++,y++;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cout<<v[i][j];
			cout<<endl;
		}
	}
}
