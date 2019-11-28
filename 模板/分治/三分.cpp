#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define eps 1e-12
int n;
double l,r,a[21];
inline int read(){
	int x=0,y=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
inline double f(double x){
    double xx=1.0,sum=0.0;
    for(int i=n+1;i>=1;i--){
        sum+=xx*a[i];
        xx*=x;
    }
    return sum;
}
signed main(){
    n=read();
    scanf("%lf%lf",&l,&r);
    for(int i=1;i<=n+1;i++) scanf("%lf",&a[i]);
    while(l+eps<=r){
        double tmp=(r-l)/3;
        double lmid=l+tmp;
        double rmid=r-tmp;
        if(f(lmid)>f(rmid))r=rmid;
        else l=lmid;
    }
    printf("%.5lf",(l+r)/2);
    return 0;
}
