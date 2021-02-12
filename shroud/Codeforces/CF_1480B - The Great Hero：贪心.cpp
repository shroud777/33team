//题意：现在一个英雄有 A 的攻击力，B 的血量，有 n 个怪物攻击力和血量分别为 ai 和 bi，如果英雄或者怪物的血量小于等于 0，就意味着死亡，无法继续战斗，现在问英雄是否可以杀光所有 n 个怪物（如果最后英雄和第 n 个怪物同时死亡也算杀光了）

//思路：首先算出英雄杀光所有的怪物需要有 Σ(bi-1+A)/A*ai 的血量，但是根据题意，我们可以在杀死最后一只怪物的前提下，与最后一只怪物同生共死
//那么也就意味着我们给最后一个怪物最后一击的时候我们活着即可，并且由于跟怪物对战的顺序没有规定，我们只需要以攻击力大的作为最后一只对战的怪物即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e6+10;

ll A,B,n;
ll a[maxn],b[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>A>>B>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        ll res=0,mx=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&b[i]);
            res+=(b[i]-1+A)/A*a[i];
            mx=max(mx,a[i]);
        }
        if(B-res+mx>0) puts("YES");
        else puts("NO");
    }
    return 0;
}
