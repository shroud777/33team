//题意：有 n 台机器，m 项任务，每台机器有一个工作时间 x 和工作等级 y ，每项任务也有完成所需时间 x 和任务等级 y ，只要一台机器的工作等级和工作时间都不小于任务的等级和时间，才能做这项工作，每台机器只能完成一个任务
//问完成任务做多情况下，报酬最高的做法，完成每项任务的报酬为 500*x+2*y

//思路；由于 y 的数据很小，所有 y 对于报酬的大小无影响，我们只需要看 x 即可，x 越高越好，那么我们使用贪心策略，尽可能先完成 x 比较大的任务，我们对 x 和 y 都降序排列，同时对机器的 x 和 y 也都降序
//这样我们先找当前满足当前任务后 y 最小的机器，因为由于我们的排序顺序，后面的任务的 x 肯定都是满足所选出来的机器的 x 的，而前一台机器选择了越小的 y，那么后面的机器就有更多的选择机会


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int n,m;

struct node{
	int x,y;
	bool operator <(const node &oth)const{
		if(x==oth.x) return y>oth.y;
		return x>oth.x;
	}
}a[maxn],b[maxn];

int cnt[maxn];

int main(){
	while(~scanf("%d %d",&n,&m)){
		for(int i=1;i<=n;i++) scanf("%d %d",&a[i].x,&a[i].y);
		for(int i=1;i<=m;i++) scanf("%d %d",&b[i].x,&b[i].y);
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		memset(cnt,0,sizeof cnt);
		int temp=1;
		ll ans=0,tot=0;
		for(int i=1;i<=m;i++){
			while(b[i].x<=a[temp].x&&temp<=n) cnt[a[temp].y]++,temp++;
			for(int j=b[i].y;j<=100;j++){
				if(cnt[j]){
					tot++;ans+=1ll*500*b[i].x+1ll*2*b[i].y;
					cnt[j]--;
					break;
				}
			}
		}
		printf("%lld %lld\n",tot,ans);
	}
	return 0;
}
