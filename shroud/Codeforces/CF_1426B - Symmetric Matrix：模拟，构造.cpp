//题意：给出 n 个 2*2 大小的矩形，现在问你能否构成一个 m*m 的矩形 s 并满足  s[i][j] = s[j][i]

//思路：首先如果 m 为奇数，显然无法构造。其次可以发现，在构成的矩形中，其中组成的每个 2*2 矩形的左上角和右下角都是无关紧要的，要么在对角线上，要么可以利用同一个满足自我对称
//我们只有找到一个左下角和右下角相等的矩形，才能满足构造

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
        bool f=0;
        int a,b,c,d;
        for(int i=1;i<=n;i++){
            cin>>a>>b>>c>>d;
            if(b==c) f=1;
        }
        if((x&1)||!f) puts("NO");
        else puts("YES");
    }
    return 0;
}
