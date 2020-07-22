//题意：给出字符串 A ，问 A 的所有前缀在 A 中出现次数的和是多少

//思路：KMP，然后可以想象到每个位置 dp[i]=dp[Next[i]]+1 ，因为 Next[i] 就代表前 i 个字符串中，前 Next[i] 个等于后 Next[i] 个。然后根据这个思路我们可以知道，最后再加上他本身即可

#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int N=1e6+10;
const int p=1e4+7;
string T,P;
int Next[maxn],dp[maxn];

void get_Next(){
	int plen=P.size();
	Next[0]=-1;
	int i=-1,j=0;
	while(j<plen){
		if(i==-1||P[i]==P[j]) Next[++j]=++i;
		else i=Next[i];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n>>P;
		get_Next();
		long long ans=0;
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			dp[i]=(dp[Next[i]]+1)%p;
			ans=(ans+dp[i])%p;
		}
		cout<<ans<<endl;
	}
	return 0;
}
