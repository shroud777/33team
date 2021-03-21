//题意：给出一个长度为 n 的序列，要求划分为尽可能少的连续区间，满足每个新区间内都不存在两个数使得 ai*aj 是完全平方数，并且现在有 k 次机会可以任意修改一个数为任何数

//思路：相比于 ez version，这道题多了一个 k 次修改。好像没有什么处理的方法，但是能想到应该是用 dp 去处理
//我们先猜测状态为 dp(i,j) 代表前 i 个数用了 j 次修改所划分的最小区间数，那么显然我们可以枚举上一个区间用了几次修改，那么这样状态转移方程为：
//dp[i][j]=min(dp[i][j],dp[pos][j-x]+1)，这个 pos 代表从 i 位置往前至多修改 k 次能够达到的最左的合法区间左端点，那么我们显然只要维护出这个 pos 即可
//我们可以用双指针再 O(n*k) 复杂度内维护出所有的 left[i][j]，即第 i 个位置至多修改 k 次能到达到的最左的合法区间左端点
//DP 复杂度 O(n*k*k)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;
const int N=1e7+10;

int n,k,vis[N],mp[N];
int a[maxn];
int l[25][maxn];

vector<int> pri;

void sieve(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]) vis[i]=i,pri.push_back(i);
        for(int j=0;j<pri.size();j++){
            int p=pri[j];
            if(vis[i]<p||p*i>n) break;
            vis[i*p]=p; 
        }
    }
}

int main(){
    sieve(1e7);
    int t;
    cin>>t;
    while(t--){
        scanf("%d %d",&n,&k);
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            a[i]=1;
            int cnt=0,last=0;
            while(x>1){
                if(vis[x]!=last){
                    if(cnt&1) a[i]*=last;
                    cnt=1;
                    last=vis[x];
                }
                else cnt++;
                x/=vis[x];
            }
            if(cnt&1) a[i]*=last;
        }
        for(int j=0;j<=k;j++){
            int p1=1,cnt=0;
            for(int i=1;i<=n;i++){
                mp[a[i]]++;
                if(mp[a[i]]>1) cnt++;
                while(cnt>j){
                    if(mp[a[p1]]>1) cnt--;
                    mp[a[p1]]--;
                    p1++;
                }
                l[j][i]=p1;
            }
            while(p1<=n) mp[a[p1]]=0,p1++;
        }
        //dp(i,j) 到第 i 个位置用了 j 次置换的最小区间数
        //dp[i][j]=min(dp[i][j],dp[left-1][j-x]+1);
        vector<vector<int> > dp(k+5,vector<int>(n+5,0x3f3f3f3f));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                for(int x=0;x<=j;x++){
                    int pos=l[x][i];
                    dp[j][i]=min(dp[j][i],dp[j-x][pos-1]+1);
                }
            }
        }
        int ans=0x3f3f3f3f;
        for(int i=0;i<=k;i++) ans=min(ans,dp[i][n]);
        printf("%d\n",ans);
    }
    return 0;
}
