//题意：有一面墙，被等分为1e7份，一份的宽度为一个单位宽度。现在往墙上贴 n 张海报，不计海报的厚度，给出海报左右边界 left 和 right,后贴的海报会覆盖之前的海报，求最后能看见几张海报

//思路：墙的宽度 1e7 ，海报张数 1e4，总共 2*1e4 个点，压缩比很大，且与数据之间的绝对大小没什么关系，只在乎海报端点的相对位置，显然应该使用离散化。      
//离散化就是如此，不改变数据的相对大小地压缩数据所在的空间关系

//!!!!!

//但是这道题普通的离散化有坑，但是数据很弱，普通的离散化都可以过，比如 [1,4] [6,10] [1,10] 显然可以看到 [1,4] [5] [6,10] 三处位置的海报，但是离散化处理后的海报相对位置变成[1,2] [3,4] [1,4] 这样显然只能看到 2 张海报了
//这种情况是因为原来可能两张海报在绝对位置上有一定距离甚至可能很远，但在相对位置上两张海报就是相邻的关系，由于离散化只关注数据的相对位置，因此就出现了上述的情况。
//要想解决上面的情况可以对离散化处理后的数据在进行处理，如果前后两个数的大小差距大于 1 ，num[i] - num[i-1] >1 说明他们绝对位置上不应该相邻，那么可以向他们之间加入一个数 num[i-1]+1 即可
//上述加入的数显然对数据无影响，这个就是离散化本身的性质，管你怎么变，只要本身在你左边的端点还是在你左边，就可以了。

//然后就是用线段树和 lazy-tag 来维护，相当于区间更新，并且这里是要求区间覆盖，每次 down_lazy 都要在 lazy-tag 降下去之后把这个位置的信息清除
//不然的话你之后查询，你遇到这个点有信息就代表被一个颜色覆盖了，就没办法看到其他颜色了。

//还有你妈的，这个数据明明是1e5，题目给的是1e4，坑死老子了

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n,tot;
int tree[maxn*8],num[maxn*4],Left[maxn],Right[maxn],vis[maxn];
void down_lazy(int l,int r,int x){
	if(!tree[x]) return;
	tree[x<<1]=tree[(x<<1)|1]=tree[x];
	tree[x]=0;
}
void modify(int l,int r,int x,int L,int R,int col){
	if(L<=l&&r<=R){
		tree[x]=col;
		return;
	}
	if(tree[x]) down_lazy(l,r,x);
	int mid=l+r>>1;
	if(L<=mid) modify(l,mid,x<<1,L,R,col);
	if(mid<R) modify(mid+1,r,(x<<1)|1,L,R,col); 
}
int query(int l,int r,int x){
	int ans=0;
	if(tree[x]){
		if(!vis[tree[x]]){
			vis[tree[x]]=1;
			return 1;
		}
		return 0;	
	}
	if(l==r) return 0;
	int mid=l+r>>1;
	ans+=query(l,mid,x<<1);
	ans+=query(mid+1,r,x<<1|1);
	return ans; 
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		tot=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&Left[i],&Right[i]);
			num[++tot]=Left[i];
			num[++tot]=Right[i];
		}
		sort(num+1,num+tot+1);
		tot=unique(num+1,num+tot+1)-num-1;
		int now=tot;
		for(int i=2;i<=now;i++) if(num[i]-num[i-1]>1) num[++tot]=num[i-1]+1;
		sort(num+1,num+tot+1);
		memset(tree,0,sizeof tree);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++){
			Left[i]=lower_bound(num+1,num+tot+1,Left[i])-num;
			Right[i]=lower_bound(num+1,num+tot+1,Right[i])-num;
			modify(1,tot,1,Left[i],Right[i],i);
		}
		printf("%d\n",query(1,tot,1));
	}
	return 0;
}
