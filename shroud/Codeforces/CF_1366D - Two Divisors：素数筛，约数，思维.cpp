//题意：给出 n 个整数 ai(1<=i<=n)，问对于每个 ai，d1|ai，d2|ai，使得 gcd(d1+d2,ai) = 1

//思路：对于一个数 a=p1^c1+p2^c2...pk^ck，如果  k<=1，那么显然不存在这样的解
//那么如果找到这两个约数呢，结论：d1=p1^c1+p2^c2+..+px^ck，d2=px+1^cx+1+px+2^cx+2+...+pk^ck
//那么如果一个数的因子超过两个，我们就可以用 d1=fac[a],d2=a/fac[a] 表示
//下面是证明，对于任意 pi ∈ d1，d1%pi==0 && d2%pi!=0，那么 d1+d2 % pi == 0+d2 %pi !=0，那么代表 d1+d2 与所有因子都互质，那么 gcd(d1+d2,a)==1
//数据有点大，先用筛法把每个合数的某个因子表达出来

#include <bits/stdc++.h>

using namespace std;

const int maxn=5e5+10;
const int N=1e7+10;

int n,a[maxn],ans1[maxn],ans2[maxn];
bool vis[N];
int d[N];
vector<int> p;

void sieve(){
	vis[1]=vis[0]=1;
	for(int i=2;i*i<=1e7;i++){
		if(!vis[i]){
			for(int j=i*i;j<=1e7;j+=i) vis[j]=1,d[j]=i;
		}
	}
}

int main(){
	sieve();
	cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(!d[x]){
			ans1[i]=ans2[i]=-1;
			continue;
		}
		int t=d[x];
		while(x%t==0) x/=t;
		if(x==1) ans1[i]=ans2[i]=-1;
		else ans1[i]=x,ans2[i]=t;
	}
	for(int i=1;i<=n;i++) printf("%d%c",ans1[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++) printf("%d%c",ans2[i],i==n?'\n':' ');
	return 0;
} 
