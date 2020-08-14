//题意：在 n*m 的二维空间里，给出一个点，该点每次可以移动到同行或者同列的每个位置，所有位置只能经过一次，输出遍历空间每一个点的方案

//思路：模拟即可。把当前的行或者列走完，然后以列和行为单位，从 1-n-n-1 或 1-m-m-1 即可

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,m,x,y;
	scanf("%d %d %d %d",&n,&m,&x,&y);
	cout<<x<<" "<<y<<endl;
	for(int i=1;i<=m;i++){
		if(i==y) continue;
		else cout<<x<<" "<<i<<endl;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt++;
		if(i==x){
			cnt--;
			continue;
		}
		if(cnt&1) for(int j=m;j>=1;j--) cout<<i<<" "<<j<<endl;
		else for(int j=1;j<=m;j++) cout<<i<<" "<<j<<endl; 
	}
	return 0;
}
