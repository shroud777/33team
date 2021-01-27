//题意：现在有 m 件物品，分别题意为 wi（wi 均是 2 的幂次），并且可以进行若干次操作将 wi 平均拆解为 2 件 wi/2，问能否正好装满大小为 n 的背包，若可以求出达到要求的最小操作次数

//思路：由于每件物品是 2 的幂次，我们考虑到从数字的二进制数来考虑做法
//我们发现如果 Σwi >= n，那么我们肯定能正好装满背包，可以极端点想，我们把 m 件物品拆成 Σwi 个 1，一定能表示出 n
//接着我们要考虑拆分的最小次数，我们把 n 拆成二进制数，那么如果从左往右第 x 位为 1，说明我们需要 2^(x-1) 大小的物品去填充它
//并且我们考虑到：从二进制数来看，两个相同位上都有 1，那么就可以向高位进 1，进位相等于同时放入背包是不需要代价的，而拆分是需要代价的
//那么我们就按照上述贪心策略，从低位到高位来判断，如果当前 n 的二进制位上需要 1，那么我们就当前位上消耗 1，如果当前位没有多余的 1，说明我们需要从高位拆解。然后我们用当前位多余的数字向高位除二进位即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
 
ll n,m,a[maxn];
int cnt[105];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int x;
        ll tot=0;
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=m;i++){
            scanf("%d",&x);
            cnt[(int)log2(x)]++;
            tot+=x;
        }
        if(tot<n){
            puts("-1");
            continue;
        }
        int ans=0,f=0,fcnt=0;
        for(int i=0;i<=31;i++){
           //cout<<i<<" "<<cnt[i]<<" "<<f<<" "<<fcnt<<endl;
            if(fcnt){
                if(cnt[i]) cnt[i]--,ans+=i-f,fcnt=0;
            }
            if(i) cnt[i]+=(cnt[i-1]+(fcnt>0?1:0))/2;
            //cout<<i<<" "<<cnt[i]<<" "<<f<<" "<<fcnt<<endl;
            if(n&(1<<i)){
                if(!cnt[i]){
                    if(!fcnt) f=i;
                    fcnt++;
                }
                else cnt[i]--;   
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
