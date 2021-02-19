//题意：现在给出一个长度为 n 的序列（n 是 3 的倍数），现在 cnti 代表 ai 对 3 取模后的结果，现在可以执行一次操作，对 ai 加 1，问使 cnt0=cnt1=cnt2 的最小次数

//思路：可以发现如果 cnti 多了，只能通过 +1，使多余部分像 cnti+1 转移，我们只需要模拟即可

#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
 
const int maxn=2e5+10;

int n,a[maxn];
int cnt[3];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],a[i]%=3;
        for(int i=0;i<3;i++) cnt[i]=count(a+1,a+n+1,i);
        int ans=0;
        for(int i=0;i<9;i++){
            if(cnt[i%3]>n/3){
                int res=cnt[i%3]-n/3;
                cnt[i%3]-=res;
                cnt[(i+1)%3]+=res;
                ans+=res;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
