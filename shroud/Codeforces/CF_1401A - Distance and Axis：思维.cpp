//题意：在 x 轴正半轴上，有两个点 A 和 B，现给出 A 点坐标和一个整数 k，现在可以移动 A，要求得到使 A 点到 B 点的距离和 原点 到 B 点的距离的差值等于 k 的最小代价
 

//思路：首先要清楚这个差值的最大值就是 A 现在的距离，就是把 B 点放在 原点 时的情况，那么如果 k 大于 A，那么我们只能将 A 向右移动，那么这个数就是 k-Ax
//另外，如果这个数值比 A 小，那么 B 的位置就应该处在 原点 和 A 的中间，那么我们可以想象，这个差值的奇偶性永远和 Ax 的奇偶性相同，因为 B 每次移动都是 +-2，那么我们只要看两者的奇偶是否相同即可
//如果相同则不需要调整 A，因为中间肯定有个位置满足条件，反之贼需要移动一格的位置

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=2e5+10;
int a[maxn];
int n,k;

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(n>=k) {
			if(n%2!=k%2) cout<<1<<endl;
			else cout<<0<<endl;
		}
		else{
			cout<<k-n<<endl;
		} 
	}
	
	return 0;
}
