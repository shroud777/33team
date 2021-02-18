//题意：现在有 n 个英雄，现在任意两个英雄进行对战直到某个英雄赢了 100^500 场战斗，问哪些英雄可能赢得战斗？

//思路：对于英雄 i，只要存在 aj<ai 的英雄，那么他就可以永远选择比他小的从而赢得战斗，所以答案就是 n-cnt[min]

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int a[maxn],n;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<n-count(a+1,a+n+1,*min_element(a+1,a+n+1))<<endl;
    }

    return 0;
}
