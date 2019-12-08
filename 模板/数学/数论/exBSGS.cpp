#include<unordered_map>
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
unordered_map<int,int>  M;
inline int ksm(int x,int y,int mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans%mod;
}
inline void exBSGS(int x,int y,int mod){
    if(y==1){
        puts("0");return ;
    }
	int g=__gcd(x,mod),res=1,ans=0;
	while(g!=1ll){
		if(y%g){
			puts("No Solution");
			return; 
		}
		y/=g;mod/=g;res=(res*x/g)%mod;++ans;
		if(res==y){
			cout<<ans<<"\n";return ;
		}
		g=__gcd(x,mod);
	}
	M.clear();
	int mx=ceil(sqrt(mod)),smul=y;
	for(int i=0;i<=mx;i++){
		M[smul]=i;
		smul=(smul*x)%mod;
//		cout<<smul<<" ";
	}
	y=ksm(x,mx,mod);smul=res;
	for(int i=1;i<=mx;i++){
	    smul=(smul*y)%mod;
//		cout<<i<<" "<<smul<<"\n";
		if(M.count(smul)){
			cout<<i*mx-M[smul]+ans<<"\n";
			return ;
		}
	}
	puts("No Solution");
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	int x,y,mod;
	while(1){
		x=read();mod=read();y=read();
		if((!x)&&(!y)&&(!mod)) return 0;
		x%=mod;y%=mod;
		exBSGS(x,y,mod);
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

