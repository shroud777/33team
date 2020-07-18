//题意：按照题目要求输出指定内容即可

//思路：模拟签到

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int maxn=2e5+10;
int main(){
    int t;
    cin>>t;
    string s1,s2;
    while(t--){
        cin>>s1;
        if(s1[0]<='z'&&s1[0]>='a'){
            cin>>s2;
            if(s1.size()<6) cout<<s1;
            else{
                if(s1=="leftup") cout<<"left up";
                if(s1=="rightup") cout<<"right up";
                if(s1=="leftdown") cout<<"left down";
                if(s1=="rightdown") cout<<"right down";
            }
            if(s2=="Dash") cout<<" "<<'X';
            cout<<endl;
        }
        else{
            if(s1[0]=='Q'||s1[0]=='S') cout<<"down"<<endl;
            else if(s1[0]=='G') cout<<'Z'<<endl;
            else if(s1[0]=='J') cout<<'C'<<endl;
        }
    }
    return 0;
}
