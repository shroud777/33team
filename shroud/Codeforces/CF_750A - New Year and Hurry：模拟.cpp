//题意：现在离派对开始还剩 4 个小时，第 i 场比赛需要花 5*i 分钟，现在有 n 场比赛，他需要 k 分钟准备，问他最多能打多少场比赛

//思路：剩余时间尽可能打多的比赛，模拟即可

#include <iostream>
#include <cstring> 
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;

ll a[maxn];
int n,k;

int main(){
	scanf("%d %d",&n,&k);
	k=240-k;
	int res=0;
	for(int i=1;;i++){
		if(k-5*i<0) break;
		k-=5*i;
		res++;
	}
	cout<<min(res,n)<<endl;
	return 0;
}
