//题意：现在有 n+1 个城市编号从 0 到 n，第 i 条路连接 i-1 个城市和 i 个城市，每条路会有一个同行的方向，并且所有 n 条路的同行方向会在从当前城市移动到相邻城市的过程中反向，问以每个城市为起点最多能经过的城市数量

//思路：首先要明确，如果我们能从城市 i 走到城市 j，那么必然能从城市 j 回到城市 i，并且只要能往一个方向走，那么我们能走到相邻两条路的方向重复的地方位置
//根据这个性质我们有很多种做法：
//1.对于每个城市，我们只需要判断相邻的路能不能走，不能走只能待在原地，否则可以走到相邻方向的道路，我们就可以把向左和向右的相邻道路放进一个数组，然后二分找到左边能走到的城市和右边的城市
//2.DP，这里 DP 也有很多种做法。这里我们可以定义 dp[2][i]，第一维为 1 代表可以通行的城市的数量，0 代表不可以通行的数量，并且这个状态定义是根据遍历的方向决定的
//比如我们从左到右遍历，那么 dp[1][i] 就代表第 i 个城市往左走可以走到的城市数量，显然根据题意 dp[0][i]=dp[1][i-1]+1 dp[1][i]=dp[0][i-1]+1，只需要正反统计两次即可
//3.可以把每个点复制两份，然后一条边 L 和 R 分别代表，i 城市的第 1 个点到 i+1 城市的第 2 个点和 i 城市的第 2 个点到 i+1 城市，然后根据图的联通度判断即可

//1:

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=3e5+10;

#define pb push_back

string s;
vector<int> L,R;

int main(){
    int t;
    cin>>t;
    while(t--){
        L.clear();
        R.clear();
        int n;
        string s;
        cin>>n>>s;
        vector<int> ::iterator it;
        for(int i=n-2;i>=0;i--){
            if(s[i]==s[i+1]) R.pb(-1*(i+1));
        }
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) L.pb(i+1);
        }
        int res;
        for(int i=0;i<=n;i++){
            res=1;
            if(s[i]=='R'&&i<n){
                it=upper_bound(L.begin(),L.end(),i+1);
                if(it==L.end()) res+=n-i;
                else res+=*it-i-1;
            }
            if(s[i-1]=='L'&&i>0){
                it=upper_bound(R.begin(),R.end(),-i);
                if(it==R.end()) res+=i;
                else res+=i-*it*(-1);
            }
            printf("%d%c",res,i==n?'\n':' ');
        }
    }
    return 0;
}

//2.


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,dp[2][maxn],ans[maxn];
string s;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>s;
        for(int i=0;i<=n;i++) dp[1][i]=dp[0][i]=ans[i]=0;

        for(int i=1;i<=n;i++){
            if(s[i-1]=='R') dp[0][i]=dp[1][i-1]+1;
            else dp[1][i]=dp[0][i-1]+1;
            ans[i]+=dp[1][i];
        }
        for(int i=0;i<=n;i++) dp[1][i]=dp[0][i]=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='R') dp[1][i]=dp[0][i+1]+1;
            else dp[0][i]=dp[1][i+1]+1;
            ans[i]+=dp[1][i];
        }
        for(int i=0;i<=n;i++) printf("%d%c",ans[i]+1,i==n?'\n':' ');
    }
    return 0;
}
