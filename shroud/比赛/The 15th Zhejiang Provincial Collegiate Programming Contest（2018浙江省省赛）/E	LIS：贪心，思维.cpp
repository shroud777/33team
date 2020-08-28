//题意：有一个长度为 n 的序列，给出该序列每个元素对应的 LIS 值，并给出原序列每个元素的值的区间范围，求原序列

//思路：如果当前位置的 LIS 值在之前以前出现过，说明他和相同 LIS 位置的值相比呈非递增，那么我们可以得到一个用贪心的思路求思考，从 1 开始，我们可以让相同 LIS 位置的一批数的最后一个取最小值
//这里也就是最右端的 LIS=1 的元素，这个元素的值尽可能小，那么前面相同 LIS 值的地方就有更多的选择，按照这个思想，我们可以解决所有相同 LIS 值位置的元素
//但是对于不同 LIS 值的元素我们又要另作考虑，如果当前元素为 w（w>1），那么 w 肯定要比之前某个 LIS = w-1 的元素值大，由于我们上面的原则，那只要比他前面最近的 LIS = w-1 的大 1 就可以了
//这里我们预处理出所有 w 前一个元素的位置，然后按照贪心的思想不断的维护出答案即可

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int n;

struct node{
	int id,f,l,r;
	bool operator <(const node &oth)const{
		if(f==oth.f) return id>oth.id;
		return f<oth.f;
	}
}a[maxn];

int ans[maxn],last[maxn],pos[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i].f),a[i].id=i;
		for(int i=1;i<=n;i++) scanf("%d %d",&a[i].l,&a[i].r);
		int L;
		memset(last,0,sizeof last);
		for(int i=1;i<=n;i++){
			pos[i]=last[a[i].f-1];
			last[a[i].f]=i;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(pos[a[i].id]) a[i].l=max(a[i].l,ans[pos[a[i].id]]+1);
			if(i==1||a[i].f!=a[i-1].f){
				ans[a[i].id]=L=a[i].l;
				continue;
			}
			L=max(L,a[i].l);
			ans[a[i].id]=L;
		}
		for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return 0;
}
