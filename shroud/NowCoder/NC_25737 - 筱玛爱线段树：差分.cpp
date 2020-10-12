//题意：有一个长度为 n 且全为 0 的序列，现有 m 个操作，操作的格式为 opt l r，当 opt == 1 时，代表对区间 [l,r] 内的所有数都加 1，当 opt == 2 时，代表再做一次区间序号 [l,r] 内的操作，求最后的序列

//思路：首先思路往差分那边走，并且这里应该反着遍历操作序列，因为正着遍历的话当前操作的操作次数还不确定（后期的操作可能会增加当前位置的操作次数）所以我们要反着遍历一遍
//我们记录一个操作次数序列和数组序列，最后利用差分来得到最后的数组即可

#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;
const int p=1e9+7;
int n,m;
int d[maxn],ans[maxn];
int l[maxn],r[maxn],opt[maxn];

inline void add(int &x,int k){
	x+=k;
	if(x>=p) x-=p; 
}

inline void del(int &x,int k){
	x-=k;
	if(x<0) x+=p;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d %d %d",&opt[i],&l[i],&r[i]);
	for(int i=m;i>=1;i--){
		d[i]+=d[i+1];
		d[i]%=p;
		if(opt[i]==1){
			add(ans[l[i]],d[i]+1);
			del(ans[r[i]+1],d[i]+1);
		}
		else{
			add(d[r[i]],d[i]+1);
			del(d[l[i]-1],d[i]+1);
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]+=ans[i-1];
		ans[i]%=p;
		printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return 0;
}
