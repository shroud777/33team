//题意：现在给出 n 个物品的价格，并且要求 pi/sigma(pj)(j<i) <= k%，如果要求增加某些 pi 的值以满足要求，问最小增加的值的大小？

//思路：首先很明显，分母是一个价格的前缀和，那我们增加第一个物品的价格，后面相当于一劳永逸，所以我们只需要用一个变量维护前缀和即可
//接着我们列出式子 pi*100/(sigma(pj)(j<i)+x) <= k     pi*100-k*sigma(pj)(j<i)<=k*x，所以 x 的取值范围可以找到，只需要向上取整就可以得到应该加上的值了，然后前缀和和答案同时加上 x 即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e3+10;

ll n,k,p[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
        ll res=p[1],ans=0;
        for(int i=2;i<=n;i++){
            if(p[i]*100>res*k){
                ll temp=(p[i]*100-res*k-1+k)/k;
                ans+=temp;
                res+=temp;
            }
            res+=p[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
