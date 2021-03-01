//题意：现在有一 n 行(1-n)，1e6+2 列(0-1e6+1) 的节点网格图，每行都存在一个障碍 ai(1<=ai<=1e6)，现在要从 (1,0) 出发到 (n,1e6+1)
//将障碍移动至 (i+1,j) (i-1,j) 位置需要 v 的代价，移动至 (i,j+1) (i,j-1) 位置需要 u 的代价，现在问使能够成功到达所需的最小代价

//思路：我们考虑什么时候可以通行，即任意 |ai-ai+1|>=2 时即可，那么这种情况下是不需要花费的
//那么我们考虑剩余的两种情况，即差为 1 和 0，差为 1 时，我们可以考虑左右移，也可以考虑向上移，即 min(u,v)
//差为 0 时，我们就必须要左右移动一次，然后就和上一种情况一样了 v+min(u,v)

#include<iostream>

using namespace std;

const int maxn=1e5+10;

int a[maxn];
int n,m,k;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        int mx=0;
        for(int i=2;i<=n;i++){
            mx=max(mx,abs(a[i]-a[i-1]));
        }
        if(mx>1) puts("0");
        else if(mx==1) cout<<min(m,k)<<endl;
        else cout<<min(m+k,2*k)<<endl;
    }
    return 0;
}
