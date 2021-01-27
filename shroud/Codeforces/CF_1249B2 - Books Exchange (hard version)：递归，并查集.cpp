//题意：给出一个长度为 n 的序列 pi，其中 pi 代表第 i 个小朋友将要给第 pi 个小朋友书，现在问对于每个小朋友，如果把书给第 pi 个小朋友，最少要经过多少个小朋友，书会回到自己手中？

//思路：递归做法：起点第 i 个小朋友，递归重点设置为当前小朋友于开始的第一个小朋友相同的时候，说明循环节结束了，设置数组记录第 i 个小朋友需要的最小步数，再循环节结束的时候返回值
//并查集做法：用并查集维护循环节，最后统计集合大小即可

//递归：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn],f[maxn];

int dfs(int st,int now,int cnt){
    if(st==now&&cnt) return f[now]=cnt;
    return f[now]=dfs(st,a[now],cnt+1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) f[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            if(!f[i]) dfs(i,i,0);
        }
        for(int i=1;i<=n;i++) printf("%d ",f[i]);
        printf("\n");
    }

    return 0;
}

//并查集

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
 
int n,fa[maxn],cnt[maxn];
 
inline int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) fa[i]=i,cnt[i]=0;
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            x=find(x);
            int y=find(i);
            if(x==y) continue;
            fa[x]=y;
        }
        for(int i=1;i<=n;i++) cnt[find(i)]++;
        for(int i=1;i<=n;i++) printf("%d%c",cnt[find(i)],i==n?'\n':' ');
    }
    return 0;
}
