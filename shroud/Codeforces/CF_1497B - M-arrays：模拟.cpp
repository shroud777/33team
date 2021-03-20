//题意：给出一个长度为 n 的序列，现在要求将原序列按任意方式拆分重组为若干序列，使得所有新序列相邻两个元素的和为 m

//思路：显然我们可以先对原序列取模，接着可以发现，对于一个数 x(x!=0)，他的相邻位置只能使 m-x
//所以我们可以发现首先对于序列取模后为零的元素，他们可以互相组成一个新序列，其他所有 (x,m-x) 对，他们要组成一个新序列的话数量差值最大为 1
//x 和 m-x 剩下来的元素只能单个成序列，那么答案就是 1+max(0,abs(cnt[x],cnt[m-x])-1)
//同时要注意，当 x==m-x 时，只需要一个序列即可安排

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e5+10;

int n,m;
int cnt[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=0;i<=m;i++) cnt[i]=0;
        int x;
        for(int i=1;i<=n;i++) scanf("%d",&x),cnt[x%m]++;
        int ans=0;
        if(cnt[0]) ans++;
        for(int i=1;i<m;i++){
            if(i>m-i) break;
            if(i==m-i&&cnt[i]) ans++;
            else if(cnt[i]||cnt[m-i]){
                ans+=1+max(0,abs(cnt[i]-cnt[m-i])-1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
