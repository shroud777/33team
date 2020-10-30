//题意：给出序列长度 n，要找的元素 x，x 所在位置 pos，问按照题目给出程序要求，有多少种数组方案数使得运行题目给出程序能找到要求位置 pos

//思路：倘若二分的区间划分能够正确进行，那么就不一定要在有序序列中进行二分，如何决定区间划分走向呢？
//首先对于我们所要找的位置 pos，如果当前的 mid 值大于它，那么显然 mid 的元素要大于目标元素 x，这样区间会往右找。反之如果 mid 值小于它，则 mid 值位置的元素也要小于 x。
//这样我们能确定二分路径上的所有值的可能性，然后对于剩余位置没有任何要求，用组合数计算即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=105;
const int p=1e9+7;

int n,x,pos;

int main(){
	cin>>n>>x>>pos;
	int l=0,r=n;
	ll ans=1,big=n-x,small=x-1,cnt=0;
	while(l<r){
		int mid=l+r>>1;
		//cout<<l<<" "<<mid<<" "<<r<<endl;
		if(mid==pos){
			l=mid+1;
		}
		else if(mid<pos){
		//	cout<<small<<" ";
			ans=ans*small%p;
			cnt++;
			small--;
			l=mid+1;
		}
		else {
		//	cout<<big<<" ";
			ans=ans*big%p;
			cnt++;
			big--;
			r=mid;
		}
	}
	//cout<<cnt<<endl;
	for(int i=1;i<=n-cnt-1;i++) ans=1ll*ans*i%p;
	cout<<ans<<endl;
	return 0;
}
