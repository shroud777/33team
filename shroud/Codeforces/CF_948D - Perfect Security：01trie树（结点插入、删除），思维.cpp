//题意：有 n 个原序列 M，有一个 n 个长度的密钥序列 P，现在得到一个序列信息序列 O，O 是通过 M 和 P 里的任意两元素元素异或而得的，现在要求信息序列的字典序最小

//思路：对于每一个 P，肯定是找在 M 中 XOR 值最小的一个，那么我们就从高位到低位，尽量选择位上相同的，然后向下延伸即可。问题在于每个选过的数不能在选了，那么我们就要考虑怎么去删除节点
//对于 01trie树 ，我们没把一个数转化为32位2进制就在每个节点上标记+1

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=3e5+10;

int n,x,trie[2][31*maxn],cnt[31*maxn],a[maxn],tot=1;

inline void insert(int x){
	int p=1,t;
	for(int i=31;i>=0;i--){
		t=(1<<i)&x?1:0;
		//cout<<t;
		if(!trie[t][p]) trie[t][p]=++tot;
		p=trie[t][p];
		cnt[p]++;
	}
	//cout<<endl;
}

inline int get_max(int x){
	int p=1,t,res=0;
	for(int i=31;i>=0;i--){
		t=(1<<i)&x?1:0;
		if(trie[t][p]&&cnt[trie[t][p]]){
			p=trie[t][p];
		}
		else{
			p=trie[t^1][p];
			res|=(1<<i);
		}
		cnt[p]--;
	}
	return res;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		insert(x);
	}
	for(int i=1;i<=n;i++){
		printf("%d%c",get_max(a[i]),i==n?'\n':' ');
	}
	return 0;
}
