//题意：给出一个二进制字符串，其中串中包含 '?'，可以替换为 '1' or '0'，问该字符串是否是或是否可以构造成任意长度为 k 的子串中都包含 k/2 的 '1' and '0'

//思路：写这题的时候已经进入状态了，思维还是挺活跃的，首先看到这道题，我没有注意到要求 k/2 个数的 01 串，但是无伤大雅，我先想到了任意长度为 k 的子串数量都相同，那么从开头的串 s[1,k] 开始
//开头位置的串的数量一定是要正确或者可构造的，首先确定它符合条件，然后 k+1 位置一定和 1 位置是相同的，k+2 和 2 位置，依次类推，保证任意 k 长度的数量相等
//但是这里存在一个 '?'，那么我们根据上述推导过程发现所有 [x%k] 位置的字符一定是要相等的，这样才能满足性质，那么我们对于每个 [x%k] 位置的字符，他们只要互相不冲突即可
//那么综上，我们要满足一下条件：
//1：在所有 x%k 位置的字符都要相同，'?' 视为与 01 都相同
//2：整体的 01 个数布局要相同，这里不需要完全相等，只要双方的个数都 <=k/2 即可，其他的就算不满足也可以完全靠 '?' 去补足
//判断模拟即可，并且为了方便，其实可以不用开头就判断 s[1,k] 是否个数可满足，因为如果它不合法，要么是后面的串 [x%k] 位置不匹配，要么整体匹配了，那么这种情况个数就和 s[1,k] 一样或者更完善 '?' 的信息被填充
//也是可以判断出合法性的

#include <bits/stdc++.h>
 
using namespace std;	
typedef long long ll;
const int maxn=3e5+10;
 
int n,k,key[maxn];
string s;
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		cin>>n>>k;
		for(int i=0;i<k;i++) key[i]=-1;
		cin>>s;
		s='#'+s;
		bool f=1;
		int cnt0,cnt1;
		cnt0=cnt1=0;
		for(int i=1;i<=k;i++){
			if(s[i]=='1') cnt1++,key[i%k]=1;
			else if(s[i]=='0') cnt0++,key[i%k]=0;
		}
		if(cnt1>k/2||cnt0>k/2){
			puts("NO");
			continue;
		}
		for(int i=k+1;i<=n;i++){
			if(s[i]=='1'||s[i]=='0'){
				if(key[i%k]==-1) key[i%k]=s[i]-'0';
				else if(key[i%k]!=s[i]-'0'){
					f=0;break;
				}
			}
		}
		cnt1=cnt0=0;
		for(int i=0;i<k;i++){
			if(key[i]==1) cnt1++;
			else if(key[i]==0) cnt0++;
		}
		if(cnt0>k/2||cnt1>k/2) f=0;
		if(f) puts("YES");
		else puts("NO");
	}
	return 0;
}
