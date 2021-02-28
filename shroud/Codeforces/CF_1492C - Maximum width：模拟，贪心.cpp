//题意；给出两个字符串长度为 n 的 s 和长度为 m 的 t，现在定义一个序列严格递增的序列 p，如果对于 spi=ti(1<=i<=n)，则称为美丽序列。定义一个序列的宽度为 max(pi-pi-1)
//现在求宽度最大的美丽序列

//思路：对于字符串 t 的每个字符，在 s 中会有一个匹配的区间，我们尽可能让 t 中相邻的两个字符前一个在区间最左，后一个在区间最右即可
//对于匹配区间我们只需要双指针正反扫一遍即可

#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;

string s,t;

int n,m;
int pre[maxn],suf[maxn];

int main(){
    cin>>n>>m>>s>>t;
    int j=0;
    for(int i=0;i<n;i++){
        if(s[i]==t[j]) pre[j]=i,j++;
        if(j==m) break;
    }
    j=m-1;
    for(int i=n-1;i>=0;i--){
        if(s[i]==t[j]) suf[j]=i,j--;
        if(j==-1) break;
    }
    int ans=0;
    for(int i=0;i<m-1;i++){
        ans=max(ans,suf[i+1]-pre[i]);
    }
    cout<<ans<<endl;
    return 0;
}
