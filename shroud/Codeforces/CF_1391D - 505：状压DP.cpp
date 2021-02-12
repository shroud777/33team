//题意：给出一个 n*m 的 01矩形，现在要求所有偶数大小的正方内包含的 1 的个数为奇数，问能否通过改变当前矩形使满足要求，并且求出最小代价

//思路：首先我们可以知道如果 n 和 m 同时大于 3，那么内部就会至少有一个 4*4 这样的子正方形，并且一个 4*4 的正方形内部有 4 个 2*2 的正方形，显然无法满足 4 个正方形内部都是奇数，然后 1 个大的内部也都是奇数
//所有我们只需要判断 2<=min(n,m)<=3 的情况即可，并且由于 n<=m，所以只需对 n 作出变化即可，这里我们可以使用状态压缩即第 i 列的所有元素进行状态压缩
//接下来设 dp[i][cmask] 为第 i 列的状态压缩表示，状态转移方程为 dp[i][mask]=min(dp[i][mask]+dp[i-1][mask']+builtin_popcount(mask^temp[i]))，这里 mask' 代表前一列能与 mask 组成合法矩形的一列，可以预处理一下


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e6+10;

int n,m;
int cmp[65][65],temp[maxn];
int a[4][maxn],dp[10][maxn];
char s[4][maxn];

void init(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            temp[i]|=a[j][i]<<j-1;
        }
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<(1<<n);j++){
            int tot=0,res[3]={1};
            for(int k=2;k<=n;k++){
                res[++tot]^=(i>>k-2&1)^(j>>k-2&1);
                res[tot]^=(i>>k-1&1)^(j>>k-1&1);
            }
            cmp[i][j]=1;
            for(int k=1;k<=tot;k++){
                cmp[i][j]&=res[k];
            }
        }
    }
}

int solve(){
    for(int i=0;i<(1<<n);i++) dp[i][0]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<(1<<n);j++){
            int res=__builtin_popcount(j^temp[i]);
            for(int k=0;k<(1<<n);k++){
                if(i!=1&&!cmp[j][k]) continue;
                dp[j][i]=min(dp[j][i],dp[k][i-1]+res);
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=0;i<(1<<n);i++) ans=min(ans,dp[i][m]);
    return ans;
}

int main(){
    cin>>n>>m;
    if(n>=4&&m>=4){
        puts("-1");return 0;
    }
    if(n<2||m<2){
        puts("0");return 0;
    }
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) a[i][j]=s[i][j]-'0';
    }
    init();
    memset(dp,0x3f,sizeof dp);
    printf("%d\n",solve());
    return 0;
}
