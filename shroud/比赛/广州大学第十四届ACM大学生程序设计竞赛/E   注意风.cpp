//题意： M 在 GR 的左边，想走到距离为 m 的右边， GR 的风前 a 秒不刮，接着 b 秒有向左的风速为 x 的风，接着 c 秒有向右的风速为 y 的风，接着一直循环往复，M 的行走速度为 z
//当前速度为风速与行走速度的矢量和，求到达右边的时间

//思路：先判断前 a 秒能不能直接到达后边，然后考虑每个周期的和是正还是负判断能不能到达右边，然后计算出需要走多少个完整的周期，然后模拟最后一个不完整的周期的情况
//这个题有数据有 bug
//他第一段 向右 移动的距离 a 特别特别长，第二段 像左 移动的距离 b 特别特别长，第三段距离很小可以无视。
//同时他这一整个周期的距离由于 a 和 b 互相抵消导致也很短，然后 a 虽然很长但是他不足以一次性直接到达右边
//他可能两边的距离是 m=a+x ，然后经过几次周期运动的铺垫他可能当前距离达到 x，然后一次 a 一举到达右边
//跟出题人交流了确实是数据水了

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
int main(){
	double a,b,c,x,y,z,m;
	cin>>a>>b>>c>>x>>y>>z>>m;
	if(a*z>=m){
		printf("%.10f\n",m/z);
		return 0;
	}
	double f=a*z+b*(z-x)+c*(z+y);
	double t=a+b+c;
	double bz=ceil((m-a*z)/f);
	double res=bz*t+max((double)0,(m-f*bz))/z;
	if(f<=0){
		cout<<"Badeline win"<<endl;
		return 0;
	}
	if((int)m%(int)f==0){
		printf("%.10f\n",min(t*(m/f),res));
		return 0;
	}
	double ans=0;
	int part=m/f;
	ans+=part*t;
	
	double left=m-part*f;

	if(a*z>=left){
		ans+=left/z;
		printf("%.10f\n",min(ans,res));
		return 0;
	}
	left-=a*z;
	ans+=a;
	if(b*(z-x)>=left){
		ans+=left/(z-x);
		printf("%.10f\n",min(ans,res));
		return 0;
	}
	left-=b*(z-x);
	//left=min(left,m);
	ans+=b;
	ans+=left/(z+y);
	printf("%.10f\n",min(ans,res));
}
