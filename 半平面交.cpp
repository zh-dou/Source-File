#include<map>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 40010
#define eps 1e-10
#define PI acos(-1)
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"

inline int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*y;
}
void put(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) put(x/10);
	putchar((x%10)+48);
}
struct Point{
	double x,y;
	Point(double _x=0.0,double _y=0.0){x=_x;y=_y;}
	Point friend operator +(const Point &a,const Point &b){return Point(a.x+b.x,a.y+b.y);}
	Point friend operator -(const Point &a,const Point &b){return Point(a.x-b.x,a.y-b.y);}
	Point friend operator *(const Point &a,const double &b){return Point(a.x*b,a.y*b);}
	Point friend operator /(const Point &a,const double &b){return Point(a.x/b,a.y/b);}
}p[N],ans[N];
double dot(const Point &a,const Point &b){return a.x*b.x+a.y*b.y;}
double mul(const Point &a,const Point &b){return a.x*b.y-a.y*b.x;}
struct Line{
	Point p,v;
	double ang;
	Line(){}
	Line(Point a,Point b){
		p=a; v=b;
		ang=atan2(v.y,v.x);
	}
}a[N],sta[N];
inline bool Onleft(const Line &A,const Point &B){
	return mul(A.v,B-A.p)>eps;
}
inline Point Linemeet(const Line &A,const Line &B){
	Point res=A.p-B.p;
	return A.p+A.v*(mul(B.v,res)/mul(A.v,B.v));
}
int n;
inline bool cmp(const Line &A,const Line &B){
	return A.ang<B.ang; 
}
inline int get_half(){
	sort(a+1,a+n+1,cmp);
	int head=1,tail=0;
	sta[++tail]=a[1];
	for(int i=2;i<=n;i++){
		while(head<tail&&!Onleft(a[i],p[tail-1])) tail--;
		while(head<tail&&!Onleft(a[i],p[head])) head++;
		sta[++tail]=a[i];
		if(fabs(mul(sta[tail].v,sta[tail-1].v))<=eps){
			tail--;
			if(Onleft(sta[tail],a[i].p)) sta[tail]=a[i];
		}
		if(head<tail) p[tail-1]=Linemeet(sta[tail],sta[tail-1]);
	}
	while(head<tail&&!Onleft(sta[head],p[tail-1])) tail--;
	if(tail<=head+1) return 0;
	p[tail]=Linemeet(sta[tail],sta[head]);
	for(int i=head;i<=tail;i++) ans[i-head+1]=p[i];
	return tail-head+1;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	int sum=0;
	for(int i=1,m;i<=n;i++){
		m=read();
		for(int j=1;j<=m;j++){
			p[j].x=read();p[j].y=read();
		}
		a[++sum]=Line(p[m],p[1]-p[m]);
		for(int j=2;j<=m;j++)
			a[++sum]=Line(p[j-1],p[j]-p[j-1]);
	}
	a[++sum]=Line(Point(-1000,-1000),Point( 2000,0));
	a[++sum]=Line(Point( 1000,-1000),Point(0, 2000));
	a[++sum]=Line(Point( 1000, 1000),Point(-2000,0));
	a[++sum]=Line(Point(-1000, 1000),Point(0,-2000));
	n=sum;
//	for(int i=1;i<=n;i++) cout<<a[i].ang<<"\n";
	n=get_half();
	double num=0.0;
//	for(int i = 1;i <= n;i ++) printf("!!!%.3f %.3f\n",ans[i].x,ans[i].y);
	for(int i=3;i<=n;i++){
		num+=mul(ans[i-1]-ans[1],ans[i]-ans[1]);
	}
	printf("%.3f\n",num/2.0);
//	for(int i=1;i<=tot;i++){
//		cout<<i<<" : "<<hull[i].x<<" "<<hull[i].y<<"\n";
//	}
	
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

