//题意：给出一个长度为 2*n 的数组，现在可以对数组做如下操作来去除原数组中的所有元素
//选择一个正整数 x，接着做 n 次如下操作：
//选择两个和等于 x 的元素
//将这两个元素剔除，并且把 x 替换成两个元素中较大的那个元素
//问是否可以确定一个 x 能使数组中的所有元素被剔除？

//思路：首先我们可以发现，对于每次要取的两个数，其中较大的一个数肯定使当前序列中剩下的最大的数，因为 x 只会不断变小，如果此时选中的两个数都比数组中剩余的某个数小，那么这个剩下的数将永远无法剔除
//接着我们可以发现，当我们确定每次必须要剔除一个序列中的最大的数之后，我们可以根据 x 来确定另一个数
//那么我们怎么确定最开始的 x 呢？
//肯定想着是去枚举 x，但是由于序列的元素值域过大，枚举会超时，而序列的元素个数只有 1e3，我们可以考虑枚举第一次取的较小的那个数，接下来我们只需要模拟这个过程即可，每次取最大的数和 x-最大的数 即可
//复杂度：O(n^2+maxA)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e3+10;

int n,a[maxn<<1],cnt[maxn*maxn];

vector<int> ans;

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=(n<<1);i++) scanf("%d",&a[i]);
        sort(a+1,a+n*2+1);
        bool flag;
        for(int i=1;i<(n<<1);i++){
            int x=a[i]+a[n<<1];
            int idx=(n<<1);
            flag=1;
            for(int j=1;j<=(n<<1);j++) cnt[a[j]]=0;
            for(int j=1;j<=(n<<1);j++) cnt[a[j]]++;
            for(int j=1;j<=n;j++){
                while(!cnt[a[idx]]) idx--;
                cnt[a[idx]]--,cnt[x-a[idx]]--;
                ans.push_back(a[idx]);
                ans.push_back(x-a[idx]);
                if(cnt[a[idx]]<0||cnt[x-a[idx]]<0){
                    cnt[a[idx]]=0;
                    cnt[x-a[idx]]=0;
                    flag=0;break;
                }
                x=a[idx];
            }
            if(flag) break;
            ans.clear();
        }
        for(int i=1;i<=(n<<1);i++) cnt[a[i]]=0;
        if(flag){
            puts("YES");
            printf("%d\n",ans[0]+ans[1]);
            for(int i=0;i<n;i++) printf("%d %d\n",ans[2*i],ans[2*i+1]);
            ans.clear();
        }
        else puts("NO");
    }
    return 0;
}
