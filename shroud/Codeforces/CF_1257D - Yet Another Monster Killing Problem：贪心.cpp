//题意：现在有 n 只怪兽，怪兽有一个能力值属性，m 个英雄，每个英雄有一个能力值属性和最多能打几只怪兽的属性，现在从第一天开始要派英雄去清理怪兽，按照给出的怪物顺序
//每天只能派出一位英雄，并且他一天只能打最多能打怪兽次数以内的怪兽和能力值小于等于他的怪兽，问最少需要几天将所有怪兽清除？

//思路：我们可以发现随着一天要打的怪兽数量增多，需要击败这些怪兽的能力值只会增大，不会减小，那么现在有两种方法应对他：
//1.贪心地去用英雄，我们将英雄以打怪兽数量降序排序，我们肯定是尽可能打多的怪兽，但是限制于能力值大小，当我们目前英雄地能力值不够时，我们只能往打怪数量少地英雄那里找
//并且如果找到了，必须判断他地打怪数量是否大于当前已经打的怪物地数量，否则就说明他不配打这个怪，并且由于我们对打怪数量排过序，那么这个英雄一定时当前地最优解，满足单调性
//为了防止每次都能力值不够向下找英雄地复杂度过高，我们记录一个最大值 mx 和一个位置 pos，代表如果要打败 mx 能力值地怪兽，必须用到 pos 个英雄才行
//2.对于英雄来说，其实随着打怪数量地增多，可以打这么多怪地最大能力值英雄数量肯定也会减少，我们可以用一个数组记录可以打 x 个怪物地英雄地能力最大值
//那么我们发现只需要在遍历怪物的时候记录两个值，一个时当前打怪的数量，一个时当前数量的怪物的最大值，那么我们只需要判断英雄打这些数量的怪物的最大值是否大于当前数量怪物的最大值就可以知道能不能降序打了

//做法1：

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;

int n,m,a[maxn];

struct node{
    int p,s;
    bool operator <(const node &oth)const{
        if(s==oth.s) return p>oth.p;
        return s>oth.s;
    }
}b[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int mx1=0,mx2=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx1=max(mx1,a[i]);
        cin>>m;
        for(int i=1;i<=m;i++) scanf("%d %d",&b[i].p,&b[i].s),mx2=max(mx2,b[i].p);
        if(mx1>mx2){
            puts("-1");continue;
        }
        sort(b+1,b+m+1);
        int ans=0;
        int i=1,j=1,cnt=0,mx=0,pos=1;
        bool f=0;
        while(i<=n){
            cnt=0,f=0;
            while(b[j].s>cnt&&i<=n){
                if(a[i]>=mx) j=pos;
                while(b[j].p<a[i]) j++;
                if(a[i]>mx){
                    mx=a[i];
                    pos=j;
                }
                if(b[j].s<=cnt){
                    f=1;
                    break;
                }
                i++;
                cnt++;
            }
            if(!f) j=1;
            ans++;
        }
        printf("%d\n",ans);
    }

    return 0;
}

//做法2：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,m,a[maxn],mx[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx[i]=0;
        scanf("%d",&m);
        int p,s;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&p,&s);
            mx[s]=max(mx[s],p);
        }
        for(int i=n-1;i;i--){
            mx[i]=max(mx[i+1],mx[i]);
        }
        int ans=0,cur=0;
        bool f=1;
        while(cur<n){
            int cnt=1,temp=a[cur+cnt];
            while(temp<=mx[cnt]&&cur+cnt<=n){
                cnt++;
                temp=max(temp,a[cur+cnt]);
            }
            if(cnt==1){
                f=0;break;
            }
            ans++;
            cur+=cnt-1;
        }
        if(f) printf("%d\n",ans);
        else puts("-1");
    }
    return 0;
}
