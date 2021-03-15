//题意：给出长度为 n 的序列 a，b，现在问能执行至多一次操作 l r k(k>0)，代表对 [l,r] 这个连续区间加上 k 的值的条件下将序列 a 变成序列 b?

//思路：可以直接找出序列不同的左右端点，然后判断区间内差值是否大于 0 并相同。也可以求出 a b 的差值序列 d，然后在 d 的前后加上 0，判断序列不相等的位置是否小于等于 2 即可

#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

typedef long long ll;

int n,a[maxn],b[maxn],x;

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        vector<int> v;
        v.push_back(0);
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            v.push_back(x-a[i]);
        }
        v.push_back(0);
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<0) cnt=3;
        }
        for(int i=1;i<v.size();i++){
            if(v[i]!=v[i-1]) cnt++;
        }
        if(cnt<=2) puts("YES");
        else puts("NO");
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

typedef long long ll;

int n,a[maxn],b[maxn],x;

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int res=0,last=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            if(a[i]>b[i]) res=3;
            if(a[i]-b[i]!=last) res++;
            last=a[i]-b[i];
        }
        if(last) res++;
        if(res<=2) puts("YES");
        else puts("NO");
    }
    return 0;
}
