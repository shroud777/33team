//题意:我们把 [n,n+p] n，n+p 都是质数，中间所有数都是合数的序列叫做 Pirme Gap，长度为 n，求给出数所在的 Prime Gap 大小

//思路：首先素数的话长度肯定为 0，不是的话只要两边找素数确定边界最后+2就可以了，用素数筛确定是否为素数

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e7+10;
bool vis[maxn];
int prime[1000005];
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
	vis[0]=vis[1]=1;
	while(scanf("%d",&n)&&n){
		if(!vis[n]) cout<<0<<endl;
		else{
			int cnt=0;
			for(int j=n+1; ;j++){
				if(!vis[j]) break;
				cnt++;
			}
			for(int j=n-1; ;j--){
				if(!vis[j]) break;
				cnt++;
			}
			cout<<cnt+2<<endl;
		}
	}
	return 0;
}
