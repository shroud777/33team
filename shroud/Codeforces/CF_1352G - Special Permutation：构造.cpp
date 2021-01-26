//题意：要求你排列一个长度为 n 的全排列，使得其相邻元素之差 x 满足，2<=x<=4

//思路：隔一个数输出，然后临近第 n 个数的时候一次输出 n-3 n-1 n-5 再向前遍历隔一个数输出即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
 
int n;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=3){
            puts("-1");continue;
        }
        if(n&1){
            for(int i=1;i<=n;i+=2) printf("%d ",i);
            printf("%d %d ",n-3,n-1);
            for(int i=n-5;i>=1;i-=2) printf("%d ",i);
            puts("");
        }
        else{
            for(int i=1;i<=n;i+=2){
                if(i==n-3){
                    printf("%d %d ",n-1,n-3);
                    break;
                }
                printf("%d ",i);
            }
            for(int i=n;i>=1;i-=2) printf("%d ",i);
            puts("");
        }
    }
}
