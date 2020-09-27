//题意：给出一个长度为 n 的序列，现在可以执行两种操作，一种是免费使得 ai-1,aj+1, i<j  另一种操作花费 1，使得 ai+1,aj+1,i<j，求最小花费使得序列所有元素变为 0

//思路：这里运用贪心的思想，如果一个负数前面没有其他正数和他一起做操作 1，那么它只能付费去使自己为 0，所以这里维护一直值 res，代表当前元素前面的可公用的正数的数量，在这个范围内的负数都可以免费变零
//而超过这部分的只需要加入答案即可，并且 res 最小变为 0，res 不能为负，因为付费的那部分负数已经加入到答案中

#include <bits/stdc++.h>
 
using namespace std;	
typedef long long ll;
const int maxn=1e5+10;
 
ll n,a[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ll res=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>0) res+=a[i];
			else{
				ans+=max(-a[i]-res,1ll*0);
				res=max(res+a[i],1ll*0);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
