//题意：给出一个长度为 n 的序列，现在你可以执行如下操作：对于元素 a[i]，你可以将它合并到一个相邻元素a[i-1] or a[i+1]（如果存在的话），现在要求执行最多 n 操作，使得序列最后所有数都相等，求最小操作数

//思路：枚举答案即可，最坏的答案就是 n-1 次合并（相当于合并整个序列），答案必然存在，并且最后序列最左端一定会合并成若干块，我们只要枚举最左端是由多少个元素合并的即可，然后只需要遍历验证是否可行
//验证的时候，如果超过枚举的答案的值，那么显然不合法，如果等于，则需要合并操作的次数减一

#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;
 
int n,a[maxn];
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int ans=n-1,temp=0;
		for(int i=1;i<=n;i++){
			temp+=a[i];
			int j=i+1,res=0,cnt=1;
			while(j<=n){
				res+=a[j];
				if(res>temp){
					cnt=-1;break;
				}
				if(res==temp) cnt++,res=0;
				j++;
			}
			if(res>0) cnt=-1;
			if(cnt!=-1) ans=min(ans,n-cnt);
		}
		printf("%d\n",ans);
	}
}
