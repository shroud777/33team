//题意：有一个长度为 n 的数组 a，使他变成数组 b，其中数组 b 中各元素出现的次数和 a 中的一样，同时相同位置 a 和 b 的元素不相同，求是否存在字典序最小的数组 b

//思路：首先很明确，如果对于一个数，他出现的次数大于 n/2 ，那么显然不可能存在这样的 b 数组，反之必然存在，那么我们想象如何使得 b 的字典序最小。
//首先可以想到一种贪心思路，将 b 数组排好序，然后检查 a 和 b 每个位置是否相等，如果相等则与后面的不同的元素置换，这样能保证前面永远是字典序最小的方案，但是这样也会出现一些问题
//比如  2 3 5 5，按照这种策略我们依次放入  3 2 ，然后发现 5 没法放了
//由此种情况我们知道一味贪心不一定能找出合理的序列，有些位置比如上面的 1 2 号位置是一定要放 5 的，这里我们得出一个结论，如果当前剩余元素数量 n-i+1 = 某个元素要安排的位置+不能放置改元素的位置
//说明剩下的位置对于这个元素来说，是必须要放入的，不然就说出现后续放不下的问题，因为要安放的数量+不能安放的数量 > 剩余可以安放元素的位置的数量
//说明溢出了，那么我们只需要每次维护这个当前必须要安放的数的集合，如果当前位置必须要放这个数，那就放这个数，否则按照字典序，放最小的，如果最小的冲突，放次小的
//这里可以选择用 set 或者 权值线段树 维护剩余元素的个数

//set 维护

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+10;

int n,a[maxn],cnt1[maxn],cnt2[maxn],ans[maxn];

set<pii> s1,s2; 
//s1 维护 p(i,cnt1)  代表剩余元素中的个数，先找出字典序最小的元素 
//s2 维护 p(cnt2,i)  代表剩余元素中某些位置必须要放的元素
//cnt2[i]= i 剩余的个数+不能放 i 的个数 
set<pii>::iterator it;


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		s1.clear(),s2.clear(); 
		scanf("%d",&n);
		for(int i=1;i<=n;i++) cnt1[i]=cnt2[i]=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt1[a[i]]++,cnt2[a[i]]+=2;
		for(int i=1;i<=n;i++){
			if(cnt1[i]) s1.insert(pii(i,cnt1[i])),s2.insert(pii(cnt2[i],i));
		}
		if((--s2.end())->first>n){
			puts("Impossible");
			continue;
		}
		for(int i=1;i<=n;i++){
			int x=a[i];
			s2.erase(pii(cnt2[x],x));
			s2.insert(pii(--cnt2[x],x));  //遍历到这个元素，代表这个元素不能放的位置变少了
			it=s2.end(),it--;
			if(it->first==n-i+1) ans[i]=it->second;
			else{
				it=s1.begin();
				if(it->first==a[i]) ans[i]=(++it)->first;
				else ans[i]=it->first;
			}
			x=ans[i];
			s1.erase(pii(x,cnt1[x]));
			if(--cnt1[x]) s1.insert(pii(x,cnt1[x]));
			s2.erase(pii(cnt2[x],x));
			if(--cnt2[x]) s2.insert(pii(cnt2[x],x));
		}
		for(int i=1;i<=n;i++) printf((i==1)?"%d":" %d",ans[i]);
		printf("\n");
	}
	
	return 0;
} 
