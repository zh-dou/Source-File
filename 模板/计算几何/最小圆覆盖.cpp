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
#define N 100010
#define eps 1e-10
#define int long long
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
int n;
double r;
struct Point{
	double x,y;
	Point(double _x=0.0,double _y=0.0){x=_x;y=_y;}
	friend Point operator + (const Point &A,const Point &B){return Point(A.x+B.x,A.y+B.y);}
	friend Point operator - (const Point &A,const Point &B){return Point(A.x-B.x,A.y-B.y);}
	friend Point operator * (const Point &A,const double &B){return Point(A.x*B,A.y*B);}
}a[N],C,p1,p2;
inline double mul(const Point &A,const Point &B){return A.x*B.y-A.y*B.x;}
inline Point rot(const Point &A){return Point(A.y,-A.x);}
inline bool check(const Point &A){
	return r*r-(A.x-C.x)*(A.x-C.x)-(A.y-C.y)*(A.y-C.y)>=-eps;
}
struct Line{
	Point p,v;
	Line(Point _p=Point(0,0),Point _v=Point(0,0)){p=_p;v=_v;}
}l1,l2;
inline Point Linemeet(const Line &A,const Line &B){
	Point res=A.p-B.p;
	return A.p+A.v*(mul(B.v,res)/mul(A.v,B.v));
}
inline Point Circumcircle(const Point &P,const Point &A,const Point &B){
//	cout<<p1.x<<" "<<p1.y<<"         point\n";
	return Linemeet(Line((A+P)*0.5,rot(A-P)),Line((B+P)*0.5,rot(B-P)));
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%lf %lf",&a[i].x,&a[i].y);
	}
	random_shuffle(a+1,a+n+1);
	C=a[1];r=0.0;
	for(int i=2;i<=n;i++){
		if(check(a[i])) continue;
		C=a[i];r=0;
		for(int j=1;j<i;j++){
			if(check(a[j])) continue;
			C=Point((a[i].x+a[j].x)*0.5,(a[i].y+a[j].y)*0.5);
			r=sqrt((a[i].x-C.x)*(a[i].x-C.x)+(a[i].y-C.y)*(a[i].y-C.y));
			for(int k=1;k<j;k++){
				if(check(a[k])) continue;
//				cout<<i<<" "<<j<<" "<<k<<" "<<C.x<<" "<<C.y<<"\n";
				C=Circumcircle(a[i],a[j],a[k]);
				r=sqrt((a[i].x-C.x)*(a[i].x-C.x)+(a[i].y-C.y)*(a[i].y-C.y));
			}
		}
//		cout<<i<<" : "<<C.x<<" "<<C.y<<"    "<<a[i].x<<" "<<a[i].y<<"\n";
	}
//	for(int i=1;i<=n;i++) cout<<check(a[i])<<" ";
//	cout<<"           iushegr\n";
	printf("%.10f\n%.10f %.10f\n",r,C.x,C.y);
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
