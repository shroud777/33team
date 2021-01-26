//题意：给出一个长度为 n 的区间，其中特殊元素定义为某一个序列中的元素和某一区间 [l,r](1<=l<r<=n) 的区间和相同，统计特殊元素的个数（序列中可能存在多个相同元素，统计时一起累加）
//1<=n<=8000 并且 1<=ai<=8000

//思路：O(n^2) 做法可以，并且由于规定了 ai 的大小，如果我们利用前缀和或者累加统计区间和，当和大于 n 时就可以停止
//并且如果使用 map 的话由于 O(n^2) 的插入复杂度过高，我们尽量选择数组，并限制前缀和大小
//还可以选择尺取，遍历数组元素，然后判断能否尺取得到这个元素即可

//方法1：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

int n,a[maxn],vis[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],vis[i]=0;
        for(int i=1;i<=n;i++){
            ll res=a[i];
            for(int j=i+1;j<=n;j++){
                res+=a[j];
                if(res>n) break;
                vis[res]=1;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(vis[a[i]]) cnt++;
        }
        cout<<cnt<<endl;
    }
}

//方法2（尺取）：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=8e3+10;

int n,a[maxn],cnt[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){ 
        cin>>n;
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
        int ans=0;
        for(int i=1;i<=8000;i++){
            if(!cnt[i]) continue;
            int p1=1,p2=2,res=a[1];
            bool f=0;
            while(p2<=n){
                res+=a[p2];
                if(res==i){
                    f=1;break;
                }
                if(res>i){
                    while(p2-p1>=2){
                        res-=a[p1];
                        p1++;
                        if(res==i){
                            f=1;break;
                        }
                        if(res<i) break;
                    }
                }
                if(f) break;
                p2++;
            }
            if(f) ans+=cnt[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}

