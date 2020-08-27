//题意：给出 n 个单词，选出其中 m 个组合成一个句子，使得每个单词之和*(m-i+1) 的值最大，如果有多个相同的和，选择字典序最小的输出

//思路：按照权值和字典序对字符串进行排序，组合成句子并计算总值

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;

struct node{
	string s;
	ll p;
}a[maxn];

bool cmp(node x,node y){
	if(x.p==y.p) return x.s<y.s;
	return x.p>y.p;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].p;
		sort(a+1,a+n+1,cmp);
		ll ans=0;
		for(int i=1;i<=m;i++) ans+=1ll*a[i].p*(m-i+1);
		printf("%lld",ans);
		for(int i=1;i<=m;i++) cout<<" "<<a[i].s;
		cout<<endl;
	}
	return 0;
}
