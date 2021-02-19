//题意：现在有四顿饭，每顿饭必选一个并且最多一个菜，第 i 顿饭有 ai 个菜可选，第 i 到 i+1 顿饭之间存在 mi+1 种不可选的菜品组合，每个菜有一个价格，现在求四顿饭符合要求的最小价格

//思路：现在我们想用 DP 来解决问题，状态转移方程很明显，设 DP[i][j] 代表第 i 顿饭选了第 j 个菜，那么我们只要从上一顿饭中不冲突的菜里去选即可
//但是这样光转移一次就有 O(n1*n2) 的复杂度，n1=n2=1.5e5，很显然无法承受，那么我们怎么来处理呢？
//我们发现我们无非是从上一轮选了什么菜的状态里去选择一个可以转移的最小的状态，那么我们可以维护出大小优先级，然后再删除有冲突的选项，即可找到最小的
//这里我们可以用 set 来维护，对于第 i 轮的状态转移，我们把 i-1 轮得到的 DP 值依次插入 set，注意这里由于值的多重性，我们需要选择 multiset，然后对于第 i 轮第 j 道菜，我们只需从 set 里剔除与他冲突的 i-1 轮的菜即可
//然后 set 里最小的元素即使当前应该转移的状态。然后把那些剔除的元素复原，继续第 j+1 个菜
//set 反复插入删除带来的常数未免有些巨大，我们其实也可以用 ST 表之类的数据结构维护出区间 RMQ，然后我们排序那个第 i 轮第 j 道菜不能选择的第 j+1 道菜，然后避开这些点查询 RMQ

//set：
//1013ms

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

int n[5],a[5][maxn];
int m[5];
int dp[5][maxn];

vector<int> v[5][maxn];
multiset<int> s;

int main(){
    for(int i=1;i<=4;i++) cin>>n[i];
    for(int i=1;i<=4;i++){
        for(int j=1;j<=n[i];j++) scanf("%d",&a[i][j]);
    }
    int x,y;
    for(int i=2;i<=4;i++){
        cin>>m[i];
        for(int j=1;j<=m[i];j++){
            scanf("%d %d",&x,&y);
            v[i][y].push_back(x);
        }
    }
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n[1];i++) dp[1][i]=a[1][i];
    for(int i=2;i<=4;i++){
        for(int j=1;j<=n[i-1];j++) s.insert(dp[i-1][j]);
        for(int j=1;j<=n[i];j++){
            for(auto it:v[i][j]) s.erase(s.find(dp[i-1][it]));
            if(!s.empty()) dp[i][j]=*s.begin()+a[i][j];
            for(auto it:v[i][j]) s.insert(dp[i-1][it]);
        }
        s.clear(); 
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n[4];i++) ans=min(ans,dp[4][i]);
    printf("%d\n",ans==0x3f3f3f3f?-1:ans);
    return 0;
}

//数据结构（ST表）维护区间RMQ
//577ms

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=2e5+10;
 
int n[5],a[5][maxn];
int m[5];
int dp[5][maxn];
int f[25][maxn];
 
vector<int> v[5][maxn];
multiset<int> s;
 
void init_RMQ(int idx){
    for(int i=1;i<=n[idx];i++) f[0][i]=dp[idx][i];
    for(int j=1;(1<<j)<=n[idx];j++){
        for(int i=1;i+(1<<j)-1<=n[idx];i++){
            f[j][i]=min(f[j-1][i],f[j-1][i+(1<<j-1)]);
        }
    }
}
 
int query(int l,int r){
    if(l>r) return 0x3f3f3f3f;
    int d=log2(r-l+1);
    return min(f[d][l],f[d][r-(1<<d)+1]);
}
 
int main(){
    for(int i=1;i<=4;i++) cin>>n[i];
    for(int i=1;i<=4;i++){
        for(int j=1;j<=n[i];j++) scanf("%d",&a[i][j]);
    }
    int x,y;
    for(int i=2;i<=4;i++){
        cin>>m[i];
        for(int j=1;j<=m[i];j++){
            scanf("%d %d",&x,&y);
            v[i][y].push_back(x);
        }
    }
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n[1];i++) dp[1][i]=a[1][i];
    for(int i=2;i<=4;i++){
        init_RMQ(i-1);
        for(int j=1;j<=n[i];j++){
            sort(v[i][j].begin(),v[i][j].end());
            if(v[i][j].size()) dp[i][j]=min(query(1,v[i][j][0]-1)+a[i][j],query(v[i][j][v[i][j].size()-1]+1,n[i-1])+a[i][j]);
            else dp[i][j]=min(dp[i][j],query(1,n[i-1])+a[i][j]);
            for(int k=1;k<v[i][j].size();k++){
                int v1=v[i][j][k-1],v2=v[i][j][k];
                dp[i][j]=min(dp[i][j],query(v1+1,v2-1)+a[i][j]);
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n[4];i++) ans=min(ans,dp[4][i]);
    printf("%d\n",ans==0x3f3f3f3f?-1:ans);
    return 0;
}
