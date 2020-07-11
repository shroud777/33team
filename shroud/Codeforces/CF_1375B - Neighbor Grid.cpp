//题意:定义矩阵 good 的标准是：当前位置的数为 k ，那么他周围的邻居数量（与它的边相交的同时也包括它自己）必须等于 k 。
//给出一个 n*m 大小的矩阵，判断他是否可成为(或已经是) good 矩阵。你可以对给定矩阵任意位置上的数加任何正整数来使他成为 good 矩阵。

//思路：四个角的最大k为2，四条外边为3，其余是4，判断是否超过最大k，由于每个位置只能进行increase，满足可直接构造每个位置k最大的矩形。

#include <bits/stdc++.h>
using namespace std;
const int maxn=310;
int a[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	int t,n,m;
	cin>>t;
	while(t--){
		bool f=1;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				if((i==1&&j==1)||(i==1&&j==m)||(i==n&&j==1)||(i==n&&j==m)){
					if(a[i][j]>2) f=0;
					a[i][j]=2;
					continue;
				}
				if(i==1||i==n||j==1||j==m){
					if(a[i][j]>3) f=0;
					a[i][j]=3;
					continue;
				}
				else {
					if(a[i][j]>4) f=0;
					a[i][j]=4;
				}
			}
		}
		if(!f){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(j==1) cout<<a[i][j];
				else cout<<" "<<a[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
