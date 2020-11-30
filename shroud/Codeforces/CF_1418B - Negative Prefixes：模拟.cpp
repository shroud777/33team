//题意：给出一个长度为 n 的序列，其中有一些元素被锁定了，其他所有没被锁定的元素都可以重排列并重新放入没有锁定的元素的位置，现在记 pi 为前 i 项的前缀和，现在记 k 为 pi<0 时下标最大的位置，初始等于 0

//思路：前缀和尽量大于 0，那么尽量把大的安排在前面，先把正的全加上去，保证最优解

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=5e5+10;
 
int n,a[maxn],b[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		vector<int> v;
		for(int i=1;i<=n;i++) if(!b[i]) v.push_back(a[i]);
		sort(v.begin(),v.end(),greater<int>());
		int cnt=-1;
		for(int i=1;i<=n;i++){
			if(!b[i]) cout<<v[++cnt]<<" ";
			else cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
