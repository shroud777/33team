//题意：现在一共有 n 个下标 1-n 号的问题，分别按 k1,k2,k3 个掌握在 A，B，C 的手中，一个人可以将他的问题给别人，现在要求若干次操作后按照 A B C 三个人（每个人自己的问题编号视为已经递增）的顺序链接依旧递增

//思路：有三种做法：
//首先说明一下：最后三个人拿的问题一定是 [1,x][x+1,y][y+1,z] 这样的
//1.思维+推导：按照题意我们最开始可以想到，如果我们枚举一个人拿了多少个，那么他需要送出多少个问题和得到多少个问题这个答案是固定的，然后只需要讨论剩余两个人怎么办即可
//这个时候我想到了只能 O(n^2) 枚举两个人的情况，但是事实并非如此
//我们首先设前两个拿到了 i 个问题，那么 i 个问题的序号都是 [1,i] 的，那么我们先预处理出 s1,s2,s3，分别代表第 i 个人已经拿到多少个小于等于 x 的问题
//我们接着设第一个人拿了 j 个问题，可以得出三个人拿问题的情况是：[1,j][j+1,i][i+1,n]
//根据我们的前缀和，我们 (i,j) 对应的答案就是 s3[i]+s1[n]-s1[j]+s2[j]+s2[n]-s2[i]，整理得到 s3[i]+s1[n]+s2[n]-s2[i]+s2[j]-s1[j]，由于 j 的取值是 [0,i]，这个取值的集合是随着 i 增大的，那我们不需要双重循环，只要用一个变量记录即可
//2.LIS+线段树/树状数组：如果我们把三段序列分别排序然后链接起来，可以发现最后的答案就是 n-|lis|，因为那些 lis 以外的数字只能花费一次去移动到正确的位置
//并且这里 LIS 要用 线段树/树状数组/二分 来优化
//3.DP：
//状态定义：dp[i][j] 第 i 个问题交给第 j 个人
//状态转移方程：dp[i][j]=min(dp[i-1][k]+(a[i]!=j))(k<=j)

//1：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int x,y,z,a1[maxn],a2[maxn],a3[maxn];
int s1[maxn],s2[maxn],s3[maxn];

int main(){
    cin>>x>>y>>z;
    int n=x+y+z,a;
    for(int i=1;i<=x;i++) scanf("%d",&a),s1[a]++;
    for(int i=1;i<=y;i++) scanf("%d",&a),s2[a]++;
    for(int i=1;i<=z;i++) scanf("%d",&a),s3[a]++;
    for(int i=1;i<=n;i++){
        s1[i]+=s1[i-1];
        s2[i]+=s2[i-1];
        s3[i]+=s3[i-1];
    }
    int mi=0x3f3f3f3f,ans=0x3f3f3f3f;
    for(int i=0;i<=n;i++){
        mi=min(s2[i]-s1[i],mi);
        ans=min(ans,s3[i]+s1[n]+s2[n]-s2[i]+mi);
    }
    cout<<ans<<endl;
    return 0;
}

//2.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,x,y,z,a[maxn],dp[maxn];
int mx[maxn];

inline void update(int x,int k){
    while(x<=n){
        mx[x]=max(mx[x],k);
        x+=x&(-x);
    }
}

inline int query(int x){
    int ans=0;
    while(x){
        ans=max(ans,mx[x]);
        x-=x&(-x);
    }
    return ans;
}

int main(){
    cin>>x>>y>>z;
    for(int i=1;i<=x;i++) scanf("%d",&a[++n]);
    for(int i=1;i<=y;i++) scanf("%d",&a[++n]);
    for(int i=1;i<=z;i++) scanf("%d",&a[++n]);
    sort(a+1,a+x+1);
    sort(a+x+1,a+x+y+1);
    sort(a+x+y+1,a+x+y+z+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        dp[i]=query(a[i]-1)+1;
        update(a[i],dp[i]);
        ans=max(ans,dp[i]);
    }
    printf("%d\n",n-ans);
    return 0;
}

//3.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

//dp[i][j] 第 i 个问题交给第 j 个人
//dp[i][j]=min(dp[i-1][k]+(a[i]!=j))(k<=j)

int x,y,z,n,a[maxn],dp[maxn][5];

int main(){
    cin>>x>>y>>z;
    n=x+y+z;
    int k;
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        if(i<=x) a[k]=1;
        else if(i<=x+y) a[k]=2;
        else a[k]=3;
    }
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=3;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            for(k=1;k<=j;k++) dp[i][j]=min(dp[i][j],dp[i-1][k]+(a[i]!=j));
        }
    }
    cout<<min(dp[n][1],min(dp[n][2],dp[n][3]))<<endl;
    return 0;
}
