//题意：给出一个数 n，要求你找到这样一个序列，序列满足如下要求：1.序列每个元素都大于 1。2.序列所有元素的乘积为 n。3.序列每个元素都整除前一个元素（如果存在的话）。4.序列长度尽可能长

//思路：根据题意要求，可以发现序列就是对 n 进行质因子分解，这样能保证第 1,2，4 个条件，那么第 3 个条件怎么满足呢
//我一开始是想不断分解，记录前一个因子，直到剩余数无法整除上一个因子，说明要把剩余数和上一个因子作为一个元素，但是这样显然是不行的，因为都是质因子，只要除外某一个相同的质因子，后面无法继续分解
//例如  2*3*3*3 这样的，由于分解出来的都是质因子，那么其实只有前后元素具有相同因子，才可能整除，所以我们要找最多的那个因子数，如果个数小于等于 1 就没法实现，反之为 cnt-1 个最多个数的因子和 1 个最多个数的因子和剩余因子的乘积

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
 
ll n,mx,temp;
vector<ll> v;
 
void get(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			int cnt=0;
			while(n%i==0) n/=i,cnt++;
			if(cnt>mx){
				mx=cnt;
				temp=i;
			}
		}
	}
}
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		mx=0;
		get(n);
		if(mx<=1){
			cout<<1<<endl<<n<<endl;
			continue;
		}
		cout<<mx<<endl;
		for(int i=1;i<=mx-1;i++){
			cout<<temp<<" ";
			n/=temp;
		}
		cout<<n<<endl;
	}
	return 0;
} 
