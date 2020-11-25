//题意：现在可以用 2 根棍子和 1 颗钻石换一个盾，或者 1 根棍子和 2 颗钻石换一把剑，现在给出 x 根棍子和 y 颗钻石，问最多可以换多少东西？

//思路：两种思路：
//思路1：若 max(x,y)>min(x,y)*2，那么必然用 2:1 的 min 和 max 去换，不满足的话就正常情况下，x 和 y 的和除以 3，可以分解为若干个 a+2*b 和 b+2*a
//思路2：约束条件 min(x,y,(x+y)/3)

//思路1：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y,ans=0;
		cin>>x>>y;
		if(x>y) swap(x,y);
		int d=y-x;
		d=min(d,min(y/2,x));
		x-=d;
		y-=2*d;
		ans+=d;
		ans+=min(y/3,x/3)*2;
		y%=3,x%=3;
		if((x>=2&&y>=1)||(y>=2&&x>=1)) ans++;
		cout<<ans<<endl;
	}
	return 0;
}

//思路2：

#include <bits/stdc++.h>
 
using namespace std;
 
int a,b;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<min(min(a,b),(a+b)/3)<<endl;
	}
	return 0;
} 
