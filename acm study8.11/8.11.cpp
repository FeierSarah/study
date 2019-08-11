#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-8;
const double inf=1e20;
const double pi=acos(-1.0);
const int maxp=1010;
int sgn(double x){   //判断一个值 是否无限接近于0
	if(fabs(x)<eps)return 0;   //约等于0返回0；
	if(x<0)return -1;
	else return 1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y){
		x=_x;y=_y;
	}
	void input(){
		scanf("%lf%lf",&x,&y);
	}
	void output(){
		printf("%.2f %.2f\n",x,y);
	}
	bool operator == (Point b)const{
		return sgn(x-b.x)==0&&sgn(y-b.y)==0;
	}
	bool operator < (Point b)const{
		return sgn(x-b.x)==0?sgn(y-b.y)<0:x<b.x;
	}
	//叉乘 （主要是向量之间）
	double operator ^ (const Point &b)const{
		return x*b.y-y*b.x;//返回模长 带正负
	}
	//点乘
	double operator * (const Point &b)const{
		return x*b.x+y*b.y;
	}
	//返回长度
	double len(){
		return hypot(x,y);  //返回值相当于sqrt(x*x+y*y);
	}
	//返回长度的平方
	double len2(){
		return x*x+y*y;
	}
	//返回两点的距离
	double distance (Point p){
		return hypot(x-p.x,y-p.y);
	}
	//向量的加减乘除
	Point operator + (const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
	Point operator - (const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	Point operator * (const double &b)const{
		return Point(x*b,y*b);
	}
	Point operator / (const double &b)const{
		return Point(x/b,y/b);
	}
	//计算这个点到a点 和 b点所存在的夹角
	//就是从这个点看a,b两点之间夹角
	double rad(Point a,Point b){
		Point p= *this;
		//cout<<p.x<<" "<<p.y<<endl;
		return fabs(atan2(fabs((a-p)^(b-p)),(a-p)*(b-p)));
	}
	//化为长度为r的向量
	Point trunc(double r){
		double l=len();
		if(!sgn(l))return *this;   //避免除0
		r/=l;
		return Point(x*r,y*r);
	}
	//逆时针旋转90度
	Point rotleft(){
		return Point(-y,x);
	}
	//顺时针旋转90度
	Point rotright(){
		return Point(y,-x);
	}
	//绕着P点逆时针旋转angle
	Point rotate(Point p,double angle){
		Point v=(*this)-p;
		double c=cos(angle),s=sin(angle);
		return Point (p.x + v.x*c - v.y*s , p.y + v.x*s + v.y*c);
	}
};


struct Line{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e){
		s=_s;e=_e;
	}
	bool operator == (Line v){
		return (s==v.s)&&(e==v.e);
	}
	//根据一个点和一个倾斜角angle确定一条直线  0<=angle<pi
	Line(Point p,double angle){
		s=p;
		if(sgn(angle-pi/2)==0){
			e=(s+Point(0,1));
		}
		else{
			e=(s+Point(1,tan(angle)));
		}
	}
	//ax+by+c=0
	Line(double a,double b,double c){
		if(sgn(a)==0){
			s=Point(0,-c/b);
			e=Point(1,-c/b);
		}
		else if(sgn(b)==0){
			s=Point(-c/a,0);
			e=Point(-c/a,1);
		}
		else{
			s=Point(0,-c/b);
			e=Point(1,(-c-a)/b);
		}
	}
	void input(){
		s.input();
		e.input();
	}
	void adjust(){
		if(e<s)swap(s,e);
	}
	//求线段的长度
	double length(){
		return s.distance(e);
	}
	//返回直线倾斜角  0<=angle<pi
	double angle(){
		double k=atan2(e.y-s.y,e.x-s.x);
		if(sgn(k)<0)k+=pi;
		if(sgn(k-pi)==0)k-=pi;
		return k;
	}
	//点和直线的关系
	//1 在直线左侧
	//2 在直线右侧
	//3 在直线上
	int relation(Point p){
		int c=sgn((p-s)^(e-s));
		if(c<0)return 1;
		else if(c>0) return 2;
		else return 3;
	}
	//点在线段上的判断
	bool point_on_seg(Point p){
		return sgn((p-s)^(p-e))==0&&sgn((p-s)*(p-e))<=0;
	}
	//两向量平行（对应直线平行或重合）
	bool parallel(Line v){
		return sgn((e-s)^(v.e-v.s))==0;
	}
	//两线段相交判断
	//2 规范相交（两条线段恰好有一个不是端点的公共点）
	//1 非规范相交
	//0 不相交
	int seg_cross_seg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		int d3 = sgn((v.e-v.s)^(s-v.s));
		int d4 = sgn((v.e-v.s)^(e-v.s));
		if((d1^d2)==-2&&(d3^d4)==-2) return 2;
		return (d1==0 && sgn((v.s-s)*(v.s-e))<=0)||
			   (d2==0 && sgn((v.e-s)*(v.e-e))<=0)||
			   (d3==0 && sgn((s-v.s)*(s-v.e))<=0)||
			   (d4==0 && sgn((e-v.s)*(e-v.e))<=0);
	}
	//直线和线段相交判断
	//-*this line    -v seg
	//2 规范相交
	//1 非规范相交
	//0 不相交
	int line_cross_seg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		if((d1^d2) == -2)return 2;
		return (d1==0||d2==0);
	}
	//两直线的关系
	//0 平行
	//1 重合
	//2 相交
	int line_cross_line(Line v){
		if((*this).parallel(v))
		return v.relation(s)==3;
		return 2;
	}
	//求两直线的交点
	//要保证两直线不平行或重合
	Point cross_point(Line v){
		double a1 = (v.e-v.s)^(s-v.s);
		double a2 = (v.e-v.s)^(e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
	}
	//点到直线的距离
	double dis_point_to_line(Point p){
		return fabs((p-s)^(e-s))/length();
	}
	//点到线段的距离
	double dis_point_to_seg(Point p){
		if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0)
		return min(p.distance(s),p.distance(e));
		return dis_point_to_line(p);
	}
	//返回线段到线段上的距离
	//前提是两段线段不相交，如果相交距离为0；
	double dis_seg_to_seg(Line v){
		return min(min(dis_point_to_seg(v.s),dis_point_to_seg(v.e)),
		min(v.dis_point_to_seg(s),v.dis_point_to_seg(e)));
	}
	//返回点p在直线上的投影
	Point line_prog(Point p){
		return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
	}
	//返回点p关于直线的对称点
	Point symmetry_point(Point p){
		Point q=line_prog(p);
		return Point(2*q.x-p.x,2*q.y-p.y);
	}
};

