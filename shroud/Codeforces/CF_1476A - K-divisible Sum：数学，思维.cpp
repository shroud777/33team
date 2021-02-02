//题意：现在由你来创造一个长度为 n 的都是正整数的序列，使得它的和是 k 的倍数，问序列中元素最大值最小是多少？

//思路：首先如果 k>=n，那么我们肯定是想平均分配 k 到 n，中，最大数显然就是 (k-1+n)/n
//那么如果 k<n，可以发现数组最小值为 n，可以全部加一变成 2*n，由于 n>k，所以在 [n,2n] 中一定会有 k 的倍数出现，当然我们还要特判下初始的 n 是否可以整除 k
//我们还可以用数学的方法来证明：我们设序列的和为 s=k*x，由于 s>=n -> x>=ceil[n/k]，然后我们得到 s 后，直接平均分配即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e3+10;

int n,k;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n<=k) cout<<(k-1+n)/n<<endl;
        else cout<<1+(n%k?1:0)<<endl;
    }
    return 0;
}
