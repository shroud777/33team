//题意：在一个二维网格中，要从 (0,0) 走到 (x,y)，且一共有五种操作，即每次 x 加减 1，或 y 加减 1，或静止，且相邻两次操作不能相同，问最少多少次操作可以到达 (x,y)

//思路：(0,0) 到 (x,y)，横纵坐标必然只需要加，那么对于 x 和 y 相同的部分，可以交替进行，x 和 y 中较大的可以和暂停交替进行
//xyxyxyx?x?x 这样的，所以答案就是 2*max(x,y)+1
//但是考虑到 x 和 y 相等的情况，我们还要加 1，因为没有任何暂停操作

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
	int t;
	cin>>t;
	int x,y;
	while(t--){
		cin>>x>>y;
		int ans=0;
		ans=max(x,y)*2-1;
		if(x==y) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
