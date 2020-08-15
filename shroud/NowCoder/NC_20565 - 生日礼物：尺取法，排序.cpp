//题意：在坐标轴上存在 n 个彩珠，且一共有 k 种类型的彩珠，给出每种彩珠的分布位置，问一包含所有种类彩珠的最短区间长度是多少？

//思路：尺取思想，设立双指针，尾指针不断向后移动，当满足要求时头指针才向后移动，找出最小的情况

#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;
int n,k;

struct node{
	int id,d;
	bool operator < (const node &other) const{
		return d<other.d;
	}
}a[maxn];

int main(){
	scanf("%d %d",&n,&k);
	int x,m,tot=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&x);
		for(int j=1;j<=x;j++) scanf("%d",&m),a[++tot].d=m,a[tot].id=i;
	}
	sort(a+1,a+n+1);
	map<int,int> mp;
	int cnt=0;
	int j=1;
	int ans=1e9+5;
	for(int i=1;i<=n;i++){
		if(!mp[a[i].id]) cnt++;
		mp[a[i].id]++;
		if(cnt==k){
			for(j; ;j++){
				mp[a[j].id]--;
				if(!mp[a[j].id]) cnt--;
				if(cnt!=k){
					ans=min(ans,a[i].d-a[j].d);
					while(a[j].d==a[j+1].d){
						mp[a[j+1].id]--;
						if(!mp[a[j+1].id]) cnt--;
						j++;
					}
					j++;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
