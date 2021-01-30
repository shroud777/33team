//题意：现在可以对一个数作两种操作：
//如果 x 为偶数，x=3/2*x
//如果 x 大于 1，x=x-1
//问能否从 x 得到 y？

//思路：可以发现如果 x>3，那么可以得到任意 y，如果 x=1，只能得到 1，x =2，3 的话就可以得到 1，2，3，判断即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;

int x,y;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>x>>y;
        if(x<=3){
            if(x==2) x=3;
            if(x>=y) puts("YES");
            else puts("NO");
            continue;
        }
        puts("YES");
    }
    return 0;
}
