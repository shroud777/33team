//题意：题目描述
//如题，给定 n 个整数构成的序列 a，将对于指定的闭区间 [l, r] 查询其区间内的第 k 小值。

//思路：可持久化线段树模板
//运用前缀和的思想，可持久化线段树的第 i 个版本相等于对序列前 i 个数建立一棵权值线段树，这样对于区间 [l,r] 我们只要用第 r 个版本和第 l-1 个版本作差就相等于在一棵权值线段树上找第 k 大

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;
const int lg=25;

vector<int> v;
int n,q,a[maxn];
int tree[maxn*lg*2],rt[maxn],lc[maxn*lg*2],rc[maxn*lg*2],tot=0;

void update(int x){
	tree[x]=tree[lc[x]]+tree[rc[x]];
}

void build(int l,int r,int &x){
	x=++tot;
	if(l==r) return;
	int mid=l+r>>1;
	build(l,mid,lc[x]);
	build(mid+1,r,rc[x]);
	update(x);
}

void modify(int l,int r,int &x,int last,int pos){
	x=++tot;
	tree[x]=tree[last];
	lc[x]=lc[last];
	rc[x]=rc[last];
	if(l==r){
		tree[x]++;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,lc[x],lc[last],pos);
	else modify(mid+1,r,rc[x],rc[last],pos);
	update(x);
}

int query(int l,int r,int x1,int x2,int k){
	if(l>=r) return l;
	int mid=l+r>>1;
	int d=tree[lc[x2]]-tree[lc[x1]]; 
	if(d>=k) return query(l,mid,lc[x1],lc[x2],k);
	return query(mid+1,r,rc[x1],rc[x2],k-d);
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	build(1,n,rt[0]);
	for(int i=1;i<=n;i++){
		modify(1,n,rt[i],rt[i-1],lower_bound(v.begin(),v.end(),a[i])-v.begin()+1);
	}
	int l,r,k;
	while(q--){
		scanf("%d %d %d",&l,&r,&k);
		//if(l==r) cout<<"ans="<<a[l]<<endl;
		printf("%d\n",v[query(1,n,rt[l-1],rt[r],k)-1]);
	}
	return 0;
}
