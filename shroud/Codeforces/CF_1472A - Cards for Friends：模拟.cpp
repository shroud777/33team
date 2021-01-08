//题意：有一张 w*h 尺寸的贺卡，现在如果 w 为偶数，就可以将当前贺卡分成 2 张 w/2*h 的贺卡，h 上同理，问能否将贺卡按照上述要求并且足够分给 n 个人

//思路：模拟即可，如果 w，h 某一为偶数，就相当于对折一次，最后答案个数就是 w 可以对折的次数 * h 可以对折的次数

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn],b[maxn];

int main(){
	int t,x,y;
	cin>>t;
	while(t--){
		cin>>x>>y>>n;
		int cnt1,cnt2;
		cnt1=cnt2=1;
		while(x&&x%2==0) cnt1<<=1,x>>=1;
		while(y&&y%2==0) cnt2<<=1,y>>=1;
		ll temp=1ll*cnt1*cnt2;
		if(temp>=n) puts("YES");
		else puts("NO");
	}	
	return 0;
} 
