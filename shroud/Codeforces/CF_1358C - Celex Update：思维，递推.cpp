//题意：有一个每个位置值按一定规律（沿右对角线元素）的格子，给出两个点，求两个点之间距离不同的路的数量

//思路：找规律，官方题解的说明比较好，沿着右到底再往下是权值最小的路径，沿着下到底再往右是最大的路径，从最小的路径开始，可以一次通过值加一衍生出 (x2-x1)*(y2-y1) 条路径，即左下三角形的面积，最后加上最小路径

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<1+(x2-x1)*(y2-y1)<<endl;
	}
  return 0;
}
