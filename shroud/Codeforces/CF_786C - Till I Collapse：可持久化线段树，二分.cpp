//题意：给出一个长度为 n 的序列，现在要求按照划分连续区间，要求连续区间内包含的不同数字的个数不超过 k，现在要求输出 k (1<=k<=n) 各个情况下的最少区间个数

//思路：对于每个 k，肯定是贪心的去扩大区间，也就是对于一个确定的左边界，应该以第 k+1 个不同的数左边为边界
//那么相当于找 [l,n] 区间的第 k+1 个数，那么我们可以用可持久化线段树，rt[i] 记录 [i,n] 中所有数第一次出现的位置
//那么最初始版本的线段树就是记录所有数第一次出现的位置，我们可以用一个数字记录某个下标元素下一次出现的位置，这样我们每次建立第 i 个版本的线段树，我们只要把 i-1 这个位置删掉，然后补上 nex[i-1] 即可
//注意复制上一版本的过程和修改权值的过程不要搞错
//还要就是线段树全局范围要注意


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;
const int lg=20;

int n,a[maxn];
int ed[maxn],nex[maxn],ans[maxn];
int rt[maxn],tree[maxn*lg<<2],lc[maxn*lg<<2],rc[maxn*lg<<2],cnt=0;

void modify(int l,int r,int &x,int last,int pos,int k){
	x=++cnt;
	lc[x]=lc[last];
	rc[x]=rc[last];
	tree[x]=tree[last]+k;
	if(l==r){
		//cout<<l<<" "<<r<<" "<<x<<" "<<k<<" ";
		//cout<<tree[x]<<endl; 
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,lc[x],lc[last],pos,k);
	else modify(mid+1,r,rc[x],rc[last],pos,k);
}

int query(int l,int r,int x,int k){
	//cout<<l<<" "<<r<<" "<<x<<" "<<tree[x]<<" "<<tree[lc[x]]<<" "<<tree[rc[x]]<<endl;
	int mid=l+r>>1;
	if(l==r){
		return l;
	}
	if(tree[lc[x]]>=k) return query(l,mid,lc[x],k);
	return query(mid+1,r,rc[x],k-tree[lc[x]]);
}

void test(int l,int r,int x){
	//cout<<"test:"<<l<<" "<<r<<" "<<endl;
	//cout<<x<<" "<<lc[x]<<" "<<rc[x]<<" "<<endl;
	//cout<<tree[x]<<" "<<tree[lc[x]]<<" "<<tree[rc[x]]<<endl;
	//cout<<endl;
	if(l==r) return;
	int mid=l+r>>1;
	test(l,mid,lc[x]);
	test(mid+1,r,rc[x]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ed[i]=n+1;
	}	
	for(int i=n;i>=1;i--){
		nex[i]=ed[a[i]];
		ed[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(ed[i]!=n+1) modify(1,n+1,rt[1],rt[1],ed[i],1);
	}
	for(int i=2;i<=n;i++){
		modify(1,n+1,rt[i],rt[i-1],i-1,-1);
		if(nex[i-1]<=n) modify(1,n+1,rt[i],rt[i],nex[i-1],1);
	}
	//for(int i=1;i<=n;i++) cout<<"rt"<<i<<endl,test(1,n,rt[i]);
	for(int i=1;i<=n;i++){
		//cout<<i<<":"<<endl;
		int l=1;
		while(l<=n){
			l=query(1,n+1,rt[l],i+1);
			//cout<<l<<" ";
			ans[i]++;
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}
