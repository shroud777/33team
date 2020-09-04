//题意：有一个长度为 n 的序列，现在你可以执行三次（必须三次）如下操作：
//在序列间选定一个长度为 len 的整数区间，对区间内的数可以加减 len 的倍数，最后经过三次操作要使序列全部为 0

//思路：首先这个序列那么长，只用三个区间，又要倍数，那么我们的想法肯定是要联合利用这三个区间，不然单个使用不可能完成所有的测试用例，那么这里由于是依靠区间长度的倍数，如果我们构造出两个区间
//两个区间半边重叠，一个长度为 n，一个为 n-1，那么由于两个区间长度差1，如果用相同的倍数，他们差的就是那个倍数的大小，这样一来就好做了，我们可以消除所有 [1,n-1] 区间内的数为 0
//对于剩下的那第 n 个数，我们只需要用第三个区间处理它即可
//另外注意只有一个数的时候特殊讨论一下

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
 
ll a[maxn],n;
 
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n==1){
		printf("1 1\n");
		printf("1\n");
		printf("1 1\n");
		printf("-1\n");
		printf("1 1\n");
		printf("%lld\n",-a[1]);
		return 0;
	}
	printf("1 %lld\n",n);
	ll f;
	ll temp;
	f=-1;
	for(int i=1;i<=n;i++){
		if(i==n){
			printf("0\n");
			break;
		}
		printf("%lld%c",1ll*f*n*a[i],i==n?'\n':' ');
	}
	printf("1 %lld\n",n-1);
	f=1;
	for(int i=1;i<n;i++){
		printf("%lld%c",1ll*(n-1)*a[i]*f,i==n-1?'\n':' ');
	}
	printf("%lld %lld\n",n,n);
	printf("%lld\n",-a[n]);
	return 0;
}
