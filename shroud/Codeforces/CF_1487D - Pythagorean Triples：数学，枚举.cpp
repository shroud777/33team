//题意：问 n 以内，有多少三元组 (a,b,c)(a<=b<=c<=n)，满足 a^2+b^2=c^2 && c=a^2-b

//思路：将 c=a^2-b 代入可以得到：b*(b+1)=c*(c-1) => c=b+1，a^2=2*c-1，
//说明 a 必然是一个奇数，b c 才有整数解，那么最大值 c 的最大取值范围为 [1,n]，代入得到 a 的范围，然后去奇数并且除去 1 即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,k;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<((int)sqrt(2*n-1)-1)/2<<endl;
    }
    return 0;
}
