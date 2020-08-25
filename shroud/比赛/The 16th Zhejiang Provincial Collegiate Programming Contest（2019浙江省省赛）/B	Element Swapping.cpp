//题意：有一个长度为 n 的数组 a，其每项乘以系数 （ai*i，i 从 1 开始）的和是 x，系数平方和是 y，在 a 序列中选择两个元素并交换他们，给出交换后的序列 b，求原数组 a 有多少种交换的可能得到 b
//注意：x 和 y 可能不是原数组的正确的和，那也意味着不可能得到正确的解

//思路：公式推导，求出 x,x',y,y' 和 ai,aj 的关系，然后可以判断出几种特殊情况：1.不存在解. 2.ai==aj 的解. 3.枚举 i 然后依次得到 aj ，然后再求出 j，检验 aj 是否等于 a[j]

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+10;

int n;
ll x,y,xx,yy;
ll a[maxn];
ll vis[maxn],cnt[maxn];


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof vis);
		memset(cnt,0,sizeof cnt);
		xx=yy=0;
		int tot=0;
		scanf("%d %lld %lld",&n,&x,&y);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(!cnt[a[i]]) vis[++tot]=a[i];
			cnt[a[i]]++;
			xx+=i*a[i];
			yy+=i*a[i]*a[i];
		}
		ll ans=0;
		ll dy=y-yy,dx=x-xx;
		//cout<<dy<<" "<<dx<<endl;
		if(dx==0){
			if(dy!=0){
				puts("0");
				continue;
			}
			else{
				for(int i=1;i<=tot;i++){
					ll j=cnt[vis[i]];
					if(j>1) ans+=1ll*j*(j-1)/2;
				}
				printf("%lld\n",ans);
				continue;
			}
		}
		else if(dy%dx!=0){
			puts("0");
			continue;
		}
		else{
			for(int i=1;i<=n;i++){
				ll aj=dy/dx-a[i];
				if(a[i]-aj==0) continue;
				if(abs(dx)%abs(a[i]-aj)!=0) continue;
				int j=i+dx/(a[i]-aj);
				if(j<=i) continue;
				//cout<<aj<<" "<<j<<endl;
				if(a[j]==aj) ans++;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
