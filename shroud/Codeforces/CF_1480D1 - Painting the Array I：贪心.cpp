//题意：给出一个长度为 n 的数组，现在要求按照下标顺序把他们依次放入两个数组 a 和 b，使得 seg(a)+seg(b) 最大
//定义 seg(x)：合并序列 x 中所有相邻等值元素后剩余元素个数

//思路：这道题可以贪心的做，我们设 a 序列的最后一个元素为 x，b 序列的最后一个为 y，我们按照顺序放元素的，设当前元素为 z
//如果 z 和 x，y 都相等的话，那么我们怎么放都一样，并且不会增加贡献
//如果 z 只和其中某一个元素相等的话，我们必然使放再另一个最后一位元素不相等的序列后面，这样贡献加一
//那么如果 z 和 x，y 都不相等呢？应该放再哪儿呢？这里我们要考虑对后面的影响，我们设 z' 为 z 后面一位元素，那么如果 z 和 x 相等，我们显然要放在 x 后面，为了阻断 x 和 z' 相连，其他同理

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int x=-1,y=-1,ans=0;
    for(int i=1;i<=n;i++){
        int z1=a[i],z2=a[i+1];
        if(z1==x&&z1==y) continue;
        ans++;
        if(z1==x) y=z1;
        else if(z1==y) x=z1;
        else{
            if(z2==x) x=z1;
            else y=z1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
