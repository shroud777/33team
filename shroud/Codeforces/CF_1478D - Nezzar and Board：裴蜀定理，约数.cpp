//题意：给出 n 个数写在黑板上。现在可以任意在黑板上选两个数 x 和 y，并且得到一个新的数 2*x-y，问能否经过多次操作得到 k？

//思路：我们设选出的数为 x 和 y，x-y=d，y=x-d，可以发现 2*x-y=2*x-(x-d)，最后的结果是 x+d，那么我们每次选两个数，得到的就是某个数和他们的差之和
//并且这个差可以是任意 {ax,ay,zy...} 的线性组合的，我们把可以得到的结果表示成 ap+{ax-ay,ay-az,az-ax....} 这样的结果，ap代表任意某个基数
//我们可以设 ap=a1，因为不管这个基数是谁，我们都能通过 a1+d 得到，我们可以用 Σk(ai-a1) 来表示任意两个数之间的差（按照一定的线性组合），或者 Σk(ai-ai-1)
//那么最后的结果可以表示为 a1+Σk(ai-a1)，根据裴蜀定理，对于 {a1,a2..ak}，存在正数解 {x1,x2..xk} 使得 a1*k1+a2*k2+...ak*xk=gcd(a1,a2...,ak)|m
//最后只要 k-a1 可以整除 gcd(an-an-1...a3-a2,a2-a1) 就说明存在正整数解，那么就说明可以通过操作得到 k

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

ll n,k,x[maxn];

inline ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
        sort(x+1,x+n+1);
        ll g=0;
        for(int i=2;i<=n;i++) g=gcd(g,x[i]-x[i-1]);
        if((k-x[1])%g) puts("NO");
        else puts("YES");
    }
}
