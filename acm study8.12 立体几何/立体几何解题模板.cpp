//立体几何 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const double eps = 1e-8;
int sgn(double x){
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
    else return 1;
}
struct point{
    double x,y,z;
    point(){};
    point(double _x,double _y,double _z){
        x=_x;
        y=_y;
        z=_z;
    }
    void input(){
        scanf("%lf%lf%lf",&x,&y,&z);
    }
    void output(){
        printf("%.2lf %.2lf %.2lf\n",x,y,z);
    }
    bool operator == (const point &b)const{
        return sgn(x-b.x)==0&&sgn(y-b.y)==0&&sgn(z-b.z)==0;
    }
    bool operator <(const point &b)const{
        return sgn(x-b.x)==0?(sgn(y-b.y)==0?sgn(z-b.z)<0:y<b.y):x<b.x;
    }
    double len(){
        return sqrt(x*x+y*y+z*z);
    }
    double len2(){
        return x*x+y*y+z*z;
    }
    double distance (const point &b)const{
        return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y)+(z-b.z)*(z-b.z));
    }
    point operator - (const point &b)const{
        return point (x-b.x,y-b.y,z-b.z);
    }
    point operator + (const point &b)const{
        return point (x+b.x,y+b.y,z+b.z);
    }
    point operator * (const double &b)const{
        return point (x*b,y*b,z*b);
    }
    point operator / (const double &b)const{
        return point (x/b,y/b,z/b);
    }
    double operator * (const point &b)const{
        return x*b.x+y*b.y+z*b.z;
    }
    point operator ^ (const point &b)const{
        return point (y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
    }
    double rad(point a,point b){
        point p = (*this);
        return acos(((a-p)*(b-p))/(a.distance(p)*b.distance(p)));
    }
    //变换长度
    point trunc(double r){
        double l=len();
        if(!sgn(l))return *this;
        r/=l;
        return point(x*r,y*r,z*r);
    }

};
struct line{
    point s,e;
    line(){};
    line(point _s,point _e){
        s=_s,e=_e;
    }
    bool operator  == (const line v){
        return (s==v.s)&&(e==v.e);
    }
    void input(){
        s.input();
        e.input();
    }
    double length(){
        return s.distance(e);
    }
    //点到直线的距离
    double dist_point_to_line(point p){
        return ((e-s)^(p-s)).len()/s.distance(e);
    }
    double dist_point_to_seg(point p){
        if(sgn((p-s)*(e-s))<0||sgn((p-e)*(s-e))<0)
        return min(p.distance(s),p.distance(e));
        return dist_point_to_line(p);
    }
    //返回点 p 在直线上的投影
    point line_prog(point p){
        return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
    }
    //p 绕此向量逆时针 arg 角度
    point ratate(point p,double ang){
        if(sgn(((s-p)^(e-p)).len()) == 0)return p;
        point f1 = (e-s)^(p-s);
        point f2 = (e-s)^(f1);
        double len = ((s-p)^(e-p)).len()/s.distance(e);
        f1 = f1.trunc(len);f2 = f2.trunc(len);
        point h = p+f2;
        point pp = h+f1;
        return h+((p-h)*cos(ang))+((pp-h)*sin(ang));
    }
    //点在直线上
    bool point_on_seg(point p){
        return sgn(((s-p)^(e-p)).len())==0 &&sgn((s-p)*(e-p))==0;
    }
};
struct plane{
    point a,b,c,o;//o表示的是法向量
    plane(){};
    point pvec(){
        return (b-a)^(c-a);
    }
    plane(point _a,point _b,point _c){
        a=_a;
        b=_b;
        c=_c;
        o= pvec();
    }
    //ax+by+cz+d=0;
    plane(double _a,double _b,double _c,double _d){
        o=point(_a,_b,_c);
        if(sgn(_a)!=0)
        a=point((-_d-_c-_b)/_a,1,1);
        else if(sgn(_b)!=0){
            a=point (1,(-_d-_c-_a)/_b,1);
        }
        else if(sgn(_c)!=0){
            a= point (1,1,(-_d-_a-_b)/_c);
        }
    }
    //点在平面上的判断
    bool pointonplane(point p){
        return sgn((p-a)*o) == 0;
    }
    //两平面夹角
    double angleplane(plane f){
        return acos(o*f.o)/(o.len()*f.o.len());
    }
    //平面和直线的交点，返回交点个数
    int cross_line(line u,point &p){
        double x = o*(u.e-a);
        double y = o*(u.s-a);
        double d = x-y;
        if(sgn(d)==0)return 0;
        p=((u.s*x)-(u.e*y))/d;
        return 1;
    }
    //点到平面的最近点（即投影）
    point point_to_plane(point p){
         line u=line(p,p+o);
         cross_line(u,p);
         return p;
    }
    //平面和平面的交线
    int cross_plane(plane f,line &u){
        point oo=o^f.o;
        point v = o^oo;
        double d = fabs(f.o*v);
        if(sgn(d)==0)return 0;
        point q= a+(v*(f.o*(f.a-a))/d);
        u=line(q,q+oo);
        return 1;
    }
};
int main()
{
    printf("板子\n");
    return 0;
}
