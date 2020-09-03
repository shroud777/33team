//题意：有两个长度为 n 的序列 a 和 b，他们的元素都由 0,1,2 组成，现在我们能得到一个 c 序列
//规则如下，ci=ai*bi (ai>bi), ci=0 (ai*bi) ,ci=-ai*bi(ai<bi)，现在给出 a 和 b 序列中 0，1，2 的个数，问 ci 序列之和的可能的最大值时多少

//思路：现在要分析出只有 ai=2,bi=1 的时候序列之和才能增加，并且只有 ai=1,bi=2 的时候序列和会减少
//那么我们运用贪心的思想，尽可能让 ai=2 和 bi=1 组合，剩下的让 ai=1 和 bi=1 和 bi=0 组合，bi=2 和 ai=0 和 ai=2 组合，使得最后的结果最优

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int a[5],b[5];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=1;i<=3;i++) scanf("%d",&a[i]);
		for(int i=1;i<=3;i++) scanf("%d",&b[i]);
		int ans=0;
		int t=min(a[3],b[2]);
		ans+=2*t;
		a[3]-=t,b[2]-=t;
		b[3]=max(0,b[3]-a[3]-a[1]);
		a[2]=max(0,a[2]-b[1]-b[2]);
		ans-=2*min(b[3],a[2]);
		printf("%d\n",ans);
	}
	return 0;
}
