//题意：现在定义特殊序列：序列中某个元素出现次数大于别的元素出现的次数的序列，现在给出一个长度为 n 的序列，找出最短的特殊序列

//思路：我们可以从左往右遍历，只要某个元素出现了两次，然后再这区间中其他元素只出现了一次，那么他就是特殊序列，所以我们只要找最小的相邻元素距离即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;

int n,a[maxn],vis[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        int ans=0x3f3f3f3f;
        cin>>n;
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            if(!vis[a[i]]) vis[a[i]]=i;
            else{
                ans=min(ans,i-vis[a[i]]+1);
                vis[a[i]]=i;
            }
        }
        if(ans==0x3f3f3f3f) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}
