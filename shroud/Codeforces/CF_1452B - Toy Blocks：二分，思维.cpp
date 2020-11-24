//题意：给出一个长度为 n 的序列 a，现在要求选择任意下标 i，都能满足把 ai 分配给其他 n-1 个序列元素，使得其他 n-1 个元素相等，现在可以花费 1 点使得序列某个元素加 1，问现在最小加多少可以使得满足题意要求

//思路：转述下题意就是把 n 个元素的和分配到 n-1 个，且 n-1 个元素的值不能低于原来的值，那么这道题的思路就可以从平均值和最大值入手
//首先我们想要平均分配，最好的情况情况是 sum/(n-1)，但是有些元素值会更大，这里就要考虑到，所以这个和至少应该是 mx*(n-1)
//这里又分为两种情况，首先：如果原序列的和比这个小，那么为了满足要求只需要加 mx*(n-1)-sum 即可
//那原序列的和大于他怎么办呢，我们肯定是想增加这个值，同时这个值必须满足 (n-1) 的倍数，那么答案显然就是 ceil((double)sum/(n-1))*(n-1) 了
//也可以用二分去求出这个数的具体位置

//二分

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=1e5+10;
 
int n,a[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ll mx=0,sum=0;
		for(int i=1;i<=n;i++) cin>>a[i],mx=max(1ll*a[i],mx),sum+=a[i];
		ll l=mx,r=1e13,ans;
		while(l<=r){
			ll mid=l+r>>1;
			if(mid*1ll*(n-1)>=sum) ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<1ll*ans*(n-1)-sum<<endl;
	}
	return 0;
}

//O(1)

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=1e5+10;
 
int n,a[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ll mx=0,sum=0;
		for(int i=1;i<=n;i++) cin>>a[i],mx=max(1ll*a[i],mx),sum+=a[i];
		if(mx*(n-1)>=sum) cout<<mx*(n-1)-sum<<endl;
		else cout<<ceil(sum*1.0/(n-1))*1ll*(n-1)-sum<<endl;
	}
	return 0;
}
