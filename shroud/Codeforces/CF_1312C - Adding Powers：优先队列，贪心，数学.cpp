//题意：给出一个长度为 n 的序列和一个整数 k，现在有一个全为 0 的序列 a，现在第 i 步（i 从 0 开始）可以作如下操作：要么选择 ai 并将它加 k^i，或者跳过本次操作

//思路：我们可以倒着执行题干过程，那么我们能加的最大的数 k^x 肯定小于等于目标序列中最大的值
//我们肯定是从当前的最大值开始减 k^x，证明如下：
//如果当前最大值 mx>= k^x，那么就可以减
//如果不减的话或者减到其他数的话，剩余的指数和 sigma i(1,x-1) k^i <= k^x ，那么显然当前当前最大值将无法再满足了（减成零了）
//用优先队列维护最大值，找到最大的指数下标，然后最后判断是否原序列所有元素都被减成零即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;

ll n,x,k;

priority_queue<ll> q;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        while(!q.empty()) q.pop();
        for(int i=1;i<=n;i++){
            scanf("%lld",&x);
            if(x) q.push(x);
        }
        if(q.empty()){
            puts("YES");
            continue;
        }
        x=q.top();
        ll cnt=0;
        while(pow(k,cnt)<=x) cnt++;
        cnt--;
        while(!q.empty()){
            x=q.top();
            q.pop();
            while(x<pow(k,cnt)&&cnt>=0) cnt--;
            x-=pow(k,cnt);
            cnt--;
            if(x) q.push(x);
            if(cnt<0) break;
        }
        if(!q.empty()) puts("NO");
        else puts("YES");
    }

    return 0;
}
