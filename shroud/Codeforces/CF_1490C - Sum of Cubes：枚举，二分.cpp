//题意：给出 x，问 x 是否可以表示为 a^3+b^3，a，b 皆为正整数

//思路：枚举 a，检查 b 是否为整数或者二分 b 最后代入检验即可

#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
 
const int maxn=2e5+10;

ll n;

unordered_set<ll> s;

int main(){
    for(ll i=1;i*i*i<=1e12;i++) s.insert(i*i*i);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        bool f=0;
        for(ll i=1;i*i*i<=n;i++){
            if(s.count(n-i*i*i)){
                f=1;break;
            }
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
