//题意：有 n 个小朋友在一列上，其中有两个小朋友分别在 a 和 b 的位置，他们的距离为 |a-b|，现在他们可以和周围的小朋友交换 x 次位置，问最大距离可以是多少？

//思路：最多可以有 n-1 的位置，尽可能多的交换

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;

int n,x,a,b;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>x>>a>>b;
        cout<<min(n-1,(abs(b-a)+x))<<endl;
    }

    return 0;
}
