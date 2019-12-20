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
#define int long long
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
	Point friend operator *(const Point &a,const int &b){return Point(a.x*b,a.y*b);}
	Point friend operator /(const Point &a,const int &b){return Point(a.x/b,a.y/b);}
}a[N],hull[N];
inline double dot(const Point &a,const Point &b){return a.x*b.x+a.y*b.y;}
inline double mul(const Point &a,const Point &b){return a.x*b.y-a.y*b.x;}
inline Point rotate(const Point &a,const double &theta){
	return Point(a.x*cos(theta)-a.y*sin(theta),a.x*sin(theta)+a.y*cos(theta));
}
int n,tot,del[N];
inline bool cmp(const Point &a,const Point &b){
	if(fabs(mul(a,b))<=eps) return a.x<b.x;
	return mul(a,b)>eps; 
}
inline bool cmp1(const Point &a,const Point &b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x; 
}
inline void get_convex(){
	if(n<=2) return;
	sort(a+1,a+n+1,cmp1);
	int fir=1;
	for(int i=2;i<=n;i++){
		if(a[i].y<a[fir].y) fir=i;
		else{
			if(a[i].y==a[fir].y&&a[i].x<a[fir].x) fir=i;
		}
	}
	swap(a[1],a[fir]);
//	for(int i=n;i>=1;i--) a[i]=a[i]-a[1];
	for(int i=n;i>=1;i--){
		a[i]=a[i]-a[1];
		if(fabs(a[i].x)<eps) a[i].x=0;
		if(fabs(a[i].y)<eps) a[i].y=0;
	}
	sort(a+2,a+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<i<<" : "<<a[i].x<<" "<<a[i].y<<"\n";
//	}
//	for(int i=1;i<=n;i++) cout<<a[i].x<<" "<<a[i].y<<"\n";
	hull[++tot]=a[1];hull[++tot]=a[2];
	for(int i=3;i<=n;i++){
		while(tot>=2&&mul(hull[tot]-hull[tot-1],a[i]-hull[tot])<=0){
//			cout<<"fuck???   "<<tot<<" "<<hull[tot].x<<" "<<hull[tot].y<<"\n";
			--tot;
		}
//		cout<<tot<<"\n";
		hull[++tot]=a[i];
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	double xl,yl,r,x,y,theta;
	scanf("%lf %lf %lf",&yl,&xl,&r);
	xl=xl/2.0-r;yl=yl/2.0-r;
	for(int i=1;i<=n;i++){
		scanf("%lf %lf %lf",&x,&y,&theta);
		a[(i<<2)-3]=rotate(Point(-xl,-yl),theta)+Point(x,y);
		a[(i<<2)-2]=rotate(Point(+xl,-yl),theta)+Point(x,y);
		a[(i<<2)-1]=rotate(Point(-xl,+yl),theta)+Point(x,y);
		a[(i<<2)  ]=rotate(Point(+xl,+yl),theta)+Point(x,y);
	}
	n<<=2;
	get_convex();
//	for(int i=1;i<=tot;i++){
//		cout<<i<<" : "<<hull[i].x<<" "<<hull[i].y<<"\n";
//	}
	double ans=2.0*PI*r+sqrt(dot(hull[1]-hull[tot],hull[1]-hull[tot]));
//	cout<<ans<<"\n";
	for(int i=2;i<=tot;i++){
		ans=ans+sqrt(dot(hull[i]-hull[i-1],hull[i]-hull[i-1]));
//		cout<<ans<<"\n";
	}
	printf("%.2f\n",ans);
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

