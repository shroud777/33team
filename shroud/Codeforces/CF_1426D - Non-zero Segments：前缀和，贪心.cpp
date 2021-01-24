//题意：给出一个长度为 n 的序列，其中没有为 0 的元素，现在可以向序列中插入一些数，使得整个序列中所有连续区间的和不为零

//思路：首先要明确，当然 pl-1=pr 时(pr-pl-1==0)，说明 [l,r] 内的和为 0
//我们现在从左到右，每当出现一个为零的区间 [l,r] ，我们就往 r-1 到 r 中间插入一个数使得 [1,r] 不会再出现为 0 的区间，那么意味着我们可以舍弃 r-1 左边的区间了，只需要看右边的即可
//那么现在的问题就是判断出现区间和为 0 的区间，我们只需要用一个 map 或者 set 记录前缀和，然后只要重复出现前缀和值，我们就把 map 或 set 清空，并且每次要把以 0 和 r 的值为前缀和的情况初始化记录其中

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;

int n,a[maxn];
 
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    map<ll,int> mp;
    int ans=0;
    ll sum=0;
    mp[0]=1;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(mp[sum]){
            ans++;
            mp.clear();
            mp[0]=1;
            sum=a[i];
        }
        mp[sum]++;
    }
    cout<<ans<<endl;
    return 0;
}
