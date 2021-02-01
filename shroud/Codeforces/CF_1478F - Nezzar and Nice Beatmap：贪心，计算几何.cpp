//题意：现在给出二维平面上的 n 个点，问是否存在一种排列顺序，使得排列中任意相邻的三个元素 ABC，满足 A->B 与 B->C 构成的角的度数小于 90 °？

//思路：任意选择一个点，我们接着只要选择距离它最远的点即可。因为三角形中次长的边对应的角肯定不可能是大于等于 90 °的角

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e3+10;

int n,x[maxn],y[maxn],vis[maxn];
ll d[maxn][maxn];

void f(int cur,int cnt){
    printf("%d ",cur);
    vis[cur]=1;
    if(cnt==n) return;
    int p=cur;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(d[cur][i]>d[cur][p]) p=i;
    }
    f(p,cnt+1);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x[i],&y[i]);
        for(int j=1;j<i;j++){
            d[i][j]=d[j][i]=1ll*(x[i]-x[j])*(x[i]-x[j])+1ll*(y[i]-y[j])*(y[i]-y[j]);
        }
    }
    f(1,1);
    return 0;
}
