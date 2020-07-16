//题意；有一颗 n 个结点的树，每个点初值权值为 0 ，进行 m 次操作，每次操作将距离 x 点树上距离 <= 1 的点的权值加1，答案是加上当前操作影响的点的权值和 * i

//思路：一开始没啥思路，想想每次操作都是根据 x 来的，想着能不能保存每个节点有关系的结点，这样是不行的，因为比如你每次把 x 的那个集合的值更新了，但是作为他的父亲或者儿子结点，他们的值的集合也要更新
//显然这种方法，不行，但是这题可以用数组来维护这种关系。设三个数组 a ，b ，c 分别代表 当前结点的操作次数（也就是当前点的点权） 儿子结点的操作次数 孙子结点的操作次数
//为什么要这样做呢？我们来想想第 i 次对 x 操作，他的点权和是不是就该受父亲结点权值，x 的权值，和 x 的所有儿子的权值呢？
//那么他的父亲结点又受爷爷结点的影响而影响，爷爷结点操作了一次加了一，那么父亲结点也会加，儿子结点也会有影响，所以父亲的贡献是：父亲结点的操作次数+爷爷结点的操作次数+ x 结点的操作次数
//即 = a[fa[fa[x]]]+a[fa[x]]+b[fa[x]]
//同样的当前 x 结点的贡献是 a[fa[x]]+a[x]+b[x]  ,x 的多个子节点的影响即 sz[x]*a[x]+b[x]+c[x]

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int p=19260817;
int fa[maxn],sz[maxn];
ll a[maxn],b[maxn],c[maxn];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int root;
	for(int i=1;i<n;i++){
		scanf("%d",&root);
		fa[i+1]=root;
		sz[root]++;
	}
	ll ans=0;
	int x;
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		a[x]++;
		if(fa[x]){
			b[fa[x]]++;
			if(fa[fa[x]]) c[fa[fa[x]]]++;
		}
		ll res=0;
		res+=(a[fa[fa[x]]]+a[fa[x]]+b[fa[x]])%p;
		res+=(a[fa[x]]+a[x]+b[x])%p;
		res+=(a[x]*sz[x]%p+c[x]+b[x])%p;
		res%=p;
		ans=(ans+res*i%p)%p;
	}
	cout<<ans<<endl;
	return 0;
} 
