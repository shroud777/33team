//题意：给出一个长度为 n 的序列，有 m 组查询，每组查询包含两个左右区间端点，求区间内相同元素位置的最小差值或不存在

//思路：对于每个区间，我们可以用 pre[i] 表示 i 位置上一个相同元素的位置，我们要用线段树维护，那么肯定是维护 i-pre[i] 的最小值，但是我们无法保证当前 i 的pre[i] 是在左端点右边或正好在左端点的
//那么我们只能换种思路，我们把 pre[i] 的位置用 i-pre[i] 的值维护，那么左端点我们可以保证不会超过，对于右端点，我们强制离线操作，把查询区间的右端点排序，然后从左到右遍历右端点
//这样一来，能出现在线段树维护范围内的元素都是当前右端点范围的元素，可以保证区间在范围内

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=5e5+10;

int n,m,a[maxn],l[maxn],r[maxn],ans[maxn];
int tree[maxn<<2],L,R;
struct node{
	int l,r,id;
	operator <(const node &oth)const{
		return r<oth.r;
	}
}b[maxn];

map<int,int> mp;

inline int min(int x,int y){
	return x<y?x:y;
}

inline void update(int x){
	tree[x]=min(tree[x<<1],tree[x<<1|1]);
}

void modify(int l,int r,int x,int pos,int k){
	if(l==r){
		tree[x]=k;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,x<<1,pos,k);
	else modify(mid+1,r,x<<1|1,pos,k);
	update(x); 
}

int query(int l,int r,int x){
	if(L<=l&&r<=R) return tree[x];
	int mid=l+r>>1;
	int ans=0x3f3f3f3f;
	if(L<=mid) ans=min(ans,query(l,mid,x<<1));
	if(mid<R) ans=min(ans,query(mid+1,r,x<<1|1));
	return ans;
}

void fuck(int x){
	if(x>1) fuck(x-1);
	cout<<"fuck"<<x<<endl; 
}

int main(){
	fuck(5);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d %d",&b[i].l,&b[i].r),b[i].id=i;
	sort(b+1,b+m+1);
	int rt=1;
	memset(tree,0x3f,sizeof tree);
	for(int i=1;i<=m;i++){
		while(rt<=b[i].r){
			if(mp[a[rt]]){
				int t=mp[a[rt]];
				modify(1,n,1,t,rt-t);		
			}
			mp[a[rt]]=rt;
			rt++;
		}
		L=b[i].l,R=b[i].r;
		int res=query(1,n,1);
		ans[b[i].id]=res==0x3f3f3f3f?-1:res;
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
