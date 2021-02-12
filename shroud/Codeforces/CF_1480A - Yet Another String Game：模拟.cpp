//题意：给出一个字符串 s，现在 A 和 B 要轮流分别选择一个没有选过的下标位置，使得 ci=s(s!=ci)，并且 A 的目标是使得字符串尽可能小，B 的目标是使字符串尽可能大

//思路：要字典序尽可能大或小肯定优先改变最前面的，然后按照 A 和 B 的需求依次模拟即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

string s;

int n,a[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='a') s[i]='b';
                else s[i]='a';
            }
            else{
                if(s[i]=='z') s[i]='y';
                else s[i]='z';
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
