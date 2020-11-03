//题意：有 n 个碗需要被清洗，但是现在每秒只能洗一个碗，每个碗有一个值 ti，当你在 T 秒时刻洗第 i 个碗时，要付出 |T-ti| 的代价，现在求最小代价

//思路：有 2 种做法：
//1.DP 做法，枚举第 i 个碗在第 j 秒完成即可
//2.建图后用匈牙利算法或最小费用最大流得到解
//首先谈谈做法 1，首先我们把序列升序排列，因为不管怎么洗，绝对位置怎么变，这几个碗的洗碗顺序肯定是从小到大，相对位置不变
//O(n^3) DP 转移最容易想到：dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(a[i]-j))(i-1<=k<j)
//其实我们可以对上述 DP 过程进行优化，我们发现那个 k 的集合其实就是 j 位置前的所有位置的最小值，所以满足集合的单调性，我们可以用一个变量记录，这里直接用 dp[i][j] 统计 dp[i][1~j] 所有的最小值进行转移即可




//O(n^3) DP

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=2e5+10;
 
int t,n,a[205],dp[205][500];
 
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(int j=1;j<=2*n;j++) dp[i][j]=0x3f3f3f3f;
		}
		sort(a+1,a+n+1);
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=a[i]+i;j++){
				int temp=abs(a[i]-j);
				for(int k=i-1;k<j;k++){
					if(dp[i-1][k]==0x3f3f3f3f) continue;
					dp[i][j]=min(dp[i][j],dp[i-1][k]+temp);
				}
			}
		}
		int ans=0x3f3f3f3f;
		/*for(int i=0;i<=n;i++){
			for(int j=0;j<=n*2;j++) cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}*/
		for(int i=1;i<=n*2;i++) ans=min(ans,dp[n][i]);
		cout<<ans<<endl; 
	}
	return 0;
}

// O(n^2) DP

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=2e5+10;
 
int t,n,a[205],dp[205][500];
 
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(int j=1;j<=2*n;j++) dp[i][j]=0x3f3f3f3f;
		}
		sort(a+1,a+n+1);
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=2*n;j++){
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(a[i]-j));
				dp[i][j+1]=min(dp[i][j+1],dp[i][j]); 
			}
		}
		cout<<dp[n][2*n]<<endl;
	}
	return 0;
}

