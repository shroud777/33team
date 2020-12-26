//题意：给出一个由 'L','R','U','D' 组成的字符串序列，现在有个机器人在一个二维坐标上，初始在 (0,0) 位置，他将根据给出字符串执行相应操作，x-1,x+1,y+1,y-1
//现在你可以在坐标任何位置放置一个障碍，使得机器人如果下一步要走到障碍物位置，他就会取消操作并原地不动，请输出一个障碍物位置使得机器人根据序列运行与规避规则最终走到 (0,0) 位置

//思路：首先只有挡住机器人的路线，才能使他改变一定的路线，回到初始位置，那么这个障碍物一定是在机器人运行的路线上的，然后我们只要枚举障碍物出现的位置，然后每次走一遍模拟判断即可
//复杂度 O(n^2)，可以用一些技巧优化代码和剪枝降低一些复杂度

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int maxn=5e5+10;
 
char s[maxn];
int dx[255],dy[255];
 
int main(){
	dx['L']=-1;
	dx['R']=1;
	dy['U']=1;
	dy['D']=-1;
	int t;
	cin>>t;
	while(t--){
		scanf("%s",s);
		int len=strlen(s); 
		int sx=0,sy=0;
		bool f=0;
		for(int i=0;i<len;i++){
			sx+=dx[s[i]];
			sy+=dy[s[i]];
			if(sx==0&&sy==0) continue;
			int x=0,y=0;
			for(int j=0;j<len;j++){
				x+=dx[s[j]];
				y+=dy[s[j]];
				if(x==sx&&y==sy){
					x-=dx[s[j]];
					y-=dy[s[j]];
				}
			}
			if(x==0&&y==0){
				f=1;
				printf("%d %d\n",sx,sy);
				break;
			}
		}
		if(!f) printf("0 0\n");
	}
	return 0;
}
