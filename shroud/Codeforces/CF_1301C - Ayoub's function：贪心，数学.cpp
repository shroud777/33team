//题意：我们定义 f(s) 代表 01 串中包含 1 的子串的数量，现在给出 01 串长度与其中包含的 m 的个数，求 f(s) 可能存在的最大值

//首先 f(s) 可以转化为 所有子串的数量减去不包含 1 的子串的数量 - 所有连续的 0 的个数等差数列之和的和
//那么这里我们子串数量是固定的  n*(n+1)/2，我们只需要尽可能让不包含 1 的个数尽量小即可，其中 0 的个数为 n-m，我们知道，如果将这 n-m 个全部连续的值肯定最大，尽量分开的值肯定会小
//那么我们考虑用 m 个 '1' 把这 n-m 个 '0' 分成 m+1 份，所以每份就是 (n+m)/(m+1) 份，并且有 (n+m)%(m+1) 份的个数要加 1

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,m;

inline ll cal(ll n){
    if(n&1) return (n+1)/2*n;
    return n/2*(n+1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ll ans=cal(n);
        ll temp=(n-m)/(m+1);
        ll k=(n-m)%(m+1);
        //cout<<temp<<" "<<k<<endl;
        cout<<ans-cal(temp)*(m+1-k)-cal(temp+1)*k<<endl;
    }
    return 0;
}
