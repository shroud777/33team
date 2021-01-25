//题意：A 可以出 a1 次石头，a2 次剪刀，a3 次布，B 可以出 b1 次石头，b2 次剪刀，b3 次布，问 A 最少获胜次数是多少，最多获胜次数为多少

//思路：最多次数，显然就是 a 尽可能多胜利即可，ans=min(a1,b2)+min(a2,b3)+min(a3,b1)
//对于最少次数，我们想要 A 尽可能多取获得平局和败局
//那么就是 a1-b1 a1-b3 a2-b2 a2-b1 a3-b3 a3-b2 这么多的策略
//要明确最后在去除平局败局后最后可能有两种情况，A B 的三种次数全部为 0，或者 A B 都剩一个非零的数 (a1,b2),(a2,b3),(a3,b2)} 一共四种剩余情况
//那么假设最后剩下的是 b2 和 a1，那么我们肯定希望 a2 和 a3 多和 b2 相消减，因为 b2 太多了其他 b1 b3 不够用
//所以第一种方法我们可以枚举上述六种策略的顺序，并且当前策略要取最多，一共 6!=720 种方法
//上述方法其实过于麻烦，因为我们最后就是无非四种情况，那么无疑这些剩下来的都是胜场，我们只要在这四种情况下取 max 即可
//还有一种方法 3，就是对于 n=1e9，a1+a2+a3=n，那么三个数中的最小值的取值范围是 (0,1e9/3)，那么我们可以用 O(1e9/3) 的时间去枚举出多少次
//比如最小的是 a1，我们可以枚举 a1->b1 的次数，那么接下来 a2 肯定全部放到剩余的 b1 里，然后 a2 剩余的放到 b2 里，以此类推

//方法2：

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;

int n,a[5],b[5];

int main(){
    cin>>n;
    for(int i=1;i<=3;i++) cin>>a[i];
    for(int i=1;i<=3;i++) cin>>b[i];
    cout<<max(0,max(b[2]-a[2]-a[3],max(b[3]-a[1]-a[3],b[1]-a[1]-a[2])))<<" ";
    cout<<min(a[1],b[2])+min(a[2],b[3])+min(a[3],b[1])<<endl;
    return 0;
}

//方法3：
//卡 O(1e9/3) 951ms 险过

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
 
int n;
int a[5],b[5],aa[5],bb[5];
 
int Min(int x,int y){
    return a[x]<a[y]?x:y;
}
 
int main(){
    scanf("%d",&n);
    for(int i=0;i<3;i++) cin>>a[i];
    for(int i=0;i<3;i++) cin>>b[i];
    int mi=n,mx=0;
    for(int i=0;i<3;i++){
        mx+=min(a[i],b[(i+1)%3]);
    }
    int pos=Min(0,Min(1,2));
    int len=a[pos];
    for(int i=0;i<=a[pos];i++){
        int res=0;
        for(int j=0;j<3;j++) aa[j]=a[j],bb[j]=b[j];
        if(i>bb[pos]) break;
        aa[pos]-=i,bb[pos]-=i,res+=i;
        int temp=min(bb[(pos+2)%3],aa[pos]);
        bb[(pos+2)%3]-=temp,res+=temp;
        temp=min(aa[(pos+2)%3],bb[(pos+2)%3]);
        aa[(pos+2)%3]-=temp,res+=temp;
        temp=min(aa[(pos+2)%3],bb[(pos+1)%3]);
        bb[(pos+1)%3]-=temp,res+=temp;
        temp=min(bb[(pos+1)%3],aa[(pos+1)%3]);
        aa[(pos+1)%3]-=temp,res+=temp;
        temp=min(aa[(pos+1)%3],bb[pos]);
        res+=temp;
        mi=min(mi,n-res);
    }
    cout<<mi<<" "<<mx<<endl;
    return 0;
}
