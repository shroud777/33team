//题意：问序列是否满足存在且只有一个 k，使得 1<k<n,且 ai<ai+1 (1<i<k),ai>ai-1 (k<i<=n)

//思维：找到峰值，然后从两边判断即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;

int n,b,x;
ll a[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bool f1=0,f2=0,f=1;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=2;i<=n;i++){
			if(a[i]>a[i-1]) f1=1;
			if(a[i]<a[i-1]){
				f2=1;
				while(i<=n){
					if(a[i]>=a[i-1]){
						f=0;break;
					}
					i++;
				}
				break;
			}
		}
		if(f&&f1&&f2) puts("Yes");
		else puts("No");
	} 
	return 0;
} 
