//题意：求 [a,b] 区间中与 n 互质的数的个数

//思路：题目可以转换为求 [1,a-1] [1,b] 区间内与 n 互质的数的个数，然后用前缀和思想得到结果
//把区间左端点移到 1 有什么好处呢？比较方便直接找到区间内 p 个倍数的个数
//这里与 n 互质的个数，我们可以先简单化处理，假设 n=p0^c0，那么显然减去区间内 p0 的倍数的个数，我们就得到了与 n 互质的数的个数
//那么对于 n=p0^c0+p1^c0，我们可以仿照上一个，依次减去 p0 和 p1 的倍数，但是我们会发现，对于那些同时包含质因子 p0，p1 的数，我们显然是重复减了一次，那我们再加上这部分即 p0*p1 个个数即可
//当 n=p0^c0+p1^c1...+pk^ck 时，我们根据上述原则即容斥原理，利用奇减偶加的性质，即可在原答案区间长度上得到最后的答案

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e8+10;

ll a,b,n;

vector<int> v;

void solve(ll n){
    v.clear();
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) v.push_back(n);
}

int main(){
    int t,T=0;
    cin>>t;
    while(t--){
        cin>>a>>b>>n;
        solve(n);
        int sz=v.size();
        ll ans=b-a+1;
        for(int i=1;i<(1<<sz);i++){
            int k=i,cnt=0;
            ll temp=1;
            while(k){
                if(k&1) temp*=v[cnt];
                cnt++;
                k>>=1;
            }
            ll res=b/temp-(a-1)/temp;
            if(__builtin_popcount(i)&1) ans-=res;
            else ans+=res;
        }
        printf("Case #%d: %lld\n",++T,ans);
    }
    return 0;
}
