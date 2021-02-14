//题意：现在有 m 件物品，每件物品分为主件与附件，都有价格与重要度，现在要求选的物品不超过 n 的价格，并且选附件必须先选主件，求最大的价格与重要度的乘积
//每件主件有 0，1，2 件附件

//思路：很明显这是一个有依赖的 01 背包，我们也可以把它看作分组背包
//对于每一组，根据附近为 0，1，2，我们可以选若干组合
//以 2 为例，我们可以选 主件，主件+附件1，主件+附件2，主件+附件1+附件2，这些都是互斥的选项，所以分在一组里
//我们还可以在主件的基础上在选择附件，用一个额外的 dp 数组记录状态转移，这样可以保证先转移主件，然后再转移附件，最后把结果带回原 dp 数组

//分组背包：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e6+10;

#define x first
#define y second
#define pb push_back

typedef pair<int,int> pii;

vector<pii> t[65],a[65];

int n,m,tot=0;
int dp[maxn];
int v[65],p[65],q[65];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>v[i]>>p[i]>>q[i];
        if(!q[i]) t[i].pb(pii(v[i],p[i]));
    }
    for(int i=1;i<=m;i++){
        if(q[i]) t[q[i]].pb(pii(v[i],p[i]));
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<t[i].size();j++) v[j]=t[i][j].first,p[j]=t[i][j].second*t[i][j].first;
        if(t[i].size()==1){
            a[++tot].pb(pii(v[0],p[0]));
        }
        else if(t[i].size()==2){
            a[++tot].pb(pii(v[0],p[0]));
            a[tot].pb(pii(v[0]+v[1],p[0]+p[1]));
        }
        else if(t[i].size()==3){
            a[++tot].pb(pii(v[0],p[0]));
            a[tot].pb(pii(v[0]+v[1],p[0]+p[1]));
            a[tot].pb(pii(v[0]+v[2],p[0]+p[2]));
            a[tot].pb(pii(v[0]+v[1]+v[2],p[0]+p[1]+p[2]));
        }
    }
    for(int i=1;i<=tot;i++){
        for(int j=n;j>=0;j--){
            for(int k=0;k<a[i].size();k++){
                int w=a[i][k].x;
                int v=a[i][k].y; 
                if(j-w>=0) dp[j]=max(dp[j],dp[j-w]+v);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}

//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e6+10;

int n,m,v[65],p[65],q[65];
int dp1[maxn],dp2[maxn];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>v[i]>>p[i]>>q[i],p[i]*=v[i];
    for(int i=1;i<=m;i++){
        if(q[i]) continue;
        for(int j=n;j>=v[i];j--) dp2[j]=dp1[j-v[i]]+p[i];
        for(int j=1;j<=m;j++){
            if(q[j]!=i) continue;
            for(int k=n;k-v[j]>=v[i];k--) dp2[k]=max(dp2[k],dp2[k-v[j]]+p[j]);
        }
        for(int j=v[i];j<=n;j++) dp1[j]=max(dp2[j],dp1[j]);
    }
    cout<<dp1[n]<<endl;
    return 0;
}
