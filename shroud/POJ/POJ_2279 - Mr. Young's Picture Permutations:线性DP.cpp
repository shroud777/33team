//题意：在 n 行（每行的长度给出，且前面的行长度大于等于下面的行），在每个行列上放置一个数，使得当前数大于该行左边所有的数和该列上面所有的数
//题意有点难概括，直接看链接把： http://poj.org/problem?id=2279

//思路：线性 DP，可以讲放数字的过程看成一个从左往右，从上往下的过程，同时行数上限是 5，我们可以用五维数组来代表每一行放置数字的情况
//状态转移方程 dp[s1][s2][s3][s4][s5]+=dp[s1-1][s2][s3][s4][s5] 第一行为例，其他行同理

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=35;
int n;
int a[10];
unsigned int dp[maxn][maxn/2+1][maxn/3+1][maxn/4+1][maxn/5+1];

int main(){
	while(cin>>n,n){
		memset(dp,0,sizeof dp);
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		dp[0][0][0][0][0]=1;
		for(int s1=1;s1<=a[1];s1++){
			for(int s2=0;s2<=min(s1,a[2]);s2++){
				for(int s3=0;s3<=min(s2,a[3]);s3++){
					for(int s4=0;s4<=min(s3,a[4]);s4++){
						for(int s5=0;s5<=min(s4,a[5]);s5++){
							unsigned int &temp=dp[s1][s2][s3][s4][s5];
							if(s1-1>=s2)temp+=dp[s1-1][s2][s3][s4][s5];
							if(s2-1>=s3) temp+=dp[s1][s2-1][s3][s4][s5];
							if(s3-1>=s4) temp+=dp[s1][s2][s3-1][s4][s5];
							if(s4-1>=s5) temp+=dp[s1][s2][s3][s4-1][s5];
							if(s5) temp+=dp[s1][s2][s3][s4][s5-1]; 
						}
					}
				}
			}
		}
		cout<<dp[a[1]][a[2]][a[3]][a[4]][a[5]]<<endl;
	}
	
	return 0;
}
