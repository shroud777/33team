//题意：现在有 a 个男生，b 个女生，并且有 k 个二元组 (x,y) 分别代表第 x 个男生可以和第 y 个女生组队参加派对，现在问有多少种方案从中任选两个二元组并且不冲突（共有同一个男生或女生）‘’

//思路：一般来说我们选中一个二元组之后剩下 k-1 对二元组，其中不可以包含有 x 的和有 y 的二元组，那么我们只要利用一个数组维护 x 有多少个二元关系，y 有多少个二元关系
//然后显然这其中会包含 2 次 (x,y) 的二元关系，所以答案是对于第 i 个二元关系来说，他能选择其他 k-1-[x]-[y]+2 作为另一个二元组
//那么我们发现这样最终会把方案统计两次，除以 2 即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

int a,b,k,cnt0[maxn],cnt1[maxn],x[maxn],y[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>k;
        for(int i=1;i<=a;i++) cnt1[i]=0;
        for(int i=1;i<=b;i++) cnt0[i]=0;
        for(int i=1;i<=k;i++){
            scanf("%d",&x[i]);
            cnt1[x[i]]++;
        }
        for(int i=1;i<=k;i++){
            scanf("%d",&y[i]);
            cnt0[y[i]]++;
        }
        ll ans=0;
        for(int i=1;i<=k;i++){
            ans+=k-1-cnt1[x[i]]-cnt0[y[i]]+2;
        }
        printf("%lld\n",ans/2);
    }
    return 0;
}
