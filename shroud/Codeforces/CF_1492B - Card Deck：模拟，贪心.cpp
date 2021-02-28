//题意：现在有 n 张牌从上到下叠放，从底到顶部依次为 p1-pn，每张牌的权值为 1-n 之间不重复的整数，现在要求得到新的牌序，规则如下：
//选出顶部若干 k 张牌，这 k 张牌保持原来的顺序放到新的牌堆里，依次类推直到 n 张牌全部清除
//现在定义一堆牌的权值为 Σn^(n-i)*pi，输出使得新牌堆权值最大的摆放顺序

//思路：对于 n^(n-i) 这个权值定义，我们很容易想到 n^(n-1) > n^(n-2)+n^(n-3)+...+n^1+n^0
//那么显然 a>b c>d -> a*c>b*d，由于数字只有 1-n 且不重复，我们在牌堆里找当前剩余的最大值值，尽可能作为牌底，这样不管其他的怎么放，权值一定最大了，具体证明不太会，按照这个思路模拟即可

#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;

int n,a[maxn],vis[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),vis[i]=0;
        int mx=n;
        for(int i=n;i>=1;i--){
            if(a[i]==mx){
                int j=i;
                while(!vis[a[j]]&&j<=n) printf("%d ",a[j]),vis[a[j]]=1,j++; 
            }
            while(vis[mx]) mx--;
        }
        puts("");
    }
    return 0;
}
