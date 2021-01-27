//题意：现在定义 good num：代表一个可以用若干个不同的 3 的幂次组成的数，现在要求输出大于 n ( n<=1e4 )的最小的 good num

//思路：相比 hard version，这题的数据非常小，我们知道最大的 answer 可能取到 3^x > 1e4，那么对于 good num，我们无非就是看他存不存在，这里我们使用一种无脑的方法
//我们可以小于 3^x 的 3 的幂次为物品，跑一个值域 [wi,3^x] 的 01 背包，这样我们就可以知道所有的 good num，用数组保存即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn],f[maxn];
ll dp[maxn];

void init(){
    int cnt=0;
    vector<int> v;
    while(pow(3,cnt)<=2e4) v.push_back(pow(3,cnt)),cnt++;
    int mx=pow(3,cnt);
    dp[0]=1;
    for(int i=0;i<v.size();i++){
        for(int j=mx;j>=v[i];j--) dp[j]|=dp[j-v[i]];
    }
}

int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        while(!dp[n]){
            n++;
        }
        cout<<n<<endl;
    }
    return 0;
}
