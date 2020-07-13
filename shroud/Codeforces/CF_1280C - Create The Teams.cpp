//题意：给出 1~n 个员工的能力值 ai ，将若干个员工组队，使得每个队伍的能力值不小于 x ，每个小组的能力值 = 该小组能力值最小的员工 * 小组的员工数，求最多可以组多少个小组，员工也可以不组队。

//思路：因为不是每个员工都要组队，所以肯定不可能以小的为基准，来找大的满足他，因此尽量抛弃小的，只要降序之后，贪心地尽量满足能力值大的员工的组队要求。

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[maxn];
int main(){
	int t,n,x;
	cin>>t;
	while(t--){
		cin>>n>>x;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n,greater<int>());
		int ans=0;
		int cnt=1;
		for(int i=1;i<=n;i++){
			if(a[i]*cnt>=x){
				ans++;
				cnt=0;
			}
			cnt++;
		}
		cout<<ans<<endl;
	} 
	
	return 0;
} 
