//题意：给出一个长度为 n 的字符串 s 和一个正整数 k，现在定义字符串 s 有 x 等级要满足如下条件，能找出 x 个长度为 k 所有字符都相等并且不想交的子串，求最大可达到的 k

//思路：找连续的字符算出可以构成多少段 k 长度的子串，并且统计即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,k,cnt[30];

string s;

int main(){
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<n;i++){
        int res=1;
        while(s[i]==s[i+1]&&i+1<n) res++,i++;
        if(res>=k) cnt[s[i]-'a']+=res/k;;
    }
    int ans=0;
    for(int i=0;i<26;i++) ans=max(ans,cnt[i]);
    cout<<ans<<endl;
    return 0;
}
