//题意：有 n 个点，给出 n 个点的关系域值 ai，输出一种方案使得 n 个点构成一棵树，且树的每条边的两个点的关系域值都不同

//思路：如果所有点的关系域值相同，那么说明不存在任何情况满足题干要求。反之则一定有情况可以满足，这里我们可以选出一种类型的关系域值，然后把它跟其他所有不同的关系域值的点全部连起来
//再把所有相同的点都连到任一不同的关系域值的点上即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=3e5+10;
 
int n,a[5005];
 
map<int,int> mp;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int mx=0,temp;
		mp.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			int temp=++mp[a[i]];
		}
		if(mp[a[n]]==n){
			puts("NO");
			continue;
		}
		puts("YES"); 
		for(int i=2;i<=n;i++){
			if(a[i]!=a[1]){
				printf("1 %d\n",i);
				temp=i;
			}
		}
		for(int i=2;i<=n;i++){
			if(a[i]==a[1]){
				printf("%d %d\n",temp,i);
			}
		}
	}
	return 0;
} 
