//题意：现在有 n 只队伍比赛，每两只队伍进行一次比赛，平局不得分，赢了得 1 分，输了减 1 分，现在要求输出比赛结果，使得所有队伍的比分相同

//思路：首先对于 n 是奇数的情况，一支队伍能和偶数支队伍比赛，显然可以用 (n-1)/2 的胜利和战败换来每个人都是 0 得分，只要构造出对应的情况即可
//而 n 是偶数的情况，事实上只是相当于奇数情况下多出一只队伍，我们只要保证 n/2 场比赛打平，就能保证和奇数情况下一样

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=3e5+10;

int n,k;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n&1){
            int m=n*(n-1)/2;
            for(int i=1;i<=m;i++) printf("%d%c",i&1?1:-1,i==m?'\n':' ');
        }
        else{
            for(int i=1;i<=n;i++){
                int cnt=i&1;
                for(int j=i+1;j<=n;j++){
                    cnt++;
                    if((i&1)&&j==i+1){
                        cnt++;
                        cout<<0<<" ";continue;
                    }
                    if(cnt&1) cout<<-1<<" ";
                    else cout<<1<<" ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
