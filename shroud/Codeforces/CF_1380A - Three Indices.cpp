//题意：给出一个长度为 n 的 1~n 的全排列，求是否有 3 个下标存在 1≤i<j<k≤n 和 pi<pj and pj>pk.

//思路:看数据可以暴力枚举下标然后从中间像两边扩展。

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
int a[maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool f=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		bool f1,f2;
		int x,y;
		for(int i=1;i<=n;i++){
			f1=f2=0;
			for(int j=i;j>=1;j--){
				if(a[j]<a[i]){
					x=j;
					f1=1;
					break;
				}
			}
			if(!f1) continue;
			for(int j=i;j<=n;j++){
				if(a[i]>a[j]){
					y=j;
					f2=1;
					break;
				}
			}
			if(f1&&f2){
				f=1;
				cout<<"YES"<<endl<<x<<" "<<i<<" "<<y<<endl;
				break;
			}
		}
		if(!f) cout<<"NO"<<endl;
	} 
	return 0;
} 
