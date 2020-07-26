//题意：给定 n 头奶头的高度，共有 q 次查询，每次回答编号 l~r 中所有奶牛的最大高度差

//思路：lazy-tag 中设置两个信息分别维护区间最大值最小值即可

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int mx[maxn<<2],mi[maxn<<2];
int n,q,L,R;
int maxx,minn;

inline int MIN(int x,int y){
	return (x<y)?x:y; 
}
inline int MAX(int x,int y){
	return (x>y)?x:y;
}

inline void update(int x){
	mx[x]=MAX(mx[x<<1],mx[x<<1|1]);
	mi[x]=MIN(mi[x<<1],mi[x<<1|1]);
}

void build(int l,int r,int x){
	if(l==r){
		scanf("%d",&mx[x]);
		mi[x]=mx[x];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	update(x);
}

void query(int l,int r,int x){
	if(L<=l&&r<=R){
		minn=MIN(minn,mi[x]);
		maxx=MAX(maxx,mx[x]);
		return;
	} 
	int mid=l+r>>1;
	if(L<=mid) query(l,mid,x<<1);
	if(mid<R) query(mid+1,r,x<<1|1);
}

int main(){
	scanf("%d %d",&n,&q);
	build(1,n,1);
	while(q--){
		scanf("%d %d",&L,&R);
		maxx=0,minn=0x3f3f3f3f;
		query(1,n,1);
		printf("%d\n",maxx-minn);
	}
	return 0;
}
