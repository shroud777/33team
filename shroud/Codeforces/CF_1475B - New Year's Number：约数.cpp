//题意：给出一个数 n，问 n 是否可以由若干个 2020 和若干个 2021 组成？

//思路：设 n=2020x+2021y,n=2020(x+y)+y，x+y>=y
// x+y=n/2020,y=n%2020
//所以只需要 x+y>=y 即可

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
        if(n/2020>=n%2020) puts("YES");
        else puts("NO");
    }
    return 0;
}
