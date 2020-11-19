//题意：给出一个 n*m 的矩阵，并且每个位置存在一个权值 a(i,j)，现在要求矩阵中任意两个相邻元素的权值不相等，并且你可以对每个元素执行至多一次加一操作，问操作后的矩阵

//思路：挺好的一个思维题，相邻元素不相等，其实类似于国际跳棋黑白格那种样子，我们想想怎么利用 +1 这个限度构造出这样的局面呢
//如果以值为目标，那样讲很难控制，但是有一个维度是与要求相符的，就是一个数的奇偶性，两个数奇偶不相等，那么值肯定也不相等，同时只需要 +1 就可以改变值的奇偶，那么答案很简单，固定格子的奇偶即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;

int n,m;

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ll tot=0,x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>x;
				tot++;
				if((tot&1)!=(x&1)) x++;
				printf("%lld%c",x,j==m?'\n':' ');
			}
			if(m%2==0) tot++;
		}
	}
	return 0;
}
