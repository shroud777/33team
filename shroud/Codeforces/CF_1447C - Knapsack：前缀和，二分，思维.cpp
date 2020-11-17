//题意：现在有 n 个物品，每个物品有一个体积 wi，现在给出一个容器体积为 W，现在要求一种方案取若干个物品，使得他们的体积之和在 [w/2,w] 之间

//思路：对于那些体积大于 W 的物品，肯定不用考虑，那么我们考虑那些体积小于等于 W 的物品，如果某些物品单件就能得到这个区间要求，我们直接选择即可
//那么对于没有满足要求的，肯定是体积过小，我们选择对物品体积排序，然后从小到大开始选择物品，这样可以逐步接近
//可以使用前缀和二分维护

#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn=2e5+10;
typedef long long ll;
 
ll sum[maxn];
 
struct node{
	int id,v;
}a[maxn];
 
bool cmp(node x,node y){
	return x.v<y.v;
}
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		ll w;
		cin>>n>>w;
		ll lim=ceil(w*1.0/2);
		for(int i=1;i<=n;i++) scanf("%d",&a[i].v),a[i].id=i;
		sort(a+1,a+n+1,cmp);
		bool f=0;
		int p=n+1;
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].v;
		for(int i=1;i<=n;i++){
			if(a[i].v>w){
				p=i;break;
			}
		}
		for(int i=p-1;i>=1;i--){
			if(f) break;
			int l=0,r=i-1;
			while(l<=r){
				int mid=l+r>>1;
				ll temp=sum[mid]+a[i].v;
				if(temp<=w&&temp>=lim){
					if(mid) cout<<mid+1<<endl;
					else cout<<1<<endl;
					for(int j=1;j<=mid;j++) printf("%d ",a[j]);
					printf("%d\n",a[i]);
					f=1;
					break;
				}
				if(temp>w) r=mid-1;
				else if(temp<lim) l=mid+1;
			}
		}
		if(!f) puts("-1");
	}
	
	return 0;
} 
