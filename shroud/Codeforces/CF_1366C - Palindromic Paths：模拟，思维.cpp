//题意：给出一个 n*m 的 01 矩阵，现在可以从 (1,1) 走到 (n,m) 且只能走 (x+1,y) (y,x+1) 位置，问最少改变原矩阵多少个元素使得任意路径都是回文路径
//回文路径：走过第一个和走过的最后一个点的值相同，走过第二个和走过的倒数第二个点的值相同，以此类推

//思路：走过的距离对称，那么我们可以想到由于矩阵中走的都是欧几里得距离，那么假设一个点 (x,y)，他到 (1,1) 的欧几里得距离为 x-1+y-1，那么与他对称的那个点里 (n,m) 的距离也要是 x+y-2
//并且至于以此点为矩形的角的矩形内的元素有关联，但是几个点之间的相互联系导致所有距离 (1,1) 和 (n,m) 欧几里得距离相等的都要相等，这里我们设 (x,y) 为 x+y 组里的元素
//那么 2 和 n+m 组里的元素要相等，3 和 n+m-1 的元素要相等，一次类推，并且如果 n+m-1 为奇数那么说明对角线没有任何其他要求与他对称的，那可以直接忽略，所以边界条件就是上下界不能相交

#include <bits/stdc++.h>

using namespace std;

const int maxn=35;

int n,m,cnt[2][maxn<<1];

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(cnt,0,sizeof cnt);
		int x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>x;
				cnt[x][i+j]++;
			}
		}
		// 2 - n+m+2 
		int ans=0;
		for(int i=2;;i++){
			int j=n+m+2-i;
			if(i>=j) break;
			ans+=min(cnt[1][i]+cnt[1][j],cnt[0][i]+cnt[0][j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
