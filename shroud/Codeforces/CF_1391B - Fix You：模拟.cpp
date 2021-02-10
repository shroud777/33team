//题意：给出一个 n*m 的网格，其中每个格子上都有一个字符代表当前格子走向哪个位置，现在要求修改若干格子内的字符使得所有 n*m-1 个格子都能到 (n,m) 位置

//思路：答案就是第 n 行 'D' 的个数与第 m 列 'R' 的个数，因为所有除了这一行一列其他所有格子不管是什么字符，最后都能达到第 n 行和第 m 列，然后就会跑出边界，所以我们只需要在乎最后一行一列即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e3+10;

char s[maxn][maxn];

int n,m,k,a[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int ans=0;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=m;i++){
            if(s[n][i]=='D') ans++;
        }
        for(int i=1;i<=n;i++){
            if(s[i][m]=='R') ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
