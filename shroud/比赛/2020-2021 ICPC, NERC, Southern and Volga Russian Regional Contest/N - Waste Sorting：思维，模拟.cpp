//题意：现在有 5 种类型的垃圾，对于 1-3 号垃圾，他们只能扔进对应的 i 号桶，4 号垃圾只能扔进 1 号或 3 号桶，5 号垃圾只能扔进 2 号或 3 号桶
//现在 5 种类型的垃圾分别有 ai 剩余，并且第 i 个桶有 ci 个容积，为能否全部扔进桶

//思路：首先，对于 1-3 号垃圾，他们只能扔进对应的 i 号桶，那么如果 ai>ci，显然没有办法处理这些垃圾
//然后处理完这三种垃圾，三个桶的容积都变为了 ci-ai
//接下来对于 4 号和 5 号垃圾，他们都可以扔进 3 号桶，但是分别又能扔进 1 号和 2 号桶，那我们肯定是先把他们扔进 1 号和 2 号桶，扔的体积是 min(ci,ai)
//接下来两种垃圾剩余部分都扔进 3 号桶，只需判断 3 号桶能否处理完剩余垃圾即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int a[10],c[10];

int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=1;i<=3;i++) scanf("%d",&c[i]);
		for(int i=1;i<=5;i++) scanf("%d",&a[i]);
		bool f=1;
		c[1]-=a[1];
		c[2]-=a[2];
		c[3]-=a[3];
		if(c[1]<0||c[2]<0||c[3]<0){
			puts("NO");
			continue;
		}
		int temp=min(c[1],a[4]);
		a[4]-=temp;
		temp=min(c[2],a[5]);
		a[5]-=temp;
		c[3]-=a[4]+a[5];
		if(c[3]<0) puts("NO");
		else puts("YES");
	}
	
	return 0;
}
