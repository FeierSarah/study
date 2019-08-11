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
int sgn(double x){   //�ж�һ��ֵ �Ƿ����޽ӽ���0
	if(fabs(x)<eps)return 0;   //Լ����0����0��
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
	//��� ����Ҫ������֮�䣩
	double operator ^ (const Point &b)const{
		return x*b.y-y*b.x;//����ģ�� ������
	}
	//���
	double operator * (const Point &b)const{
		return x*b.x+y*b.y;
	}
	//���س���
	double len(){
		return hypot(x,y);  //����ֵ�൱��sqrt(x*x+y*y);
	}
	//���س��ȵ�ƽ��
	double len2(){
		return x*x+y*y;
	}
	//��������ľ���
	double distance (Point p){
		return hypot(x-p.x,y-p.y);
	}
	//�����ļӼ��˳�
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
	//��������㵽a�� �� b�������ڵļн�
	//���Ǵ�����㿴a,b����֮��н�
	double rad(Point a,Point b){
		Point p= *this;
		//cout<<p.x<<" "<<p.y<<endl;
		return fabs(atan2(fabs((a-p)^(b-p)),(a-p)*(b-p)));
	}
	//��Ϊ����Ϊr������
	Point trunc(double r){
		double l=len();
		if(!sgn(l))return *this;   //�����0
		r/=l;
		return Point(x*r,y*r);
	}
	//��ʱ����ת90��
	Point rotleft(){
		return Point(-y,x);
	}
	//˳ʱ����ת90��
	Point rotright(){
		return Point(y,-x);
	}
	//����P����ʱ����תangle
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
	//����һ�����һ����б��angleȷ��һ��ֱ��  0<=angle<pi
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
	//���߶εĳ���
	double length(){
		return s.distance(e);
	}
	//����ֱ����б��  0<=angle<pi
	double angle(){
		double k=atan2(e.y-s.y,e.x-s.x);
		if(sgn(k)<0)k+=pi;
		if(sgn(k-pi)==0)k-=pi;
		return k;
	}
	//���ֱ�ߵĹ�ϵ
	//1 ��ֱ�����
	//2 ��ֱ���Ҳ�
	//3 ��ֱ����
	int relation(Point p){
		int c=sgn((p-s)^(e-s));
		if(c<0)return 1;
		else if(c>0) return 2;
		else return 3;
	}
	//�����߶��ϵ��ж�
	bool point_on_seg(Point p){
		return sgn((p-s)^(p-e))==0&&sgn((p-s)*(p-e))<=0;
	}
	//������ƽ�У���Ӧֱ��ƽ�л��غϣ�
	bool parallel(Line v){
		return sgn((e-s)^(v.e-v.s))==0;
	}
	//���߶��ཻ�ж�
	//2 �淶�ཻ�������߶�ǡ����һ�����Ƕ˵�Ĺ����㣩
	//1 �ǹ淶�ཻ
	//0 ���ཻ
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
	//ֱ�ߺ��߶��ཻ�ж�
	//-*this line    -v seg
	//2 �淶�ཻ
	//1 �ǹ淶�ཻ
	//0 ���ཻ
	int line_cross_seg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		if((d1^d2) == -2)return 2;
		return (d1==0||d2==0);
	}
	//��ֱ�ߵĹ�ϵ
	//0 ƽ��
	//1 �غ�
	//2 �ཻ
	int line_cross_line(Line v){
		if((*this).parallel(v))
		return v.relation(s)==3;
		return 2;
	}
	//����ֱ�ߵĽ���
	//Ҫ��֤��ֱ�߲�ƽ�л��غ�
	Point cross_point(Line v){
		double a1 = (v.e-v.s)^(s-v.s);
		double a2 = (v.e-v.s)^(e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
	}
	//�㵽ֱ�ߵľ���
	double dis_point_to_line(Point p){
		return fabs((p-s)^(e-s))/length();
	}
	//�㵽�߶εľ���
	double dis_point_to_seg(Point p){
		if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0)
		return min(p.distance(s),p.distance(e));
		return dis_point_to_line(p);
	}
	//�����߶ε��߶��ϵľ���
	//ǰ���������߶β��ཻ������ཻ����Ϊ0��
	double dis_seg_to_seg(Line v){
		return min(min(dis_point_to_seg(v.s),dis_point_to_seg(v.e)),
		min(v.dis_point_to_seg(s),v.dis_point_to_seg(e)));
	}
	//���ص�p��ֱ���ϵ�ͶӰ
	Point line_prog(Point p){
		return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
	}
	//���ص�p����ֱ�ߵĶԳƵ�
	Point symmetry_point(Point p){
		Point q=line_prog(p);
		return Point(2*q.x-p.x,2*q.y-p.y);
	}
};

