//题意：现在有 n 条线段，第 i 条线段覆盖了 [l,r] 之间 r-l+1 个点，现在要求每个点最多被 k 条线段覆盖，问最少删去几条线段可以满足要求？

//思路：eazy version 的数据比较小，我们可以通过贪心策略取得最优解，只要以线段的右端升序排序，这样我们可以按照顺序覆盖
//我们从前到后处理，对于一个点如果有多条线段覆盖，那么他必然要选择右端点尽量大的线段，因为这样对于后面的贡献比较大
//我们只需要暴力区间累加判断即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;
int cnt[maxn];

vector<int> ans;

struct node{
    int l,r,id;
    bool operator <(const node &oth)const{
        return r<oth.r;
    }
}a[maxn];

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d %d",&a[i].l,&a[i].r),a[i].id=i;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        bool f=0;
        for(int j=a[i].l;j<=a[i].r;j++){
            cnt[j]++;
            if(cnt[j]>k) f=1;
        }
        if(f){
            for(int j=a[i].l;j<=a[i].r;j++) cnt[j]--;
            ans.push_back(a[i].id);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    return 0;
}
