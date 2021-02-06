//题意：给出一个字符串代表飞船在二维平面上行行驶的操作，分别代表上下左右移动一个格，现在问删除若干个操作后能否到达 (x,y) 坐标

//思路：只要原来字符串中包含的某个方向的字符的最大值大于往这个直线方向需要行驶的距离即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

string s;

int n,a[maxn];

int main(){
    int t;
    cin>>t;
    int x,y;
    while(t--){
        cin>>x>>y>>s;
        int l,r,u,d;
        l=r=u=d=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L') l++;
            else if(s[i]=='R') r++;
            else if(s[i]=='U') u++;
            else if(s[i]=='D') d++;
        }
        bool f=1;
        if(x>0&&r<x) f=0;
        if(x<0&&l<-x) f=0;
        if(y>0&&u<y) f=0;
        if(y<0&&d<-y) f=0;
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
