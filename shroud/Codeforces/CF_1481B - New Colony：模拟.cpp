//题意：现在有 n 座高度分别为 hi 的山，现在从第一座山开始扔小球，如果对于当前小球处在的位置 hi>=hi+1，小球会行进到下一座山，否则小球停留，hi=hi+1，然后又从第一座山开始扔。
//现在一共有 k 个小球，问第 k 个小球会停留在哪个位置或者滚过第 n 座山消失不见？

//思路：模拟即可，注意当你遇到 hi<hi+1 时不可立即将 hi 变为 hi+1，因为当你 hi 增加了一点，小球可能就无法直接从 hi-1 过来，所以要一个一个球模拟

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,k;
int h[105];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>h[i];
        int ans=0;
        while(k){
            bool f=1;
            for(int i=1;i<n;i++){
                if(h[i]<h[i+1]){
                    f=0;
                    h[i]++,k--,ans=i;break;
                }
            }
            if(f){
                ans=-1;break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
