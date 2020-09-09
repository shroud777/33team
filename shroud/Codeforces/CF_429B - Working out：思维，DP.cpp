//题意：给定一张 n 行 m 列的地图，其中小 A 从（1,1）走到（n,m），小 B 从（n,1） 走到 （m,1），其中地图每个位置都有一个权值，如果地图中某个位置只有两人中的一人走过，则加入总权值，求总权值最大的情况

//思路：首先最优情况肯定是两个人只有一个交点。证明：假设最大值是两个人有多个交点，那么要使移动其中一段使其交点减少，那么它的值肯定会增大或不变。
//然后两种相交情况，设交点为 (i,j)，第一种情况，小 A 从 （i-1,j） 走到 (i+1,j)，小 B 从（i,j-1） 走到 （i,j+1）
//第二种小 A 从 （i,j-1）走到 （i,j+1） 小 B 从 （i-1,j）走到 （i+1,j）

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e3+10;

int n,m,a[maxn][maxn];
ll dp1[maxn][maxn],dp2[maxn][maxn],dp3[maxn][maxn],dp4[maxn][maxn];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) dp1[i][j]=max(dp1[i][j-1],dp1[i-1][j])+a[i][j];
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++) dp2[i][j]=max(dp2[i][j-1],dp2[i+1][j])+a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--) dp3[i][j]=max(dp3[i][j+1],dp3[i-1][j])+a[i][j];
	}
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--) dp4[i][j]=max(dp4[i+1][j],dp4[i][j+1])+a[i][j];
	}
	ll ans=0;
	for(int i=2;i<n;i++){
		for(int j=2;j<m;j++){
			ans=max(ans,max(dp1[i][j-1]+dp4[i][j+1]+dp2[i+1][j]+dp3[i-1][j],dp1[i-1][j]+dp4[i+1][j]+dp2[i][j-1]+dp3[i][j+1]));
		}
	}
	cout<<ans<<endl;
	return 0;
}
