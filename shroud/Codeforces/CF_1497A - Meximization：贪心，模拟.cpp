//题意：给出一个长度为 n 的序列 a，要求重新排列序列使得新序列所有前缀的 MEX 的和最大

//思路：首先可以想到，根据前缀的性质，我们想要 MEX 尽量大，我们应该使序列 a 从小开始排列，并且已经在前缀出现过的数不会影响 MEX
//所以我们要让所有出现的数先按升序出现一次，然后剩余的元素随意排列即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e5+10;

int n,cnt[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        int x;
        for(int i=1;i<=n;i++) scanf("%d",&x),cnt[x]++;
        for(int i=0;i<=100;i++){
            if(cnt[i]) printf("%d ",i),cnt[i]--;
        }
        for(int i=0;i<=100;i++){
            for(int j=1;j<=cnt[i];j++) printf("%d ",i);
            cnt[i]=0;
        }
        puts("");
    }
    return 0;
}
