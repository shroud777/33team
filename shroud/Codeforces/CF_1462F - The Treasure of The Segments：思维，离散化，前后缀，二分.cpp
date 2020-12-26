//题意：给出 n 个区间，现在定义一个区间集合是 good 的如果集合中存在一个区间与其他所有区间相交，问对于 n 个区间，最少去掉多少个区间使得剩余区间成为一个 good 的区间集合

//思路：首先很好想到枚举区间的方法，枚举当前区间就代表当前区间能覆盖剩余区间集合，那么我们要删除的元素就是那些右端点小于当前区间左端点，左端点大于当前区间右端点的区间
//问题在于怎么判断这些要删除的区间的个数，这里可以用到二分，即分别用两个 vector 保存左右端点，然后只要二分即可
//或者使用离散化（因为区间端点值域 [1,1e9]），然后我们做一个前后缀统计，统计右端点的前缀和左端点的后缀，每次只需要查询当前区间小于左端点的前缀和大于右端点的后缀即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=2e5+10;
 
int n,l[maxn],r[maxn],o[maxn<<1],len=0;
int pre[maxn<<1],suf[maxn<<1];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			scanf("%d %d",&l[i],&r[i]);
			o[(i<<1)-1]=l[i],o[i<<1]=r[i];
		}
		for(int i=1;i<=2*n+5;i++) suf[i]=pre[i]=0;
		sort(o+1,o+n+n+1);
		len=unique(o+1,o+n+n+1)-o-1;
		//for(int i=1;i<=len;i++) cout<<o[i]<<" ";
		//cout<<endl;
		for(int i=1;i<=n;++i){
			l[i]=lower_bound(o+1,o+len+1,l[i])-o;
			r[i]=lower_bound(o+1,o+len+1,r[i])-o;
			suf[l[i]]++;
			pre[r[i]]++;
		}
		for(int i=2;i<=len;++i) pre[i]+=pre[i-1];
		for(int i=len-1;i>=1;--i) suf[i]+=suf[i+1];
		//for(int i=1;i<=len;++i) cout<<"i="<<i<<" "<<suf[i]<<" "<<pre[i]<<endl;
		int ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++) ans=min(ans,pre[l[i]-1]+suf[r[i]+1]);//cout<<l[i]<<" "<<r[i]<<" "<<pre[l[i]-1]<<" "<<suf[r[i]+1]<<endl;
		printf("%d\n",ans);
	}
	return 0;
}
