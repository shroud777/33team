//题意：给出一个正整数 n，要求输出一个 n*n 的矩阵，并且矩阵满足每个元素都不是质数，且每一行每一列的和都要是质数

//思路：不管用哪种方法，0 和 1 两个数不是质数
//方法 1：先用 1 把矩阵填满，那么每一行每一列元素的值为 n，如果 n 为质数，那么显然以满足，否则把主对角线元素值不断 +1，直到 主对角线的元素不是质数，和为质数即可
//方法 2：先把矩阵初始化为 0，主对角线和次对角线元素全部变为 1，这样所有行列的值都是 2，但是若 n 为奇数则不满足，那么 n 为奇数时，可以把 t=n/2+1，a[1][t]=a[t][1]=a[n][t]=a[t][n]=1，满足要求

//方法 1：
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=1e4+10;
int vis[maxn],prime[maxn],tot=0;
int n,temp[105][105];
 
void init_1(int n){
	for(int i=0;i<=n;i++) vis[i]=false;   //如果 vis 是 true，代表这个数被筛掉了，不是素数 
	vis[0]=vis[1]=1;
	for(int i=2;i*i<=n;i++){ //试除法，如果这个数 x 是合数，那么他肯定可以被 <=sqrt(x) 的质数整除 
		if(!vis[i]){
			for(int j=i*i;j<=n;j+=i) vis[j]=1; // j=2*i ，优化为 j=i*i，因为 2*j - j*j 有一些已经被筛掉了 
		}
	}
	for(int i=2;i<=n;i++) if(!vis[i]) prime[++tot]=i; //没有被筛过的就是质数了 
} 
 
int main(){
	init_1(1000);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) temp[i][j]=1;
		} 
		for(int i=0;i<=100;i++){
			if(!vis[i+n]&&vis[i+1]){
				int y=1; 
				for(int xx=1;xx<=n;xx++,y++){
					if(y>n) y-=n;
					temp[xx][y]+=i;
				}
				break;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) printf("%d%c",temp[i][j],j==n?'\n':' ');
		} 
	}
	return 0;
}

//方法 2：

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=105;
int a[maxn][maxn],n;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++) a[i][i]=1,a[i][n-i+1]=1;
		if(n&1){
			int t=n/2+1;
			a[1][t]=a[t][1]=a[n][t]=a[t][n]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d%c",a[i][j],j==n?'\n':' ');
			}
		}
	}
	
	
	return 0;
}
