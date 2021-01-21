//题意：给出一个数 d，要求输出一个数 x，满足：
//x 至少有 4 个约数
//x 的每个相邻约数之间不能差小于 d
//x 尽可能小

//思路：首先我们可以想四个约数，其中 1 和 x 已经占据了两个，那么我们可以考虑剩下的约数怎么去安排
//首先我们考虑只满足四个约数的情况，那就是 1 p p^2 p^3 or 1 p q pq（其中 p 和 q 都是质数，可以避免存在其他因子导致相邻约数的差值小于 d）
//我们显然就可以去构造上述情况，并且尽可能小，我们从这一点出发，那么第二个约数 p 一定是大于等于 1+d 的最小质数（p>=d+1）
//q>=d+p>=d+1+d=2*d+1;
//p^2>=(1+d)^2=d^2+2*d+1>=2*d+1
//那么我们显然只要找到那两个符合的质数即可
//方法1：我们可以线性筛预处理出质数并且放进一个数组进行二分 O(n(/nloglogn)+Tlogn)
//方法2：我们向上枚举差大于等于 d 的数并判断是否是质数即可 O(T*tag*sqrt(n)) tag 即为相邻质数的差

//方法1：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int leastfac[maxn];

vector<int> p;
int d;

void sieve(int N){
    for(int i=2;i<=N;i++){
        if(!leastfac[i]){
            leastfac[i]=i;
            p.push_back(i);
        }
        for(int j=0;j<p.size()&&p[j]<=leastfac[i]&&i*p[j]<=N;j++){
            leastfac[i*p[j]]=p[j];
        }
    }
}

int main(){
    sieve(20055);
    int t;
    cin>>t;
    while(t--){
        cin>>d;
        int p1=*lower_bound(p.begin(),p.end(),1+d);
        int p2=*lower_bound(p.begin(),p.end(),p1+d);
        cout<<1ll*p1*p2<<endl;
    }
    return 0;
}

//方法2：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int leastfac[maxn];

vector<int> p;
int d;

void sieve(int N){
    for(int i=2;i<=N;i++){
        if(!leastfac[i]){
            leastfac[i]=i;
            p.push_back(i);
        }
        for(int j=0;j<p.size()&&p[j]<=leastfac[i]&&i*p[j]<=N;j++){
            leastfac[i*p[j]]=p[j];
        }
    }
}

int main(){
    sieve(20055);
    int t;
    cin>>t;
    while(t--){
        cin>>d;
        int p1=*lower_bound(p.begin(),p.end(),1+d);
        int p2=*lower_bound(p.begin(),p.end(),p1+d);
        cout<<1ll*p1*p2<<endl;
    }
    return 0;
}
