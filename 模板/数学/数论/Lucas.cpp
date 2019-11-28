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
int p,fac[100010];
int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p;
		y>>=1;
	}
	return ans;
}
inline int C(int m,int n){
	if(m>n) return 0;
	if(!m) return 1;
	return ((fac[n]*ksm(fac[m],p-2)%p)*ksm(fac[n-m],p-2)%p)%p;
}
int Lucas(int m,int n){
	if(m>n) return 0;
	if(!m) return 1;
	return C(m%p,n%p)*Lucas(m/p,n/p)%p;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read(),n,m;
	while(T--){
		n=read();m=read();p=read();
		fac[0]=1;
		for(int i=1;i<=n+m;i++) fac[i]=fac[i-1]*i%p;
		cout<<Lucas(m,n+m)%p<<"\n";
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

