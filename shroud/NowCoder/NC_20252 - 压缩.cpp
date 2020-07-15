//给一个字符串，对其进行压缩，对于每个重复串，例如abab可以压缩为MabR对于每个重复串，例如abab可以压缩为MabR
//R表示重复到上一个M中间所有的解压后内容R表示重复到上一个M中间所有的解压后内容，求压缩后的最短长度求压缩后的最短长度

//思路：有点难，区间DP，dp[l][r] 记录区间[l,r]能被压缩的最小长度，由于他还会受 M 的影响限制，如果单纯的 min(dp[l][r],dp[l][k]+dp[k+r][r])，显然是错的。
//如果发现[l,r]区间中出现重复了，但是区间之前已经使用过 M ，就会导致不能在最后加R重复整个区间，所以就需要再加一维表示区间是否存在M所以就需要再加一维表示区间是否存在 M
//dp[l][r][1/0]区间[l,r]存在/不存在 M 的最短长度dp[l][r][1/0]区间[l,r]存在/不存在M的最短长度，那么就可以用不存在M的情况进行找重复
//在长度为偶数的情况下,如果区间的前半段和后半段相等     dp[l][r][0]=dp[l][(l+r)/2][0]+1      就是前半段的最短长度加个R就是前半段的最短长度加个R
//如果不存在相等的情况下的转移，就是前半段的最短长度加后半段长度,因为前半段R如果前面没有M，就是重复前面的所有字符串，那么前半段可以暂时先不加M
//但是后半段如果dp是压缩后长度，这种情况两段中间就应该有一个M，但是由于是0的情况，不存在M，所以就不能这样转移
//正确转移方程应该是    dp[l][r][0]=dp[l][k][0] +r-k
//对于存在M的情况，直接模拟M的位置就行了,因为存在M，分成的两段都可以保证取到压缩后的长度
//所以转移方程为所以转移方程为
//dp[l][r][1]=min(dp[l][r][1], min(dp[l][k][1],dp[l][k][0])+1+min(dp[k+1][r][0],dp[k+1][r][1]))
//最后答案取dp[1][n][0/1]的最小值即可

#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int dp[110][110][2];
string s;
bool check(int i,int j){
	if((j-i+1)%2!=0) return false;
	int mid=i+j>>1;
	j=mid+1;
	while(i<=mid){
		if(s[i]!=s[j]) return false;
		i++;j++;
	}
	return true;
}
int main(){
	cin>>s;
	int sz=s.size();
	s='#'+s;
	for(int len=1;len<=sz;len++){
		for(int i=1;i+len-1<=sz;i++){
			int j=i+len-1;
			dp[i][j][0]=dp[i][j][1]=len;
			for(int k=i;k<=j;k++) 
				dp[i][j][0]=min(dp[i][j][0],dp[i][k][0]+j-k);
			if(check(i,j)) dp[i][j][0]=min(dp[i][j][0],dp[i][(i+j)/2][0]+1);
			for(int k=i;k<=j;k++)
				dp[i][j][1]=min(dp[i][j][1],min(dp[i][k][0],dp[i][k][1])+1+min(dp[k+1][j][0],dp[k+1][j][1]));
		}
	}
	cout<<min(dp[1][sz][0],dp[1][sz][1])<<endl;
}
