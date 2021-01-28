//题意：给出一个 n，问 n 是否存在一个奇约数 x？

//思路：所有质数中只有 2 是偶数，所以只要 n 包含除 2 外的其他质因子，就存在这么个 x。也就是说只要 n 不是 2 的幂次，那么就存在 x
//判断一个数是否是 2 的幂次，我们可以不断除 2，最后判断剩下的数是否为 1，或者直接用位运算技巧，我们知道 2 的幂次在二进制中只有一位，我们用 x & (-x)，那么就能消掉 2 的幂次唯一的一位二进制位

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

ll n;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        bool f=0;
        while(n){
            if(n%2==1&&n!=1) f=1;
            n>>=1;
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
