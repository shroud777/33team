//题意：把 n 个圆盘分配到 m 个塔上且每个塔上至少有一个圆盘，给出第 i 个圆盘所属 ti 个塔
//对于任意两座塔，每次操作可以从某座塔上选一定数量的圆盘按原来的顺序放到另一座踏上，这些圆盘必须满足最底下的也就是最大的比另一座塔最上面的小
//然后定义一些塔的 difficulty 为把所有圆盘从小到大依次叠在一个塔上
//进行 m-1 次操作，第 i 次将合并 ai 和 bi 座塔，并且每次合并后输出合并当前所有这些塔的 difficulty

//思路：并查集，从小到大合并。我们可以发现，最多需要 n -1 次合并，我们从 1-n 遍历下去，第 i 次要是 i-1 个元素和它在一座塔上，那么他就不用移动
//那么初始想法就是每个圆盘都在一个塔上，把这些塔看成一个个集合，每次合并就把两个塔合并到同一个集合，然后每次扫一遍 O(n * m)。但是 n 和 m 都达到了 2e5，显然不行
//于是要进行改进，萌生了另一种想法，他每次把集合并入元素，对于要并入的一个元素 a ，如果 a+1 或者 a-1 在要并入的元素中，以为着他本来是需要花费 1~2 次操作去找他的邻居但，但是合并之后显然少了这些次数
//所以应该可以通过查询邻居并把 y 并到 x 里，但是这样出现了一个问题，就是会产生 MLE 
//先想想产生 MLE 的原因可能是每个塔上只有一个盘子，然后每次集合都是两两合并，最后耗费 O(m!) 的空间，所以我们要考虑把小集合合并到大集合上，然后问题又又又来了，有时候这个集合可能已经被合并掉了，所以不能单单只访问他
//要找他合并到的祖先是谁
//多思考思考，毕竟也是2300的题，还有 LCA 做法就先不写了，

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m;
int fa[maxn],p[maxn];
int find(int x){
	if(x==p[x]) return x;
	p[x]=find(p[x]);
	return p[x];
}
void init(){
	for(int i=1;i<=m;i++) p[i]=i;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	vector<vector<int> > v(n+2);
	int root,ans=n-1;
	for(int i=1;i<=n;i++){
		cin>>root;
		fa[i]=root;
		v[root].push_back(i);
		if(i>1) ans-=fa[i]==fa[i-1];
	}
	init();
	cout<<ans<<endl;
	m--;
	int x,y;
	while(m--){
		cin>>x>>y;
		x=find(x),y=find(y);
		if(v[x].size()<v[y].size()) swap(x,y);
		int now;
		for(int i=0;i<v[y].size();i++){
			now=v[y][i];
			//cout<<now<<" "<<fa[now-1]<<" "<<fa[now+1]<<endl; 
			if(now+1<=n&&fa[now+1]==x) ans--;
			if(now-1&&fa[now-1]==x) ans--;
		}
		for(int i=0;i<v[y].size();i++){
			now=v[y][i];
			v[x].push_back(now);
			fa[now]=x;
		}
		p[y]=x;
		cout<<ans<<endl;
	}
	return 0;
}
