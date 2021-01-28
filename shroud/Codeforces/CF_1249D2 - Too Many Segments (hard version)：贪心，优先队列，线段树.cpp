//题意：现在有 n 条线段，第 i 条线段覆盖了 [l,r] 之间 r-l+1 个点，现在要求每个点最多被 k 条线段覆盖，问最少删去几条线段可以满足要求？

//思路：相比 eazy version，如果按照原来的策略，我们显然无法继续使用暴力累加的方式，如果要按照之前的做法，我们需要使用高效的数据结构判断当前线段区间内的最大值，并且实现区间累加
//这里我们可以用线段树维护
//当然我们可以继续使用贪心策略，将线段按照左端点升序，模拟放入线段的过程，然后对于 i 号点，如果当前线段数超过 k，那么我们选择删掉一些线段，这时候我们肯定要删除右端点最大的线段
//我们可以用 set 或者 优先队列 来维护最大右端点的线段，就可以实现高效模拟

//线段树：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;
ll mx[maxn<<2],lazy[maxn<<2],L,R;

vector<int> ans;

struct node{
    int l,r,id;
    bool operator <(const node &oth)const{
        return r<oth.r;
    }
}a[maxn];


inline int max(int x,int y){
    return x>y?x:y;
}

inline void update(int x){
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
}

void put_lazy(int l,int r,int x,int k){
    mx[x]+=k;
    lazy[x]+=k;
}

void down_lazy(int l,int r,int x){
    int mid=l+r>>1;
    put_lazy(l,mid,x<<1,lazy[x]);
    put_lazy(mid+1,r,x<<1|1,lazy[x]);
    lazy[x]=0;
}

void modify(int l,int r,int x){
    if(L<=l&&r<=R){
        put_lazy(l,r,x,1);
        return;
    }
    if(lazy[x]) down_lazy(l,r,x);
    int mid=l+r>>1;
    if(L<=mid) modify(l,mid,x<<1);
    if(mid<R) modify(mid+1,r,x<<1|1);
    update(x);
}

int query(int l,int r,int x){
    if(L<=l&&r<=R) return mx[x];
    if(lazy[x]) down_lazy(l,r,x);
    int mid=l+r>>1;
    ll ans=0;
    if(L<=mid) ans=max(ans,query(l,mid,x<<1));
    if(mid<R) ans=max(ans,query(mid+1,r,x<<1|1));
    return ans;
}


int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d %d",&a[i].l,&a[i].r),a[i].id=i;
    sort(a+1,a+n+1);
    int m=a[n].r;
    for(int i=1;i<=n;i++){
        L=a[i].l,R=a[i].r;
        if(query(1,m,1)+1>k){
            ans.push_back(a[i].id);
            continue;
        }
        modify(1,m,1);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    return 0;
}

//优先队列：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

int n,k,d[maxn];

struct node{
    int l,r,id;
}a[maxn];

bool cmp(node x,node y){
    return x.l<y.l;
}

priority_queue<pii> q;
vector<int> ans;

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].l,&a[i].r);
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    int cur=1,cnt=0;
    for(int i=1;i<=2e5;i++){
        while(a[cur].l==i){
            d[a[cur].r+1]--;
            q.push(pii(a[cur].r,a[cur].id));
            cnt++;
            cur++;
        }
        d[i]+=d[i-1];
        //cout<<i<<" "<<cnt<<" "<<d[i]<<endl;
        while(cnt+d[i]>k){
            int id=q.top().second,rpos=q.top().first;
            q.pop();
            ans.push_back(id);
            d[rpos+1]++;
            cnt--;
        }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++) printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    return 0;
}
