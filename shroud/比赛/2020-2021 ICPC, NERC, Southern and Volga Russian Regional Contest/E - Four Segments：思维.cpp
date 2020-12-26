//题意：给出 4 条线段的长度，现在要求使线段构成一个封闭的矩形，线段可以相交，问矩形的最大面积

//思路：首先矩形的长或宽取决于各自两两平行线段中最短的那一条，那么很明显，设四条边从小到大排序后为 a1,a2,a3,a4，那么 a1 是肯定要作为宽的，另外可以选择 a2 or a3 作为长
//那么最后的答案肯定是 a1*a3

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int a[10];

int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=1;i<=4;i++) cin>>a[i];
		sort(a+1,a+5);
		cout<<1ll*a[1]*a[3]<<endl;
	}
	
	return 0;
}
