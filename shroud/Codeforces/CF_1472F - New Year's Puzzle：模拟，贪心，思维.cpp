//题意：给出一个 n*2 尺寸的方格，并且方格中有 m 格是被锁定的，现在要求你用若干 2*1 或者 1*2 的格子来填充所有非锁定的区域，问是否可行？

//思路：我们从左到右思考策略
//1：首先如果最左端的上下两个方块全是没有锁定的或者全部是锁定的，那我们肯定把他们去掉，变成 (n-1)*2 规模的问题
//2：如果只有一半锁定了，比如上半部锁定了，那我们摆放的方式肯定是固定的，用 1*2 的格子铺剩下的地方，那么我们这时候就要判断下半部第二格有没有被锁定，如果有的话显然就不存在可能的方案，接着我们就要一直这样摆下去
//3：考虑到数据较大，我们只需要判断离当前最近的块的下一个位置即可，如果同上同下，那么相距的位置必须为奇数，反之偶数
//根据上述操作不断从左到右递进即可，另外还需要总共剩余的格子是否为偶数才可以

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int maxn=5e5+10;
 
int n,m;
pii a[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			scanf("%d %d",&a[i].second,&a[i].first);	
		}
		int res=n*2-m;
		if(res&1){
			puts("NO");
			continue;
		}
		sort(a+1,a+m+1);
		bool flag=1;
		for(int i=1;i<=m;i+=2){
			if(i+1>m) break;
			int t=a[i].second==a[i+1].second?1:0;
			if((a[i+1].first-a[i].first)%2!=t){
				flag=0;break;
			}
			if(i+2>m) break;
			if(a[i+1].first==a[i+2].first){
				flag=0;break;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
