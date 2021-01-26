//题意：给出一个长度为 n 的 01 串，现在要求字符串中的相邻 '1' 的距离必须为 k，即 j-i=k，并且你可以操作翻转字符，问使得给出字符串满足要求的最小翻转次数

//思路：首先可以知道，如果对于一个合法的 01 串，他只会在 i i+k i+2k 等位置的可能会出现 '1'，其他位置只可能存在 '0'
//我们让字符串 ti 等于所有位置下标模 k 余数等于 i 的字符相连构成的字符串，我们按照上述题意，我们要保证一个 ti 可能存在 '1'，其他 tj 全部为 '0' 串
//并且由于相邻位置距离必须为 k，题意就变成了我们要把 ti 转换为字符串中 '1' 必须连续的字符串
//我们考虑 DP，定义 dp[i] 为使得字符串 s 前缀 si 全部合法并且 s[i] 位置等于 '1' 的最小代价，设 cnt(l,r) 代表区间 [l,r] 内 '1' 的个数
//那么状态转移方程为 dp[i]=min(dp[i-1]+cnt(0,i-1))+(s[i]=='1')，接着我们可以发现使这个字符串合法的最优解就是枚举 i 使得 res=min(res,dp[i]+cnt(i+1,s.size()-1)
//那么最后的答案显然就是枚举 i，删除除了 i 为余数的地方的 '1'，ans=min(ans,res+总共包含的 '1'- si 中包含的 '1')

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,k;
string s;

int solve(const string &s){
    int pre=0,res,tot;
    res=tot=count(s.begin(),s.end(),'1');
    vector<int> dp(s.size());
    for(int i=0;i<s.size();i++){
       int cur=(s[i]=='0');
       pre+=1-cur;
       if(i>0) dp[i]=min(dp[i-1]+cur,pre);
       res=min(res,dp[i]+tot-pre); 
    }  
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>s;
        int tot=count(s.begin(),s.end(),'1');
        vector<string> v(k);
        for(int i=0;i<n;i++) v[i%k]+=s[i];
        int ans=tot;
        for(int i=0;i<k;i++){
            int cur=count(v[i].begin(),v[i].end(),'1');
            ans=min(ans,solve(v[i])+tot-cur);
            //cout<<tot<<" "<<cur<<endl;
        }
        printf("%d\n",ans);
    }  
    return 0;
}
