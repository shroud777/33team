//题意：给定一个长度为 n 的序列，对于序列中的任意两个元素 ai=x，aj=y（1≤i,j≤n），可以进行下列操作， ai=x AND y , aj=x OR y ，AND 和 OR 即按位与 和 按位或，最后求序列 n 个元素的最大平方和

//思路：首先我们思考上述操作，每次操作两个数前后的二进制数中 1 的总数是不会变的，那么也就是说他们前后两个数的和也是不变的即 （ai + aj）的值恒不变，那这个操作变的是啥呢？
//我们知道按位与是两个二进制数位上都是 1 才会得到 1，那么 ai 作为 AND 的结果，肯定会比之前的 ai 小或者不变，aj 则变大，这一操作即把二进制中的 1 往 aj 里聚集
//如果之前的进制数中两个数同一位置只有 1 个 1，那么只会集中到 aj，如果有 2 个才会把多的那个分到 ai，这样一看这一操作就会使 ai 和 aj 的和不变，差值变大或不变
//那么差值的变化对于两数的平方和有何影响内，事实上会变大，证明如下： （a+n）^2+(a-n)^2 = 2*a^2+2*n^2 > 2*a^2
//这样一看这题就很明显了，我们尽量让每个数两两进行上述操作，把这些有限个数的二进制 1 都集中到 1 个或尽量少的数身上去
//那么我们只要统计二进制权值位上的个数，然后贪心的每次尽可能的多取二进制权值上的数，这个化整为零的过程即尽可能构造一个更大的数
//具体来说我们每次可以取最小次数且不为零的权值位，设它有 n 个，然后以此为标准选上其他所有不为零的权值，然后把他们的数量都减去 n，那么我们答案就加上了 n 个以上二进制权值位上有值的数的平方和。
//代码写的比较清楚，还有这题 踏马的 unsigned long long 就可以了，我偏偏自己写了个 int128，草他妈的

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int cnt[25];
inline int lowbit(__int128 x){
	return x & (-x);
}

void get(__int128 x){
	int base=0;
	while(x){
		if(x&1) cnt[base]++;
		base++;
		x>>=1;
	}
}

inline __int128 read(){
	__int128 x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x*10)+c-'0';
		c=getchar();
	}
	return x*f;
}

inline void write(__int128 x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int main(){
	cout<<sizeof(__int128)<<endl;
	int n;
	cin>>n;
	__int128 num;
	while(n--){
		num=read();
		get(num);
	}
	__int128 ans=0;
	while(1){
		__int128 mi=1e9;
		__int128 temp=0;
		for(int i=0;i<=20;i++){
			if(cnt[i]) mi=min(mi,(__int128)cnt[i]);
		}
		if(mi==1e9) break;
		for(int i=0;i<=20;i++){
			if(cnt[i]){
				cnt[i]-=mi;
				temp+=(1<<i);
			}
		}
		temp*=temp;
		ans+=temp*mi;
	}
	write(ans);
	cout<<endl;
	return 0;
}
