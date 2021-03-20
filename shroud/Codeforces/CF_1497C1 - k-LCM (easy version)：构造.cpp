//题意：要求构造长度为 k(k=3) 的序列，满足 a1+a2+..+ak=n 且 lcm(a1,a2,...,ak)<=n/2

//思路：显然，很容易想到如果 n 是奇数，我们直接可以构造出 (1,(n-1)/2,(n-1)/2)
//接着就只剩偶数情况了，偶数分为两种，能被 4 整除的与不能整除的，那么显然如果可以被 4 整除，可以构造成 (n/4,n/4,n/2)
//剩下的最后一种情况，我们可以把这个数减 2，然后就变成了能被 4 整除的偶数，这种数还有一种性质，就是 x/2 仍然是偶数，所以我们构造 (2,(n-2)/2,(n-2)/2)
//由于 gcd(2,(n-2)/2)=2，所以他们的 lcm 就是 (n-2)/2，符合条件

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e5+10;

int n,k;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int temp=n-k+2;
        if(temp%2==0){
            for(int i=1;i<=k-2;i++) printf("1 ");
            printf("%d %d\n",temp/2,temp/2);
        }
        else{
            temp++;
            for(int i=1;i<=k-3;i++) printf("1 ");
            if(temp%4==0) printf("%d %d %d\n",temp/4,temp/4,temp/2);
            else printf("%d %d %d\n",2,(temp-2)/2,(temp-2)/2);
        }
    }
    return 0;
}
