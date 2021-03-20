//题意：要求构造长度为 k (k>=3)的序列，满足 a1+a2+..+ak=n 且 lcm(a1,a2,...,ak)<=n/2

//思路：相比 easy version，这道题少了对 k 的限制，由于题目保证存在解，且 ai>=1，那么我们只需要参照 ez version 把 n 改为 n-k+3 即可，然后前 k-3 个位置全部设置为 1 即可

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
