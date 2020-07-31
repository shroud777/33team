//题意：给出 n 把枪的属性，伤害 di 和每次攻击的间隔 ai，A 和 B 要进行对枪，两人初始都有 100 hp，如果某一时刻一人的血量低于或等于 0，则他的队手获胜，其他则两个各有 50% 概率获胜
//在开始的一瞬间两人同时开枪，每次间隔时间一到，立刻开枪，B 从 n 把枪中任意选一把枪，求你帮 A 选一把枪使胜率更高

//思路：根据枪的属性排序并选出杀人最快的那把枪，并统计是否有枪所需杀人时间相同，最后得出概率

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+10;
int a[maxn];
int main(){
    int t;
    scanf("%d",&t);
    int n;
    while(t--){
        scanf("%d",&n);
        int A,D; 
        for(int i=1;i<=n;i++){
            scanf("%d %d",&A,&D);
            a[i]=(ceil((100*1.0)/A)-1)*D;
        }
        if(n==1){
            cout<<0.5<<endl;
            continue;
        } 
        sort(a+1,a+n+1);
        int cnt=1;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]) cnt++;
            else break;
        }
        cout<<(n-cnt)*1.0/n+0.5*cnt/n<<endl;
    }
    
    return 0;
}
