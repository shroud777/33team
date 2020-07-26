//题意：给定一个长度为 2^k 的字符串，问它最少能通过修改几个字符变成 'a'-string  (c='a') ,
//要成为c-string 就要满足一下 3 个条件  (这里 c 代指某个小写拉丁字母)
//1.字符串长度为 1,且由 c 组成。
//2.字符串前半段由 c-string 组成，后半段由 c+1-string 组成，例如 “aaaabbcd” 
//3.字符串后半段由 c+1-stirng 组成，前半段由 c-string 组成，例如 “cdbbaaaa”

//思路：明显的 O(logn) 递归树式递归，刚开始理解错题意耽误了点时间，但主要还是因为对递归理解不够深才会如此
//之后虽然递归写对了，但是想法比较 low，就是递归出 n 个字符串然后和原字符串暴力对比，显然超时
//其实不用特地构建字符串，因为这个递归思路来看，你当前是构建 c-string ,那么你左半边或者右半边应该已经确定了是 c ，然后再去递归右半边或左半边为 c+1-sring,所以可以用确定了的和原串比较并记录值一直递归下去

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int maxn=2e5+10;
string st;
int res;
int len;
void solve(int l,int r,char c,int cnt){
	if(l==r){
		if(st[l]!=c) cnt++;
		res=min(res,cnt);
		return;
	}
	int cnt1,cnt2;
	cnt1=cnt2=cnt;
	int mid=l+r>>1;
	for(int i=l;i<=mid;i++) if(st[i]!=c) cnt2++;
	for(int i=mid+1;i<=r;i++) if(st[i]!=c) cnt1++;
	solve(l,mid,c+1,cnt1);
	solve(mid+1,r,c+1,cnt2);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		res=0x3f3f3f3f;
		cin>>len>>st;
		solve(0,len-1,'a',0);
		cout<<res<<endl;
	}
}
