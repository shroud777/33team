//题意：给出一个长度为 n 的序列，找到一个异或值最大的连续子序列，若存在多个，则有限选择末端在前的，如果还不唯一，则选择较短的

//思路：数据大小为 1e5，那么我们必然要把区间问题转化为左右端点问题，区间 [l,r] 的异或和可以转化为前 r 个异或和与前 l-1 个异或和异或的值
//那么问题转化为找 n 个数中两两异或最大的值，那么我们维护一个异或前缀和，每次把它插入到 01trie 中，并记录最大值和最右端点即可，每次找到最大值就把最大值和端点换掉

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;

int n,x,sum,st,ed,ans;
int trie[2][22*maxn],f[22*maxn],tot=1;

void insert(int id,int x){
	int p=1,t;
	for(int i=21;i>=0;i--){
		t=(1<<i)&x?1:0;
		if(!trie[t][p]) trie[t][p]=++tot;
		p=trie[t][p];
	}
	f[p]=id;
}

void get_max(int id,int x){
	int p=1,t,res=0;
	for(int i=21;i>=0;i--){
		t=(1<<i)&x?1:0;
		if(trie[t^1][p]) p=trie[t^1][p],res+=(1<<i);
		else p=trie[t][p];
	}
	if(res>ans){
		ans=res;
		ed=id;
		st=f[p];
	}
}

int main(){
	insert(0,0); 
	sum=-0x3f3f3f3f,st=0,ed=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(i==1) sum=x;
		else sum^=x;
		get_max(i,sum);
		insert(i,sum);
	}
	printf("%d %d %d\n",ans,st+1,ed);
	return 0;
}
