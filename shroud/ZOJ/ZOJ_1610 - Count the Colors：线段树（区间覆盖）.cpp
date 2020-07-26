//题意：对一个 [0,8000] 的区间进行操作，每次给出 l r c ，代表对以 l 为区间左端点，r 为区间右端点的区间涂成 c，后涂的可以覆盖前面涂的，问最后可以看到多少个颜色的区间

//思路：线段树。线段树每个点都是有长度的，而题中给出的只是端点，比如 l=0,r=1 在线段树上就代表长度为 1 的 [1,1] 结点。并且这道题是进行区间覆盖，只需要修改 lazy-tag 即可
//最后由于是查询每种颜色区间的个数而不是颜色的个数，因此要每个点暴力查询颜色，然后如果和上一个点不一样并且不等于 lazy-tag 的初始值，就说明有一个新的颜色区间。

#include <bits/stdc++.h>
using namespace std;
const int maxn=8005;
int lazy[maxn*4];
int n,L,R;

void put_lazy(int l,int r,int x,int c){
	lazy[x]=c;
}

void down_lazy(int l,int r,int x){
	if(lazy[x]==-1) return;
	int mid=l+r>>1;
	put_lazy(l,mid,x<<1,lazy[x]);
	put_lazy(mid+1,r,x<<1|1,lazy[x]);
	lazy[x]=-1;
}

void modify(int l,int r,int x,int c){
	if(L<=l&&r<=R){
		put_lazy(l,r,x,c);
		return;
	}
	down_lazy(l,r,x);
	int mid=l+r>>1;
	if(L<=mid) modify(l,mid,x<<1,c);
	if(mid<R) modify(mid+1,r,x<<1|1,c);
}

int query(int l,int r,int x,int pos){
	if(l==r) return lazy[x];
	if(lazy[x]!=-1) down_lazy(l,r,x);
	int mid=l+r>>1;	
	if(pos<=mid) return query(l,mid,x<<1,pos);
	return query(mid+1,r,x<<1|1,pos);
}

int main(){
	while(~scanf("%d",&n)){
		memset(lazy,-1,sizeof lazy);
		int c;
		while(n--){
			scanf("%d %d %d",&L,&R,&c);
			L++;
			modify(1,8000,1,c);
		}
		int pre=-1;
		vector<int> res[8005];
		for(int i=1;i<=8000;i++){
			int now=query(1,8000,1,i);
			if(now!=pre&&now!=-1) res[now].push_back(1);
			pre=now;
		}
		for(int i=0;i<=8000;i++){
			if(res[i].size()) cout<<i<<" "<<res[i].size()<<endl; 
		}
		cout<<endl; 
	}	
	return 0;
}
