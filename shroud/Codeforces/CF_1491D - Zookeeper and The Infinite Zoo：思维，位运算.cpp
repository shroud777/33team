//题意：现在有无穷个点，对于每个点 u 对于所有满足 u&v=v 的点 u+v 存在一条单向边，现在有 q 组询问，问 u 能否到达 v 点

//思路：首先只有 u<=v 这种情况，才可能存在单向边。根据题意，对于点 u，我们可以先把它拆成二进制，然后对于当前 u 中的二进制数中的 1，我们可以选择将其单独取出作为 v，然后连接 u->u+v
//我们按照这个思路把 u，v 按照二进制位来拆分，然后从低位到高位累加，那么如果存在 vi>ui 的位置，说明 ui 累加也无法得到 vi 这个位置数量的前缀 1，说明不存在解

#include<iostream>

using namespace std;

const int maxn=5e5+10;

typedef long long ll;

int q,u,v;
int a[35],b[35];

int main(){
    cin>>q;
    while(q--){
        cin>>u>>v;
        if(u>v){
            puts("NO");continue;
        }
        for(int i=0;i<=30;i++){
            a[i]=u>>i&1;
            b[i]=v>>i&1;
        }
        for(int i=1;i<=30;i++) a[i]+=a[i-1],b[i]+=b[i-1];
        bool f=1;
        for(int i=0;i<=30;i++){
            if(a[i]<b[i]){
                f=0;break;
            }
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
