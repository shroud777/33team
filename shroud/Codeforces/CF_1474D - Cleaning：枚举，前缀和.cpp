//题意：有 n 堆石子，第 i 堆中共有 pi 个石子，现在要清理这些石子，可以选择两堆剩余石子数不为零的下标相邻的石子，并各自减去 1 个石子，并且现在可以作至多一次交换相邻位置的两堆石子个数
//问是否可以使得所有石子都按照规则被清除？

//思路：先从简单的来分析，如果没有交换操作，我们只需要线性的检验即可
//并且由于最左或者最右只能选择和他相邻的一侧的石子一起消去，所有我们可以线性扫描，对于 a[2]，我们通过 a[1] 消耗，得到 a[2]=a[2]-a[1]，后面的以此类推
//如果过程中出现 a[i-1]>a[i] 或者最终剩下的一堆石子 a[n]>0 的情况，说明无法清理
//接下来考虑交换，由于至多交换一次，我们可以考虑枚举交换的位置，那么我们每次交换后还需要 O(n) 的时间去检查，对于 2e5 的数据来说显然 O(n^2) 的时间复杂度不够
//我们可以发现，每次枚举其实只需要看看交换石子那两个位置和他们的前后半段即可，并且由于题目形式，我们可以参考前面检测合法性的方法，只需要维护出前后缀和即可
//接着我们就只要判断 {p[i-1],a[i+1],a[i],s[i+2]} 这个序列是否合法即可
//总结一下就是把两两消除这一个过程在思维中转化为线性的前缀累加过程，可以具有方向性

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

int n;
ll p[maxn],s[maxn];

bool check(vector<ll> v){
    int sz=v.size();
    for(int i=1;i<sz;i++){
        v[i]-=v[i-1];
        if(v[i]<0) return false;
    }
    if(v[sz-1]==0) return true;
    return false;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        if(check(a)){
            puts("YES");
            continue;
        }
        swap(a[0],a[1]);
        if(check(a)){
            puts("YES");
            continue;
        }
        swap(a[0],a[1]);
        swap(a[n-1],a[n-2]);
        if(check(a)){
            puts("YES");
            continue;
        }
        swap(a[n-1],a[n-2]);

        vector<ll> b=a;
        p[0]=b[0];
        for(int i=1;i<n;i++){
            if(p[i-1]==-1||b[i-1]>b[i]) p[i]=-1;
            else{
                b[i]-=b[i-1];
                p[i]=b[i];
            }
        }
        b=a;
        s[n-1]=b[n-1];
        for(int i=n-2;i>=0;i--){
            if(s[i+1]==-1||b[i+1]>b[i]) s[i]=-1;
            else{
                b[i]-=b[i+1];
                s[i]=b[i];
            }
        }
        bool f=0;
        for(int i=1;i<n-2;i++){
            if(p[i-1]==-1||s[i+2]==-1) continue;
            vector<ll> res={p[i-1],a[i+1],a[i],s[i+2]};
            if(check(res)){
                f=1;break;
            }
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
