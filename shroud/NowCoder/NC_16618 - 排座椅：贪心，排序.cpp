//题意：在一个 n*m 的网格中，存在 d 对上下相邻或左右相邻的坐标点，现在有 k 条横线和 l 条竖线可以放再某两个格子中间，代表将两侧的坐标对隔开，问怎样安排隔离线使被隔开的坐标对最多

//思路：以行和列为单位分别统计该行列若被安排线，会有多少坐标对被隔开，所以只需要统计后排序，贪心地每次选择最大的即可，注意：输出结果的序号要从小到大，将答案再次即可

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
struct node{
	int cnt,id;
	bool operator < (const node other) const{
		return cnt>other.cnt;
	}
}row[maxn],col[maxn];
int n,m,k,l,d;
int X1,X2,Y1,Y2;

int main(){
	vector<int> ans;
	memset(col,0,sizeof 0);
	memset(row,0,sizeof 0);
	scanf("%d %d %d %d %d",&n,&m,&k,&l,&d);
	for(int i=1;i<=n;i++) row[i].id=i;
	for(int i=1;i<=m;i++) col[i].id=i;
	for(int i=1;i<=d;i++){
		scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
		if(X1==X2) col[min(Y1,Y2)].cnt++;
		else row[min(X1,X2)].cnt++;
	} 
	sort(row+1,row+n);
	sort(col+1,col+m);
	
	for(int i=1;i<=k;i++) ans.push_back(row[i].id);
	sort(ans.begin(),ans.end());
	printf("%d",ans[0]);
	for(int i=1;i<ans.size();i++) printf(" %d",ans[i]);
	printf("\n");
	
	ans.clear();
	for(int i=1;i<=l;i++) ans.push_back(col[i].id);
	sort(ans.begin(),ans.end());
	printf("%d",ans[0]);
	for(int i=1;i<ans.size();i++) printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
