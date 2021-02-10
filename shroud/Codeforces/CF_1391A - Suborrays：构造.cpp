//题意：要求输出一个长度为 n 的全排列序列，使得找出任意两个位置 1<=i<=j<=n，满足 ai|ai+1|...|aj>=j-i+1

//思路：所有全排列都是满足的，随便输出即可，因为对于任意一个序列 (i,j) 必然有一个 ak>=j-i+1

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

string s;

int n,m,k,a[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) printf("%d%c",i,i==n?'\n':' ');
    }

    return 0;
}
