//题意：给出一个长度为 n 的原序列，现在有两种类型的操作
//1.在原序列的末尾增加一个数 x，序列长度加一
//2.给出区间 [l,r] 和一个 x，求区间内一个位置 p，是的 ap Xor ap+1 Xor ap+2... Xor an Xor x 的值最大

//思路：首先对于每一个异或后缀，我们只需要维护一个总的异或前缀 sn，然后再异或 si(l-1<=i<=r-1)，因为做两次异或相同的部分就消除了，就相当于后一端值的异或值
//那么如果是枚举区间，复杂度显然太高，就算每次用前继信息也要花很多时间，那么我们要把区间问题转化为端点问题
//其实这里只给出一个右区间限制，即 [1,r]，那么我们只要用 可持久化Trie树 维护即可，维护每一个历史版本的异或前缀值，然后每次查询 root[r] 版本的 Trie 即可，这里就是查询 sn^x 的最大异或值
//但是对于这里的左区间限制，我们有没有什么办法能对 Trie 进行限制性的找最大异或值呢，这里我们想到每次插入一个数时，用数组维护插入结点位置时的当前下标，当然数组最终维护的是该结点子树的最右边的下标
//然后我们每次指针向下移动或者向下递归的时候我们就只要判断 01Trie 下面两个结点的维护的最右下标是否大于等于 l-1 即可，是的话就可以指针下移或者向下递归了

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=3e5+10;

int n,m,root[maxn<<1],s[maxn<<1],tot=0;
int trie[2][maxn*24<<1],l[maxn*24<<1];

void insert(int i,int dep,int p,int q){
	if(dep<0){
		l[q]=i;
		return;
	}
	int c=(1<<dep)&s[i]?1:0;
	if(p) trie[c^1][q]=trie[c^1][p];
	trie[c][q]=++tot;
	insert(i,dep-1,trie[c][p],trie[c][q]);
	l[q]=max(l[trie[0][q]],l[trie[1][q]]);
}

int query(int p,int lim,int x){
	int t,res=0;
	for(int i=23;i>=0;i--){
		t=(1<<i)&x?1:0;
		//cout<<t<<" "<<trie[t^1][p]<<" "<<trie[t][p]<<endl;
		if(l[trie[t^1][p]]>=lim){
			p=trie[t^1][p];
			res+=(1<<i);
		}
		else p=trie[t][p];
	}
	return res;
}

int main(){
	scanf("%d %d",&n,&m);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		root[i]=++tot;
		s[i]=s[i-1]^x;
		insert(i,23,root[i-1],root[i]);
	}
	char ch[2];
	int l,r;
	while(m--){
		scanf("%s",ch);
		if(ch[0]=='A'){
			scanf("%d",&x);
			root[++n]=++tot;
			s[n]=s[n-1]^x;
			insert(n,23,root[n-1],root[n]);
		}
		else{
			scanf("%d %d %d",&l,&r,&x);
			printf("%d\n",query(root[r-1],l-1,x^s[n]));
		}
	}
	return 0;
}
