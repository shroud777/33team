//题意：要求构造两个包含 a 个 0，b 个 1 的不包含前导零的 01 串，使他们的差正好为 k 个 1

//思路：这题的构造还是比较难的，片面的做法很容易想到，但是完备的做法还是不算很好想的
//根据官方题解，我们构造一个 b 个连续的 1 作为前缀，剩余 0 作为后缀的 01 串，形如 1111.....0000
//然后这作为我们的第一个 01 串，我们复制它的形状构造第二个字符串
//并且我们把连续的前缀 1 的最后一位向后移动 min(k,a) 位，这样我们可以得到 min(k,a) 个 1 作为答案
//如果还不够，我们显然可以把剩余的连续前缀 1 中的最后一位向后移动一位，可以发现答案会多 1 个 1，以此类推
//由于 01 串中不能包含前导零，我们可以发现答案就是最多只能有 a+b-2 个 1，并且要排除没有 0 和只有 1 个 1 的情况，这种情况下无法正常构造

#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e5+10;

int a,b,k;

//a 个 0，b 个 1

void print1(int x){
    for(int i=1;i<=x;i++) printf("1");
}

void print0(int x){
    for(int i=1;i<=x;i++) printf("0");
}

int main(){
    cin>>a>>b>>k;
    if(k==0){
        puts("Yes");
        print1(b);print0(a);puts("");
        print1(b);print0(a);
        return 0;
    }
    if(a<1||b<2||k>a+b-2){
        puts("No");
        return 0;
    }
    puts("Yes");
    print1(b);print0(a);puts("");
    if(k<=a){
        print1(b-1);print0(k);print1(1);print0(a-k);
        return 0;
    }
    print1(b-k+a-1);print0(1);print1(k-a);print0(a-1);print1(1);
    return 0;
}
