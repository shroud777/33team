//题意：在一个 1e5 * 1e5 的二维地图上，存在 n 个红色泡泡，每个泡泡在（xi，yi）处且不重复，泡泡可以穿梭到同一行或同一列的红色跑跑，给出两个泡泡的位置，问能否到达

//思路：刚开始看到这个题，看到这个恐怖的数据在想是不是有什么规律，每次只要 O(1) 的查询即可，后来失败了
//一个泡泡想要到达另一个泡泡，那么他肯定是要直接或者通过其他泡泡到达这个泡泡，那么我们可以用并查集，把所有能到达（同一行或同一列）的泡泡放到一个集合，这样每次查询只要判断是否在同一集合即可
//还有一种方法就是搜索，从一点开始同一行和同一列的全部加入其中，然后不断扩展，其实和并查集一个思路，这样扩展出来的一个集合算是一个联通分量，然后在搜索其他位置不在这个集合里的，复杂度O(logn*n)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
const int maxn=1e6+55;
int n,q;
int fa[maxn],height[maxn];

inline int find(int x){
    if(x==fa[x]) return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
 
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(height[x]==height[y]){
        height[x]=height[y]+1;
        fa[y]=x;
    }
    else{
        if(height[x]<height[y]) fa[x]=y;
        else fa[y]=x;
    }
}

void init(){
	for(int i=1;i<=n;i++){
		height[i]=0;
        fa[i]=i;
	}
}
int row[maxn],col[maxn];

int main(){
    scanf("%d %d",&n,&q);
    init();
    int x,y;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        if(row[x]) merge(row[x],i);
        else row[x]=i;
        if(col[y]) merge(col[y],i);
        else col[y]=i;
    }
    int p1,p2;
    while(q--){
        scanf("%d %d",&p1,&p2);
        p1=find(p1);
        p2=find(p2);
        if(p1==p2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
