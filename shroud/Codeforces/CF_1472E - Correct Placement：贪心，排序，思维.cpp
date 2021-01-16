//题意：现在有 n 张照片，尺寸为 wi*hi，现在要按一定的顺序摆放，且只有 wi<wj && hi<hj 或 wi<hj && hi<wj 的照片 i 才可以放在 j 之前，输出每张照片 i 前面可以放的任意一张照片 j 的编号

//思路：首先我们可以统一一下 w 和 h，对于题目的条件，我们发现无所谓长还是宽，其实只要满足要求即可排在前面，所以我们先将这两个参数以大小为基准，设 li=min(wi,hi)，ri=min(wi,hi)
//这样我们就可以更好的去比较了，然后我们按照 li 升序排序，这样我们可以保证 li，只需要比较 ri 即可，我们要找一个 rj 比当前 ri 小，且 lj 不能等于 li 的，那么我们可以用一个变量，记录所有 [1,li-1] 的最小值即可
//如果 ri 小于等于这个最小值，说明不存在解，反之存在解

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

int n,ans[maxn];
struct node{
	int l,r,id;
	bool operator <(const node&oth)const{
		return l<oth.l;
	}
}a[maxn];

int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&a[i].l,&a[i].r);
			a[i].id=i;
			if(a[i].l>a[i].r) swap(a[i].l,a[i].r);
 		}
		sort(a+1,a+n+1);
		int mi=0x3f3f3f3f,id,p=1;
		for(int i=1;i<=n;i++){
			while(a[i].l!=a[p].l){
				if(a[p].r<mi) mi=a[p].r,id=a[p].id;
				p++;
			}
			if(a[i].r<=mi) ans[a[i].id]=-1;
			else ans[a[i].id]=id;
		}
		for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return 0;
}
