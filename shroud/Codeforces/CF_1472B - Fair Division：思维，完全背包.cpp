//题意：有 n 个糖果，每个糖果重为 1 或 2，现在问能否分配糖果为两份，使得两份的重量相等

//思路：两种做法：
//1.首先如果糖果的总重为奇数，那么显然不可能按重量平分。然后如果重量的一半为偶数，那么显然不管糖果的具体组成始终可以平分
//如果为奇数，那么如果没有重为 1 的糖果，那么显然不能平分，所以只要判断上述条件即可
//2.直接完全背包跑可能构成的方案，看看能不能用现有的糖果拼成一半的重量

//做法1：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int x,res=0,cnt=0;
		for(int i=1;i<=n;i++) cin>>x,res+=x,cnt+=(x==1);
		if(res&1){
			puts("NO");
			continue;
		}
		res>>=1;
		if((res&1)&&cnt==0) puts("NO");
		else puts("YES");
	}
	
	
	return 0;
} 

//做法2：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn],dp[maxn];

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
		for(int i=1;i<=sum;i++) dp[i]=0;
		dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=a[i];j<=sum;j++) dp[j]+=dp[j-a[i]];
		}
		if(sum&1||!dp[sum/2]) puts("NO");
		else puts("YES"); 
	}
	return 0;
} 
