//题意：现在有 n 个软件，第 i 个软件占据 ai 的内存，拥有 bi 的方便度，删除第 i 个软件会清空 ai 的内存，并减少 bi 的方便度，现在要求在删除内存大于等于 m 的情况下，减少的方便度最小

//思路：这题方法比较多：
//第一种方法：由于只有 1 和 2 两种方便度，对于同种方便度的软件，我们肯定是从大到小选择内存，也就是说方案是固定的，所以我们可以枚举某种方便度的软件删除了多少个，然后再降序了的前缀和中二分找到是否存在一个大于等于 m-s 的值即可
//第二种方法：先取某种方便度的所有元素，其实方法和第一种类似，我们删去刚刚取的方便度中占用内存最少的，然后再另一个方便度中方便都从大到小尺取，直到当前和 >=m，取最优解即可
//第三种方法：更好的贪心，当前如果 1 方便度的内存最大的两个元素之和小于等于 2 方便度的内存最大元素，那么我们肯定要考虑取 2 方便度的了，如果小于，那么我们就取 1 方便度最大的
//但是这里另外要考虑，如果当前取 1 个 1 方便度或 2 方便度的就能直接达到要求，那么我们肯定还是优先考虑

//方法一：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

ll a[maxn],b[maxn];
int n,m;

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<ll> v1,v2;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            if(x==1) v1.push_back(a[i]);
            else v2.push_back(a[i]);
        }
        sort(v1.rbegin(),v1.rend());
        sort(v2.rbegin(),v2.rend());
        for(int i=1;i<v2.size();i++) v2[i]+=v2[i-1];
        int ans=0x3f3f3f3f;
        v1.insert(v1.begin(),0);
        int res=0;
        for(int i=0;i<v1.size();i++){
            res+=v1[i];
            if(res>=m){
                ans=min(ans,i);
                break;
            }
            int pos=lower_bound(v2.begin(),v2.end(),m-res)-v2.begin();
            if(pos==v2.size()) continue;
            ans=min(ans,i+2*(pos+1));
        }
        if(ans==0x3f3f3f3f) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}


//方法二：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,m;
int a[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){ 
        vector<int> v1,v2;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            if(x==1) v1.push_back(a[i]);
            else v2.push_back(a[i]);
        }
        ll sum=0;
        for(int i=0;i<(int)v2.size();i++) sum+=v2[i];
        sort(v1.rbegin(),v1.rend());
        sort(v2.rbegin(),v2.rend());
        int ans=1e9,j=0;
        for(int i=(int)v2.size()-1;i>=-1;i--){
            while(sum<m&&j<(int)v1.size()) sum+=v1[j],j++;
            if(sum<m) break;
            ans=min(ans,(i+1)*2+j);
            if(i==-1) continue;
            sum-=v2[i];
        }
        if(ans==1e9) puts("-1");
        else printf("%d\n",ans);
    }

    return 0;
}
