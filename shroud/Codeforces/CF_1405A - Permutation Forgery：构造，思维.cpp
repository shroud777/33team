//题意：给出一个长度为 n 的 1-n 的全排列 p，规定 F(p)=sort([p1+p2,p2+p3,…,pn−1+pn])，要求输出一个与给出全排列不同排列顺序的全排列 p'，使得 F(p')=F(p)

//思路：相对位置不变，逆序输出即可

#include <bits/stdc++.h>
 
using namespace std;	
typedef long long ll;
const int maxn=105;
 
int n,a[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=n;i>=1;i--) printf("%d%c",a[i],i==1?'\n':' ');
	}
	return 0;
}
