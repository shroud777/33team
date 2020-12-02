//题意：在 x 轴上有 n 个不重复的点，现在有两种操作：
//0 x，代表删除 x 轴上的点 x，保证 x 已经存在在 x 轴上
//1 x，代表加入 x 到 x 轴上，保证 x 不存在 x 轴上
//问每次操作后 n 个点要聚集到不超过两个点的地方的最小步数，一步可以把所有在 x 的点移动至 x+1 或 x-1

//思路：上述操作如果是把所有点聚到一起，那么答案就是 max-min 值，但是由于可以分成至少两块，那么我们可以出去中间距离最大的作为两块的分界，那么答案就是 max-min-maxgap
//那么怎么维护这些信息呢，有很多方法，首先是用 set 和 mutiset
//我们可以知道所有 x 轴上的值都是不唯一的，那么我们可以用一个 set 维护最大值最小值，每次插入删除也很方便，但是我们需要维护一个 n 个数的最大差值怎么办呢
//这里就必须用到 multiset，因为差值的值不唯一，每次插入一个数，我们要看他插入的具体位置（按照升序），如果实在头部或尾部，那么他能为 multiset 多加一个差值，如果他左右都有数字，那么就要先减去他左右的差，然后在加上他和左右的差值
//这里我们有一些技巧，我们只要分别判断前后有没有数即可，然后差值和记录，具体看代码
//每次删除也是如此，看删除数字的具体位置我们也要对 multiset 做不同的操作
//接下来说说线段树，线段树的效率比 multiset 要搞一些，因为每次只需要 O(logn) 的修改和 O(1) 的查询，那么是怎么做到的
//一般来说找最大值最小值，一般是用权值线段树或普通线段树维护区间最值，但是这样维护最大差值就很难
//这里我们运用离散化操作，把所有询问离线处理，这样就可以知道一个需要操作的数在离散化全局中的位置，那么这样我们相当于用线段树维护离散化数组，并且直接用他原来的值作为结点的值即可
//那么我们可以直接维护出区间最小的值，区间最大的值和区间最大的差值
//如果左子区间的最小值存在，那么就去左区间，不存在代表左子区间没有值，否则就去右子区间，最大值一个道理
//那么区间最大值，初始化叶结点都为 0，应该等于左子区间的区间最大值和右子区间的区间最大值和右子区间的最小值-左子区间的最大值的 max 值

//set，multiset

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=2e5+10;
 
int n,q,a[maxn];
 
set<int> v;
multiset<int> d;
multiset<int> ::iterator it;
 
void print(){
	if(!d.size()){
		puts("0");return;
	}
	printf("%d\n",*v.rbegin()-*v.begin()-*d.rbegin());
}
 
int main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),v.insert(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) d.insert(a[i+1]-a[i]);
	print();
	int op,x;
	while(q--){
		scanf("%d %d",&op,&x);
		if(op){
			v.insert(x);
			it=v.find(x);
			int p1=0,p2=0;
			if(it!=v.begin()){
				p1=*(--it);
				d.insert(x-p1);
				it++;
			}
			++it;
			if(it!=v.end()){
				p2=*it;
				d.insert(p2-x);
				it--;
			}
			if(p1&&p2) d.erase(d.find(p2-p1));
		}
		else{
			it=v.find(x);
			int p1=0,p2=0;
			if(it!=v.begin()){
				p1=*(--it);
				d.erase(d.find(x-p1));
				it++;
			}
			it++;
			if(it!=v.end()){
				p2=*it;
				d.erase(d.find(p2-x));
				it--;
			}
			if(p1&&p2) d.insert(p2-p1);
			v.erase(v.find(x));
		}
		//for(it=v.begin();it!=v.end();it++) cout<<*it<<" ";cout<<endl;
		//for(it=d.begin();it!=d.end();it++) cout<<*it<<" ";cout<<endl;
		print();
	}
	return 0;
}

//线段树

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=1e5+10;
 
int a[maxn<<1],op[maxn],b[maxn],t[maxn];
bool vis[maxn<<1];
int n,q;
 
struct node{
	int mi,mx,d;
}tree[maxn<<4];
 
inline void update(int x){
	tree[x].mi=(tree[x<<1].mi?tree[x<<1].mi:tree[x<<1|1].mi);
	tree[x].mx=(tree[x<<1|1].mx?tree[x<<1|1].mx:tree[x<<1].mx);
	int t=0;
	if(tree[x<<1].mx&&tree[x<<1|1].mi) t=tree[x<<1|1].mi-tree[x<<1].mx;
	tree[x].d=max(t,max(tree[x<<1|1].d,tree[x<<1].d));
}
 
void build(int l,int r,int x){
	if(l==r){
		if(vis[l]) tree[x].mi=tree[x].mx=a[l];//cout<<"FUCK"<<a[l]<<endl; 
		return;
	}
	int mid=l+r>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	update(x);
}
 
void modify(int l,int r,int x,int pos){
	if(l==r){
		if(tree[x].mi) tree[x].mi=tree[x].mx=0;
		else tree[x].mi=tree[x].mx=a[l];//cout<<"fuck!"<<l<<" "<<a[l]<<endl; 
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,x<<1,pos);
	else modify(mid+1,r,x<<1|1,pos);
	update(x);
}
 
int main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		a[i]=b[i];
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&op[i],&t[i]);
		a[i+n]=t[i];
	}
	sort(a+1,a+n+q+1);
	sort(b+1,b+n+1);
	int cnt=unique(a+1,a+n+q+1)-a-1;
	int p=1;
	for(int i=1;i<=cnt;i++){
		if(a[i]==b[p]){
			vis[i]=1,p++;
		}
	}
	build(1,cnt,1);
	//for(int i=1;i<=cnt*3;i++) cout<<i<<":"<<endl,cout<<tree[i].mx<<" "<<tree[i].mi<<" "<<tree[i].d<<endl;
	printf("%d\n",tree[1].mx-tree[1].mi-tree[1].d);
	for(int i=1;i<=q;i++){
		modify(1,cnt,1,lower_bound(a+1,a+cnt+1,t[i])-a);
		//cout<<"?"<<lower_bound(a+1,a+cnt+1,t[i])-a<<" "<<a[lower_bound(a+1,a+cnt+1,t[i])-a]<<endl;
		printf("%d\n",tree[1].mx-tree[1].mi-tree[1].d);
	}
	return 0;
} 
