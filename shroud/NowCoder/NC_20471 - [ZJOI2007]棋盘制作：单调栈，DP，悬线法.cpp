//题意：给出一个 n*m 格子为黑或白的矩形，现在要求找出最大的正方形棋盘与矩形棋盘，棋盘即满足黑白相间

//思路：
//1.可以通过 DP 预处理出每个格子可以延申到左右哪个位置，然后我们从上到下，可以发现当前格子所在行对于上一行，如果颜色不同说明可取，那么如果我们要延申到上一行，那么作为一个矩形，左右肯定也要被约束
//这就相当于有一根线控制左右边界的临界位置，所有边界都不可以超过这个临界位置。
//并且假设存在下方左右延申位置比上方大的情况，并且实际上的面积也是下方那一块大，不用担心，左右极端点的地方必然会存在一个位置无法延申到上面，这个时候计算的就是下面那一块的面积了，比较抽象
//https://www.luogu.com.cn/problem/solution/P1169
//2.如果我们从每一行来处理，每次我们可以根据预处理可以得到当前 (i,j) 位置可以向上延申的距离 h[j]，那么就变成了一个经典的单调栈问题，如果当前高度 h[j] 低于栈顶，那就不断弹出栈顶并计算贡献
//并且注意最后要清空栈还有如果和前一列的颜色相等，那么就不能继承前面的，要直接清空栈

//1.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e3+10;

int n,m;
int a[maxn][maxn];
int l[maxn][maxn],r[maxn][maxn],h[maxn][maxn];


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]),l[i][j]=r[i][j]=h[i][j]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(a[i][j]!=a[i][j-1]) l[i][j]=l[i][j-1]+1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m-1;j>=1;j--){
            if(a[i][j]!=a[i][j+1]) r[i][j]=r[i][j+1]+1;
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>1&&a[i][j]!=a[i-1][j]){
                l[i][j]=min(l[i][j],l[i-1][j]);
                r[i][j]=min(r[i][j],r[i-1][j]);
                h[i][j]=h[i-1][j]+1;
            }
            int a=l[i][j]+r[i][j]-1;
            int b=h[i][j];
            int c=min(a,b);
            ans1=max(ans1,a*b),ans2=max(ans2,c*c);
        }
    }
    cout<<ans2<<endl<<ans1<<endl;
    return 0;
}

//2.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e3+10;

int n,m,ans1,ans2;
int a[maxn][maxn],h[maxn];
int s[maxn];

void cal(int a,int b){
    int c=min(a,b);
    ans1=max(ans1,c*c);
    ans2=max(ans2,a*b);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>1&&a[i][j]!=a[i-1][j]) h[j]=h[j]+1;
            else h[j]=1;
        }
        int top=0,cur=1;
        while(cur<=m){
            s[0]=cur-1,s[top=1]=cur++;
            while(cur<=m&&a[i][cur]!=a[i][cur-1]){
                while(h[s[top]]>h[cur]&&top){
                    cal(h[s[top]],cur-s[top-1]-1);
                    top--;
                }
                s[++top]=cur++;
            }
            while(top) cal(h[s[top]],cur-s[top-1]-1),top--;
        }
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}
