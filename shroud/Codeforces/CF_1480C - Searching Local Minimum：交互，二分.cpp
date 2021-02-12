//题意：给出一个长度为 n 的全排列，现在要找到一个下标 k，满足 a[k-1]>a[k]<a[k+1]，并且 a[0] 和 a[n+1] 的值视为 +∞

//思路：我们要找一个位置，可以使用二分，查看 mid 位置的单调性
//初始化值域 [l,r]=[1,n]
//如果 amid<amid+1，说明 [l,mid] 可能存在，反之查看 [mid+1,r] 区间

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,a[maxn];

int main(){
    cin>>n;
    int l=1,r=n;
    while(l<r){
        int mid=l+r>>1;
        printf("? %d\n",mid);
        fflush(stdout);
        scanf("%d",&a[mid]);
        printf("? %d\n",mid+1);
        fflush(stdout);
        scanf("%d",&a[mid+1]);
        if(a[mid]>a[mid+1]) l=mid+1;
        else r=mid; 
    }
    printf("! %d\n",l);
    fflush(stdout);
    return 0;
}
