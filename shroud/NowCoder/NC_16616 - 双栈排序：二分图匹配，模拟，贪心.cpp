//题意：给出一个 1-n 的无序序列，问能否通过两个栈的进栈出栈操作使得该序列变得有序，且对于一号栈，入栈和出栈的操作序号为 'a' 和 'b' ，对于二号栈，入栈和出栈的操作序列为 'c' 和 'd'，使操作序列的字典序最小

//思路：可以用二分图匹配来做，但是暂时不会。先说明普通的贪心和模拟思想，要想达到字典序最小，那么肯定是在不冲突的情况下对一号栈操作，这个时候就要去思考冲突情况有哪些
//首先，如果一号栈空或者一号栈栈顶元素小于当前要入栈元素时可以考虑入栈，但是在某些情况下，可能将当前元素放到一号栈导致后期冲突的情况，如果把他换一下放在二号栈可能能避免，
//例如数据：10 2 8 1 7 9 3 4 5 6
//如果把 7 放在一号栈，那么当前两个栈顶元素分别是 7 和 8，9 显然不能入栈，7 和 8 由于不是最小元素也不能在之前出栈，所以我们可以做一个判断：
//如果当前要入栈元素符合条件且他不会影响后续，导致冲突就可以入一号栈，判断只需要看当前入一号栈的元素有没有既比它大又比它小的即可
//一号栈的条件判断完成，那么整体的思路就差不多了，根据字典序的顺序进行下去，判断能否进行当前操作，如果所有操作都做不了，但次数没达到 2*n 次，那么就说明无法完成双栈排序，反之用数组保存记录结果

#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
#define pb push_back
int a[maxn];
int n;
vector<char> ans;
stack<int> s1,s2;
bool f;

bool check(int pos){
	if(s2.empty()) return true;
	int i;
	for(i=pos+1;i<=n;i++) if(a[i]>a[pos]&&a[i]>s2.top()) break;
	for(int j=i+1;j<=n;j++) if(a[j]<a[pos]) return false;
	return true;
}

int main(){
	int now=1,cnt=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=2*n;i++){
		f=0;
		if((s1.empty()||s1.top()>a[cnt])&&cnt<=n&&check(cnt)){
			ans.pb('a');
			f=1;
			s1.push(a[cnt]);
			cnt++;
		}
		else if(!s1.empty()&&s1.top()==now){
			s1.pop();
			ans.pb('b');
			f=1;
			now++;
		}
		else if((s2.empty()||s2.top()>a[cnt])&&cnt<=n){
			ans.pb('c');
			f=1;
			s2.push(a[cnt]);
			cnt++;
		}
		else if(!s2.empty()&&s2.top()==now){
			s2.pop();
			ans.pb('d');
			f=1;
			now++;
		}
		if(!f){
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<ans[0];
	for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}
