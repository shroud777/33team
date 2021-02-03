//题意：给定一个n*m的矩阵，矩阵元素由X和O构成，请求出其中最大的由X构成的蝴蝶形状。
//由X构成的蝴蝶形状的定义如下：
//存在一个中心点，并且其往左上、左下、右上、右下四个方向扩展相同的长度（扩展的长度上都是X)，且左上顶点与左下顶点、右上顶点与右下顶点之间的格子全由X填充。我们不在意在蝴蝶形状内部是X还是O

//思路：蝴蝶其实就是一个奇数大小的矩阵，并且对角线和边都由 X 组成，现在我们要这个蝴蝶形状尽可能大，我们想想如果考虑枚举中心点，复杂度显然 O(n^3) 不止
//现在考虑枚举左上角，那么我们能达到的最大的蝴蝶形状就是左上角往下连续 X 的最大值和往右下角连续 X 的最大值两者的最小值，然后我们可以根据这个距离枚举出右上角，然后判断右上角是否满足条件即可
//这条的难点不在于状态转移方程，而是在于定义状态

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e3+10;
const int p=3600;

int n,m,dp1[maxn][maxn],dp2[maxn][maxn],dp3[maxn][maxn];
char s[maxn][maxn];

inline bool check(int x,int y){
    if(x<1||x>n||y<1||y>m) return false;
    return true;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=n;i;i--){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='X'){
                dp1[i][j]=dp1[i+1][j]+1;
                dp2[i][j]=dp2[i+1][j+1]+1;
                dp3[i][j]=dp3[i+1][j-1]+1;
            }
            else dp1[i][j]=0,dp2[i][j]=0,dp3[i][j]=0;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int d=min(dp1[i][j],dp2[i][j]);
            if(d%2==0) d--; 
            for(int k=d;k>ans;k-=2){
                if(dp1[i][j+k-1]>=k&&dp3[i][j+k-1]>=k){
                    ans=k;break;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
