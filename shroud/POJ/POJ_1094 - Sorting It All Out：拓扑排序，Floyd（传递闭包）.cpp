//题意：对于前 n 个大写字母，给出 m 组他们之间的两两关系，问能否确定所有 n 个字母的关系，或是否存在冲突

//思路：1.拓扑排序
//对于 n 个大写字母，可以看成 n 个点，他们之间的关系，可以看做一条有向边，并且存在三种情况：
//首先拓扑排序结束后仍有点没有入队，说明图中存在环导致某个点无法入队，这也说明关系冲突
//然后如果拓扑排序正常进行，但过程中出现队列元素不止一个的情况，说明某两个点之间的相互关系还未确定，关系不完善
//最后满足上述两种情况，所有点的关系已经确定
//
//2.FLoyd 传递闭包
// g[i][j] = 1 代表 j 比 i 大的情况，判定只需要找任意 g[i][j] 和 g[j][i] 相等的，若等于 0 说明关系不完善，都等于 1 说明相冲突了


//做法 1：
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e3+10;

int n,m;
vector<int> g[35];
string s;
int deg[35],d[35];
string ans;

int topsort(){
	ans.clear();
	memcpy(d,deg,sizeof deg);
	queue<int> q;
	bool f=1;
	int cnt=0;
	for(int i=1;i<=n;i++) if(d[i]==0) q.push(i);
	while(!q.empty()){
		if(q.size()>1) f=0;
		int u=q.front();
		ans=char(u+'A'-1)+ans;
		q.pop();
		cnt++;
		for(int i=0;i<g[u].size();i++){
			int j=g[u][i];
			d[j]--;
			if(d[j]==0) q.push(j); 
		}
	}
	if(cnt==n){
		if(f) return 1;
		return 2;
	}
	return 3;
}

int main(){
	while(cin>>n>>m){
		if(n==0&&m==0) return 0;
		for(int i=0;i<=n;i++){
			g[i].clear();	
			deg[i]=0;
		}
		int u,v,f=2,xb;
		for(int i=1;i<=m;i++){
			cin>>s;
			if(f==1||f==3) continue;
			u=s[2]-'A'+1;
			v=s[0]-'A'+1;
			deg[v]++;
			g[u].push_back(v);
			f=topsort();
			if(f==1||f==3) xb=i;
		}
		if(f==1) cout<<"Sorted sequence determined after "<<xb<<" relations: "<<ans<<"."<<endl;
		else if(f==2) cout<<"Sorted sequence cannot be determined."<<endl;
		else if(f==3) cout<<"Inconsistency found after "<<xb<<" relations."<<endl;
	}
	
	return 0;
}

//做法 2：
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1005;

int n,m;
int g[maxn][maxn];
struct node{
	int id,cnt;
};
bool cmp(node x,node y){
	return x.cnt<y.cnt;
}


void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) g[i][j]|=g[i][k]&g[k][j];
		}
	}
}
//1 关系完善
//2 关系不足 
//3 关系冲突 

int check(){
	bool f=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(g[i][j]==g[j][i]){
				if(g[i][j]==0) f=0;
				else return 3;
			}
		}
	}
	if(f) return 1;
	return 2;
}


string s;
int main(){
	while(cin>>n>>m,n+m){
		memset(g,0,sizeof g);
		node a[n+5];
		for(int i=1;i<=n;i++) a[i].id=i,a[i].cnt=0;
		int xb;
		int temp=2;
		for(int i=1;i<=m;i++){
			cin>>s;
			if(temp==1||temp==3) continue;
			int u=s[0]-'A'+1;
			int v=s[2]-'A'+1; 
			g[u][v]=1;
			floyd();
			temp=check();
			if(temp==1||temp==3) xb=i;
		}
		if(temp==3) printf("Inconsistency found after %d relations.\n",xb);
		else if(temp==2) printf("Sorted sequence cannot be determined.\n");
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					if(g[i][j]==1) a[j].cnt++;
				}
			}
			sort(a+1,a+n+1,cmp);
			cout<<"Sorted sequence determined after "<<xb<<" relations: ";
			for(int i=1;i<=n;i++) cout<<(char)(a[i].id+'A'-1);
			cout<<"."<<endl;
		}
	} 
	return 0;
}
