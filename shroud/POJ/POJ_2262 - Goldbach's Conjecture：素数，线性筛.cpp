//题意：给出一个偶数 n ，输出得到 n=a+b 的形式，a 和 b 都是素数，且要求 b-a 的值尽量大

//思路：首先打一个素数表，确定素数，然后从小到大枚举素数，用 n 减去改素数的数若为素数就直接输出
//1e6的数据，埃式筛和欧拉筛都可以用

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e6+10;

bool vis[maxn];
int prime[100005];
int tot;

void init_1(){
	tot=0;
	memset(vis,false,sizeof vis);
	for(int i=2;i<=1000000;i++){
		if(!vis[i]){
			prime[++tot]=i;for(int j=i+i;j<=maxn;j+=i) vis[j]=1;
		}
	}
}

void init_2(){
	tot=0;
	memset(vis,false,sizeof vis);
	for(int i=2;i<=maxn;i++){
		if(!vis[i]) prime[++tot]=i;
		for(int j=1;j<=tot&&prime[j]*i<=maxn;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}


int main(){
	init_2();
	int n;
	while(scanf("%d",&n)&&n){
		for(int i=1;i<=tot;i++){
			if(!vis[n-prime[i]]){
				printf("%d = %d + %d\n",n,min(n-prime[i],prime[i]),max(n-prime[i],prime[i]));
				break;
			}
		}
	}
	return 0;
}
