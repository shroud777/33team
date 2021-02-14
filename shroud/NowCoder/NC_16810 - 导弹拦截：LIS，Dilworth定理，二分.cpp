//题意：现在敌国发射导弹，高度分别为 hi，导弹拦截系统有一个缺陷，每次拦截的炮弹高度不能高于前一发的炮弹高度
//问这套系统最多能拦截多少导弹，并且最少要配备多少套这种导弹拦截系统才能拦截所有导弹

//思路：第一问显然就是最长不上升子序列，我们可以用二分或者数据结构优化DP来实现 O(nlogn) 得到长度
//第二问根据 Dilworth 定理，可划分最多反链个数等于最长链的长度，那我们只需要求最长上升子序列即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e6+10;

int n,a[maxn],dp[[maxn];

int main(){
    n=1;
    while(~scanf("%d",a+n)) n++;
    n--;
    int tot1=1;
    dp[tot1]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]<=dp[tot1]) dp[++tot1]=a[i];
        else *upper_bound(dp+1,dp+tot1+1,a[i],greater<int>())=a[i];
    }
    int tot2=1;
    dp[tot2]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]>dp[tot2]) dp[++tot2]=a[i];
        else *lower_bound(dp+1,dp+tot2+1,a[i])=a[i];
    }
    cout<<tot1<<endl<<tot2<<endl;
    return 0;
}
