//题意：给出一个长度为 n 的序列，现在要求按照如下方法构造一棵树：
//对于区间 [l,r]，找到最大值的位置 pos，然后以它作为当前子树的根，然后继续构造左子树 [l,pos-1]，右子树 [pos+1,r]

//思路：按照题意，递归即可，找出最大值，设置返回边界，并以树深为参数

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

ll n,a[maxn],d[maxn];

void solve(int l,int r,int deep){
    if(l>r) return;
    int pos=max_element(a+l,a+r+1)-a;
    d[pos]=deep;
    solve(l,pos-1,deep+1);
    solve(pos+1,r,deep+1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        solve(1,n,0);
        for(int i=1;i<=n;i++) printf("%lld%c",d[i],i==n?'\n':' ');
    }
    return 0;
}
