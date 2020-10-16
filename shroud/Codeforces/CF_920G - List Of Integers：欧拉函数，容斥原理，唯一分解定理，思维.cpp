//题意：给出一个二元序对（x,p），代表大于 x 的和 p 互质的序列，现在给出 t 个上述序对，每个样例给出一个 k，要求输出第 k 个大于 x 与 p 互质的数

//思路：暴力求解显然会超时，这里我们可以想到二分求一个 pos 值，因为互质个数是随着 pos 值单调变化的，那么我们现在目标变成求 [1,pos] 内大于 x 与 p 互质的数
//这个题干很容易想到 φ(p)，欧拉函数的定义为[1,p−1] 中有几个数与 p 互质，其公式为 φ(p)=p∏(1− 1/pi),这里显然不能套用，但是从根去想，我们可以考容斥来求 φ(p)
//那么这里就变成 f(pos)-f(x) 的值，并且这个结果要无限贴近 k，大于等于 k 二分上届都要往下
//注意细节

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e6+10;
int n,x,p,k,fact[maxn],tot;

inline int check(int x){
	int ans=x;
	for(int i=1;i<(1<<tot);i++){
		int cnt=0,res=1;
		for(int j=1;j<=tot;j++){
			if((1<<j-1)&i) cnt^=1,res*=fact[j];
		}
		if(cnt&1) ans-=x/res;
		else ans+=x/res;
	}
	return ans;
}

inline void get(int x){
	tot=0;
	for(int i=2;i*i<=x;i++){
		if(x%i) continue;
		fact[++tot]=i;
		while(x%i==0) x/=i;
	}
	if(x>1) fact[++tot]=x;
}

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d %d %d",&x,&p,&k);
		get(p);
		int s=check(x);
		int l=x+1,r=1e9,ans=1e9;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)-s>=k) ans=mid,r=mid-1; 
			else l=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
