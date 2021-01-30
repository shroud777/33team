//题意：现在有一个 n*n 的矩阵 a 并且每个元素只由 0 或 1 构造的矩阵，现在可以执行两种操作：
//1：垂直异或：选择第 i 行，使得 aj,i (1<=j<=n) 都异或上 1
//2. 水平异或：选择第 i 列，使得 ai,j (1<=j<=n) 都异或上 1
//问能否通过矩阵 a 经过上述操作得到矩阵 b？

//思路：可以发现如果对同一行或列作两次以上的操作都是没有意义的，要么不做，要么做一次。并且我们可以发现一个位置的元素想要改变它，要么通过对它所在行作水平异或，要么对它所在列作垂直异或
//事实上我们只需要看两个矩阵的第一行，然后根据他们可以判断是否要作垂直异或，当然这里有两种情况
//第一种就是我们不对矩阵 a 的第一行作水平异或，第二种是做一次水平异或，那么其实剩余操作都已经被决定了，因为第一行的元素只能通过垂直异或改变，然后在这之后相当于我们再也不能使用垂直异或了，因为第一行已经固定好了
//这也以为着剩下的行我们只能通过水平异或操作，接下来只需判断模拟即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e3+10;

int n,a[maxn][maxn],b[maxn][maxn];
char ch[maxn];

bool check(int a[][maxn]){
    for(int i=1;i<=n;i++){
        if(a[1][i]!=b[1][i]){
            for(int j=1;j<=n;j++) a[j][i]^=1;
        }
    }
    for(int i=2;i<=n;i++){
        int res=a[i][1]^b[i][1];
        for(int j=2;j<=n;j++){
            if(a[i][j]^b[i][j]!=res) return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%s",ch+1);
            for(int j=1;j<=n;j++) a[i][j]=ch[j]-'0';
        }
        for(int i=1;i<=n;i++){
            scanf("%s",ch+1);
            for(int j=1;j<=n;j++) b[i][j]=ch[j]-'0';
        }
        bool f=0;
        for(int i=1;i<=2;i++){
            if(check(a)) f=1;
            for(int j=1;j<=n;j++) a[1][j]^=1;
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
