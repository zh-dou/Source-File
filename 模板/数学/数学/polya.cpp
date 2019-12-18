#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 8000010
#define int long long
#define mod 1000000007
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
inline int chu_phi(int x){
    int res=1;
    for(int i=2;i*i<=x;i++){
    	if(x%i) continue;
            x/=i,res=res*(i-1);
            while(x%i==0) x/=i,res=res*i;
	}
    if(x>1) res=res*(x-1);
    return res;
}
inline int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    int T=read(),n,ans;
    while(T-->0){
    	n=read();ans=0;
    	for(int i=1;i*i<=n;i++){
    		if(n%i) continue;
			ans=(ans+(chu_phi(i)*ksm(n,n/i-1))%mod)%mod;
			if(i*i!=n) ans=(ans+(chu_phi(n/i)*ksm(n,i-1))%mod)%mod;
    	}
    	cout<<ans<<"\n";
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
