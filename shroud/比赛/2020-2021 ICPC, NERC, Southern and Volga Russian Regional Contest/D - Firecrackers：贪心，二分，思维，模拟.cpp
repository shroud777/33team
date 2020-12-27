//题意：现在有一个走廊被分为 n 个 1x1 的区域，从左到右分别为 1 到 n 号，现在坏人在 a 号位置，守卫在 b 号位置，坏人有 m 个炸弹，每个炸弹需要 si 的时间爆炸
//现在每一秒可以按照如下顺序执行操作：
//1.坏人往当前位置的左或右走一格，或者坏人选择原地不动，点燃一个炸弹
//2.在 si 秒前扔下的 i 号炸弹爆炸
//3.守卫向坏人方向走一格
//当守卫和坏人共处一个格子时游戏结束，问坏人在结束前最多可以点燃多少个炸弹并爆炸？

//思路：首先要明确几个关系：
//1.坏人为了让更多的炸弹爆炸，他最多点燃 abs(a-b)+1 个炸弹，并且这 abs(a-b)+1 个炸弹肯定是在一开始的时候就点燃的，因为这样才有更多的时间让他们引爆，不然到最后走了一段路程再点燃，肯定不如这样号
//2.为了尽可能多的炸弹爆炸，肯定要选择爆炸时间短一些的
//3.留给炸弹爆炸的时间是确定的，一般就是 (a<b?b-1:n-b)-1-cnt，cnt 是已经点燃的炸弹个数，因为点燃一个炸弹留给其他炸弹的时间就少了 1
//这里思路基本上明确了，我们可以延申出两种做法：
//O(n) 做法：
//既然留给炸弹的爆炸时间确定了，我们只要对炸弹爆炸时间降序，我们只要贪心地，因为剩余时间越来越短，所以尽可能让爆炸时间长的炸弹先爆炸，并且设置最多点燃炸弹的限制即可
//O(nlogn) 做法：
//我们可以二分答案，假设可以爆炸的炸弹个数为 mid
//那么我们只要选择前 mid 小爆炸时间的炸弹来 check 能否爆炸即可，并且这 mid 个炸弹中爆炸时间最长的肯定先点燃

//O(n) 做法：

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int maxn=2e5+10;
 
ll n,m,a,b;
ll s[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>a>>b;
		//最多放 b-a-1 个炸弹
		for(int i=1;i<=m;i++) scanf("%lld",&s[i]);
		sort(s+1,s+m+1,greater<ll>());
		ll cnt=0,temp,mx;
		if(a<b) temp=b-1,mx=b-a-1;
		else temp=n-b,mx=a-b-1;
		for(int i=1;i<=m;i++){
			if(cnt==mx) break;
			if(temp-cnt>s[i]) cnt++;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}

//O(nlogn) 做法：

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=2e5+10;
 
int n,m,a,b,temp,s[maxn];
 
bool check(int x){
	for(int i=x;i>=1;--i){
		if(temp-x+i<=s[i]) return false; 
	}
	return true;
}
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>a>>b;
		for(int i=1;i<=m;i++) scanf("%d",&s[i]);
		sort(s+1,s+m+1);
		temp=a<b?b-1:n-b;
		int l=0,r=min(a<b?b-a-1:a-b-1,m),ans;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)) ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
