//题意：给出一个长度为 n 的序列，现在执行 q 种操作，每种操作包含两部份，将序列所有数和 x 作 XOR 运算操作，且原序列也改变，求改变后的序列的 MEX 值

//思路：首先根据结合律 a XOR b XOR c == a XOR (b XOR c)，我们可以每次不用原序列做操作，只需要维护一个异或前缀值即可
//然后我们可以想想，每个不同的数和 x 作 xor 运算的值都不同，那么根据 MEX 的定义，他是不出现在 x 与原序列的 XOR 序列中的，那么也就是说 MEX 要得到的话肯定是非序列元素与 x 的异或
//MEX 就可以看做是和非序列元素做一个 XOR 运算得到的最小值，那么问题就变成了最小异或值，我们从高位到低位建 01trie 树然后贪心地求答案即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=3e5+10;
int n,q,x,vis[(1<<20)+5];
int trie[2][maxn*32],tot=1;

void insert(int x){
	int p=1,t=0;
	for(int i=21;i>=0;i--){
		t=(1<<i)&x?1:0;
		if(!trie[t][p]) trie[t][p]=++tot;
		p=trie[t][p];
	}
}

int get_min(int x){
	int p=1,t=0,res=0;
	for(int i=21;i>=0;i--){
		t=(1<<i)&x?1:0;
		if(trie[t][p]) p=trie[t][p];
		else p=trie[t^1][p],res|=(1<<i);
	}
	return res;
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		vis[x]=1;
	}
	for(int i=0;i<=(1<<20);i++) if(!vis[i]) insert(i);
	int pre=0;
	while(q--){
		scanf("%d",&x);
		pre^=x;
		printf("%d\n",get_min(pre));
	}
	return 0;
} 
