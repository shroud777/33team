//题意：给出一个长度为 n 的序列，若序列中某两个元素 ai,aj 满足 gcd(ai,aj)=序列中的最小元素，那么则可以交换这两个元素的位置，问能否使序列非递减

//思路：这道题一开始卡了很久，主要是思维被限制了，我想着就是尽量次数少的交换，还有就是对 gcd 的理解脑子又出问题了。。。
//我想者就是看每个元素能不能回到它的位置上，那就是当前位置现有元素和应有元素交换，但是这种想法肯定使不对的，我也不知道当时为什么这么想
//后来发现，其实可以通过这个 最小元素 作为 temp 来进行交换
//那么只要所有无序的数满足 gcd(ai,minn)=minn，就可以变得有序，同时这里 gcd 只要看成最小值是他的因子的一部分即可

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn=1e5+10;


int a[maxn],b[maxn];

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	int t,n,mi;
	scanf("%d",&t);
	while(t--){
		mi=INF;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]<mi) mi=a[i];
			b[i]=a[i];
		}
		if(mi==1){
			cout<<"YES"<<endl;
			continue;
		}
		sort(b+1,b+1+n);
		bool f=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i]){
				if(gcd(a[i],mi)!=mi){
					f=0;
					break;
				}
			}
		}
		if(f) puts("YES");
		else puts("NO");
	}
	return 0;
}
