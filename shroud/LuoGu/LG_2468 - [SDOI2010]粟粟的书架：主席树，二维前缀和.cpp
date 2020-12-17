//题意：给出一个 n*m 的二维序列，有 q 组询问，每组询问给出两个坐标 (x1,y1) (x2,y2) 和一个 h，问最少在给出坐标范围内取多少个元素使得和大于等于 h
//对于50%的数据，满足R, C≤200，M≤200,000
//另有50%的数据，满足R＝1，C≤500,000，M≤20,000

//思路：我们可以发现数据可以分为两种类型，一种就是二维序列，一种其实是一维的序列
//首先要明确，我们肯定是贪心找二维或一维区间内的未被选取的最大值
//对于二维序列，我们可以预处理出二维前缀和，并且要设置一个限制，即大于等于 k 的二维前缀和 f[i][j][k]，然后就可以对区间进行二分答案，设选中的最小的值为 mid
//上述做法我们将最优解问题转化为可行性问题，利用函数的单调性，使用二分降低复杂度
//那么对于一维序列我们怎么做呢？
//其实可以参考二维的，但是一维的数据过大难以维护，我们这里可以使用主席树，以每个下标建立一个历史版本的权值线段树，每个结点维护的是权值的个数和总值，那么我们可以参考第 k 大元素的做法
//这里我们优先于找大的，那么我们可以首先判断右子区间的总值是否满足要求，满足的话递归右子区间，否则递归左子区间，总值减去右子区间的总值
//注意到这里当 l==r 即到了某个结点时，要返回的值应该是 当前要求的值/当前结点的值（向上取整）

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;
const int maxlog=25;

int n,m,q,h;
int rt[maxn],lc[maxn*25],rc[maxn*25],sz[maxn*25],sum[maxn*25],tot=0;
int a[205][205],f[205][205][1005],cnt[205][205][1005];

inline void update(int x){
	sz[x]=sz[lc[x]]+sz[rc[x]];
	sum[x]=sum[lc[x]]+sum[rc[x]];
}

void modify(int l,int r,int &x,int last,int pos){
	x=++tot;
	lc[x]=lc[last];
	rc[x]=rc[last];
	if(l==r){
		sz[x]=sz[last]+1;
		sum[x]=sum[last]+l;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,lc[x],lc[last],pos);
	else modify(mid+1,r,rc[x],rc[last],pos);
	update(x);
}

int query(int l,int r,int xl,int xr,int k){
	if(l==r) return (k-1)/l+1;
	int d1=sum[rc[xr]]-sum[rc[xl]];
	int d2=sz[rc[xr]]-sz[rc[xl]];
	//cout<<"区间："<<l<<" "<<r<<" "<<"最大值："<<d1<<" "<<d2<<endl;
	int mid=l+r>>1;
	if(d1>=k) return query(mid+1,r,rc[xl],rc[xr],k);
	return query(l,mid,lc[xl],lc[xr],k-d1)+d2;
}

int s(int x1,int y1,int x2,int y2,int k){
	return f[x2][y2][k]-f[x1-1][y2][k]-f[x2][y1-1][k]+f[x1-1][y1-1][k];
}

int c(int x1,int y1,int x2,int y2,int k){
	return cnt[x2][y2][k]-cnt[x1-1][y2][k]-cnt[x2][y1-1][k]+cnt[x1-1][y1-1][k];
}

int main(){
	scanf("%d %d %d",&n,&m,&q);
	if(n==1){
		int x;
		for(int i=1;i<=m;i++){
			scanf("%d",&x);
			modify(1,1000,rt[i],rt[i-1],x);
		}
		int x1,x2,L,R;
		while(q--){
			scanf("%d %d %d %d %d",&x1,&L,&x2,&R,&h);
			if(sum[rt[R]]-sum[rt[L-1]]<h){
				puts("Poor QLW");
				continue;
			}
			printf("%d\n",query(1,1000,rt[L-1],rt[R],h));
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
		}
		for(int k=1;k<=1000;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					f[i][j][k]=f[i][j-1][k]+f[i-1][j][k]-f[i-1][j-1][k]+(a[i][j]>=k?a[i][j]:0);
					cnt[i][j][k]=cnt[i][j-1][k]+cnt[i-1][j][k]-cnt[i-1][j-1][k]+(a[i][j]>=k?1:0);
				}
			}
		}
		int x1,y1,x2,y2;
		while(q--){
			scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&h);
			int l=1,r=1000,ans=-1;
			while(l<=r){
				int mid=l+r>>1;
				//cout<<mid<<" "<<s(x1,y1,x2,y2,mid)<<endl; 
				if(s(x1,y1,x2,y2,mid)>=h) ans=mid,l=mid+1;
				else r=mid-1;
			}
			if(ans==-1) puts("Poor QLW");
			else{
				printf("%d\n",c(x1,y1,x2,y2,ans)-(s(x1,y1,x2,y2,ans)-h)/ans);
			}
		}
	}
	return 0;
} 
