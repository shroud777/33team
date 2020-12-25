//题意：给出若干个三元组任务（si,ei,pi），代表从 si 时刻开始，ei 时刻结束，优先级为 pi 的任务。现在有若干组询问，每次询问查询第 x 时刻，优先级前 k 小的 k 个任务的优先级之和大小

//思路：首先我们很容易想到，对时刻的历史版本建立主席树，对于第 i 时刻的权值线段树，我们只要维护个数和总值即可。
//但是有个很严重的问题，就是如果我们对于暴力维护每个时刻的主席树，那么复杂度将会非常高，并且由于我们要先维护好 Ti-1 棵才能维护 Ti，问题变得非常复杂
//这里我们把每棵树想象成一个点，那么我们发现这个问题似乎可以用差分来解答，对于每个时刻来说，我们分别保存开始的任务和结束的任务，然后作相应的维护即可
//最后就是要注意 query 的时候，当 l==r 时我们要根据需求返回值，而不是把当前位置结点的所有个数都返回

 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e5+10;

int n,m,len,o[maxn];
int head_1[maxn],to_1[maxn],nex_1[maxn],tot_1=0;
int head_2[maxn],to_2[maxn],nex_2[maxn],tot_2=0;
int rt[maxn],lc[maxn*36],rc[maxn*36],cnt[maxn*36],tot=0;
ll sum[maxn*36];

int inline read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}

inline void add_1(int u,int v){
	to_1[++tot_1]=v;
	nex_1[tot_1]=head_1[u];
	head_1[u]=tot_1;
}

inline void add_2(int u,int v){
	to_2[++tot_2]=v;
	nex_2[tot_2]=head_2[u];
	head_2[u]=tot_2;
}

void modify(int l,int r,int &x,int pos,int k){
	cnt[++tot]=cnt[x]+k;
	sum[tot]=sum[x]+k*o[pos];
	lc[tot]=lc[x];
	rc[tot]=rc[x];
	x=tot;
	if(l==r) return;
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,lc[x],pos,k);
	else modify(mid+1,r,rc[x],pos,k);
}

ll query(int l,int r,int x,int k){
	if(cnt[x]<=k) return sum[x];
	if(l==r) return 1ll*k*o[l];
	int mid=l+r>>1;
	if(cnt[lc[x]]>=k) return query(l,mid,lc[x],k);
	return query(mid+1,r,rc[x],k-cnt[lc[x]])+sum[lc[x]]; 
}

int main(){
	n=read(),m=read();
	int s,e,p;
	for(int i=1;i<=n;i++){
		s=read(),e=read(),p=read();
		o[i]=p;
		add_1(s,p);
		add_2(e+1,p);
	}
	sort(o+1,o+n+1);
	len=unique(o+1,o+n+1)-o-1;
	for(int i=1;i<=m;i++){
		rt[i]=rt[i-1];
		for(int j=head_1[i];j;j=nex_1[j]){
			int p=lower_bound(o+1,o+len+1,to_1[j])-o;
			modify(1,len,rt[i],p,1);
		}
		for(int j=head_2[i];j;j=nex_2[j]){
			int p=lower_bound(o+1,o+len+1,to_2[j])-o;
			modify(1,len,rt[i],p,-1);
		}
	}
	ll pre=1;
	int x,a,b,c;
	for(int i=1;i<=m;i++){
		x=read(),a=read(),b=read(),c=read();
		int k=1+(1ll*a*pre+b)%c;
		if(cnt[rt[x]]<=k) pre=sum[rt[x]];
		else pre=query(1,len,rt[x],k);
		printf("%lld\n",pre);
	}
	return 0;
}
