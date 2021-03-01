//题意：现在有 n 个蹦床，每个蹦床有一个弹性强度 si，如果你跳到 i 号蹦床，那么会通过 i 号蹦床跳到下一个位置 i+si，并且 i 号的弹性强度会变为 max(1,si-1)，如果 i+si 是一个大于 n 的位置，那么这次跳跃就结束了
//现在你要任意选择起始位置开始，并且尽可能少的次数内是所有的蹦床弹性强度变为 1

//思路：首先我们要明确一个贪心策略：我们从左到右遍历整个序列，如果当前 si>1，那么代表由于左边已经完成，我们只能以 i 为起点跳 si-1 次
//那么我们可以以此开展分析：如果 si 大于 1，那么从 [i+1,i+si] 位置都要减 1，由于这里数据比较小，我们可以选择循环累加，当然数据大了只能选择用差分数组
//然后这里就是细节所在，如果当前 si，si 减去累加上的差分数组，仍然大于 1，那么就说明我们需要花费代价去消除；那么如果小于 1 呢？说明仅靠左边的蹦床的贡献，我们就可以消除当前蹦床的贡献，同时！
//由于左侧的多次贡献，当前 si<1，那么我们当前蹦床跳出去的贡献肯定不止 [i+1,i+si] 这个区间了，所有 1-x 这些贡献都将延申到下一个蹦床，并且不断延续下去，直到某个蹦床吸收左边贡献后值仍大于 1

#include<iostream>

using namespace std;

const int maxn=5e5+10;

typedef long long ll;

ll a[maxn],d[maxn];
int n,m,k;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),d[i]=0;
        ll ans=0,temp=0;
        for(int i=1;i<=n;i++){
            d[i]+=d[i-1];
            d[i+2]++;
            d[min(1ll*(n+1),i+a[i]+1)]--;
            a[i]-=d[i]+temp;
            ll res=a[i]-1;
            if(a[i]>1) temp=0;
            else temp=1-a[i]; 
            if(res>0) ans+=res;
        }
        cout<<ans<<endl;
    }
    return 0;
}
