//题意：给出一个长度为 n 的序列，其中序列中存在 -1，现在可以选择任意一个 k 来代替所有的 -1，使得序列相邻元素的差最小

//思路：考虑 k 代替 -1 的影响，无非是 -1 与周围相邻非 -1 元素的差的产生，那么就是与 -1 相邻的最大值与最小值的和的 1/2，并且还要考虑原数组的相邻元素的差的大小即可
//这题还可以三分，因为 k 的过大和过小都会让最大差值有变大的趋势，所有总体来说就是一个凹函数，我们可以三分找到峰值，误差控制在 1，因为有相同值时边界无法收束到 l==r

//模拟：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int cnt=0,mx=0,mi=1e9,ans=0;
        for(int i=1;i<=n;i++){
            if((i>1&&a[i-1]==-1)||(i<n&&a[i+1]==-1)){
                if(a[i]==-1) continue;
                mx=max(mx,a[i]);
                mi=min(mi,a[i]);
            }
        }
        int temp=(mx+mi)/2;
        for(int i=1;i<=n;i++){
            if(a[i]==-1) a[i]=temp;
            if(i-1) ans=max(ans,abs(a[i]-a[i-1]));
        }
        cout<<ans<<" "<<temp<<endl;
    }
    return 0;
}

//三分：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn],b[maxn];

int f(int x){
    int ans=0;
    for(int i=1;i<=n;i++) b[i]=(a[i]==-1?x:a[i]);
    for(int i=2;i<=n;i++) ans=max(ans,abs(b[i]-b[i-1]));
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int l=-1,r=1e9,lmid,rmid;
        while(l+1<r){
            lmid=(l+r)>>1;
            rmid=(lmid+r)>>1;
            int f1=f(lmid),f2=f(rmid);
            if(f1<f2) r=rmid;
            else l=lmid;
        }
        cout<<f(l)<<" "<<l<<endl;
    }
    return 0;
}
