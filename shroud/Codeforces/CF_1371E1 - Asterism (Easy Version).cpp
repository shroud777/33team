//题意：Yuzu 有 x 个糖果，一个序列由 n 个数组成的序列 ai，分别代表第 i 个 badman 身上的糖果数，p(a) 是对 ai 下标的某种全排列 （1~n），即 ai 的顺序  例如 P ={1,3,2}，则按照 a1，a3，a2的方式出现
//Yuzu 将和 n 个 badman 按照 p（a）的顺序，进行 n 次 battle，如果 Yuzu 当前的糖果数比 pi 大或者相等，那么则算击败了这个 badman 并获得了他的糖果并能用在接下来的 battle 中
//Yuzu 要战胜所有 badman ，这会存在多少种 P（a）呢？即 badman 的出场顺序
//同时定义 f（x） 代表当 Yuzu 糖果数为 x 时，存在的大获全胜的 P（a）的种数
//再给出一个 mod ，如果 f（x）% mod != 0 ，那么 x 就是 good 的
//求存在多少个 good 的 x？

//思路：首先我们确顶序列 a 的元素和个数是固定的，设想 f(x) 的数量显然和 x 的大小也密切相关，如果 x 比 a 序列中最小的数小，那么这个 f(x) = 0，如果 x 大于 a 中最大的元素，那么 f(x) = n!
//所有这个数 f(x) 的有效值和递增是在一个范围里的，我们可以缩小区间，然后对于每个 x ，从每轮都赢的角度他在和第 i 个 badman battle 的时候他应该就有 x+i-1 个糖果
//由于这里 n 有1000，如果每次都 O(n) 进行检索那么单次判断 f(x) 就会达到 1e6，所以这里要用二分把 O(n^2) 降到 O(n*logn) 
//然后每次找到的数 s 代表当前这个位置可以有多少种选择，然后前面 i-1 次已经选掉了 i-1 个，且根据单调性，前面选中的数肯定实在这些数里面的，因此这里就剩 s-i+1 种选择了（代码里我 i 是从 0 开始的）
//记得每次乘上之后都要模 mod ，然后如果 res 出现 0，就说明这个 f(x) 存在 mod 的倍数， x 不可能 good 了

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2005];
int n,p;
bool check(int x){
	ll res=1;
	for(int i=0;i<n;i++){
		//x+i;
		//a[i]<=x+i
		int s=upper_bound(a+1,a+n+1,x+i)-a-1;
		//s-i;
		res=(res*(s-i))%p;
		if(!res) return false;
	}
	return res;
}
int main(){
	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	//x+n-1>=an;
	int st=a[n]+1-n;
	vector<int> ans;
	for(int i=st;i<=a[n];i++){
		if(check(i)) ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	if(ans.size()) cout<<ans[0];
	for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
	cout<<endl;
}