struct circle{
	Point p;  //圆心
	double r;   //半径
	circle(){}
	circle(Point _p,double _r){
		p=_p;
		r=_r;
	}
	circle(double x,double y,double _r){
		p=Point(x,y);
		r=_r;
	}
	//三角形的外接圆
	//需要 Point 的 + / rotate() 以及 Line 的 cross_point();
	//利用两条边的中垂线得到圆心
	circle(Point a,Point b,Point c){
		Line u = Line((a+b)/2,((a+b)/2)+((b-a).rotleft()));
		Line v = Line((b+c)/2,((b+c)/2)+((c-b).rotleft()));
		p = u.cross_point(v);
		r = p.distance(a);
	}
	//三角形的内切圆
	//内切圆圆心是三条角平分线的交点
	//参数 bool t 没有作用 只是为了区别  外接圆
	circle(Point a,Point b,Point c,bool t){
		Line u,v;
		double m = atan2(b.y-a.y,b.x-a.x), n = atan2(c.y-a.y,c.x-a.x);
		u.s = a;
		u.e = u.s+Point(cos((n+m)/2),sin((n+m)/2));
		v.s = b;
		m = atan2(a.y-b.y,a.x-b.x) ,n = atan2(c.y-b.y,c.x-b.x);
		v.e = v.s + Point(cos((n+m)/2),sin((n+m)/2));
		p = u.cross_point(v);
		r = Line(a,b).dis_point_to_seg(p);
	}
	void input(){
		p.input();
		scanf("%lf",&r);
	}
	void output(){
		printf("%.2lf %.2lf %.2lf\n",p.x,p.y,r);
	}
	bool operator == (circle v){
		return (p==v.p)&&sgn(v.r-r)==0;
	}
	bool operator < (circle v)const{
		return ((p<v.p)||((p==v.p)&&sgn(r-v.r)<0));
	}
	double area(){
		return pi*r*r;
	}
	double circle_perimeter(){
		return 2*pi*r;
	}
	//点和圆的关系
	//0 圆外
	//1 圆上
	//2 圆内
	int relation_point(Point b){
		double dist=b.distance(p);
		if(sgn(dist - r)<0)return 2;
		else if (sgn(dist - r )==0) return 1;
		return 0;
	}
	//线段和圆的关系
	//比较的是  圆心到线段的距离和半径的关系
	int relation_seg(Line v){
		double dist = v.dis_point_to_seg(p);
		if(sgn(dist-r)<0)return 2;  //园内
		else if(sgn(dist - r)==0)return 1;// 圆上
		return 0;// 圆外
	}
	// 直线和圆的关系
	// 比较的是圆心到直线的距离和半径的关系
	int relation_line(Line v){
		double dist = v.dis_point_to_line(p);
		if(sgn(dist-r)<0)return 2;// 圆内
		else if(sgn(dist - r)==0 )return 1; //圆上
		return 0;//圆外
	}
	//两圆的关系
	//5 相离
	//4 外切
	//3 相交
	//2 内切
	//1 内含
	//需要用到  Point 的 distance
	int relation_circle(circle v){
		double d = p.distance(v.p);
		if(sgn(d-r-v.r)>0)return 5;
		if(sgn(d-r-v.r)==0)return 4;
		double l = fabs(r-v.r);
		if(sgn(d-r-v.r)<0&&sgn(d-l)>0)return 3;
		if(sgn(d-l)==0)return 2;
		if(sgn(d-l)<0)return 1;
	}
	//求两个圆的交点，0表示没有交点，1 表示一个交点   2表示两个交点
	// 需要  relation_circle
	int point_cross_circle(circle v,Point &p1,Point &p2){
		int rel = relation_circle(v);
		if(rel == 1||rel == 5)return 0;
		double d = p.distance(v.p);
		double l = (d*d+r*r-v.r*v.r)/(2*d);
		double h = sqrt(r*r-l*l);
		Point temp = p+(v.p-p).trunc(l);
		p1=temp + ((v.p-p).rotleft().trunc(h));
		p2=temp + ((v.p-p).rotright().trunc(h));
		if(rel == 2|| rel==4)
			return 1;
		return 2;
	}
	//求直线和圆的交点，返回交点个数
	int point_cross_line(Line v,Point &p1,Point &p2){
		if(!(*this).relation_line(v))return 0;
		Point  a = v.line_prog(p);
		double d = v.dis_point_to_line(p);
		d = sqrt(r*r-d*d);
		if(sgn(d)==0){
			p1=a;
			p2=a;
			return 1;
		}
		p1 = a + (v.e-v.s).trunc(d);
		p2 = a - (v.e-v.s).trunc(d);
		return 2;
	}
	//得到过a，b两点，半径为r1的两个圆
	int get_circle(Point a,Point b,double r1,circle &c1,circle &c2){
		circle x(a,r1),y(b,r1);
		int t=x.point_cross_circle(y,c1.p,c2.p);
		if(!t)return 0;
		c1.r=c2.r=r1;
		return t;
	}
	//得到直线与u相切，过点q,半径为r1的圆。
	int get_circle(Line u,Point q,double r1,circle &c1,circle &c2){
		double dis=u.dis_point_to_line(q);
		if(sgn(dis-r1*2)>0)return 0;
		if(sgn(dis)==0){
			c1.p=q+((u.e-u.s).rotleft().trunc(r1));
			c2.p=q+((u.e-u.s).rotright().trunc(r1));
			c1.r=c2.r=r1;
			return 2;
		}
		Line u1=Line((u.s+(u.e-u.s).rotleft().trunc(r1)),(u.e+(u.e-u.s).rotleft().trunc(r1)));
		Line u2=Line((u.s+(u.e-u.s).rotright().trunc(r1)),(u.e+(u.e-u.s).rotright().trunc(r1)));
		circle cc=circle(q,r1);
		Point p1,p2;
		if(!cc.point_cross_line(u1,p1,p2))cc.point_cross_line(u2,p1,p2);
		c1=circle(p1,r1);
		if(p1==p2){
			c2=c1;
			return 1;
		}
		c2=circle (p2,r1);
		return 2;
	}
	//同时与直线u,v相切，半径为r1的圆
	int get_circle(Line u,Line v,double r1,circle &c1,circle &c2,circle &c3,circle &c4){
		if(u.parallel(v))return 0;
		Line u1=Line(u.s+(u.e-u.s).rotleft().trunc(r1),u.e+(u.e-u.s).rotleft().trunc(r1));
		Line u2=Line(u.s+(u.e-u.s).rotright().trunc(r1),u.e+(u.e-u.s).rotright().trunc(r1));
		Line v1=Line(v.s+(v.e-v.s).rotleft().trunc(r1),v.e+(v.e-v.s).rotleft().trunc(r1));
		Line v2=Line(v.s+(v.e-v.s).rotright().trunc(r1),v.e+(v.e-v.s).rotright().trunc(r1));
		c1.r=c2.r=c3.r=c4.r=r1;
		c1.p=u1.cross_point(v1);
		c2.p=u1.cross_point(v2);
		c3.p=u2.cross_point(v1);
		c4.p=u2.cross_point(v2);
		return 4;
	}
	//同时与不相交的圆 cx，cy相切  ，半径为r1的圆
	int get_circle(circle cx,circle cy,double r1,circle &c1,circle &c2){
		circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
		int t=x.point_cross_circle(y,c1.p,c2.p);
		if(!t)return 0;
		c1.r=c2.r=r1;
		return t;
	}
	//过一点做圆的切线  （先判断点和圆的关系）
	int tangent_line(Point q,Line &u,Line &v){
		int x = relation_point(q);
		if(x==2)return 0;
		if(x==1){
			u=Line(q,q+(q-p).rotleft());
			v=u;
			return 1;
		}
		double d=p.distance(q);
		double l=r*r/d;
		double h=sqrt(r*r-l*l);
		u=Line(q,p+((q-p).trunc(l)+(q-p).rotleft().trunc(h)));
		v=Line(q,p+((q-p).trunc(l)+(q-p).rotright().trunc(h)));
		return 2;
	}
	//求两圆相交的面积
	double area_circle(circle v){
		int rel = relation_circle(v);
		if(rel>=4)return 0.0;
		if(rel<=2)return min(area(),v.area());
		double d=p.distance(v.p);
		double hf=(r+v.r+d)/2.0;
		double ss=2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
		double a1=acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
		a1=a1*r*r;
		double a2=acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
		a2=a2*v.r*v.r;
		return a1+a2-ss;
	}
	//求圆和三角形 pab 的相交的面积
	double area_triangle(Point a,Point b){
		if(sgn((p-a)^(p-b))==0)return 0.0;
		Point q[5];
		int len=0;
		q[len++]=a;
		Line l(a,b);
		Point p1,p2;
		if(point_cross_line(l,q[1],q[2])==2){
			if(sgn((a-q[1])*(b-q[1]))<0)q[len++]=q[1];
			if(sgn((a-q[2])*(b-q[2]))<0)q[len++]=q[2];
		}
		q[len++]=b;
		if(len==4&&sgn((q[0]-q[1])*(q[2]-q[1]))>0) swap(q[1],q[2]);
		double res = 0;
		for(int i=0;i<len-1;i++){
			if(relation_point(q[i])==0||relation_point(q[i+1])==0){
				double arg=p.rad(q[i],q[i+1]);
				res+=r*r*arg/2.0;
			}
			else{
				res+=fabs((q[i]-p)^(q[i+1]-p))/2.0;
			}
		}
		return res;
	}
};

