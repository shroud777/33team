//题意：题目中包含 4 中查询，题目数据要求自己生成
//1 l r x ：将[l,r]区间所有数加上x
//2 l r x ：将[l,r]区间所有数改成x
//3 l r x ：输出将[l,r]区间从小到大排序后的第 x 个数是的多少(即区间第 x 小)
//4 l r x y ：输出[l,r]区间每个数字的 x 次方的和模 y 的值

//珂朵莉模板

//https://github.com/shroud777/33team/blob/patch-2/shroud/%E6%80%9D%E8%80%83%E6%80%BB%E7%BB%93/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%8F%82%E6%9C%B5%E8%8E%89%E6%A0%91/%E7%8F%82%E6%9C%B5%E8%8E%89%E6%A0%91.md

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define IT set<node> ::iterator

const int p=1e9+7;
const int maxn=1e5+10;

int n,m;
ll seed,vmax;

int a[maxn];

//珂朵莉树：是一种基于std::set的暴力数据结构
//关键操作：推平一段区间，使 [l,r] 区间都变成 x

struct node{
    int l,r;
    mutable ll v; //mutable 修饰代表不定的，使我们可以修改 v 的值，不加可能会出现 CE
    node(int L,int R=-1,ll V=0):l(L),r(R),v(V){}
    bool operator <(const node &o)const{
        return l<o.l;
    }
};

//结点存在 set 里
set<node> s;

ll qpow(ll a,ll b,ll mod){
    ll res=1;
    a%=mod;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

//spilt(pos) 代表将原来含有 pos 位置的结点分成 [l,pos-1] [pos,r] 两部分
//并且最后返回包含 pos 的那个区间（pos为左端点）

IT spilt(int pos){
    IT it=s.lower_bound(node(pos));
    if(it!=s.end()&&it->l==pos) return it;
    //如果 set 里找到左端点为 pos 的区间结点直接返回
    it--;
    int L=it->l,R=it->r;
    //[L,R] 为要分割的区间
    ll V=it->v;
    s.erase(it);
    s.insert(node(L,pos-1,V));
    return s.insert(node(pos,R,V)).first;
    //pair<iterator,bool> insert (const value_type& val)
    //返回值为迭代器
}

void assign(int l,int r,ll k){
    IT itr=spilt(r+1),itl=spilt(l);
    s.erase(itl,itr);
    //void erase (iterator first, iterator last)可删除[first,last)区间
    //这里就是把[l,r+1)内的部分推成一段。
    s.insert(node(l,r,k));
}

//区间加：分裂出来挨个加
void add(int l,int r,ll k){
    IT itr=spilt(r+1),itl=spilt(l);
    for(;itl!=itr;itl++) itl->v+=k;
}

//第 k 小，暴力排序取出来，对应的区间在 set 里没有多少个结点
ll kth(int l,int r,int k){
    IT itr=spilt(r+1),itl=spilt(l);
    vector<pair<ll,int> > v;
    for(;itl!=itr;itl++) v.push_back(pair<ll,int> (itl->v,itl->r-itl->l+1));
    sort(v.begin(),v.end());
    for(vector<pair<ll,int> > ::iterator it=v.begin();it!=v.end();it++){
        k-=it->second;
        if(k<=0) return it->first;
    }
    return -1;
}

//区间幂次和，暴力取出来快速幂累加即可
ll sum(int l,int r,ll k,ll mod){
    IT itr=spilt(r+1),itl=spilt(l);
    ll ans=0;
    for(;itl!=itr;itl++){
        ans=(ans+1ll*(itl->r-itl->l+1)*qpow(itl->v,k,mod))%mod;
    }
    return ans;
}

inline ll rnd(){
    ll res=seed;
    seed=(seed*7+13)%p;
    return res;
}

int main(){
    scanf("%d %d %lld %lld",&n,&m,&seed,&vmax);
    //根据输入插入结点
    for(int i=1;i<=n;i++) a[i]=(rnd()%vmax)+1,s.insert(node(i,i,a[i]));
    int op,l,r,x,y;
    for(int i=1;i<=m;i++){
        op=(rnd()%4)+1;
        l=(rnd()%n)+1;
        r=(rnd()%n)+1;
        if(l>r) swap(l,r);
        if(op==3) x=(rnd()%(r-l+1))+1;
        else x=(rnd()%vmax)+1;
        if(op==4) y=(rnd()%vmax)+1;
        if(op==1) add(l,r,x);
        else if(op==2) assign(l,r,x);
        else if(op==3) printf("%lld\n",kth(l,r,x));
        else printf("%lld\n",sum(l,r,x,y));
    } 
    return 0;
}
/*
10 10
8 9 7 2 3 1 5 6 4 8
2 6 7 9
1 3 10 8
4 4 6 2 4
1 4 5 8
2 1 7 1
4 7 9 4 4 
1 2 7 9
4 5 8 1 1 
2 5 7 5 
4 3 10 8 5
*/
