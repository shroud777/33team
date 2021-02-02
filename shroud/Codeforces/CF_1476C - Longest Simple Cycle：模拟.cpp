//题意：现在有 n 条链，每条链有 ci 个点与 ci-1 条边将点 j 与 j+1 相连(1<=j<ci)，然后第 i 条链的第一个点会和 i-1 的第 ai 个点相连，第 ci 个点会和 i-1 的第 bi 个点相连，并且第一条链跳过
//现在问构成的边最多的封闭图形有几条边？

//可以发现第 i 条链与 i-1 相连时，构成的图形无非是考虑要么第 i 个自己独立形成一个：abs(ai-bi)+ci+1，要么就是依照前面的图形，把他们连起来：res-abs(ai-bi)+ci+1，那么我们发现就是 res-abs(ai-bi 与 abs(ai-bi) 的取舍
//求个最大值即可，另外注意第一条链没有向前的边，第二条链固定只有一个 abs(a2-b2)+c2+1，所以我们将 res 复制为第二条链的结果后从第三条链开始模拟即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

ll a[maxn],b[maxn],c[maxn],n;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&c[i]),c[i]--;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]),b[i]=abs(a[i]-b[i]);
        ll res=c[2]+b[2]+2,ans=c[2]+b[2]+2;
        for(int i=3;i<=n;i++){
            if(b[i]==0) res=2+c[i];
            else res=max(res-b[i]+c[i]+2,b[i]+c[i]+2);
            ans=max(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}
