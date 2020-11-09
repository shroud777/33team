//题意：您需要写一种数据结构（可参考题目标题），来维护一些数，其中需要提供以下操作：
//1.插入 x 数
//2.删除 x 数(若有多个相同的数，因只删除一个)
//3.查询 x 数的排名(排名定义为比当前数小的数的个数 +1 )
//4.查询排名为 x 的数
//5.求 x 的前驱(前驱定义为小于 x，且最大的数)
//6.求 x 的后继(后继定义为大于 x，且最小的数)

//思路：本题为平衡树模板题，做法却有很多很多，这里先用权值线段树+动态开点解决这个问题，后续平衡树以及其他数据结构的解法会陆续更新
//权值线段树做法，首先数据 [-1e7,1e7]，这样数据范围对于一颗权值线段树来说太不友好了，首先实际数据只有 1e5，但他却要浪费巨大的空间
//离散化是一种方法，但是这里用一种更简便的方法，就是动态开点，对于线段树的动态开点，递归到哪个结点就开哪个结点，丝毫没有浪费
//然后对于 1,2 两种操作没什么好说的，权值线段树的单点修改操作
//然后对于第 3 个操作，我们可以统计 [-1e7,x-1] 的区间和，那么 x 就是 sum+1 个数
//第 4 个操作，我们可以利用线段树的二分特性以及权值线段树的桶特性，如果左子树的数的个数大于等于 x，那么排名为 x 的数肯定在左子区间，反之在右子区间找第 x-tree[lc[x]] 个数
//第 5，6 个操作其实差不多，我们可以先找到 x 的前半部分和包括 x 的部分有多少个数，那么我们知道了个数，相当于知道了排名，那么久转换为第 3 种操作了

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;
const int lg=25;

int q,opt,x;
int L,R,tree[maxn*lg],lc[maxn*lg],rc[maxn*lg],tot=0;

inline void update(int x){
	tree[x]=tree[lc[x]]+tree[rc[x]];
}

void modify(int l,int r,int &x,int k){
	if(!x) x=++tot;
	if(l==r){
		tree[x]+=k;
		return;
	}
	int mid=l+r>>1;
	if(L<=mid) modify(l,mid,lc[x],k);
	if(mid<R) modify(mid+1,r,rc[x],k);
	update(x);
}

int query_1(int l,int r,int x){     //查询区间内数的个数 
	if(!x) return 0;
	if(L<=l&&r<=R) return tree[x];
	int mid=l+r>>1;
	int ans=0;
	if(L<=mid) ans+=query_1(l,mid,lc[x]);
	if(mid<R) ans+=query_1(mid+1,r,rc[x]);
	return ans;
}

int query_2(int l,int r,int x,int k){ //查询区间第 k 大 
	int mid=l+r>>1;
	if(l==r) return l;
	if(tree[lc[x]]>=k) return query_2(l,mid,lc[x],k);
	return query_2(mid+1,r,rc[x],k-tree[lc[x]]);
}

int main(){
	scanf("%d",&q);
	int rt=++tot;
	while(q--){
		scanf("%d %d",&opt,&x);
		if(opt==1) L=R=x,modify(-1e7,1e7,rt,1);
		else if(opt==2) L=R=x,modify(-1e7,1e7,rt,-1);
		else if(opt==3) L=-1e7,R=x-1,printf("%d\n",query_1(-1e7,1e7,rt)+1);
		else if(opt==4) printf("%d\n",query_2(-1e7,1e7,rt,x));
		else if(opt==5){
			L=-1e7,R=x-1; 
			int res=query_1(-1e7,1e7,rt);
			printf("%d\n",query_2(-1e7,1e7,rt,res));
		}
		else if(opt==6){
			L=-1e7,R=x;
			int res=query_1(-1e7,1e7,rt);
			printf("%d\n",query_2(-1e7,1e7,rt,res+1));
		}
	}
	return 0;
}
