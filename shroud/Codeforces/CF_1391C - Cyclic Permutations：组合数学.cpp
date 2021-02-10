//题意：在一个全排列中，根据以下规则建图：
//对于 1<=i<=n，找到下标最大的 j(1<=j<i)并且 pj>pi，从点 i 到点 j 连一条无向边
//对于 1<=i<=n，找到下标最小的 j(i<j<=n)并且 pj>pi，从点 i 到点 j 连一条无向边
//现在定义 p 是一个循环如果满足：存在 v1,v2...v3(k>=3)，只有 vi-vi+1 和 v1-vk 存在一条边，其他点之间不存在边

//思路：首先要找出循环的特点，如果存在一个位置 i 满足 ai>ai+1 && ai>ai-1，那么肯定是循环，因为三个点都会相连，满足要求
//那么我们从中得到启发，根据正难则反原则，我们可以他的相反情况，即不存在上述特点的情况，那么我们只要将根据降序然后依次把数放在当前序列的左侧或者右侧即可，第一个数已经放好，所以 n-1 个数
//一共 2^(n-1) 种情况

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e6+10;
const int p=1e9+7;

ll fac[maxn];

ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=a*res%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}

void init(){
    fac[0]=1;
    for(int i=1;i<=1e6;i++) fac[i]=fac[i-1]*i%p;
}

ll n;

int main(){
    init();
    cin>>n;
    cout<<(fac[n]-qpow(2,n-1)+p)%p<<endl;
    return 0;
}
