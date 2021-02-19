//题意：给出一个长度为 n 的序列，现在可以删除任意元素，求使序列中所有相同元素出现次数相等的最少删除数量

//思路：我们不在乎元素的大小，我们只在乎出现次数，我们先统计每个元素出现的次数，然后再统计出现 x 次的数的个数 y，用 2 个 map 即可
//然后我们可以枚举答案，即相同元素出现的次数应该是多少，那么假设当前枚举的出现次数为 x，答案就是 所有小于 x 的数 + Σ大于 x 的数 m 的个数*(m-x)
//为了方便计算，我们可以假设把所有数删掉，那么我们多减掉的无非就是出现次数大于等于 x 的数的个数 * x

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

int n,a[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        map<int,int> mp,cnt;
        int x,tot=0;
        for(int i=1;i<=n;i++) scanf("%d",&x),mp[x]++;
        for(auto it:mp) cnt[it.second]++,tot++;
        //出现 x 次的数的数量为 y
        int ans=0x3f3f3f3f,l=0;
        for(auto[x,y]:cnt){
            ans=min(ans,n-tot*x);
            tot-=y;
            l+=x*y;
        }
        cout<<ans<<endl;
    }
    return 0;
}
