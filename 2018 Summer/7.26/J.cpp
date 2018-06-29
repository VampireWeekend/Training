
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include <iomanip>
 typedef long double ld;
using namespace std;
 
const ld eps = 1e-8;
const ld PI = acos(-1.0);
 
int dcmp(ld x){
	if( x > eps ) return 1;
	return x < -eps ? -1 : 0;
}
 
struct Point{
	ld x,y;
	Point(){
		x = y = 0;
	}
	Point(ld a,ld b){
		x = a;y = b;
	}
	inline void input(){
		scanf("%Lf%Lf",&x,&y);
	}
	inline Point operator-(const Point &b)const{
		return Point(x - b.x,y - b.y);
	}
	inline Point operator+(const Point &b)const{
		return Point(x + b.x,y + b.y);
	}
	inline Point operator*(const ld &b)const{
		return Point(x * b,y * b);
	}
	inline Point operator/(const ld &b)const{
		return Point(x / b,y / b);
	}
	inline ld dot(const Point &b)const{
		return x * b.x + y * b.y;
	}
	inline ld cross(const Point &b,const Point &c)const{
		return (b.x - x) * (c.y - y) - (c.x - x) * (b.y - y);
	}
	inline ld Dis(const Point &b)const{
		return sqrt((*this-b).dot(*this-b));
	}
	inline bool InLine(const Point &b,const Point &c)const{ //三点共线 
		return !dcmp(cross(b,c));
	}
	inline bool OnSeg(const Point &b,const Point &c)const{ //点在线段上，包括端点 
		return InLine(b,c) && (*this - c).dot(*this - b) < eps;
	}
};
 
inline ld min(ld a,ld b){
	return a < b ? a : b;
}
inline ld max(ld a,ld b){
	return a > b ? a : b;
}
inline ld Sqr(ld x){
	return x * x;
}
inline ld Sqr(const Point &p){
	return p.dot(p);
}
 
Point LineCross(const Point &a,const Point &b,const Point &c,const Point &d){
	ld u = a.cross(b,c) , v = b.cross(a,d);
	return Point((c.x * v + d.x * u) / (u + v) , (c.y * v + d.y * u) / (u + v));
} 
 
ld LineCrossCircle(const Point &a,const Point &b,const Point &r,
                               ld R,Point &p1,Point & p2){
	Point fp = LineCross(r , Point(r.x+a.y-b.y , r.y+b.x-a.x) , a , b);
	ld rtol = r.Dis(fp);
	ld rtos = fp.OnSeg(a , b) ? rtol : min(r.Dis(a) , r.Dis(b));
	ld atob = a.Dis(b);
	ld fptoe = sqrt(R * R - rtol * rtol) / atob;
	if( rtos > R - eps ) return rtos;
	p1 = fp + (a - b) * fptoe;
	p2 = fp + (b - a) * fptoe;
	return rtos;
}
 
ld SectorArea(const Point &r,const Point &a,const Point &b,ld R){ //不大�?80度扇形面积，r->a->b逆时�?
	ld A2 = Sqr(r - a) , B2 = Sqr(r - b) , C2 = Sqr(a - b);
	return R * R * acos( (A2 + B2 - C2) * 0.5 / sqrt(A2) / sqrt(B2)) * 0.5;
}
 
ld TACIA(const Point &r,const Point &a,const Point &b,ld R){
	ld adis = r.Dis(a) , bdis = r.Dis(b);
	if( adis < R + eps && bdis < R + eps )
		return r.cross(a , b) * 0.5;
	Point ta , tb;
	if( r.InLine(a,b) ) return 0.0;
	ld rtos = LineCrossCircle(a, b, r, R, ta, tb);
	if( rtos > R - eps ) 
		return SectorArea(r, a, b, R);
	if( adis < R + eps )
		return r.cross(a, tb) * 0.5 + SectorArea(r, tb, b, R);
	if( bdis < R + eps )
		return r.cross(ta, b) * 0.5 + SectorArea(r, a, ta, R);
	return r.cross(ta, tb) * 0.5 + SectorArea(r, tb, b, R) + SectorArea(r, a, ta, R);
}
 
const int MAXN  = 505;
Point p[MAXN];
 
ld SPICA(int n,Point r,ld R){
	int i;
	ld ret = 0 , if_clock_t;
	for( i = 0 ; i < n ; ++i ){
		if_clock_t = dcmp(r.cross(p[i], p[(i + 1) % n]));
		if( if_clock_t < 0 )
			ret -= TACIA(r, p[(i + 1) % n], p[i], R);
		else ret += TACIA(r, p[i], p[(i + 1) % n], R);
	}
	return fabs(ret);
}
 
int main(){
	int n,i;
	Point sum=Point(0,0);
	scanf("%d",&n);
	for( i = 0 ; i < n ; ++i ) {
		p[i].input();
		sum=sum+p[i];
	}
	sum=sum/n;
	ld tot=0;
	for (i=0;i<n-1;i++) {
		tot+=sum.cross(p[i],p[i+1]);
	}
	tot+=sum.cross(p[n-1],p[0]);
    tot=fabs(tot/2.0L);
	int m;
	scanf("%d",&m);
	while (m--) {
		Point circle;
		circle.input(); 
		ld P,Q;
		cin >> P >> Q;
		ld R;
		ld l,r,mid;
		l=0;r=1500000;
		while (fabs(l-r)>eps) {
			mid=R=(l+r)/2.0L;
			ld size=SPICA(n,circle,R);
			if (size*Q>(Q-P)*tot) r=mid; else l=mid;
		}
		cout << setiosflags(ios::fixed) << setprecision(12);
        cout << (l+r)/2.0L << endl;
	}
	return 0;
}
