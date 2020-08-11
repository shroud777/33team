//题意：给出一个 n*m 的矩阵，可以选 k 次，每此选某一行或某一列的所有数，最后答案加上这些数，并且取过的数可以视为 0 ，请可能得到求出最大的权值

//首先，如果 min(n,m)<=k，说明可以直接把整个矩阵的数取走，不用再看。而对于剩下的情况，由于 n,m <= 15，我们可以选择二进制枚举，我本来想直接枚举取行和列，那就变成 n+m 了，2^30 次一定会超时的，
//那么我们怎么优化下枚举方案呢，我们可以枚举行，然后对于所有受影响的列做处理，然后最后补足那剩余的不到 k 次的枚举在值大的行上

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=20;
int a[maxn][maxn],vis[maxn][maxn],n,m,k,sum;
int s[maxn];

int main(){
	sum=0;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
		}
	}
	if(min(n,m)<=k){
		printf("%d\n",sum);
		return 0;
	}
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		memset(vis,0,sizeof vis);
		memset(s,0,sizeof s);
		int temp=i,tot=1,cnt=0,res=0;
		while(temp){
			if(temp&1){
				 for(int j=1;j<=m;j++) res+=a[tot][j],vis[tot][j]=1;
				 cnt++;
			}
			tot++;
			temp>>=1;
		}
		if(cnt>k) continue;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) if(!vis[i][j]) s[j]+=a[i][j];
		}
		sort(s+1,s+m+1,greater<int>());
		for(int i=1;i<=k-cnt;i++) res+=s[i];
		ans=max(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}
