//题意：给出一个由小写字母构成的字符串，现在要求构造一个由小写字母组成的键盘并且满足原字符串中所有相邻元素在新的字符串中也相邻

//思路：这里有 3 种做法，首先介绍下贪心：
//1.贪心：我们从左到右遍历字符串，可以发现对于当前字符 si，如果它已经在出现过，那么对于它的前一个字符 si-1，si 上一次出现必然是在字符 si-1 出现过的位置的相邻位置，否则 si 将有两个不同于 si-1 的相邻字符
//这里我们用一个字符串变量来维护信息，并且保证当前指针指向位置必然使 si-1 字符的位置，这样如果 si 出现过，我们只需要判断 si-1 在字符串变量的前后是不是 si 即可，不是得话说明不存在答案
//如果当前字符没有遍历过，那么说明我们只需要加到 si-1 字符在字符串变量中的相邻位置即可，如果相邻位置被别的字符占有了，说明不存在答案
//2.并查集，这里并查集可以很好的维护字符之间的关系，对于 si 和 si-1，如果他们已经属于同一集合并且在之前不是邻居，说明他们已经通过若干个元素链接起来了，但是现在又要将他们相连，只能构成环，说明不存在答案
//3.递归：我们用 set 维护出相邻元素的信息，然后找到 set 大小为 1 的字符，那便是字符串的头，开始递归，如果当前字符的集合中存在两个以上的相邻元素，那么不存在解，或者当前字符已经访问过，也不存在解

//做法1：（贪心）

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

string s;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        vector<bool> vis(26);
        string ans=string(1,s[0]);
        vis[s[0]-'a']=true;
        int pos=0;
        bool f=1;
        for(int i=1;i<s.size();i++){
            int j=s[i]-'a';
            if(!f) break;
            if(!vis[j]){
                if(pos==0) ans=s[i]+ans;
                else if(pos==ans.size()-1) ans+=s[i],pos++;
                else f=0;
            }
            else{
                if(pos>0&&ans[pos-1]==s[i]) pos--;
                else if(pos+1<=ans.size()-1&&ans[pos+1]==s[i]) pos++;
                else f=0;
            }
            vis[j]=1;
        }
        if(!f){
            puts("NO");
            continue;
        }
        for(int i=0;i<26;i++){
            if(!vis[i]) ans+=i+'a';
        }
        puts("YES");
        cout<<ans<<endl;
    }
    return 0;
}

//做法2： 并查集

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;

string s;

int fa[105],vis[105];

void init(){
    for(int i=1;i<=26;i++) vis[i]=0,fa[i]=i;
}

int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        bool f=1;
        init();
        set<int> ss[30];
        for(int i=1;i<s.size();i++){
            int x=s[i-1]-'a'+1;
            int y=s[i]-'a'+1;
            if(ss[x].find(y)!=ss[x].end()) continue;
            int rx=find(x),ry=find(y);
            if(rx==ry){
                f=0;break;
            }
            fa[rx]=ry;
            ss[x].insert(y);
            ss[y].insert(x);
            
            if(ss[x].size()>2||ss[y].size()>2){
                f=0;break;
            }
            
        }
        if(f){
            puts("YES");
            string ans;
            int st=-1;
            for(int i=1;i<=26;i++){
                if(ss[i].size()==1) st=i;
            }
            if(st==-1){
                for(int i=1;i<=26;i++) ans+=(i+'a'-1);
                cout<<ans<<endl;
                continue;
            }
            set<int> ::iterator it;
            vis[st]=1;
            while(true){
                //cout<<st<<endl;
                ans+=(st+'a'-1);
                for(it=ss[st].begin();it!=ss[st].end();it++){
                    if(!vis[*it]){
                        st=*it;vis[st]=1;break;
                    }
                }
                if(ss[st].size()==1){
                    ans+=(st+'a'-1);break;
                }
            }
            for(int i=1;i<=26;i++){
                if(!vis[i]) ans+=(i+'a'-1);
            }
            cout<<ans<<endl;
        }
        else puts("NO");
    }

    return 0;
}

//做法 3： （递归）

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;

string s,ans;

set<int> ss[30];
int vis[30];
bool f;

void dfs(int cur,int last){
    set<int> ::iterator it;
    if(ss[cur].size()>2||vis[cur]){
        f=0;return;
    }
    vis[cur]=1;
    ans+=(cur+'a'-1);
    for(it=ss[cur].begin();it!=ss[cur].end();it++){
        if(*it!=last) dfs(*it,cur);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        f=1;
        for(int i=1;i<=26;i++) ss[i].clear(),vis[i]=0;
        cin>>s;
        for(int i=1;i<s.size();i++){
            int x=s[i]-'a'+1,y=s[i-1]-'a'+1;
            ss[x].insert(y);
            ss[y].insert(x);
        }
        ans="";
        for(int i=0;i<26;i++){
            if(ss[i].size()) f=0;
            if(ss[i].size()==1){
                f=1;
                dfs(i,0);
                break;
            }
        }
        if(!f) puts("NO");
        else{
            puts("YES");
            for(int i=1;i<=26;i++){
                if(!vis[i]) ans+=(i+'a'-1);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
