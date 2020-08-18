//题意：在二维坐标上有 n 个病毒，可以在 x 轴上安装消毒剂，消毒剂的消毒半径为 d，问最少使用多少消毒机，可以使得所有病毒被消灭

//思路：两种贪心思路
//第一种：首先可以想，我们从左端开始，我们尽可能让当前的那个病毒在圆的左半边界，因为这样右边就可以尽可能多消灭几个病毒，但是这样我们就要考虑以当前病毒为左半边界的那个圆应该怎么画，
//当开始我认为是 x 越大，作出的圆越靠左，当然这个思路是错误的，要综合看 x 和 y，这里我们预处理一下，处理出每个圆的位置，然后排序后贪心即可，看看下一个病毒在不在消毒范围内，在的话就不用新加圆
//第二种：每个病毒在 x 轴上有一段消毒范围，什么意思呢？就是在这个范围内安装消毒机器在有效，这一段区域是 [x-d,x+d]，d=sqrt(r*r-y*y)
//然后问题就变成了切长条问题，即在切断所有线段（即在消毒范围内安装机器，以消灭所有病毒）的情况下，使切割刀数最少，那么我们以线段右端点排序即可，然后看下一线段的左端点在不在可行范围内

//做法 1：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e2+10;

int n;double d;

struct node{
	int x,y;
	double rx;
	bool operator <(const node &other)const{
		return rx<other.rx;
	}
}a[maxn];


double dis(int x1,int y1,int x2,int y2){
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

bool check(int i,int rx){
	if(dis(a[i].x,a[i].y,rx,0)<=d) return true;
	return false;
}

int main(){
	while(scanf("%d %lf",&n,&d)&&(n+d)){
		bool f=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&a[i].x,&a[i].y);
			if(abs(a[i].y)>d) f=1;
		}
		if(f){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++) a[i].rx=a[i].x*1.0+sqrt(d*d-a[i].y*a[i].y);
		sort(a+1,a+n+1);
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans++;
			int t=i;
			while(check(i+1,a[t].rx)&&i+1<=n) i++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

//做法 2：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e3+10;

int n;
double r;

struct node{
	double l,r;
	bool operator <(const node &oth)const{
		if(fabs(r-oth.r)<1e-7) return l<oth.l;
		return r<oth.r;
	}
}a[maxn];

int main(){
	while(scanf("%d %lf",&n,&r)&&n+r){
		double x,y;
		bool f=0;
		for(int i=1;i<=n;i++){
			scanf("%lf %lf",&x,&y);
			if(abs(y)>r) f=1;
			if(f) continue;
			double d=sqrt(r*r-y*y);
			a[i].l=x-d,a[i].r=x+d;
		}
		if(f){
			puts("-1");
			continue;
		}
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			double t=a[i].r; ans++;
			i++;
			while(a[i].l<=t&&i<=n) i++;
			i--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
