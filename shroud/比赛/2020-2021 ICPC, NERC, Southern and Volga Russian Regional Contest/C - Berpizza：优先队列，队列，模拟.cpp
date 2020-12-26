//题意：在一家披萨店，有若干名客人将要来排队就餐，员工 A 和 B 对于等待人群有不同的选择方案来决定先服务谁，员工 A 根据顾客到店的时间（先入店的），员工 B 根据顾客要消费的金额（消费多的），现在有 m 种操作执行，共有三种操作类型
//1 m：代表有一名消费金额为 m 的顾客来排队就餐
//2：代表员工 A 来选择当前的服务对象
//3：代表员工 B 来选择当前的服务对象
//每个客人来排队只能被服务一次，请输出最后的服务顺序名单

//思路：用一个队列和一个优先队列分别维护 2 3 两种操作，并且用一个数组维护已经访问过的客户对象，这样我们每次在某个数据结构中得到当前服务对象时，就不必在另一个数据结构中删除该对象了，只要判断当前有没有访问过即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int maxn=5e5+10;
 
int vis[maxn];
struct node{
	int id,sp;
	node(int a,int b){
		id=a,sp=b;
	}
	bool operator <(const node &oth)const{
		if(sp==oth.sp) return id>oth.id;
		return sp<oth.sp;
	}
};
 
 
priority_queue<node> pq;
queue<int> q;
 
int main(){
	int m,x,op,tot=0;
	cin>>m;
	while(m--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&x);
			pq.push(node(++tot,x));
			q.push(tot);
		}
		else if(op==2){
			x=q.front();
			while(vis[x]) q.pop(),x=q.front();
			printf("%d ",x);
			vis[x]=1;
		    q.pop();
		}
		else if(op==3){
			x=pq.top().id;
			while(vis[x]) pq.pop(),x=pq.top().id;
			printf("%d ",x);
			vis[x]=1;
			pq.pop();
		}
	}
	return 0;
}
