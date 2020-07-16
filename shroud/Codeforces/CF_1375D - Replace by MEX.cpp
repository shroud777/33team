//题意：给出一个长度为 n 的序列，请你进行 2*n 次以内的操作，每次操作可以将序列的 MEX 和任意位置元素交换，使得最终序列不递减，求出操作次数和每次操作选择的位置
// MEX 是不在序列中的最小的数（从 0 开始），比如序列 0 1 2 4 的 MEX 就是 3，其次每趟操作后的 MEX 是会变的

//思路：稍微找了会规律发现，如果 MEX < n ，只要将下标位置（数组下标从 1 开始）为 MEX+1 的位置变为 MEX，重复循环这个过程
//MEX是不在序列中的最小数，而且从 0 开始，所以这个方法其实也是在不断构造 0~n-1 的序列
//但如果 MEX 的值等于 n，也就是意味着这 n 个序列已经存在 0~n-1 的全排列，如果序列已经排列整齐，那不用多说，否则，我们定义当前位置 数组元素+1 = 数组下标的就是 fixed
//那么 MEX=n 是，我们可以去找那些 unfixed 元素，然后把他换成当前的 MEX=n ，这样这个位置上的本来的元素又跑到了他该去的地方
//然后就是注意小细节，妈的一个小错误一直MTE，我还以为是爆栈了什么的，改了将近四十分钟

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
int vis[maxn],a[maxn];
int n;
bool check(){
	for(int i=2;i<=n;i++) if(a[i]<a[i-1]) return false;
	return true; 
}
inline int get(){
	for(int i=0;i<=n;i++) if(!vis[i]) return i;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof vis);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			vis[a[i]]++;
		}
		int temp=n;
		vector<int> ans; 
		while(!check()){
			while(temp--){
				int now=get();
				if(now==n){
					if(check()) break; 
					for(int i=1;i<=n;i++) if(a[i]!=i-1){
						vis[a[i]]--;
						a[i]=n;
						vis[n]++;
						ans.push_back(i);
						break;
					}
					continue;
				}
				ans.push_back(now+1);
				vis[a[now+1]]--;
				vis[now]++;
				a[now+1]=now;
			}
		}
		cout<<ans.size()<<endl;
		if(ans.size()) cout<<ans[0];
		for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
		cout<<endl;
	}
	return 0;
}
