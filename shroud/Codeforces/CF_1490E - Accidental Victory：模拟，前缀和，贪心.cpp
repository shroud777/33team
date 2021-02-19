//题意：有 n 个玩家，每个玩家有一个能力值 ai，任意选择 2 个能力值非零的玩家进行 n-1 场对战，其中能力值大的玩家的能力值在战斗后变为两个玩家的能力值之和，小的玩家的能力变为 0
//最后一个能力值非 0 的玩家获得胜利，问可能胜利的玩家

//思路：一个能力值为 ai 的玩家一定能直接消除所有 aj(aj<=ai) 的玩家，那么它将变成 ai+Σaj，然后再去挑战更多的玩家，但是一旦没打过后面的任意一个玩家，他就不可能得到胜利
//所以我们只需要维护一个前缀和，si 代表能力值从小到大前 i 个玩家（如果所有 sj 都大于等于 aj+1）最优策略下最大能积累的和，那么只要找到最后一个 si<ai+1 的位置，那么这个位置之后的玩家都可以赢得胜利
//我们可以用结构体保存大小和玩家编号
//能力值最大的玩家一定能得到胜利，所以最差情况 pos=n，就是只有一个玩家满足要求

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

int n;

struct node{
    ll v;
    int id;
    bool operator <(const node &oth)const{
        return v<oth.v;
    }
}a[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> ans;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i].v),a[i].id=i;
        sort(a+1,a+n+1);
        ll sum=0,pos;
        for(int i=1;i<=n;i++){
            if(sum<a[i].v) pos=i;
            sum+=a[i].v;
        }
        for(int i=pos;i<=n;i++) ans.push_back(a[i].id);
        printf("%d\n",ans.size());
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++) printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
}
