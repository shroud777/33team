//题意：给出一个长度为 n 的序列，对于一个正整数 t，如果所有序列元素 |xi-t|<=1，则称序列是 good 的，现在要求一个 t 使得序列对于该 t 是 good 的并且修改的元素的值的和最小

//思路：序列元素值域 [1,100]，那么 t 的值也应该从 [1,100] 中挑选，我们 O(100*n) 枚举即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn];

string s1,s2;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int mn=0x3f3f3f3f,ans;
    for(int i=1;i<=100;i++){
        int res=0;
        for(int j=1;j<=n;j++){
            if(a[j]>i) res+=a[j]-i-1;
            else if(a[j]<i) res+=i-1-a[j];
        }
        if(res<mn){
            mn=res,ans=i;
        }
    }
    cout<<ans<<" "<<mn<<endl;
    return 0;
}
