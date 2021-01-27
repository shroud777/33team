//题意：现在定义 good num：代表一个可以用若干个不同的 3 的幂次组成的数，现在要求输出大于 n ( n<=1e18 )的最小的 good num

//思路：相比 eazy version，我们之前的背包做法显然不可行，我们要找到另一种更高效的方法。这里我们可以考虑贪心做法：
//有两种贪心做法，首先，这个 good num 无非是由若干个幂次组成的，那么我们可以先求出 Σ3^i >=n 的最小值，然后考虑从高到低去尝试这个数能否被 3^i 次减掉
//为什么要从高到低呢？因为还是这个道理 Σx^i <x^i+1，如果我们从小开始减的话，我们可能由于减掉了一些较小的数使得无法被更大的数减，但是事实上更大的数永远比这些小的数相加更大，所以我们要从高到低
//第二种做法，事实上题目要求用一个没有 2 的三进制数表示，那么我们可以对 n 的三进制数进行分析，如果本来就没有 2，那么就是 n 本身，否则的话，我们找到最高位的那个 2
//这里为什么要最高位呢？因为我们肯定是要加一个 3^x 次把这个 2 变成 0，那么所有低位肯定都只要变成 0 就可以了，然后这个 2+1 带来的进位会不停蔓延，直至遇到 0，他才能保证进位为 1，不影响后面的高位

//做法1：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

ll n;

vector<ll> v;

void init(){
    for(int i=0;i<=38;i++) v.push_back(pow(3,i));
}

int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        ll res=0,cur=0;
        while(res<n){
            res+=v[cur];
            cur++;
        }
        while(cur>=0){
            if(res-v[cur]>=n) res-=v[cur];
            cur--;
        }
        cout<<res<<endl;
    }
    return 0;
}

//做法2：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v;
        int pos=-1;
        ll ans=n;
        while(n){
            v.push_back(n%3);
            if(n%3==2) pos=v.size()-1;
            n/=3;
        }
        v.push_back(0);
        if(pos==-1){
            printf("%lld\n",ans);continue;
        }
        int p=find(v.begin()+pos,v.end(),0)-v.begin();
        for(int i=0;i<p;i++) v[i]=0;
        v[p]=1;
        ll res=0,base=1;
        for(int i=0;i<v.size();i++){
            res+=base*v[i];
            base*=3;
        }
        printf("%lld\n",res);
    }
    return 0;
}
