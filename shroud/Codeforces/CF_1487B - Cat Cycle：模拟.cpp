//题意：现在有 A，B 两只猫，有 n 个窝，A 习惯轮流在：n n-1...1 号 窝，B 习惯轮流在 1 2...n 号窝，每个小时换一个窝，如果两只猫在同一个窝，那么 B 会移动到下一个习惯的窝
//现在问 A 初始在 n，B 初始在 1，k 小时后，问第 B 只猫在哪儿

//思路：可以发现如果 n 是偶数，两只猫不会撞窝。否则 ceil[n/2] 会撞一次窝，每次撞窝 B 会移动一次，那么相当于 B 额外移动了 k/ceil[n/2] 个窝，所以加上 k 个取模即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,k;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int base=n/2;
        k--;
        cout<<(k+k/base*(n&1))%n+1<<endl;
    }
    return 0;
}
