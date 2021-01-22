//题意：定义一种 n 阶有根树 Rooted Dead Bush (RDB)，构造方法如下：
//n 阶 RDB 由 n-1 阶 RDB 构造得来
//对于没有子结点的结点 u，我们给 u 增加 1 个子结点
//对于有 1 个子结点的结点 u，我们给 u 增加 2 个子结点
//对于有超过 1 个子结点的结点 u，我们不作任何操作
//现在定义有 1 个父结点与 3 个子结点的有根树叫 claw
//问对于 n RDB，其中最多选中几个不重复占用结点的 claw？

//思路：画图找规律，可以发现 i 阶 RDB 可以由一个根节点连接 1 个 i-1 阶 RDB 和 2 个 i-2 阶 RDB 得到，并且由于我们是从下往上找 claw 的，对于 3 的倍数的 n，初始根结点和 2 个 n-2 阶的根和 1 个 n-1 阶的根又可以组成一个新的 claw
//所以我们得到递推式 dp[i]=dp[i-1]+dp[i-2]*2+(i%3==0?4:0)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e6+10;
const int p=1e9+7;

int n;
ll dp[maxn];

void init(){
	for(int i=3;i<=2e6;i++){
		dp[i]=(dp[i-1]+2*dp[i-2]+(i%3==0?4:0))%p;
	}
}

int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
	return 0;
}
