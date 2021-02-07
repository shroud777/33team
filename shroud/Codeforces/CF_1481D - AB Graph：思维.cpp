//题意：给出一个完全图，现在所有的边上都存在一个字符 'a'/'b'，现在要求找出一条长度为 m 的路径使得走过路径组成的字符为回文串，可以重复经过一个点或一条边

//思路：首先对于那些存在两个点之间两条不同方向的边如果存在同一个字符的话肯定是可行的，因为只有一个相同字符，长度为 m 重复 m 次即可
//接着对于 m 为奇数的情况也是一定可行的，只需要重复 aba/bab 即可
//然后剩余情况如果 m 为偶数，如果 m=2 的时候不满足最开始两条边字符相同的情况，那么不存在解， m>2 时一定存在解：
//首先对于 m/2 为奇数，很好证明对于任意三个点，一定存在连续两条边的字符相同的情况，那么由于只有字符 'a'/'b'，我们很好处理剩余的情况，m/2 为奇数
//就是 m=6，10 这种情况，每次增加 3 个字符，那么 aabbaa 为基础单位，很显然可以满足情况，我们只需构造 aabbaa aabbaa 这样的字符即可
//对于 m/2 为偶数，我们只需构造 abba abba 这样的情况即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,m;
char s[1005][1005];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        if(m&1){
            puts("YES");
            printf("%d ",1);
            for(int i=1;i<=m;i++){
                printf("%d%c",i&1?2:1,i==m?'\n':' ');
            }
            continue;
        }
        bool f=0;
        int u,v,w;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(s[i][j]==s[j][i]){
                    u=i,v=j;
                    f=1;break;
                }
            }
            if(f) break;
        }
        if(f){
            puts("YES");
            printf("%d ",u);
            for(int i=1;i<=m;i++){
                printf("%d%c",i&1?v:u,i==m?'\n':' ');
            }
            continue;
        }
        if(n<3){
            puts("NO");continue;
        }
        puts("YES");
        if(s[1][2]==s[2][3]) u=1,v=2,w=3;
        else if(s[2][3]==s[3][1]) u=2,v=3,w=1;
        else if(s[3][1]==s[1][2]) u=3,v=1,w=2;
        if(m/2&1){
            printf("%d %d %d",u,v,w);
            for(int i=2;i<m;i+=4){
                printf(" %d %d %d %d",v,u,v,w);
            }
        }
        else{
            printf("%d %d %d %d %d",v,u,v,w,v);
            for(int i=4;i<m;i+=4){
                printf(" %d %d %d %d",u,v,w,v);
            }
        }
        puts("");
    }
    return 0;
}
