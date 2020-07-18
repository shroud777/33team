//题意：给定长度为 n 的 a 数组，问最少需要消除多少 a 的前缀使得成为 good 序列，good 序列的定义是，对于 good 数组 b，每次从他首尾拿去元素，最后得到一个非递减的数组 c

//思路：由从两边拿得到一个非递减的序列可以想到，想要成为 good 序列，那么他肯定是一个单调递增/递减，或者先递增后递减，趋势呈现倒 V 型的序列。同时换句话说，满足这三种情况也就是序列不能呈 V 型，先递减后递增
//那么想要把 a 变成这样的序列，我们可以让 a 不是 V 型趋势的序列就可以了，那么我们从后往前，找到序列元素呈下降趋势后的第一次上升，那么当前位置的后半段即使符合要求的，前半段需要删去

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int maxn=2e5+10;
int a[maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		bool f=0;
		int t=0;
		for(int i=n;i>=1;i--){
			if(f&&a[i]<a[i-1]){
				t=i-1;
				break;
			}
			if(a[i]>a[i-1]) f=1;
		}
		cout<<t<<endl;
	}
	return 0;
}
