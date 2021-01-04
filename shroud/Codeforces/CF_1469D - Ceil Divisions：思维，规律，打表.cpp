//题意：给出一个长度为 n 的序列，序列元素为 1-n 的元素的递增排列，现在可以执行如下操作不超过 n+5 次，可以选择两个下标 x,y(x!=y)，并使 ax=ceil(ax/ay)，要使整个序列变成 n-1 个 1，和 1 个 2

//思路：首先根据题意，我们要得到那么多的 1，并且操作都是向上取整的操作，那么我们肯定要用小一点的数去除以较大的数，初始的想法就是所有数除以一个 n，那么显然会留下一个较大的无法处理的数字 n
//那么第一种做法由此产生，我们可不可以留下一个数 x，使得 x 和 n 互相做操作，且总的操作次数尽可能少呢？根据打表得到，28 （还要其他几个数也可以）每次都可以稳定的在 6 次内完成操作，得到一个 2 和一个 1
//那么我们只需要按照开始的思路处理 (2 - n-1) 之间除 28 以外的数，然后其他数字全部正常处理即可
//注意这里小于 28 的数由于取不到 28，可以留一个 2，让 n 一直除以 2，直到为 1
//另一种做法，思路更明了，就是我们可以留下 n 的 sqrt(n)，这样我们可以保证在 sqrt(...sqrt(n)...) 次操作内完成要求，那么我们只需要 2 次，就可以处理一个 n，然后让 n 继续等于 sqrt(n)，其他剩余的之间的数，在之前除以 n 即可

//做法1：

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int maxn=2e5+10;
 
int n;
vector<pii> ans; 
 
int main(){
	int t;
	cin>>t;
	while(t--){
		ans.clear();
		scanf("%d",&n);
		if(n<=28){
			for(int i=3;i<n;i++) ans.push_back(pii(i,n));
			int temp=n;
			while(n!=1){
				ans.push_back(pii(temp,2));
				n=(n-1)/2+1;
			}
		}
		else{
			for(int i=2;i<n;i++){
				if(i==28) continue;
				ans.push_back(pii(i,n));
			}
			int x=28,y=n;
			while(x>2||y>2){
				if(x>y) ans.push_back(pii(28,n)),x=(x-1)/y+1;
				else ans.push_back(pii(n,28)),y=(y-1)/x+1;
			}
			if(x==2&&y==2) ans.push_back(pii(n,28));
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second); 
	}
	return 0;
} 

//做法2：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e5+10;

int n;
vector<pii> ans;

int main(){
	int t;
	cin>>t;
	while(t--){
		ans.clear();
		cin>>n;
		while(n>2){
			int d=ceil(sqrt(n));
			for(int i=d+1;i<n;i++) ans.push_back(pii(i,n));
			ans.push_back(pii(n,d));
			ans.push_back(pii(n,d));
			n=d;
		}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
	}	
	return 0;
} 
