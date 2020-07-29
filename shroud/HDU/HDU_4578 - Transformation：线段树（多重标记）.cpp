//题意：有一个初始值全为 0 的长度为 n 的序列下标从(1~n)，一共对该序列进行 4 种操作：
// 1  x y c  [x,y] 内所有数加上 c
// 2  x y c  [x,y] 内所有数乘上 c
// 3  x y c  [x,y] 内所有数变成 c
// 4  x y c  查询 [x,y] 内每个值的 c 次方的和 (1<=c<=3)

//思路：如果抛开查询区间的次方和，那么这道题只需要 lazy-tag 维护即可。我本来以为 c 次方，c 是个很大的数，但仔细一看只有 3，那么可以把每个次方和都记录下，每次操作改变 3 个次方和
//但是每个数的次方和也不是那么容易维护的，根据多项式展开定理来得出 加上 c，乘上 c，变成 c 这三种不同情况下的变化，但是实际上个这几种只用同一个函数也可以维护
//每次 加 c 操作参数就是 （+c ，*1） ，乘 c 就是（+0,*c）,而变成 c 可以看成 （+c，*0）
//同时这里有很多细节，对于这道题来说，多项式展开后的式子不能写错，由于代码量比较大，还是需要仔细点，耐心点
//与此同时，对于 lazy-tag 和 put_lazy 操作，注意要先对乘法进行操作，再对加法进行操作，这些都是值得注意的
//这道题感觉写出来还是蛮不容易的，wa 了一下午，别人都用几百行写的，我竟然同样的方法只用了 90+

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int p=1e4+7;
int n,m,L,R;
struct node{
	ll s1,s2,s3,a,m;
}tree[maxn<<2];

void build(int l,int r,int x){
	tree[x].s1=tree[x].s2=tree[x].s3=tree[x].a=0;
	tree[x].m=1;
	if(l==r) return;
	int mid=l+r>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
}

void update(int x){
	int lc=x<<1,rc=x<<1|1;
	tree[x].s1=(tree[lc].s1+tree[rc].s1)%p;
	tree[x].s2=(tree[lc].s2+tree[rc].s2)%p;
	tree[x].s3=(tree[lc].s3+tree[rc].s3)%p;
}

void put_lazy(int l,int r,int x,int m,int a){
		tree[x].s3=tree[x].s3*m%p*m%p*m%p;
		tree[x].s2=tree[x].s2*m%p*m%p;
		tree[x].s1=tree[x].s1*m%p;
		
		tree[x].a=(tree[x].a*m%p+a)%p;
		tree[x].m=tree[x].m*m%p;

		tree[x].s3=(((tree[x].s1*3*a%p*a%p+tree[x].s2*3*a%p)%p+tree[x].s3)%p+(r-l+1)*a%p*a%p*a%p)%p;
		tree[x].s2=((tree[x].s2+tree[x].s1*2*a)%p+(r-l+1)*a%p*a%p)%p;
		tree[x].s1=(tree[x].s1+(r-l+1)*a%p)%p;
}

void down_lazy(int l,int r,int x){
	if(!tree[x].a&&tree[x].m==1) return;
	if(l==r) return;
	int mid=l+r>>1;
	put_lazy(l,mid,x<<1,tree[x].m,tree[x].a);
	put_lazy(mid+1,r,x<<1|1,tree[x].m,tree[x].a);
	tree[x].a=0;
	tree[x].m=1;
}

void modify(int l,int r,int x,int m,int a){
	if(L<=l&&r<=R){
		put_lazy(l,r,x,m,a);
		return;
	}
	int mid=l+r>>1;
	down_lazy(l,r,x);
	if(L<=mid) modify(l,mid,x<<1,m,a);
	if(mid<R) modify(mid+1,r,x<<1|1,m,a);
	update(x);
}

ll query(int l,int r,int x,int pow){
	if(L<=l&&r<=R){
		if(pow==1) return tree[x].s1;
		else if(pow==2) return tree[x].s2;
		return tree[x].s3;
	}
	down_lazy(l,r,x); 
	int mid=l+r>>1;
	ll ans=0;
	if(L<=mid) ans=(ans+query(l,mid,x<<1,pow))%p;
	if(mid<R) ans=(ans+query(mid+1,r,x<<1|1,pow))%p;
	return ans;
}

int main(){
	while(~scanf("%d %d",&n,&m)&&(n+m)){
		build(1,n,1);
		int d,x,y,c;
		while(m--){
			scanf("%d %d %d %d",&d,&x,&y,&c);
			L=x,R=y;
			if(d==1) modify(1,n,1,1,c);
			else if(d==2) modify(1,n,1,c,0);
			else if(d==3) modify(1,n,1,0,c);
			else printf("%lld\n",query(1,n,1,c)%p);	
		}
	}
	return 0;
}
