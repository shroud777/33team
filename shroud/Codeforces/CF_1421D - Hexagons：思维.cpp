//题意：在一个若干个六边形边边相贴构成的平面，可移动至六个方向的六边形，同时存在六个方向移动的代价，给出目标位置 (x,y)，求从起点 (0,0) 到目标位置的最小代价

//思路：某个方向的值可以由附近两个方向相加构成，那么它的取值也可以由此去到最优值，然后根据具体方向得到方案，对于剩余的向量补上即可

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
 
ll c[10],x,y;
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld",&x,&y);
		for(int i=0;i<6;i++) scanf("%d",&c[i]);
		for(int i=0;i<6;i++) c[i]=min(c[i],c[(i-1+6)%6]+c[(i+1+6)%6]);
		ll ans=0;
		if(x>=0&&y>=0){
			int t=min(x,y);
			ans+=t*c[0];
			x-=t,y-=t;
		}
		else if(x<0&&y<0){
			int t=min(-x,-y);
			ans+=t*c[3];
			x+=t,y+=t;
		}
		if(x>=0) ans+=c[5]*x;
 		else ans+=c[2]*(-x);
 		if(y>=0) ans+=c[1]*y;
 		else ans+=c[4]*-y;
 		cout<<ans<<endl;
	}
	return 0;
}
