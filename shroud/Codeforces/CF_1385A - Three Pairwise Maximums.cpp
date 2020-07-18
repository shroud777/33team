//题意：给出 x,y,z x=max(a,b) y=max(a,c) z=max(b,c) 求是否这样的 a,b,c 并按任意顺序打印

//思路：假设 x<=y<=z ,那么 z 肯定包含 a,b,c 中的最大值，并且按照要求这个最大值也会体现在 y 或者 x，所以 y 和 z 是一定相等的，这是必要条件，
//然后按任意顺序打印，我们只要知道是 1 个最大值，其余 2 个是最小值就可以了

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	vector<int> a(3);
	while(t--){
		cin>>a[0]>>a[1]>>a[2];
		sort(a.begin(),a.end());
		if(a[1]!=a[2]) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			cout<<a[0]<<" "<<a[0]<<" "<<a[2]<<endl; 
		}
	}
	return 0;
}
