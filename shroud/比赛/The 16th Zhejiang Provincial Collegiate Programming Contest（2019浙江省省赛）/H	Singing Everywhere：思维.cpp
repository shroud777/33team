//题意：给出一个长度为 n 的代表音高的序列，如果出现一个 k 使得 a[k]>a[k-1] && a[k]>a[k+1]，称之为 voice crack，现在可以删除序列中至多一个数，使得 voice crack 的数量最少，问最少有多少个

//思路：首先我们想到如果是删除一个数，有可能减少 0个 1个 或 2 个
//0个的情况就是 voice crack 的极点位置删除后产生的了新的结点，导致无法减少 voice crack 的总数量
//1个的情况是可能 voice crack 的两边相等，或一系列不会产生新的 voice crack 的情况
//2个的情况就是相邻为 2 的两个 voice crack 极点相同，把中间的谷点去除后减少了两个

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int a[maxn],b[maxn];
int n;

map<int,int> mp;
vector<int> res;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		res.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int f=0;
		for(int i=2;i<n;i++){
			if(a[i]>a[i-1]&&a[i]>a[i+1]&&a[i]){
				res.push_back(i);
				if((i-2==0||a[i-2]>=a[i-1])&&(i+2==n+1||a[i+2]>=a[i+1])||(a[n-1]==a[n+1])) f=1;
			}
		}
		for(int i=1;i<res.size();i++){
			if(res[i]-res[i-1]==2&&a[res[i]]==a[res[i-1]]){
				f=2;break;
			}
		}
		printf("%d\n",res.size()-f);
	}
	return 0;
}
