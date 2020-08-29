//题意：给出一个长度为 n 的序列，分别由 0 和 1 组成，'0' 代表女生，'1' 代表男生，且这些人的战斗力为在序列中的位置 i（从 1 开始）
//先把所有人分为 G1,G2,G3,G4 四个小团体，其中某个团体可以为空，G1,G2 都是女生，G3,G4 都是男生，要使得战斗力 G1+G3 = G2+G4，问是否存在这样的情况，若存在输出任意解

//思路：首先我们可以想着先只往 G1+G3 里放人，那么只要两边的数量相等的时候才能有解，那么这个所有人的战斗力的总和为偶数，因为 odd+odd=even even+even=even
//说明只要满足上述条件就一定存在解，因为 1-n 的组合可以组合出任意 1-n 总和以下的数，那么我们把先组合出来的男生女生分别放入 G1,G3 其他的全部放入 G2,G4 即可
//要注意刚开始算总和的时候不能爆 long long

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int n,ans[maxn];
string s;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		cin>>s;
		s='#'+s;
		ll sum=1ll*(1+n)*n/2;
		if(sum&1){
			puts("-1");
			continue;
		}
		sum/=2;
		memset(ans,0,sizeof ans);
		for(int i=n;i>=1;i--){
			if(sum>=i){
				if(s[i]=='0') ans[i]=1;
				else ans[i]=3;
				sum-=i;
				if(sum==0) break;
			}
			else{
				if(s[sum]=='0') ans[sum]=1;
				else ans[sum]=3;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(!ans[i]){
				if(s[i]=='0') printf("2");
				else printf("4");
			}
			else printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
