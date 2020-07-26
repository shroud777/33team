//题意：有一块长为 x ，宽为 y 的蛋糕，要把他切成等面积的 n 块，每次切必须平行长或者宽地把他切成两块，要求 n 块蛋糕的长边与短边的比值的最大值最小

//思路：数据大小 n = 10，直接暴力DFS，因为每一刀切的位置都是平行的，枚举一下切的位置，然后只剩一块的时候返回当前的比值

#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
double dfs(double a,double b,double k){
	if(k==1) return max(a,b)/min(a,b);
	double ans=0x3f3f3f3f;
	for(int i=1;i<=k/2;i++){
		ans=min(ans,max(dfs(a/k*i,b,i),dfs(a/k*(k-i),b,k-i)));
		ans=min(ans,max(dfs(a,b/k*i,i),dfs(a,b/k*(k-i),k-i)));
	}
	return ans;
}
int main(){
	int n;
	double x,y;
	cin>>x>>y>>n;
	cout<<fixed<<setprecision(6)<<dfs(x,y,n)<<endl;	
	return 0;
}
