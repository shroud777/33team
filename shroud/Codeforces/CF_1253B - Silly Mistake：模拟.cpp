//题意：现在给出一个序列代表若干编号的员工上下班的顺序，现在将该序列分为若干连续的子序列，一段子序列代表一天内的上下班情况
//在一天中：所有人必须在先上班的前提下才能下班，一天内最多上下班一次

//思路：按照题意思路，我们只需要简单的模拟即可，可以在当前上下班结束后立刻结束一天

#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

typedef long long ll;

int n,a[maxn];

map<int,int> vis,vis2;
vector<int> ans;

bool solve(){
    int res=0,cnt=0;
    int x;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x>0){
            if(vis[x]) return false;
            else{
                res++;
                cnt++;
                vis[x]++;
                vis2[x]++;
            }
        }
        else{
            x=-x;
            if(!vis2[x]) return false;
            vis2[x]--;
            res--;
            cnt++;
        }
        if(res==0){
            vis.clear();
            ans.push_back(cnt);
            cnt=0;
        }
    }
    if(res) return false;
    return true;
}

int main(){
    scanf("%d",&n);
    bool f=solve();
    if(!f) puts("-1");
    else {
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++) printf("%d%c",ans[i],i==ans[i]-1?'\n':' ');
    }
    return 0;
}
