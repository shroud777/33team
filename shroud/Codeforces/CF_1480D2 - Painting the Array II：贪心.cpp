//题意：给出一个长度为 n 的数组，现在要求按照下标顺序把他们依次放入两个数组 a 和 b，使得 seg(a)+seg(b) 最小
//定义 seg(x)：合并序列 x 中所有相邻等值元素后剩余元素个数

//思路：相比要最大值，其实分析的想法很像，我们一样可以根据 a b 两个序列的最后一个元素 x，y 去做一些分析
//首先如果 x=y=z，那么没啥好说的，怎么放都一样
//如果 z 等于 x，y 中的某一个元素，那么我们尽可能放到那个元素后面，使相邻相等元素尽可能多
//那么最后如果都不等，我们需要分析对后面的元素的影响，既然 z 对于答案的贡献必然要加 1，那么放哪儿主要看覆盖了 x 和 y 后的影响
//那么我们只需要找到 z 后面等于 x 和 y 的元素的位置，哪个远，我们就把 z 放在谁后面，因为这样中间增加的贡献可以少一点

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn];
int pos[maxn],nex[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos[i]=n+1;
    for(int i=n;i;i--){
        nex[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    int xpos=0,ypos=0,ans=0;
    nex[0]=n+2;
    for(int i=1;i<=n;i++){
        int z1=a[i],x=a[xpos],y=a[ypos];
        if(z1==x&&z1==y) continue;
        if(z1==x&&z1!=y){
            xpos=i;continue;
        }
        if(z1==y&&z1!=x){
            ypos=i;continue;
        }
        ans++;
        if(nex[xpos]<nex[ypos]) ypos=i;
        else xpos=i;
    }
    cout<<ans<<endl;
    return 0;
}
