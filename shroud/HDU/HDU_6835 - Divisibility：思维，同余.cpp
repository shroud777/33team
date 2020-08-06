//题意：给出一个任意 b 进制数 c1c2c3...cn （ci 代表这个 b 进制数从左往右第 i 个数），如果 c1+c2+c3...+cn % x = 0，则 y % x = 0,反之 y % x !=0 ，给出 b 和 x 问对于任意 b 进制数 y，上述结论是否成立

//思维：当且仅当 b % x = 1 时上述结论才成立
//当 b % x = 1 时, y % x ==( c1*b^(n-1) + c2*b^(n-2) + c3*b^(n-3)... + cn*b^0 )% x
//所以上述结论成立

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll b,x;
        scanf("%lld %lld",&b,&x);
        if((b-1)%x==0) cout<<"T"<<endl;
        else cout<<"F"<<endl;
    }
    return 0;
} 
