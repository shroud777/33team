//题意：判断给出实数 A 和 B 是否相等

//思路：考虑排除前导零后导零，符号，小数点带来的影响
//1.得到除前导零前缀，根据上面的筛选条件，前缀代表整部部分，所以两个前缀必须一模一样
//2.前缀部分相同说明整数部分相同，接下来判断后半部分
//3.小数点成了第一个难点，因为有小数点和没小数不能成为判断两个数是否相等的依据
//4.那么如果我们分情况讨论，那么代码量和难度必然会增加很多
//5.这里我们想到前导零和小数点后后导零的相似性，我们可以反转字符串，忽视后导零
//6.并且没有小数点就可以直接用空字符串来代替
//7.比如 1 和 1.00000 
//8.第一个数由于没有小数点，直接得到空的字符串 
//9.第二个数有小数点，但是翻转后变成 00000.1 直接忽视所有前导零 

#include <iostream>
#include <algorithm>

using namespace std;

string get_prefix(string s){
	bool f=0;
	string res;
	for(int i=0;i<s.size();i++){
		if(s[i]=='.') return res; 		      //截取小数点之前的除前导零前缀 
		if(!f&&s[i]!='0'&&s[i]!='-') f=1;  //如果有 1~9 的数字出现，那么前导零就不会再出现了
		if(f) res+=s[i];   				         //前导零不出现之后，数字就可以直接加入到前缀中
										                  //c++ string 用起来和 java 差不多，可以直接 s1+=s2; or s1=s1+s2;
	}
	return res;
}

bool check(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='.') return true;
	}
	return false;
}

int main(){
	string s1,s2,t1,t2;
	while(cin>>s1>>s2){
		if((s1[0]=='-'&&s2[0]!='-')||(s1[0]!='-'&&s2[0]=='-')){     //首先判断符号，放在最开始判断比较方便 
			puts("NO");continue;
		}
		if(get_prefix(s1)!=get_prefix(s2)){						     // 1 
			puts("NO");continue;
		}  															 
																	//2~9
		if(check(s1)) reverse(s1.begin(),s1.end()),t1=get_prefix(s1); //reverse 函数，更多细节可以百度，这里就是翻转整个字符串 
		if(check(s2)) reverse(s2.begin(),s2.end()),t2=get_prefix(s2);
		if(t1!=t2){
			puts("NO");continue;
		}
		puts("YES");
	}
	return 0;
}
