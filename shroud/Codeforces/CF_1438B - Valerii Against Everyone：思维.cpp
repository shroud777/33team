//题意：给出一个长度为 n 的序列 ai，bi = 2 ^ ai，现在要求找到两个区间 [l1,r1] [l2,r2] 并满足 1<=l1<=r1<l2<=r2<=n,使得 bi 在两个区间内的和相等

//思路；这道题虽然比较简单，但是从某些方向来讲，如果思维被局限住了的话那就怎么也想不到了，我就被卡了好久。。。。
//首先对于原序列如果存在两个相等的 ai,aj(i!=j)，那么答案显而易见
//但是如果不存在这样的两个元素，那么我们就要通过区间相加来获得答案了，并且序列 a 相加类似于二进制加法，两个相同的 x 相加可以得到一个 x+1
//那么如果我们想要通过相加进位来得到解，肯定也要存在两个相等的来进位，那么我们只要判断原序列是否存在两个相等的数即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=2e5+10;
 
int n;
map<int,int> mp;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		mp.clear();
		bool f=0;
		int x;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(mp[x]) f=1;
			mp[x]++;
		}
		if(f) puts("YES");
		else puts("NO");
	}
	return 0;
} 
