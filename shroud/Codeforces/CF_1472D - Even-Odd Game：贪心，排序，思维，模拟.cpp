//题意：有一个长度为 n 的序列，现在 A 和 B 分别从序列中取数并移除，A 先拿，并且 A 如果拿到偶数会加上相应的分，拿到奇数不加分，B 拿到奇数加上相应的分，拿到偶数不加分
//问在双方保证最优策略的情况下，谁有获胜？

//思路：首先要明确，我们设 A 的总分为 SA，B 的总分为 SB，那么评估最后的结果就是看 res=SA-SB 的值，如果 res<0，则 B 胜;res>0，A 胜;res=0，打平
//那么我们可以看到，每个数，其实奇偶性的影响无关紧要，因为就算不加分，会相当于间接影响另一位选手的分数，所以我们只需要从大到小拿元素，并且判断值即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn];

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1,greater<int>());
		ll ans=0;
		for(int i=1;i<=n;i++){
			if((i&1)&&(a[i]%2==0)) ans+=a[i];
			else if((i%2==0)&&(a[i]&1)) ans-=a[i];
		}
		if(ans>0) puts("Alice");
		else if(ans<0) puts("Bob");
		else puts("Tie");
	} 
	
	return 0;
}
