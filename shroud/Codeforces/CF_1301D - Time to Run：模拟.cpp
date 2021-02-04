//题意：在一个 n*m 的格子里，每两个相邻格子间有连接两者但两条方向不同的路，总共 4*n*m-2*n-2*m 条，现在 Bashar 要走 k 条路并且不重复（格子可以重复），请你按照如下格式给出不多于 3000 次的操作
//一次操作的格式如下：某一动作的重复次数 + 某一动作指令

//思路：首先所有 4*n*m-2*n-2*m 都可以在 3000 次操作内执行完毕，所有首先判断可行与否，然后给出操作，我们可以按照如下操作：
//1.先往下 n-1 格
//2.往右 m-1 格
//3.往左 m-1 格
//4.重复向上 1 格，执行右下上 m-1 次，向左 m-1 格
//按照上述操作执行，并且中途判断步数有没有超过，注意细节即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,string> pis;

const int maxn=5e5+10;

int n,m,k;

vector<pis> ans;

int main(){
    cin>>n>>m>>k;
    if(k>4*n*m-2*n-2*m){
        puts("NO");return 0;
    }
    puts("YES");
    while(1){
        if(n-1){
            if(k<=n-1){
                ans.push_back(pis(k,"D"));
                break;
            }
            ans.push_back(pis(n-1,"D"));
            k-=n-1;
        }
        if(m-1){
            if(k<=m-1){
                ans.push_back(pis(k,"R"));
                break;
            }
            k-=m-1;
            ans.push_back(pis(m-1,"R"));
        }
        if(m-1){
            if(k<=m-1){
                ans.push_back(pis(k,"L"));
                break;
            }
            k-=m-1;
            ans.push_back(pis(m-1,"L"));
        }
        for(int i=1;i<n;i++){
            if(k<=1){
                ans.push_back(pis(k,"U"));
                break;
            }
            k--;
            ans.push_back(pis(1,"U"));
            if(m-1){
                if(k<=3*(m-1)){
                    string temp="RDU";
                    if(int(k/3)) ans.push_back(pis(int(k/3),"RDU"));
                    if(k%3==1) ans.push_back(pis(1,"R"));
                    else if(k%3==2) ans.push_back(pis(1,"RD"));
                    break;
                }
                k-=3*(m-1);
                ans.push_back(pis(m-1,"RDU"));
                if(k<=m-1){
                    ans.push_back(pis(k,"L"));
                    break;
                }
                k-=m-1;
                ans.push_back(pis(m-1,"L"));
            }
        }
        break;
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++) printf("%d %s\n",ans[i].first,ans[i].second.c_str());
    return 0;
}
