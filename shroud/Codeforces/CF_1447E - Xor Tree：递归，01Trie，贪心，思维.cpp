//题意：给出一个长度为 n 的结点序列，并且存在权值 ai，对于每个 ai，需要找到序列中的一个 aj(1<=j<=n && j!=i)，使得 aj Xor ai 的值最小，然后在 ai 和 aj 中连一条无向边
//现在问最少删掉几个点使得所有结点构成一棵树

//思路：首先要从 Xor值最小去入手，对于一个值 ai
//异或值最小那么肯定是从高位到地位去比较，对于 ai 的最高位，肯定尽量也去找同样是 1 或者是 0 的，那么这样会导致出现一种情况，最高位根据 0 和 1，图呈现两块连通块状分布
//因为 0 肯定全去找 0，1 全取找 1
//发现这个规律之后题目就变得很简单了，如果当前比较的位全是 0 或 1，那么我们不用管，继续往下一个位找，如果存在一个 1 或者 0，是不影响的，因为这一个位数只能去找和他相反的位异或了
//那么对于 0 和 1 数量都大于等于 2 的情况来说，我们选择递归或用 01Trie 来解决，最后的值应该是 max(s1,s0)+1，s 代表继续往下递归解决的解
//如果要朴素递归的话，那只能先排序后再操作，因为这样很容易根据最高位是 0 还是 1 划分左右区间，分治解决


//01Trie

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;

int n,trie[2][maxn*30],tot=1;

void insert(int x){
	int p=1,t;
	for(int i=30;i>=0;i--){
		t=(x>>i&1);
		if(!trie[t][p]) trie[t][p]=++tot;
		p=trie[t][p];
	}
}

int query(int p){
	int lc=trie[0][p],rc=trie[1][p];
	if(!lc&&!rc) return 1;
	if(lc&&rc) return max(query(lc),query(rc))+1;
	return query(lc+rc);
}

int main(){
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++) scanf("%d",&x),insert(x);
	cout<<n-query(1)<<endl;
	return 0;
}


//朴素递归

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;

int n,a[maxn];

int solve(int l,int r,int t){
	//cout<<l<<" "<<r<<endl;
	if(l==r) return 1;
	if(t==-1) return r-l+1; 
	for(int i=l;i<=r;i++){
		if(a[i]>>t&1) return max(solve(l,i-1,t-1)+min(r-i+1,1),solve(i,r,t-1)+min(i-l,1));
	}
	return solve(l,r,t-1);	
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	cout<<n-solve(1,n,30)<<endl;
	return 0;
} 
