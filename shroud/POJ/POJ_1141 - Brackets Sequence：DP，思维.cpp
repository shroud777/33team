//题意：给出一个只包含 '(' ')' '[' ']' 的序列 s，求以 s 为子序列的长度最短的合法括号序列

//思路：初始化 dp(i,i)=1,单个括号肯定需要补齐
//dp(i,j) 表示字符串左端从 i 下标起到右段 j 这段子串所需要增加的最少括号
//dp(i,j) = dp(i+1,j-1) (i==j)
//dp(i,j) = min(dp(i,k),dp(k+1,j)) (i!=j) 寻找最优决策点，区间dp思想 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn=105;
int dp[maxn][maxn],ans[maxn][maxn];
string s;

void print(int i,int j){
	//cout<<i<<" "<<j<<" "<<ans[i][j]<<endl;
	if(i>j) return;
	if(i==j){
		if(s[i]=='['||s[i]==']') printf("[]");
		else printf("()");
	}
	else if(ans[i][j]==-1){
		printf("%c",s[i]);
		print(i+1,j-1);
		printf("%c",s[j]); 
	}
	else{
		print(i,ans[i][j]);
		print(ans[i][j]+1,j);
	}
}


int main(){
	while(getline(cin,s)){
		int len=s.length();
		if(len==0){
			printf("\n");
			continue;
		}
		memset(dp,0,sizeof dp);
		for(int i=0;i<len;i++) dp[i][i]=1;
		for(int l=1;l<len;l++){
			for(int i=0;i+l<len;i++){
				int j=i+l;
				dp[i][j]=INF;
				if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']')){
					dp[i][j]=dp[i+1][j-1];
					ans[i][j]=-1;
				}
				for(int k=i;k<j;k++){
					if(dp[i][j]>dp[i][k]+dp[k+1][j]){
						dp[i][j]=dp[i][k]+dp[k+1][j];
						ans[i][j]=k;
					}
				}
			}
		}
		print(0,len-1);
		printf("\n");
	}
	return 0;
}
