//题意：给出一个棵 n 个结点的树，有k种不同颜色的染料给树染色。一个染色方案是合法的，当且仅当对于所有相同颜色的点对(x,y)，x到y的路径上的所有点的颜色都要与x和y相同。请统计方案数。

//思路：这道题做法比较多
//首先清楚对于题干要求，其实就是划分若干个不同颜色的连通块，那么我们得到启发，对于 x 个连通块相当于选择 x-1 条边去划分，然后去染色，这就想到了组合数学的方法
//然后根据 DFS序 处理这棵树，我们依次对结点染色，当前结点的颜色肯定只有两种选择，要么就是用之前用过的颜色，要么就用新的颜色，而第一种方法必须要用和父节点颜色一样的去染色
//因为其他点已经祖先结点或者父节点的兄弟结点已经染好了，那么我们要选择已经用过的点，路径上必然要经过父亲结点，那么答案就显而易见了
//设 dp(i,j) 代表第 i 个点已经用了 j 种颜色，那么 dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*(k-j+1)

//组合数学

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;
const int p=1e9+7;

int n,k;
ll fact[305],ifact[305];

ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}

void init(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=1ll*fact[i-1]*i%p;
	ifact[n]=qpow(fact[n],p-2);
	for(int i=n-1;i>=0;i--) ifact[i]=1ll*ifact[i+1]*(i+1)%p;
}

inline ll c(ll n,ll m){
	return 1ll*fact[n]*ifact[n-m]%p*ifact[m]%p;
}

int main(){
	scanf("%d %d",&n,&k);
	init(300);
	int u,v;
	for(int i=1;i<n;i++) scanf("%d %d",&u,&v);
	ll ans=0;
	for(int i=1;i<=k;i++){
		ans=(ans+c(n-1,i-1)*c(k,i)%p*fact[i]%p)%p;
	}
	cout<<ans<<endl;
	return 0;
}


//dp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;
const int p=1e9+7;

int n,k;
ll dp[305][305];

int main(){
	scanf("%d %d",&n,&k);
	int u,v;
	for(int i=1;i<n;i++) scanf("%d %d",&u,&v);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
            if(n<k) continue;
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]*(k-j+1)%p)%p;
		}
	}
	ll ans=0;
	for(int i=1;i<=k;i++) ans=(ans+dp[n][i])%p;
	cout<<ans<<endl;
	return 0;
}
