//题意：给出一个长度为 n 个序列，其中序列中如果一个元素比相邻的元素大，则可以将较小的元素排除数组外，并且该元素的值+1，问现在能否有一个元素能和合并所有元素并输出改元素的位置

//思路：首先，如果 n 个数都相同，那么说明不可能达到指定要求，那么如果不都相同，那么必定存在解，因为每个最大值的周围必定存在元素比他小，然后他就成了唯一的最大值，不断模拟合并即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=3e5+10;
 
int n,a[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int mx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>mx) mx=a[i];
		}
		int f=-1;
		for(int i=1;i<=n;i++){
			if(a[i]==mx){
				if(i-1>0&&a[i-1]<a[i]){
					f=i;break;
				}
				if(i+1<=n&&a[i+1]<a[i]){
					f=i;break;
				}
			}
		}
		printf("%d\n",f);
	}
	return 0;
} 
