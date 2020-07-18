//题意：给出一行字符串，逆转字符串

//思路：签到，reverse 和 getline(cin,string) 用好，注意输入带空格即可

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int maxn=2e5+10;
int main(){
    string s;
    while(getline(cin,s)){
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
    return 0;
}
