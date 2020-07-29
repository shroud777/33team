//题意：给出一个只包含 '(', ')' , '*' 的字符串，一个'*' 可以变成任意 '(' 或 ')'，要求使给出字符串成为一个合法的括号序列 ，并且字典序最小

//思路：和正常的括号序列匹配一样，但是这里用到 vector 记录 '('  '*' 的位置，并且满足 '(' 尽量往前放, ')' 尽量往后放来达到字典序最小的要求，先负责 ')' 的匹配，如果前面没有'('，则用选择最前的 '*'
//如果前面一种都没有，则无法成为合法序列，匹配完了之后观察 '(' 的数量，若没有多余的则直接输出改变后的字符串，反之，将与之匹配的 ')' 尽量从后开始放置
//这也是选择 vector 的原因，因为之前需要从前往后，现在要从后往前，如果最后一个 '*' 在 '(' 前面，或者 '*' 的数量小于 '('，都可以认为是无法成为合法的序列
//码力和思维有待加强啊，几十分钟就能做出来的题目，硬是因为贪心策略想叉劈，然后又因为代码问题各种 wa 和 re，浪费了好多时间

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
int main(){

    int t;
    char s[maxn];
    vector<int> res;
    vector<int> v;
    scanf("%d",&t);
    while(t--){
        v.clear();
        res.clear();
        scanf("%s",s);
        bool f=1;
        int len=strlen(s);
        for(int i=0;i<len;i++){
            //cout<<i<<" "<<v.size()<<endl; //shanchu
            if(s[i]=='*') res.push_back(i);
            else if(s[i]=='(') v.push_back(i);
            else {
                if(v.size()<=0){
                    if(!res.empty()){
                        s[*res.begin()]='(';
                        res.erase(res.begin());
                    }
                    else {
                        f=0;break;
                    }
                }
                else v.pop_back();
            }
        }
        //for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
        //for(int i=0;i<res.size();i++) cout<<res[i]<<" ";cout<<endl;
        while(!v.empty()){
            if(v.size()>res.size()){
                f=0;
                break;
            }
            else{
                while(!v.empty()&&!res.empty()&&*(v.end()-1)<*(res.end()-1)){
                    //cout<<*(v.end()-1)<<" "<<*(res.end()-1)<<endl;
                    s[*(res.end()-1)]=')';
                    v.pop_back();
                    res.pop_back();
                }
                if(!v.empty()){
                    f=0;break;
                }
            }
        }
        if(!f) printf("No solution!");
        else for(int i=0;i<len;i++){
            if(s[i]=='*') continue;
            else printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
