//题意：给出一个形如 num operator num equal num 的表达式， operator 只包含 + - * /，数字是由 2~16 进制组成，判断表达式的最小进制是多少

//思路：模拟即可，从表达式中最大数字进制开始枚举，注意不存在 0进制 和 1进制，因此最小也要从 2 开始，注意细节即可

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
string num[5];

inline ll qpow(ll a,ll b){   
    ll base=a;
    ll ans=1; 
    while(b){
        if(b&1) ans=ans*base;
        base=base*base;
        b>>=1;
    }
    return ans;
}

inline ll turn(string s,int r){
    reverse(s.begin(),s.end());
    ll ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0') ans+=(s[i]-'0')*qpow(r,i);
        else ans+=(s[i]-'A'+10)*qpow(r,i);
    }
    return ans;
}

ll temp[5];

int main(){
    string s;
    while(cin>>s){
        int maxc=0,cmp;
        int tot=0,xb;
        for(int i=0;i<4;i++) num[i].clear();
        for(int i=0;i<s.size();i++){
            if((s[i]<='9'&&s[i]>='0')||(s[i]<='F'&&s[i]>='A')){
                tot++;
                while((s[i]<='9'&&s[i]>='0')||(s[i]<='F'&&s[i]>='A')){
                    cmp=((s[i]<='9'&&s[i]>='0')?s[i]-'0':s[i]-'A'+10);
                    maxc=max(maxc,cmp);
                    num[tot]+=s[i];
                    i++;
                }
                i--;
            }
            else if(s[i]!='=') xb=i;
        }
        maxc=max(1,maxc);
        int ans=-1;
        for(int i=maxc+1;i<=16;i++){
            for(int j=1;j<=3;j++) temp[j]=turn(num[j],i);
            //cout<<temp[1]<<" "<<temp[2]<<" "<<temp[3]<<endl;
            if(s[xb]=='/'){
                if(temp[1]*1.0/temp[2]==temp[3]){
                    ans=i;
                    break;
                }
            }
            else if(s[xb]=='*'){
                if(temp[1]*temp[2]==temp[3]){
                    ans=i;
                    break;
                }
            }
            else if(s[xb]=='+'){
                if(temp[1]+temp[2]==temp[3]){
                    ans=i;
                    break;
                }
            }
            else if(s[xb]=='-'){
                if(temp[1]-temp[2]==temp[3]){
                    ans=i;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
} 
