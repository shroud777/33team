//题意：对于长度相同的 01 串 A 和 B，现在串 C 能通过 A 和 B 对应位相加得到，并且按照十进制规则相加，串 D 是将串 C 中连续的字符变成单一字符得到的串
//现在给出字符串 A，求一个字符串 B 使得 D 最大

//思路：首先长度越长就越大，所以我们保证 C 字符相邻位置都不一样，这样 D 的长度就是 n，并且肯定高位尽可能大，那我们肯定把 B 的第一位设置成 1，然后剩余的位满足在 ai+bi != ai-1+bi-1 的情况下，bi尽可能大

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

int n;
string a;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>a;
        string b="1";
        for(int i=1;i<n;i++){
            if(a[i]+'1'==a[i-1]+b[i-1]) b+="0";
            else b+="1";
        }
        cout<<b<<endl;
    }
    return 0;
}
