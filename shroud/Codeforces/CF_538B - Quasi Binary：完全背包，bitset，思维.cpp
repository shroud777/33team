//题意：给出一个正整数 n，现在要求用最少的每个位上权值只有 0，1 的十进制表示它

//思路：2种思路
//第 1 种思路：如果尽可能少的数，那么每一位肯定尽可能往大了选，那么就是 1，那么显而易见，所需要的数的个数就是 n 权值最大的某位
//设改位上的权值位 x，那么他在这个位置上每次都要出 1，其他位置上只要出现次数达到 n 上该位对应的权值，那么出 0 即可
//第 2 种思路：一个数 n，那么构成他的 01 十进制有限，且可以通过二进制枚举得到，我们把这些数作为一个集合，然后跑一个完全背包
// dp[i] 代表构成 i 这个数所用的集合里的数的最少个数
//状态转移方程 dp[i]=min(dp[i],dp[i-x]+1) （x属于该集合）


//第 1 种：
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,cnt[10];

int main(){
	scanf("%d",&n);
	int tot=0,mx=0;
	while(n){
		cnt[++tot]=n%10;
		n/=10;
		mx=max(cnt[tot],mx);
	}
	cout<<mx<<endl;
	while(mx--){
		int i;
		for(i=tot;i>=1;i--){
			if(cnt[i]) break;
		}
		for(i;i>=1;i--){
			if(cnt[i]) cout<<1,cnt[i]--;
			else cout<<0;
		}
		printf("%c",mx?' ':'\n');
	}
	return 0;
} 

//第 2 种

#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6+17;

int n;
int dp[maxn],pre[maxn];

inline int qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

int main(){
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	scanf("%d",&n);
	int len=log10(n)+1;
	vector<int> v;
	for(int i=(1<<len)-1;i>0;i--){
		int res=0,t=i,cnt=0;
		while(t){
			if(t&1) res+=qpow(10,cnt);
			cnt++;
			t>>=1;
		}
		v.push_back(res);
	}
	for(int i=0;i<v.size();i++){
		for(int j=v[i];j<=n;j++){
			if(dp[j]>dp[j-v[i]]+1){
				dp[j]=dp[j-v[i]]+1;
				pre[j]=j-v[i];
			}
		}
	}
	printf("%d\n",dp[n]);
	while(pre[n]){
		printf("%d ",n-pre[n]);
		n=pre[n];
	}
	printf("%d\n",n-pre[n]); 
	return 0;
}
