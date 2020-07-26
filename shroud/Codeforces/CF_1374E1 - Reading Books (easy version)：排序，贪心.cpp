//题意:Alice和Bob两人都要看 k 本书，给出一个长度为n的序列代表 n 本书的信息，t[i] 代表读这本书需要的时间，x[i] 为 1 代表Alice喜欢看这本书，0 则不喜欢，y[i] 为 1 代表Bob喜欢这本书，0 不喜欢。
//若能从序列中找出一定数量的书，并且其中两个人喜欢的书都要达到 k 本以上，且花费时间最短。不能则输出-1.

//思路：数组 a 按花费时间升序存放只有Alice喜欢的书，b 升序存放只有Bob喜欢的书，合并前min(sizeof a,sizeof b)个 ai 和 bi 到 c 中，a和b中没有被捆绑的数可以扔掉，因为没有人和他一起，如果min(sizeof a,sizeof b)<k只能用c里的代替，排序取前k个。

#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
ll a[maxn],b[maxn],c[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	int t,x,y,cnt1=0,cnt2=0,cnt3=0;
	while(n--){
		cin>>t>>x>>y;
		if(x&&y) c[++cnt3]=t;
		else if(x||y){
			if(x) a[++cnt1]=t;
			else b[++cnt2]=t;
		}
	}
	if(cnt1+cnt3<k||cnt2+cnt3<k){
		cout<<-1<<endl;
		return 0;
	}
	sort(a+1,a+1+cnt1);
	sort(b+1,b+1+cnt2);
	for(int i=1;i<=min(cnt1,cnt2);i++) c[i+cnt3]=a[i]+b[i]; 
	sort(c+1,c+1+cnt3+min(cnt1,cnt2));
	ll ans=0;
	for(int i=1;i<=k;i++) ans+=c[i];
	cout<<ans<<endl;
	return 0;
} 
