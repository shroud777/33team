//题意：一个长度为 2n 的序列，所有的元素都不相等，并且存在对于任意 i(1<=i<=2n)，都存在一个 j(1<=j<=2n) 使得 a[i]=-a[j]。现在给出数组 d，di = ∑|ai−aj|，问是否存在满足题意的序列 a？

//思路：首先可以发现对于数组的最大值 ai 到任意 aj(j!=n) 和 -aj 的距离都是 2*ai，而 aj 到 ai 和 -ai 的距离之和也为 ai，那么这道题有了突破口
//我们把所有序列想象是排列在数轴上的数，并且由于序列中的元素都不相等，绝对值最大的一个数 x，里其他的数的距离之和也就是 dx 是最大的 = 2*n*x，并且值为 -ax 的 d 值也为 2*n*x
//所以这里我们要保证 d 数组中的元素都是两两相等，并且与其他都不等，并且 d 值按照降序应该可以整除 (n-i+1)*2
//接着我们可以对绝对值次大的 y 来分析，他的 d 值应该是 2*(n-1)*y+2x，并且由于 x 已经求出，我们依旧可以按照上面的做法，判断是否有余数后得到 y....接着以此类推，只要能整除，并且得到的值不为 0 和负数就可以了
//因为 0 的话代表两个数都要为 0，显然不满足题意

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

map<ll,int> mp;
int n;

int main(){
    int t;
    cin>>t;
    while(t--){
        mp.clear();
        vector<ll> v;
        cin>>n;
        ll x;
        for(int i=1;i<=2*n;i++){
            scanf("%lld",&x);
            if(!mp[x]) v.push_back(x);
            mp[x]++;
        }
        bool f=1;
        for(int i=0;i<v.size();i++){
            if(mp[v[i]]!=2){
                f=0;break;
            }
        }
        if(v.size()!=n||!f){
            puts("NO");continue;
        }
        sort(v.rbegin(),v.rend());
        ll sum=0;
        for(int i=0;i<v.size();i++){
            ll temp=v[i];
            temp-=sum;
            if(temp%(2*(n-i))!=0||temp<=0){
                f=0;break;
            }
            ll res=temp/(2*(n-i));
            if(res<=0){
                f=0;break;
            }
            sum+=2*res;
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
