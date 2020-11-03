//题意：给出一个长度为 n 的一棵树 BFS 序列，对于每个结点子节点的 BFS 顺序按升序输出，现在求这课树的最低深度为多少

//思路：我们希望树的深度尽量小，那么尽量贪心地多地把结点都作为子节点结合到上一层的结点上，那么对于每个升序子段，我们都把他作为子节点连接到一个点上，同时这些子节点的个数就是下一层的叶子的数量
//所以我们也需要记录，也就是说我们要记录当前可用的父结点数量，与下一层有的叶结点数量，这样当前的父节点用完了，层数加一，那么所有的下一层叶结点就变成了当前这一层的父节点

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=2e5+10;
 
int cnt,nex,dep,n,a[maxn];
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		cnt=1,nex=0,dep=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=2;i<=n;i++){
			if(cnt){
				while(a[i]<a[i+1]&&i+1<=n) i++,nex++;
				nex++;
				cnt--;
			}
			if(!cnt&&i!=n){
				cnt=nex;
				nex=0;
				dep++;
			}
		}
		cout<<dep<<endl;
	}
	return 0;
} 
