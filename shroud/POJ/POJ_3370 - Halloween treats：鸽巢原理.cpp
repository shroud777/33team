//题意：有 c 个孩子，n 个邻居，（n>=c）第 i 个邻居给 ai 个糖果，现在问能否从若干个邻居手中拿去糖果使得糖果可以平均分配给 c 个孩子？

//思路：首先根据鸽巢原理，对于一个 a1,a2...am 序列，必然存在连续的子序列，满足 Σaj % m = 0
//那么由于 n>=c，这里必然存在连续子序列满足要求，找到这样的子序列即可

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int maxn=1e5+10;

int n,c,a[maxn],last[maxn];
ll s[maxn];

int main(){
    while(scanf("%d %d",&c,&n)!=EOF){
        if(n==0&&c==0) break;
        for(int i=0;i<=c;i++) last[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
        int l,r;
        for(int i=1;i<=n;i++){
            s[i]%=c;
            if(s[i]==0){
                l=1,r=i;break;
            }
            if(last[s[i]]){
                l=last[s[i]]+1,r=i;break;
            }
            last[s[i]]=i;
        }
        for(int i=l;i<=r;i++) printf("%d%c",i,i==r?'\n':' ');
    }
    return 0;
}
