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
#define mod 998244353
#define int long long
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"
int n,k,x[2010],y[2010];
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
//inline int* mul(int a[],int b[]){
//	int c[]
//}
inline int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans%mod;
}
inline int Lagrange(){
	int ans=0;
	for(int i=1,res;i<=n;i++){
		res=1;
//		cout<<i<<":\n";
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			res=(res*((x[i]+mod-x[j])%mod))%mod;
		}
		res=ksm(res,mod-2);
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			res=(res*((k+mod-x[j])%mod))%mod;
		}
		res=res*y[i]%mod;
		ans=(ans+res)%mod;
//		cout<<ans<<"\n";
	}
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		x[i]=read();y[i]=read();
	}
	cout<<Lagrange()<<"\n";
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
