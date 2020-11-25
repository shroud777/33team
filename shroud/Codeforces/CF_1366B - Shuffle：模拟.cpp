//题意：给出一个长度为 n 的序列，初始状态除了 x 位置的值为 1，其他位置全为 0，现在有 m 组操作，每次给出一个区间 [l,r] 你可以交换这个区间内的任意两个位置的数（下标可以相等）,现在结束后有几个位置可能是 1

//思路：按照题意每次扩大有效区间即可，只要当前给出的区间和有效区间有交集就取并集，最后答案 r-l+1

By shroud777#, contest: Educational Codeforces Round 89 (Rated for Div. 2), problem: (B) Shuffle, Accepted, #, Copy
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
 
int n,xx,m;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>n>>xx>>m;
		l=r=xx;
		int x,y;
		while(m--){
			cin>>x>>y;
			if(l<=y&&l>=x) l=min(l,x);
			if(r>=x&&r<=y) r=max(r,y);
		}
		cout<<r-l+1<<endl;
	}
	return 0;
}
