//题意：给出三个长度为 n 的字符串 a,b,c，现在对于每个 ci，必须和 ai 或 bi 交换一次，问最后字符串 a 和 b 能否相等？

//思路：由于 ci 必须进行一次交换，所以最后 ai 和 bi 相等于变成了 ci 和 bi 或 ai 和 ci，所以只要这俩种情况存在字符相等即可满足交换后 ai=bi

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;
int n;

string a,b,c;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        n=a.size();
        bool f=1;
        for(int i=0;i<n;i++){
            if(a[i]==c[i]||b[i]==c[i]) continue;
            f=0;
            break;
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
