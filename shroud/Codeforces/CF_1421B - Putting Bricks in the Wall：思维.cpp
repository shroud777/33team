//题意：给出一个 n*n 的二维区域，其中除了 （1,1）和（n，n）其他位置都由 0 和 1 组成，可以从 （1,1）出发，每次选择一个数 0 or 1，那么只能走 0 or 1 构成的路，现在要翻转两个位置的值，使得无论如何无法通行从 （1,1）到 （n,n）

//思路：由于翻转的个数只有 2 个，那么考虑封闭区域中间段的必然不现实，我们考虑封闭 （1,1）或（n，n）位置周围的块，可以考虑把 （2,2）（1,3）（3,1）全部变成 0 或 1
//（1,2）（2,1）全部变成 1 或 0


#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
 
int t1[3][2]={2,2,1,3,3,1};
int t2[2][2]={1,2,2,1};
 
char a[205][205];
int n;
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
		vector<pii> v;
		for(int i=0;i<3;i++){
			int x=t1[i][0],y=t1[i][1];
			if(a[x][y]!='0') v.pb(pii(x,y));
		}
		for(int i=0;i<2;i++){
			int x=t2[i][0],y=t2[i][1];
			if(a[x][y]!='1') v.push_back(pii(x,y));
		}
		if(v.size()<=2){
			cout<<v.size()<<endl;
			for(int i=0;i<v.size();i++) cout<<v[i].first<<" "<<v[i].second<<endl;
			continue;
		}
		v.clear();
		for(int i=0;i<3;i++){
			int x=t1[i][0],y=t1[i][1];
			if(a[x][y]!='1') v.pb(pii(x,y));
		}
		for(int i=0;i<2;i++){
			int x=t2[i][0],y=t2[i][1];
			if(a[x][y]!='0') v.push_back(pii(x,y));
		}
		if(v.size()<=2){
			cout<<v.size()<<endl;
			for(int i=0;i<v.size();i++) cout<<v[i].first<<" "<<v[i].second<<endl;
			continue;
		}
	}
	return 0;
}
