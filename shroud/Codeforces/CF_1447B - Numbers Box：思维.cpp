//给出一个 n*m 大小的矩阵，矩阵中所有的元素皆为整数，现在可以对两个相邻元素作操作，使两个元素都乘以 -1，现在可以对矩阵作若干次操作，是的操作后的矩阵值尽可能大

//首先我们可以考虑到，对于任意两个连续的负数元素，我们只要作一次操作，就可以使他们全变成正数
//对于两个一正一负的数，我们作操作相当于交换他们的位置
//基于上述结论，我们首先可以想象到我们可以把所有负数元素通过交换聚集到一起，然后我们讨论负数个数的奇偶性，如果个数为偶数，那么可以全部转化为正数，如果为奇数，那么就要剩一个了
//对于零其实有很多处理方法

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int n,m,x,sum,cnt,cnt_0;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int mi=105;
		sum=cnt=cnt_0=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&x);
				if(!x) cnt_0++;
				if(x<0){
					cnt++;
					x=-x;
					sum+=x;
				}
				else sum+=x;
				mi=min(mi,x);
			}
		}
		if(cnt&1&&!cnt_0) cout<<sum-2*mi<<endl;
		else cout<<sum<<endl;
	}
	return 0;
}
