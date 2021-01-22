//题意：现在有 n 个整数，分别分配给 k 个朋友，每个朋友可以分到 wi 个整数 Σi(1-k) = n，并且定义每个朋友的快乐值为收到的最大整数和最小整数之和，现在要你选择一种分配方式使得 k 个朋友的快乐值最大

//思路：首先我们考虑 wi=1 的朋友，显然，他们有优先选择权，因为他们拿一个整数，相当于同样的拿了两次，所以贪心地将大的整数分配给 wi=1 的人
//对于剩下的人，我们先将整数升序排序，除去分给 wi=1 的人的那些最大的整数，接下来对于每个人，我们选择剩余整数中最大的作为这个人所拥有的最大整数，那么我们想到取剩余 wi-1 个整数，取决于最小的那个
//如果我们取剩余整数中中段的，由于我们跳过了最左端的那些比较小的数，我们相当于浪费了一些中段大小的数（因为我们本可以把中段的数留给后面的人，我们这次取较小的数）
//所以我们剩余 wi-1 个数肯定是从剩余数中取最小的 wi-1 个，所以贡献就是 w1+wn（剩余数中最大与最小的）

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,k;
int a[maxn],w[maxn];

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int cnt=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=k;i++){
			scanf("%d",&w[i]);
			if(w[i]==1) cnt++;
		}
		sort(a+1,a+n+1);
		sort(w+1,w+k+1,greater<int>());
		int p1=1,p2=n;
		ll res=0;
		for(int i=1;i<=cnt;i++){
			res+=2*a[p2];
			p2--;
		}
		for(int i=1;i<=k-cnt;i++){
			res+=a[p2]+a[p1];
			p2--;
			p1+=w[i]-1;
		}
		cout<<res<<endl;
	}
	return 0;
}
