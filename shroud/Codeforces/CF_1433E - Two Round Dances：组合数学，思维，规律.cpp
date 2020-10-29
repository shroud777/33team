//题意：有 n 个人（n为偶数），现在要选择 n/2 组成一支队伍，剩余的人组成另一只队伍，求队伍组成的不同方案数，其中如果两支队伍分别首尾相连成环，两个环完全相同，则视为相同

//思路：1.组合数求方案，首先从 n 个人中选择 n/2 个人。然后我们固定一个头，剩余部分不同方案数为 (n/2-1)!，另外一支队伍也是如此。但是要注意这里还要除以2，因为（x,y）和（y,x）序对会重复
//2.找规律，最后发现 ans(n)=n!/(n*n/2)


//方案2题解：

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=3e5+10;
 
ll n,c[35];
 
void init(){
	c[0]=1;
	for(int i=1;i<=30;i++) c[i]=c[i-1]*1ll*i;//cout<<i<<" "<<c[i]<<endl; 
}
 
inline ll cal(int n,int m){
	return c[n]/(c[n-m]*c[m]);
}
 
int main(){
	//cout<<"ans:"<<1ll*2432902008176640000/12164510040883200<<endl;
	init();
	cin>>n;
	cout<<c[n]/(n*n/2)<<endl;
	return 0;
} 
