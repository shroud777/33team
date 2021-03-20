//题意：给出一个长度为 n 的序列，要求划分为尽可能少的连续区间，满足每个新区间内都不存在两个数使得 ai*aj 是完全平方数

//思路：显然类似这种看似 O(n^2) 转线性的问题，我们一般都按照顺序遍历过去，用一个集合储存我们需要保存的东西，然后线性匹配即可
//这道题显然也可以这样做，对于两个乘积为完全平方的数：显然就是乘积所有因子的个数都是偶数，那么对于原来的两个数，他们那些个数为偶数的因子我们可以直接忽略
//也就是把原数看成 mask(x)=p1^(c1%2)*p2^(c2%2).....pk^(ck%2) 的形式，并且由于全是质数的形式，当 mask(x)=mask(y) 时，x 必然能和 y 组成完全平方数
//那我们只要遍历并得到每个数的 mask 并储存，每次 mask(x) 与之前的相同，就清空 mask 储存的数组并且开一个新的区间序列即可，并把 mask(x) 记录进去
//每个数 1e7，我们可以选择欧拉筛找出每个数最小的质因子，然后再分解质因数比较好

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e7+10;

int n,k;
int last[maxn],vis[maxn],pri[maxn],tot=0;

void sieve(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]) pri[++tot]=i,vis[i]=i;
        for(int j=1;j<=tot;j++){
            if(pri[j]>vis[i]||pri[j]*i>n) break;
            vis[pri[j]*i]=pri[j];
        }
    }
}

inline int get(int x){
    for(int i=1;i<=tot;i++){
        int p=pri[i]*pri[i];
        if(x<p) return x;
        while(x%p==0) x/=p;
    }
    return x;
}


int main(){
    sieve(sqrt(1e7)+10);
    int t;
    cin>>t;
    while(t--){
        map<int,int> last;
        int ans=0;
        scanf("%d %d",&n,&k);
        int x,l=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            int temp=get(x);
            if(last[temp]>=l){
                l=i;ans++;
            }
            last[temp]=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
