//题意：有 n 次考试，每次考试有 bi 道题，你做对了 ai 道，其中可以舍弃 k 场考试的结果，求 100*sigma(a[i)/sigma(b[i) 的最大值

//思路：01分数规划，首先我们假设 100*sigma(a[i)/sigma(b[i) 的最大值为 L
//求得 100*sigma(a[i]-b[i]*L)*xi,xi 只有 0,1 两种选择，代表选和不选这一项，我们发现如果该表达式大于等于0，代表原式的最大值比 L 大，那么下界上升，反之上界下降。总之就是一个二分答案的过程

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define eps 1e-8 
const int maxn=1e3+10;

int n,k;
int a[maxn],b[maxn];
double t[maxn];

bool check(double x){
	for(int i=1;i<=n;i++) t[i]=1.0*a[i]-1.0*b[i]*x;
	sort(t+1,t+n+1);
	double res=0;
	for(int i=k+1;i<=n;i++) res+=t[i];
	return res>=0;
}

int main(){
	while(~scanf("%d %d",&n,&k)&&n){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		double l=0,r=1;
		while(r-l>=eps){
			double mid=(l+r)/2.0;
			if(check(mid)) l=mid;
			else r=mid;
		}
		cout<<fixed<<setprecision(0)<<((l+r)/2*100)<<endl;
	}		
	return 0;
} 
