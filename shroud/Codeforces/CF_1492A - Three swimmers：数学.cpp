//题意：现在有 3 个人在游泳，初始位置都在左上角，三个人游一圈分别需要 a，b，c 的时间，现在有个人在 p 时刻进入左上角并待在原地，问第一次与别人相遇的时间

//思路：显然答案就是 p 对每个单位时间 a，b，c 取模，然后得到对于每段单位时间现在处在的位置，然后再用单位时间 a，b，c 减去这一段即可，并且注意如果取模为 0，代表两者已经重合

#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;

ll p,a[5];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>p;
        for(int i=1;i<=3;i++) cin>>a[i];
        ll ans=1e18;
        for(int i=1;i<=3;i++){
            ans=min(ans,p%a[i]==0?0:a[i]-p%a[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
