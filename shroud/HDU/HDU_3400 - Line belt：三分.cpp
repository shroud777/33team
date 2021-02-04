//题意：现在在二维平面上有 AB 和 CD 两条线段，并且在这两条线段上的运动速度分别为 p，q，在二维平面其他地方的运动速度为 r，现在求 A 点运动到 D 点的最短时间

//思路：题目并没有说明一定要从 A 到 B 再到 C 再到 D 这样的，而是根据速度，决定怎么走，但是模型都是在 A 上走到 (x1,y1)，然后再直接走直线到 CD 上的 (x2,y2) 然后再走到 D
//假如固定 (x1,y1) 点，那么最短时间与 (x2,y2) 与 D 的距离应该是一个凹函数，这里我们可以用三分求解最优解，那么对于 (x1,y1) 一开始想到枚举，但是显然枚举小数有点夸张
//我们这里依旧使用三分，所以总体来说就是三分套三分，外层三分求 (x1,y1) 的位置，内层三分求确定了 (x1,y1) 后 (x2,y2) 的位置
//注意细节

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=5e5+10;
const double eps=1e-7;

int ax,ay,bx,by,cx,cy,dx,dy;
int p,q,r;
double ab,cd;
double x1,y1,x2,y2;

inline double dist(double x1,double y1,double x2,double y2){
    return sqrt(1.0*(x1-x2)*(x1-x2)+1.0*(y1-y2)*(y1-y2)+eps);
}

double check(double x){
    x2=dx-x*(dx-cx)/cd;
    y2=dy-x*(dy-cy)/cd;
    double d1=dist(x1,y1,x2,y2);
    double d2=dist(dx,dy,x2,y2);
    return d1/r+d2/q;
}

double f(double x){
    x1=ax-x*(ax-bx)/ab;
    y1=ay-x*(ay-by)/ab;
    double l=0,r=cd,lmid,rmid;
    while(abs(r-l)>eps){
        lmid=(l+r)/2;
        rmid=(lmid+r)/2;
        double f1=check(lmid),f2=check(rmid);
        if(f1<f2) r=rmid;
        else l=lmid;
    }
    return dist(ax,ay,x1,y1)/p+check(l);
}

double solve(){
    double l=0,r=ab,lmid,rmid;
    while(abs(r-l)>eps){
        lmid=(l+r)/2;
        rmid=(lmid+r)/2;
        double f1=f(lmid),f2=f(rmid);
        if(f1<f2) r=rmid;
        else l=lmid;  
    }
    return f(l);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
        cin>>p>>q>>r;
        ab=dist(ax,ay,bx,by);
        cd=dist(cx,cy,dx,dy);
        printf("%.2f\n",solve());
    }
    return 0;
}
