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
#define N 50010
#define int long long
#define eps 1e-10
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
int n,tot,del[N];
inline bool cmp(const Point &a,const Point &b){
	if(fabs(mul(a,b))<=eps) return a.x<b.x;
	return mul(a,b)>eps; 
}
inline void get_convex(){
	if(n<=2) return;
	int fir=1;
	for(int i=2;i<=n;i++){
		if(a[i].y<a[fir].y) fir=i;
		else{
			if(a[i].y==a[fir].y&&a[i].x<a[fir].x) fir=i;
		}
	}
	swap(a[1],a[fir]);
	for(int i=n;i>=1;i--) a[i]=a[i]-a[1];
	sort(a+2,a+n+1,cmp);
//	for(int i=1;i<=n;i++) cout<<a[i].x<<" "<<a[i].y<<"\n";
	hull[++tot]=a[1];hull[++tot]=a[2];
	for(int i=3;i<=n;i++){
		while(tot>=2&&mul(hull[tot]-hull[tot-1],a[i]-hull[tot])<=0){
//			cout<<"fuck???   "<<(hull[tot]-hull[tot-1]).x<<" "<<(hull[tot]-hull[tot-1]).y<<" "<<(a[i]-hull[tot]).x<<" "<<(a[i]-hull[tot]).y<<"\n";
			--tot;
		}
//		cout<<tot<<"\n";
		hull[++tot]=a[i];
	}
}
inline int diameter(){
	int i=1,j=1,ans=0;
	while(i<=tot&&j<=tot){
		while(j<=i+1||fabs(mul(hull[i]-hull[j],hull[i+1]-hull[j]))<fabs(mul(hull[i]-hull[j+1],hull[i+1]-hull[j+1]))){
			ans=max(ans,(int)dot(hull[j]-hull[i],hull[j]-hull[i]));
			ans=max(ans,(int)dot(hull[j]-hull[i+1],hull[j]-hull[i+1]));
			++j;
		}
		ans=max(ans,(int)dot(hull[j]-hull[i],hull[j]-hull[i]));
		ans=max(ans,(int)dot(hull[j]-hull[i+1],hull[j]-hull[i+1]));
		++i;
	}
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){a[i].x=read();a[i].y=read();}
	if(n==1) return puts("0"),0;
	if(n==2) return cout<<abs((int)(dot(a[1]-a[2],a[1]-a[2])))<<"\n",0;
	get_convex();
	cout<<diameter()<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
