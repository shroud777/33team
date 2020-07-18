//题意：给定一个字符串长度为 n 的字符串，代表 M 在 1~n 秒内在二维平面内的移动轨迹，B 在 k 秒时站在 M 0 秒时所在位置，且第 t （t>k）秒时重复 M 第 t-k 秒的运动方式
//若过程中两者相遇，则任务失败，判断任务能否成功

//思路：模拟即可，在第 k 秒后判断当前时间 t 与 t-k 的位置是否相同

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int maxn=3e5+55;
struct node{
    int x,y;
}a[maxn];
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s='#'+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='U') a[i].y++;
        if(s[i]=='D') a[i].y--;
        if(s[i]=='L') a[i].x--;
        if(s[i]=='R') a[i].x++;
        a[i].x+=a[i-1].x;
        a[i].y+=a[i-1].y;
        if(i>=k&&a[i].x==a[i-k].x&&a[i].y==a[i-k].y){
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    return 0;
}
