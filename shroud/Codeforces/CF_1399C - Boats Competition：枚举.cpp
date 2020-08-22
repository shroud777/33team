//题意：有 n 个人想要组队，每个人有一哥重量，若组队要满足要求：队伍有两人组成，且队伍的重量之和等于 s，找出一个 s 使得可以组队的队伍最多

//思路：数据很小，可以直接枚举可能的 s:[2,2*n] ，然后从 [1,s/2] 枚举，得到最大的可能，同时注意如果 s 是偶数，那么 s/2 要特判，两个 s/2 重量的人只能结合乘一个队伍

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+10;
 
int a[105],cnt[105];
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(cnt,0,sizeof cnt);
		int n;
		scanf("%d",&n);
		int x;
		for(int i=1;i<=n;i++) scanf("%d",&x),cnt[x]++;
		int ans=0;
		for(int k=2;k<=2*n;k++){
			int res=0;
			for(int i=1;i<=k/2;i++){
				if(i==k*1.0/2) res+=cnt[i]/2;
				else res+=min(cnt[i],cnt[k-i]);
			}
			//cout<<k<<" "<<res<<endl; 
			ans=max(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}