struct circle{
	Point p;  //Բ��
	double r;   //�뾶
	circle(){}
	circle(Point _p,double _r){
		p=_p;
		r=_r;
	}
	circle(double x,double y,double _r){
		p=Point(x,y);
		r=_r;
	}
	//�����ε����Բ
	//��Ҫ Point �� + / rotate() �Լ� Line �� cross_point();
	//���������ߵ��д��ߵõ�Բ��
	circle(Point a,Point b,Point c){
		Line u = Line((a+b)/2,((a+b)/2)+((b-a).rotleft()));
		Line v = Line((b+c)/2,((b+c)/2)+((c-b).rotleft()));
		p = u.cross_point(v);
		r = p.distance(a);
	}
	//�����ε�����Բ
	//����ԲԲ����������ƽ���ߵĽ���
	//���� bool t û������ ֻ��Ϊ������  ���Բ
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
	//���Բ�Ĺ�ϵ
	//0 Բ��
	//1 Բ��
	//2 Բ��
	int relation_point(Point b){
		double dist=b.distance(p);
		if(sgn(dist - r)<0)return 2;
		else if (sgn(dist - r )==0) return 1;
		return 0;
	}
	//�߶κ�Բ�Ĺ�ϵ
	//�Ƚϵ���  Բ�ĵ��߶εľ���Ͱ뾶�Ĺ�ϵ
	int relation_seg(Line v){
		double dist = v.dis_point_to_seg(p);
		if(sgn(dist-r)<0)return 2;  //԰��
		else if(sgn(dist - r)==0)return 1;// Բ��
		return 0;// Բ��
	}
	// ֱ�ߺ�Բ�Ĺ�ϵ
	// �Ƚϵ���Բ�ĵ�ֱ�ߵľ���Ͱ뾶�Ĺ�ϵ
	int relation_line(Line v){
		double dist = v.dis_point_to_line(p);
		if(sgn(dist-r)<0)return 2;// Բ��
		else if(sgn(dist - r)==0 )return 1; //Բ��
		return 0;//Բ��
	}
	//��Բ�Ĺ�ϵ
	//5 ����
	//4 ����
	//3 �ཻ
	//2 ����
	//1 �ں�
	//��Ҫ�õ�  Point �� distance
	int relation_circle(circle v){
		double d = p.distance(v.p);
		if(sgn(d-r-v.r)>0)return 5;
		if(sgn(d-r-v.r)==0)return 4;
		double l = fabs(r-v.r);
		if(sgn(d-r-v.r)<0&&sgn(d-l)>0)return 3;
		if(sgn(d-l)==0)return 2;
		if(sgn(d-l)<0)return 1;
	}
	//������Բ�Ľ��㣬0��ʾû�н��㣬1 ��ʾһ������   2��ʾ��������
	// ��Ҫ  relation_circle
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
	//��ֱ�ߺ�Բ�Ľ��㣬���ؽ������
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
	//�õ���a��b���㣬�뾶Ϊr1������Բ
	int get_circle(Point a,Point b,double r1,circle &c1,circle &c2){
		circle x(a,r1),y(b,r1);
		int t=x.point_cross_circle(y,c1.p,c2.p);
		if(!t)return 0;
		c1.r=c2.r=r1;
		return t;
	}
	//�õ�ֱ����u���У�����q,�뾶Ϊr1��Բ��
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
	//ͬʱ��ֱ��u,v���У��뾶Ϊr1��Բ
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
	//ͬʱ�벻�ཻ��Բ cx��cy����  ���뾶Ϊr1��Բ
	int get_circle(circle cx,circle cy,double r1,circle &c1,circle &c2){
		circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
		int t=x.point_cross_circle(y,c1.p,c2.p);
		if(!t)return 0;
		c1.r=c2.r=r1;
		return t;
	}
	//��һ����Բ������  �����жϵ��Բ�Ĺ�ϵ��
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
	//����Բ�ཻ�����
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
	//��Բ�������� pab ���ཻ�����
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
	//���м�������
	//������Ҫ�ҵ������½ǵĵ�
	//��Ҫ���غź�  Point �� < ��������minҪ�ã�
	void norm(){
		Point mi=p[0];
		for(int i=0;i<n;i++){
			mi=min(mi,p[i]);
		}
		sort(p,p+n,cmp(mi));
	}
	//�õ�͹��
	//�õ�͹������ĵ�����  0~n-1 ��
	//����͹���ķ���
	//ע�������Ӱ�죬Ҫ���������е㹲�㣬���߹��ߵ��������
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
		convex.norm();//ԭ���õ�����˳ʱ��ĵ㣬����֮���Ϊ��ʱ��
	}
	//�õ�͹������һ�ַ���
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
	//�ж��ǲ���͹��
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
	//�жϵ���������εĹ�ϵ
	//3 �ڶ���εĶ�����
	//2 �ڶ���εı���
	//1 �ڶ�����ڲ�
	//0 �ڶ�����ⲿ
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
	//ֱ�� u �и�͹��������
	//ע��ֱ�߷���
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
	//�õ��ܳ�
	double get_perimeter(){
		double sum=0;
		for(int i=0;i<n;i++){
			sum+=p[i].distance(p[(i+1)%n]);
		}
		return sum;
	}
	//�õ����
	double get_area(){
		double sum=0;
		for(int i=0;i<n;i++){
			sum+=(p[i]^p[(i+1)%n]);
		}
		return fabs(sum)/2;
	}
	// �õ�����
	// 1��ʾ��ʱ��  0��ʾ˳ʱ��
	bool get_dir(){
		double sum=0;
		for(int i=0;i<n;i++){
			sum+=(p[i]^p[(i+1)%n]);
		}
		if(sgn(sum)>0)return 1;
		return 0;
	}
	//�õ�����
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
	//����κ�Բ�������
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
	//����κ�Բ�Ĺ�ϵ
	//2 Բ��ȫ�ڶ������
	//1 Բ�ڶ��������  �����˶���εı߽�
	//0 ����
	int relation_circle(circle c){
		get_line();// �õ��ڲ�ֱ��
		int x=2;
		if(relation_point(c.p)!=1)return 0;  //Բ�Ĳ����ڲ�
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
