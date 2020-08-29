//题意：给出一个长度为 n 的序列，有 m 次询问，每次询问给出一个数 p，求序列所有元素 (ceil)(ai/(logp(ai)) 之和

//思路：ai 和 p 的范围很大，但是 logp(ai) 的值域只有 [1,30]，那么我们可以想到，预处理出对应的分母的值，但是如果这样我们处理序列每个元素的分母，那我们依旧需要 m*n 的查询和 n*30 的空间
//我们考虑把序列排序，使其有序化，那么每次分母的值必然呈单调趋势，并且我们预处理出每个对应分母时序列的前缀和值，那么我们只需要对有序序列二分找出对应分母的那一段位置，然后直接 O(1) 的前缀和查询即可

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5e5+10;
const ll p=1e9;

int n,q;
ll m,a[maxn],sum[35][maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&q);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=31;i++){
			for(int j=1;j<=n;j++) sum[i][j]=(sum[i][j-1]+(ll)(a[j]/i))%p;
		}
		ll ans=0;
		for(int k=1;k<=q;k++){
			scanf("%lld",&m);
			ll down=1,up=m,i=0,res=0;
			while(1){
				ll l=upper_bound(a+1,a+n+1,down)-a;
				ll r=upper_bound(a+1,a+n+1,up)-a-1;
				down=up;
				up*=m;
				if(l==n+1) break;
				res+=(sum[++i][r]-sum[i][l-1]+p)%p;
			}
			ans=(ans+k*res%p)%p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
