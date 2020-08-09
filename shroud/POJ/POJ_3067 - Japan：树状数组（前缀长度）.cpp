//题意：日本东岸有 n 个城市（在一条直线上），西岸有 m 个城市（平行于东岸的城市线），建立 k 条高速公路连接东西岸，问有几条线条相交

//思路：可以以高速公路的一端的城市序号为主要关键字升序排列，另一端次要关键字升序，那么我们每一次安放高速公路，可以发现按照顺序放下去，当前的线条当前只会和主要关键字城市序号比他小的相交
//并且相交的都是那些次要关键字城市序号比它大的公路，那么我们只要对数据进行排序后对 [y,m] （这里以东岸序号为主要关键字）内的公路数量统计即可，每次只需要询问和维护即可


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=1005;
int n,m,k;
ll tree[maxn];
struct node{
	int x,y;
}a[maxn*maxn];

bool cmp(node n1,node n2){
	if(n1.x==n2.x) return n1.y<=n2.y;
 	return n1.x<n2.x;
}


int lowbit(int x){
	return x&-x;
}

void add(int x,int k){
	while(x<=m){
		tree[x]+=k;
		x+=lowbit(x);
	}
}

ll query(int x){
	ll ans=0;
	while(x){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d %d %d",&n,&m,&k);
		for(int i=1;i<=k;i++) scanf("%d %d",&a[i].x,&a[i].y);
		sort(a+1,a+k+1,cmp);
		memset(tree,0,sizeof tree);
		ll ans=0;
		for(int i=1;i<=k;i++){
			add(a[i].y,1);
			ans+=query(m)-query(a[i].y);
		}
		printf("Test case %d: %lld\n",t,ans);
	}
	return 0;
}
