//题意：一个字符串的价值是其中最大回文串的长度，现在给出字符串 A 和 B，合成一个串 C，属于 A 和 B 的字符在 C 中的顺序保持不变，问 C 可能的最大价值是多少？

//思路：数据范围较小，可以考虑区间DP
//我们考虑 C 中的最大回文串是由 A 的子串和 B 的子串得到的，那我们设是由 [Al,Ar] 合并 [Bl,Br] 得到
//我们可以枚举子串，设状态 DP[i][j][k][l]，代表选取的 [Ai,Aj] [Bk,Bj] 得到
//那么我们可以发现它可以由 [Ai,Aj-1][Bk+1,Bl](Aj==Bk),  [Ai+1,Aj][Bk,Bl-1](Ai==Bl),  [Ai+1,Aj-1][Bk,Bl](Ai==Bl),  [Ai,Aj][Bk+1,Bl-1](Bk==Bl) 这四种情况转移
//并且边界条件的设置比较关键，我们可以将两个字符串的长度和不超过 1 时设置为 true，然后用逻辑与运算进行转移

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e3+10;

string a,b;

//dp[i][j][k][l] 第一个字符串的 [i,j] 第二个字符串的 [k,l]

bool dp[55][55][55][55];
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof dp);
        cin>>a>>b;
        a='#'+a;
        b='#'+b;
        int ans=1;
        for(int lena=0;lena<a.size();lena++){
            for(int lenb=0;lenb<b.size();lenb++){
                for(int i=1,j=lena;j<a.size();i++,j++){
                    for(int k=1,l=lenb;l<b.size();k++,l++){
                        if(lena+lenb<=1) dp[i][j][k][l]=1;
                        else{
                            if(a[i]==a[j]&&i) dp[i][j][k][l]|=dp[i+1][j-1][k][l];
                            if(a[i]==b[l]&&i) dp[i][j][k][l]|=dp[i+1][j][k][l-1];
                            if(b[k]==b[l]&&k) dp[i][j][k][l]|=dp[i][j][k+1][l-1];
                            if(a[j]==b[k]&&k) dp[i][j][k][l]|=dp[i][j-1][k+1][l];
                        }
                        if(dp[i][j][k][l]) ans=max(ans,lena+lenb);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
