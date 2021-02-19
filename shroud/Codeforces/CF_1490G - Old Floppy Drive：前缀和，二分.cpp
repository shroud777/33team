//题意：给出一个长度为 n 的序列，不断循环累加上序列的值，1->n->1...，直到得到一个大于等于 x 的值，或者输出 -1 代表不存在解

//思路：设 si 代表前 i 项的前缀和，mx 为最大前缀和，如果 s[n]<=0 && mx<x，那么显然不存在解
//否则我们可以用 [(x-mx)/s[n]] 个循环类加上这么多个 s[n]，然后一定在 n 次累加内得到解，但是题目要求我们输出第一个大于等于 x 的位置，我们必须找到第一个大于等于它的值
//这里我们可以处理 dp 数组，代表第 i 个位置出现过的最大值，于是数组满足单调递增，二分即可。或者用类似单调栈思想，删除所有小于栈顶的元素，把大于的放上栈顶即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

int n,m,a[maxn];
ll s[maxn],dp[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        ll mx=*max_element(s+1,s+n+1);
        dp[1]=s[1];
        for(int i=2;i<=n;i++) dp[i]=max(dp[i-1],s[i]);
        while(m--){
            ll x;
            scanf("%lld",&x);
            if(s[n]<=0){
                int pos=-1;
                pos=lower_bound(dp+1,dp+n+1,x)-dp;
                printf("%d ",pos==n+1?-1:pos-1);
                continue;
            }
            ll k=max(0ll,x-mx);
            ll res=(k-1+s[n])/s[n];
            ll sum=1ll*res*s[n],pos;
            pos=lower_bound(dp+1,dp+n+1,x-sum)-dp;
            printf("%lld ",1ll*n*res+pos-1);
        }
        puts("");
    }
    return 0;
}
