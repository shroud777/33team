//题意：求第一个大于 n 的不能被 4 整除而能被 7 整除的数

//思路：模拟即可

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int a[maxn],b[maxn];
int n;

map<int,int> mp;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=n;;i++){
			if(i%4!=0&&i%7==0){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
