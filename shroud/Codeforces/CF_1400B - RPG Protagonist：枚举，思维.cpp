//题意：你有一个重量限度为 p 的背包，你的仆人有一个重量限度为 f 的背包，现在有 cnts 件剑，重为 s，有 cntw 件斧头，重为 w，问怎么装可以得到最多的武器

//思路：如果只要一个背包，我们可以考虑贪心想法，尽量先装轻的，然后装到极限为止，但是这里有两个背包，可能出现这样的情况：第一个背包重为 10，第二个为 7，然后又 3 个重量为 3 的剑，2 个重量为 4 的斧头
//这样一味的贪心可能导致某个背包有空缺，造成一定的损失。所以我们必须要枚举所有方案，这里只要两个人，那么我们只需要枚举我的背包装多少剑，其他信息全部可以推算得出，仆人的背包贪心求解，再求出最优解


//改良标程

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;

ll p,f,cnts,cntw,s,w;

ll cal(ll w,ll x,ll y,ll wx,ll wy){
	if(wx>wy) return cal(w,y,x,wy,wx);
	ll res=min(x,w/wx);
	return res+min((w-res*wx)/wy,y);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld %lld %lld %lld %lld",&p,&f,&cnts,&cntw,&s,&w);
		ll ans=0;
		for(int i=0;i<=cnts;i++){
			if(1ll*i*s>p) break;
			int j=min((p-i*s)/w,cntw);
			ans=max(ans,i+j+cal(f,cnts-i,cntw-j,s,w));
		}
		printf("%lld\n",ans);
	}
	return 0;
}



//劣质现场版

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
 
int n;
int a[maxn],b[maxn];
ll p,f,cnts,s,cntw,w;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>p>>f>>cnts>>cntw>>s>>w;
		//第一个人买 i 个 s, 
		// cnts-i 
		ll ans=0,res;
		for(ll i=0;i<=cnts;i++){
			if(p<1ll*i*s) break;
			res=0;  
			ll left=p-1ll*i*s;   //p剩余容量 
			res+=i;
			ll t=min(cntw,left/w);				
			res+=t;		//全部买 w 
			ll ss=cnts-i;       //i 是买 s 的个数,left/w 是买 w 的个数 
			ll ww=cntw-t;
			//剩下 ss 个 s，ww 个 w
			//接下来考虑背包 f 装入剩下的东西 
			//第一种策略 f 里先装 s
			//
			ll res1=0,res2=0;
			ll tempf=f;
			ll num=min(1ll*f/s,ss);
			res1+=num;
			tempf-=1ll*num*s;
			res1+=min(1ll*tempf/w,ww);		
			//第二种
			//	          
			tempf=f;
			num=min(1ll*f/w,ww);
			res2+=num;
			tempf-=1ll*num*w;
			res2+=min(1ll*tempf/s,ss);
			res+=max(res1,res2);
			ans=max(ans,res);
		}
		cout<<ans<<endl;
	}
	return 0;
}
