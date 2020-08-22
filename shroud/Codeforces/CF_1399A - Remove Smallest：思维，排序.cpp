//题意：给出一个长度为 n 的序列，你可以选择序列中任意两个下标 i,j，若 ai，aj 的大小差小于等于 1，则可以选择移除其中一个元素，问能否使序列只剩一个元素

//思路：对于每个给出的序列，先将他们排序，因为我们肯定是从小找到大，这样才能保证尽可能删除 n-1 个元素，然后遍历如果两个数的差大于 1 则说明不可能交换

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1005;
int a[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		bool f=1;
		for(int i=1;i<n;i++){
			if(a[i+1]-a[i]>1){
				f=0;break;
			}
		}
		if(f) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	
	return 0;
} 
