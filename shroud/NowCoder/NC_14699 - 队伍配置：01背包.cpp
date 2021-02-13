//题意：现在玩家可以自己配置自己的队伍，可供玩家选择的人物称为“从者”，玩家对每个“从者”可以至多装备 1 件“礼装“，玩家有一个 cost 上限值
//每个从者和礼装都有攻击值 ATK，并且都会占据一定的 cost 值，礼装和从者的 cost 值之和不得超过玩家的 cost 上限
//每个从者和礼装都只能上场一次，并且不能重复使用，礼装不能单独存在，只能装备在从者身上
//最多可以选择 5 名从者（在 cost 值得限制下），现在要求满意定义得条件下队伍可以凑出得最大 ATK 值

//思路：题目要求其实和 01背包 十分相似，就是每个从者和礼装选和不选
//dp[i][j][k] 代表 i 个从者，j 个礼装，cost 值为 k 时的最大 atk，由于礼装依附于从者，我们先转移 j=0 时从者的状态
//接着转移礼装的状态，注意转移的顺序即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=305;

int n,m,d;
int atk1[maxn],atk2[maxn],cost1[maxn],cost2[maxn];
int dp[maxn][maxn][205];

//dp[i][j][k] 代表 i 个从者，j 个礼装，cost 值为 k 时的最大 atk

int main(){
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++) scanf("%d %d",&atk1[i],&cost1[i]);
    for(int i=1;i<=m;i++) scanf("%d %d",&atk2[i],&cost2[i]);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=min(5,i);j;j--){
            for(int k=d;k>=cost1[i];k--){
                dp[j][0][k]=max(dp[j][0][k],dp[j-1][0][k-cost1[i]]+atk1[i]);
                ans=max(ans,dp[j][0][k]);
            }
        }
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=m;j++){
            for(int k=i;k;k--){
                for(int l=d;l>=cost2[j];l--){
                    dp[i][k][l]=max(dp[i][k][l],dp[i][k-1][l-cost2[j]]+atk2[j]);
                    ans=max(ans,dp[i][k][l]);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
