//题意：n 个同学拍成一排，老师邀请若干位同学出列，使得合唱队形满足要求：剩下同学的身高满足 T1<...<Ti>Ti+1>…>TK(1<=i<=K)

//思路：正反做两次 LIS，然后枚举最高点即可，答案就是 |LIS1|+|LIS2|-1

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e6+10;

int n,a[maxn];
int dp1[maxn],dp2[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        dp1[i]=1;
        for(int j=1;j<i;j++){
            if(a[i]>a[j]) dp1[i]=max(dp1[i],dp1[j]+1);
        }
    }
    int ans=0;
    for(int i=n;i>=1;i--){
        dp2[i]=1;
        for(int j=n;j>i;j--){
            if(a[i]>a[j]) dp2[i]=max(dp2[i],dp2[j]+1);
        }
        ans=max(ans,dp1[i]+dp2[i]-1);
    }
    cout<<n-ans<<endl;
    return 0;
}
