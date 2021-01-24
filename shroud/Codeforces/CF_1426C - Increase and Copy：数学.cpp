//题意：有一个初始长度为 1 包含元素 a1=1 的序列，现在可以作如下两种操作：
//1.将序列中某个元素的值加 1
//2.复制序列中某个元素增加到序列尾部
//问现在最少操作多少次使得序列和大于等于 n

//思路：首先要明确，我们肯定是第一个元素操作若干次，最后再用若干次复制它使序列和大于等于 n
//因为就贡献来讲，我们集中给一个元素增加值，然后复制，比分散几个元素增加值复制收益肯定要大，然后增加每次贡献只能 +1，而复制取决于之前的增加次数
//所以我们可以得出，最后的结果应该使 (1+增加次数)*(复制次数+1)
//那么我们知道要使满足 x*y=n 的 x+y 最小，答案就是 x 和 y 越接近的时候
//我们类比这种思想，取 s=sqrt(n)，那么如果 n 是个完全平方数，那么我们肯定只需要 (s-1)+(s-1) 次就可以了
//然后如果有浮点数，我们考虑 s*(s+1) 是否大于等于 n，答案为 s+s-1
//否则我们只能用 (s+1)*(s+1) 来代替了，答案是 s+s

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,x,vis[maxn];


int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        int res=(sqrt(n));
        if(res*res>=n) cout<<res*2-2<<endl;
        else if((res+1)*res>=n) cout<<res*2-1<<endl;
        else cout<<res*2<<endl;
    }
    return 0;
}
