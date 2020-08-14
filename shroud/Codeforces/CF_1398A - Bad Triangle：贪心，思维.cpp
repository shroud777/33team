//题意：给出一个非递减长度为 n 的序列，问中是否存在下标 i,j,k，使得 a[i],a[j],a[k] 不能构成三角形

//思路：贪心思想，直接用最小的两个和最大的比即可，如果这三个都能构成三角形，那么其他的肯定也可以，反之直接输出

#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn=5e4+10;
int a[maxn];
 
bool check(int a,int b,int c){
	if(a+b<=c||a+c<=b||b+c<=a) return true;
	return false;
} 
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(!check(a[1],a[2],a[n])) cout<<-1<<endl;
		else cout<<1<<" "<<2<<" "<<n<<endl;
	}
	return 0;
}
