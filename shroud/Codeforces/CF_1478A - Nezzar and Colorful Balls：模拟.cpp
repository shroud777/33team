//题意：现在 n 个非递减的小球编号，现在要给他们上色，相同颜色的小球序号不能相同，问最多需要多少种颜色?

//思路：找出现最多的数的个数即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=2e5+10;
 
ll n,a[maxn];
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for(int i=1;i<=n;i++){
            int res=1;
            while(a[i]==a[i+1]&&i+1<=n) res++,i++;
            ans=max(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}
