//题意：给出 r 个红球，b 个篮球，g 个绿球，w 个白球，可以用三个 r，g，b 色的球一起换一个白球，问能否使序列中所数字所代表的的所有球按照颜色进行回文串对称排列

//思路：要是回文串，那球的数量一定是四个偶数或者三个偶数一个奇数，另外可以想到，每一次三换一，都能使所有球的奇偶性反转，那么可以看出来 0,4 1,3 3,1 4,0 这些奇偶组合都可以，只要不是 2
//另外要注意如果 r，g，b 三种颜色如果有个球的数量为 0，那么他肯定不能进行交换，那么只能就当前的奇偶情况进行判断

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a[4];
		int cnt=0;
		bool f=0;
		for(int i=0;i<4;i++){
			scanf("%d",&a[i]);
			if(a[i]&1) cnt++;
			if(a[i]==0&&i<3) f=1;
		}
		if(f){
			if(cnt>1) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
			continue;
		}
		if(cnt==2) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;		
	}
	return 0;
}