struct polygon{
	int n;
	Point p[maxp];
	Line l[maxp];
	void input(int _n){
		n=_n;
		for(int i=0;i<n;i++){
			p[i].input();
		}
	}
	void add(Point q){
		p[n++]=q;
	}
	void get_line(){
		for(int i=0;i<n;i++){
			l[i]=Line(p[i],p[(i+1)%n]);
		}
	}
	struct cmp{
		Point p;
		cmp(const Point &p0){
			p=p0;
		}
		bool operator () (const Point &aa,const Point &bb){
			Point a=aa,b=bb;
			int d=sgn((a-p)^(b-p));
			if(d==0){
				return sgn(a.distance(p)-b.distance(p))<0;
			}
			return d>0;
		}
	};
	//进行极角排序
	//首先需要找到最左下角的点
	//需要重载号好  Point 的 < 操作符（min要用）
	void norm(){
		Point mi=p[0];
		for(int i=0;i<n;i++){
			mi=min(mi,p[i]);
		}
		sort(p,p+n,cmp(mi));
	}
	//得到凸包
	//得到凸包里面的点编号是  0~n-1 的
	//两种凸包的方法
	//注意如果有影响，要特判下所有点共点，或者共线的特殊情况
	void get_convex(polygon &convex){
		sort(p,p+n);
		convex.n=n;
		for(int i=0;i<min(n,2);i++){
			convex.p[i]=p[i];
		}
		if(convex.n==2&&(convex.p[0]==convex.p[1]))
		convex.n--;
		if(n<=2)return ;
		int &top=convex.n;
		top=1;
		for(int i=2;i<n;i++){
			while(top&&sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i]))<=0){
				top--;
			}
			convex.p[++top]=p[i];
		}
		int temp = top;
		convex.p[++top]=p[n-2];
		for(int i=n-3;i>=0;i--){
			while(top!=temp&&sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i]))<=0){
				top--;
			}
			convex.p[++top]=p[i];
		}
		if(convex.n==2&&(convex.p[0]==convex.p[1]))convex.n--;
		convex.norm();//原来得到的是顺时针的点，排序之后变为逆时针
	}
	//得到凸包的另一种方法
	void Graham(polygon &convex){
		norm();
		int &top=convex.n;
		top=0;
		if(n==1){
			top=1;
			convex.p[0]=p[0];
			return ;
		}
		if(n==2){
			top=2;
			convex.p[0]=p[0];
			convex.p[1]=p[1];
			if(convex.p[0]==convex.p[1])top--;
			return ;
		}
		convex.p[0]=p[0];
		convex.p[1]=p[1];
		top=2;
		for(int i=2;i<n;i++){
			while(top>1&&sgn((convex.p[top-1]-convex.p[top-2])^(p[i]-convex.p[top-2]))<=0)
			top--;
			convex.p[top++]=p[i];
		}
		if(convex.n==2&&(convex.p[0]==convex.p[1]))convex.n--;
	}
	//判断是不是凸的
	bool is_convex(){
		bool s[2];
		memset(s,false,sizeof(s));
		for(int i=0;i<n;i++){
			int j=(i+1)%n;
			int k=(j+1)%n;
			s[sgn((p[j]-p[i])^(p[k]-p[i]))+1]=true;
			if(s[0]&&s[2])return false;
		}
		return true;
	}
	//判断点和任意多边形的关系
	//3 在多边形的顶点上
	//2 在多边形的边上
	//1 在多边形内部
	//0 在多边形外部
	int relation_point(Point q){
		for(int i=0;i<n;i++){
			if(p[i]==q)return 3;
		}
		get_line();
		for(int i=0;i<n;i++){
			if(l[i].point_on_seg(q))return 2;
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			int j=(i+1)%n;
			int k=sgn((q-p[j])^(p[i]-p[j]));
			int u=sgn(p[i].y-q.y);
			int v=sgn(p[j].y-q.y);
			if(k>0&&u<0&&v>=0)cnt++;
			if(k<0&&u>=0&&v<0)cnt--;
		}
		return cnt!=0;
	}
	//直线 u 切割凸多边形左侧
	//注意直线方向
	void convexcnt(Line u,polygon &po){
		int &top=po.n;
		top=0;
		for(int i=0;i<n;i++){
			int d1=sgn((u.e-u.s)^(p[i]-u.s));
			int d2=sgn((u.e-u.s)^(p[(i+1)&n]-u.s));
			if(d1>=0)po.p[top++]=p[i];
			if(d1*d2<0){
				po.p[top++]=u.cross_point(Line(p[i],p[(i+1)%n]));
			}
		}
	}
	//得到周长
	double get_perimeter(){
		double sum=0;
		for(int i=0;i<n;i++){
			sum+=p[i].distance(p[(i+1)%n]);
		}
		return sum;
	}
	//得到面积
	double get_area(){
		double sum=0;
		for(int i=0;i<n;i++){
			sum+=(p[i]^p[(i+1)%n]);
		}
		return fabs(sum)/2;
	}
	// 得到方向
	// 1表示逆时针  0表示顺时针
	bool get_dir(){
		double sum=0;
		for(int i=0;i<n;i++){
			sum+=(p[i]^p[(i+1)%n]);
		}
		if(sgn(sum)>0)return 1;
		return 0;
	}
	//得到重心
	Point get_barycentre(){
		Point ret(0,0);
		double area=0;
		for(int i=1;i<n-1;i++){
			double temp=(p[i]-p[0])^(p[i+1]-p[0]);
			if(sgn(temp)==0) continue;
			area+=temp;
			ret.x+=(p[0].x+p[i].x+p[i+1].x)/3*temp;
			ret.y+=(p[0].y+p[i].y+p[i+1].y)/3*temp;
		}
		if(sgn(area)) ret=ret/area;
		return ret;
	}
	//多边形和圆交的面积
	double area_circle(circle c){
		double ans = 0;
		for(int i=0;i<n;i++){
			int j=(i+1)%n;
			if(sgn((p[j]-c.p)^(p[i]-c.p))>=0){
				ans+=c.area_triangle(p[i],p[j]);
			}
			else{
				ans-=c.area_triangle(p[i],p[j]);
			}
		}
		return fabs(ans);
	}
	//多边形和圆的关系
	//2 圆完全在多边形内
	//1 圆在多边形里面  碰到了多边形的边界
	//0 其他
	int relation_circle(circle c){
		get_line();// 得到内部直线
		int x=2;
		if(relation_point(c.p)!=1)return 0;  //圆心不在内部
		for(int i=0;i<n;i++){
			if(c.relation_seg(l[i])==2){
				return 0;
			}
			if(c.relation_seg(l[i])==1)x=1;
		}
		return x;
	}
};
int main()
{
	Point a[100];
	for(int i=0;i<10;i++)
	a[i].input();
	sort(a,a+10);
	for(int i=0;i<10;i++)
	a[i].output();
	return 0;
}
