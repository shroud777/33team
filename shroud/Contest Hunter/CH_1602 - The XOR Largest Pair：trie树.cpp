//题意：给出 n 个整数，求 XOR 值最大的一个序对

//思路：我们把所有数转化为 32 位二进制，不够的位数补零，然后插入到 01 trie 树中，对于每个待插入的 32 位二进制，为了使 XOR 值尽量大，我们从高位到低位尽量选择与当前进制位不同的 01 进制
//如果不同的 01 进制上不存在，那么就只能继续当前的指针往下找了，顺便统计答案

#include <bits/stdc++.h>

using namespace std;	
typedef long long ll;
const int maxn=1e5+10;

int trie[2][maxn*32],tot=1;
int n;

void insert(int x){
	int p=1,t;
	for(int i=31;i>=0;i--){
		t=((x&(1<<i))?1:0);
		if(!trie[t][p]) trie[t][p]=++tot;
		p=trie[t][p];
	}
}

int get_max(int x){
	int p=1,t,oth,res=0;
	for(int i=31;i>=0;i--){
		t=((x&(1<<i))?1:0),oth=t^1;
		if(trie[oth][p]) res+=(1<<i),p=trie[oth][p];
		else p=trie[t][p];
	}
	return res;
}

int main(){
	scanf("%d",&n);
	int x,ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		insert(x);
		ans=max(ans,get_max(x));
	}
	cout<<ans<<endl;
	return 0;
} 
