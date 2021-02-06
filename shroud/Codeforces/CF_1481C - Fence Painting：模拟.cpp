//题意：现在有 n 个栅栏颜色分别为 ai，现在要将每个栅栏涂成 bi 颜色，现在有 m 个油漆工，他们将会按照出场顺序依次对某个栅栏涂成 ci 种颜色，只能并且必须涂一个栅栏，问是否可行与涂色方案

//思路：首先我们可以发现对于所有 ai!=bi 的栅栏都是需要重新涂色的，我们可以用一个 vector 来储存每个颜色被哪几个栅栏所需要，最后只要所有的 vector 都为空就满足了要求
//然后对于第 m 个颜色，如果没有出现在 b 里面，说明不存在解，因为最后一个涂的颜色无法用其他颜色覆盖。相反我们可以以这个颜色作为中介，使其他不存在 b 里的颜色都涂在这个上面，然后最后用 cm 覆盖即可
//但是这里存在一个问题，就是我们不知道第 cm 个颜色在第几格，由于那些被需要的 bi 颜色可能不够，如果 cm 的颜色中存在 bi!=ai 的话，我们应该优先选这些。否则就找出序列中 cm 的位置即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,m;
int a[maxn],b[maxn],c[maxn],ans[maxn];
vector<int> v[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        map<int,int> mp,cnt;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),v[i].clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            if(a[i]!=b[i]) v[b[i]].push_back(i);
            mp[b[i]]=i;
        }
        for(int i=1;i<=m;i++) scanf("%d",&c[i]);
        if(!mp[c[m]]){
            puts("NO");continue;
        }
        for(int i=1;i<=m;i++){
            int sz=v[c[i]].size();
            if(sz) ans[i]=v[c[i]][sz-1],v[c[i]].pop_back();
            else{
                if(mp[c[i]]) ans[i]=mp[c[i]];
                else ans[i]=-1;
            }
        }
        bool f=1;
        for(int i=1;i<=n;i++){
            if(!v[i].empty()){
                f=0;break;
            }
        }
        if(!f){
            puts("NO");continue;
        }
        puts("YES");
        for(int i=1;i<=m;i++) printf("%d%c",ans[i]==-1?ans[m]:ans[i],i==m?';\n':' ');
    }
    return 0;
}
