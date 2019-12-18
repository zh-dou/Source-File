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
#define mod 998244353
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
struct Ans{
	int f,g,h;
	Ans(int _f=0,int _g=0,int _h=0){f=_f;g=_g;h=_h;}
};
Ans Solve(int a,int b,int c,int n){
	Ans ans,res;
	if(a==0){
		ans.f=(n+1)*(b/c)%mod;
		ans.g=((n+1)*(b/c)%mod)*(b/c)%mod;
		ans.h=((n*(n+1)%mod)*499122177%mod)*(b/c)%mod;
//		cout<<a<<" "<<b<<" "<<c<<" "<<n<<" : "<<ans.f<<" , "<<ans.g<<" , "<<ans.h<<"\n";
		return ans;
	}
	int m=(a*n+b)/c;
	if(a>=c||b>=c){
		res=Solve(a%c,b%c,c,n);
		ans.f=((((n*(n+1)%mod)*499122177)%mod)*(a/c)%mod+(b/c)*(n+1)%mod+res.f)%mod;
		ans.g=((((a/c)*res.h%mod+(b/c)*res.f%mod)%mod)*2%mod+((((n*(n+1)%mod)*(2*n+1)%mod)*166374059%mod)*(a/c)%mod)*(a/c)%mod+((n*(n+1))%mod*(a/c)%mod)*(b/c)%mod+((n+1)*(b/c)%mod)*(b/c)%mod+res.g)%mod;
		ans.h=((((n*(n+1)%mod)*(2*n+1)%mod)*166374059%mod)*(a/c)%mod+((n*(n+1)%mod)*499122177%mod)*(b/c)%mod+res.h)%mod;
	}else{
		res=Solve(c,c-b-1,a,m-1);
		ans.f=(((m*n)%mod-res.f)%mod+mod)%mod;
		ans.g=(((n*m%mod)*(m+1)%mod-ans.f-((res.f+res.h)%mod)*2%mod)%mod+mod)%mod;
		ans.h=((((m*n%mod)*(n+1)%mod-res.f-res.g)%mod+mod)%mod)*499122177%mod;
	}
//	cout<<a<<" "<<b<<" "<<c<<" "<<n<<" : "<<ans.f<<" , "<<ans.g<<" , "<<ans.h<<"\n";
	return ans;
}

signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	int T=read(),a,b,c,n;
	Ans ans;
	while(T--){
		n=read();a=read();b=read();c=read();
		ans=Solve(a,b,c,n);
		cout<<ans.f<<" "<<ans.g<<" "<<ans.h<<"\n";
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

