//题意：给出一个长度为 n 的序列，现在要求插入若干数，满足 max(a[i],a[i+1])/min(a[i+1],a[i])<=2 (1<=i<n)

//思路：数据比较小，可以直接模拟，不断让小的那个乘 2
//也可以直接 O(1) 求出，我们求出他们差的倍数，然后取  2  的对数并取整-1，并且要注意前后两个数相同就跳过

//模拟：

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=2e5+10;

int n,a[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for(int i=1;i<n;i++){
            int l=min(a[i],a[i+1]);
            int r=max(a[i],a[i+1]);
            for(int j=l;j<<1<r;j<<=1) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

//O(1)

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=2e5+10;

int n,a[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for(int i=1;i<n;i++){
            if(a[i]==a[i+1]) continue;
            ans+=ceil(log2(max(a[i],a[i+1])*1.0/min(a[i],a[i+1])))-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
