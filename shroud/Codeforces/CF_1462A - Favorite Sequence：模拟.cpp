//题意：有一个长度为 n 的序列 a，现在把序列 a 的元素按照下列规则写到白板上：
//把 a1 写在最左边，把 a2 写在最右边，把 a3 写在当前坐左边（a1 的右边），把 a4 写在当前最右边（a2 的左边）
//现在给出在白板上的序列，还原原序列

//思路；按照题意模拟即可，显然原序列就是先后在最左边和最右边取数

#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
 
int n,a[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int l=0,r=n+1;
		for(int i=1;i<=n;i++){
			if(i&1) printf("%d ",a[++l]);
			else printf("%d ",a[--r]);
		}
		printf("\n");
	}
	return 0;
} 
