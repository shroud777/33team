//题意：有一个长度为 n 的序列，其中每个元素为 0 或 1，现在有 q 组查询，每组查询支持如下两种操作：
//1 x：将 ax 的值变为 1-ax
//2 k：输出序列第 k 大的值

//思路：序列只存在 1 和 0，我们可以记录序列的和，就代表了有多少个 1，那么对于 1 号操作我们只需要改变原序列和 1 的个数，然后对于 2 号操作只需要判断 1 的个数是否大于等于 k 即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

string s;

int n,q,a[maxn];

int main(){
    cin>>n>>q;
    int cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1) cnt++;
    }
    int op,x;
    while(q--){
        scanf("%d %d",&op,&x);
        if(op==1){
            if(a[x]==0) cnt++;
            else cnt--;
            a[x]^=1;
        }
        else printf("%d\n",cnt>=x?1:0);
    }
    return 0;
}
