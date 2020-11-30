//题意：现在有 n 个 boss，编号从 1 到 n，现在你和你的朋友，要轮流打 boss，先从你的朋友开始打第 1 个 boss，每次要么至少打 1 个，至多打 2 个
//n 个boss 中有困难难度的 boss 和简单难度的 boss，你的朋友打困难的 boss 需要花费一张券跳过，同时也算击败了这个 boss，问你和你的朋友打完 n 个boss 最少要几张券

//两种可行的做法：1.贪心。2.DP
//首先来说说贪心，这个贪心还是比较难想到的，我一开始想的是让你尽量去打困难的 boss，如果当前是简单的 boss，只有轮到我了才打，朋友就反过来，但是这种做法存在一些问题
//正确的贪心做法是，首先考虑第一个位置，由于是朋友先打，那么无法避免的，如果第一个是困难 boss，那么必然要付出 1 的代价，接下来可以发现（总有方法能保证），我们总是能保证让你去打第一个困难的 boss
//那么接下来如果是 2 个困难 boss 连着，那就让你去全部打掉，如果 3 个连着，就要你的朋友去花费了
//第二个是DP做法，DP具体写起来也有很多差距，大体上就是设 dp i,j 代表第 u 个 boss 是 j 杀的，由于不能同一个人连着几个，

//贪心

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=2e5+10;
 
int n,a[maxn]; 
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int res=(a[1]==1);
		for(int i=2;i<=n;i++){
			if(!a[i]) continue;
			int pos=i;
			while(a[i]==1&&i<=n) i++;
			res+=(i-pos)/3;
		}
		cout<<res<<endl; 
	}
	return 0;
}


//DP
//第一个版本DP
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=5e5+10;
 
int n,a[maxn],dp[maxn][2],cnt[maxn][2];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			dp[i][0]=dp[i][1]=0x3f3f3f3f;
			cnt[i][0]=cnt[i][1]=0;
		}
		dp[1][0]=(a[1]==1);
		cnt[1][0]=1;
		for(int i=2;i<=n;i++){
			int t=(a[i]==1);
			if(i-1>0){
				if(dp[i][0]>dp[i-1][1]+t){
					dp[i][0]=dp[i-1][1]+t;
					cnt[i][0]=1;
				}
				if(dp[i][0]==dp[i-1][1]+t&&cnt[i][0]==2) cnt[i][0]=1;
			}
			if(i-1>0&&cnt[i-1][0]<=1){
				if(dp[i][0]>dp[i-1][0]+t){
					dp[i][0]=dp[i-1][0]+t;
					cnt[i][0]=cnt[i-1][0]+1;
				}
			}
			if(i-1>0&&cnt[i-1][1]<=1){
				if(dp[i][1]>dp[i-1][1]){
					dp[i][1]=dp[i-1][1];
					cnt[i][1]=cnt[i-1][1]+1;
				}
			}
			if(i-1>0){
				if(dp[i][1]>dp[i-1][0]){
					dp[i][1]=dp[i-1][0];
					cnt[i][1]=1;
				}
				if(dp[i][1]==dp[i-1][0]&&cnt[i][1]==2) cnt[i][1]=1;
			}
		}
		//for(int i=1;i<=n;i++) cout<<dp[i][0]<<" ";cout<<endl;
		//for(int i=1;i<=n;i++) cout<<cnt[i][0]<<" ";cout<<endl;
		//for(int i=1;i<=n;i++) cout<<dp[i][1]<<" ";cout<<endl;
		//for(int i=1;i<=n;i++) cout<<cnt[i][0]<<" ";cout<<endl;
		cout<<min(dp[n][1],dp[n][0])<<endl;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;

int n,a[maxn],dp[maxn][2];

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),dp[i][1]=dp[i][0]=n;
		dp[1][0]=a[1];
		dp[2][0]=a[1]+a[2];
		dp[2][1]=a[1];
		for(int i=3;i<=n;i++){
			for(int j=0;j<2;j++){
				int sum=0;
				for(int k=1;k<=2;k++){
					sum+=a[i-k+1]*(1-j);
					dp[i][j]=min(dp[i][j],dp[i-k][j^1]+sum);
				}
			}
		}
		cout<<min(dp[n][1],dp[n][0])<<endl;
	}
	return 0;
}
