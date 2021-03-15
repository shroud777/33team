//题意：现在有 n 颗糖果，每颗糖果具有一个甜度 ai，现在在第 i 天（天数下标从 1 开始）吃第 i 颗糖能获得 d*ai 的权值，每天最多吃 m 颗，求吃完 1~n 颗糖的最小权值

//思路：根据重排不等式，我们总是用甜度较高的来搭配天数下标较小的来获得更小的权值，那么我们如果直接计算显然复杂度为 O(n^2)
//那么我们通过模拟可以发现，当从 k 个糖到 k+1 个糖时，我们那些处于 k%m 天数的糖果的天数系数会加一，所以我们只需要用一个数组记录天数取模位置的前缀和即可
//换种思路，从 k 到 k+m 天，可以发现新增加了 Σk+1-k+m 糖果 * 第一天（1） 的权值加前 k 天的权值

#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

typedef long long ll;

int n,m;
ll a[maxn],sum[maxn];

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    ll res=0;
    for(int i=1;i<=n;i++){
        res+=a[i];
        res+=sum[i%m];
        sum[i%m]+=a[i];
        printf("%lld ",res);
    }
    return 0;
}
