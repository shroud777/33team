//题意：给出一个长度为 n 的序列，现在要求一个三元组 (ai,aj,ak)，使得 max(ai,aj,ak)-min(ai,aj,ak) <= 2，问这样存在的三元组的个数

//思路：首先很容易想到排序之后找出一个差值小于等于 2 的序列来判断，但是如果我们就这样在这样一个区间里直接找 3 个数，那么会造成一些重复
//那么我们可以确定一个数，设置指针 l，从 1 扫到 n，然后找到一个区间 [l,r] 即最大差值小于等于 2 的区间，然后在区间 [l+1,r] 里找两个数即可，这样我们可以保证找到的三元组不重复
//预处理 C(n,2) 即可

#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
 
int n,a[maxn];
ll f[maxn];
 
int main(){
	for(int i=1;i<=2e5;i++) f[i]=f[i-1]+i;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int l=1,r=3;
		ll ans=0;
		while(l<=n){
			while(a[r]-a[l]<=2&&r<=n) r++;
			if(a[r]-a[l]>2||r>n) r--;
			if(r-l<2){
				l++;continue;
			}
			ans+=f[r-l-1];
			l++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
