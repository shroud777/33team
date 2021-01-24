//题意：现在除了第一层楼有 2 个套房外，其他楼层都有 x 个套房，套房编号从低到高升序，现在问 n 号套房处在第几层

//思路：当 n<=2 时，在第一层套房，否则就在 (n-3)/x+2 层

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,x;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>x;
        if(n<=2) puts("1");
        else printf("%d\n",(n-3)/x+2);
    }
    return 0;
}
