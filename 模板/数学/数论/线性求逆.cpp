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
#define N 1000010
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
int inv[N];
inline ksm(int x,int y,int mod){
	int ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans%mod;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),mod=read();
	//1~n
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	//
	//1!~n!
	int ans=1;
	for(int i=2;i<=n;i++) ans=ans*i%mod;
	inv[n]=ksm(ans,mod-2,mod);
	for(int i=n-1;i>0;i--) inv[i]=inv[i+1]*(i+1)%mod;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
