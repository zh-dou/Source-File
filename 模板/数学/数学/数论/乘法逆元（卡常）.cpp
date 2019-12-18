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
int n,k,mod;
int a[5000010],b[5000010],s[5000010],ans;
int ksm(int x, int y){
    int res=1;
    while(y){
        if(y&1) res=(res*x)%mod;
        y>>=1;
        x=(x*x)% mod;
    }
    return res%mod;
}
signed main(){
    n=read();mod=read();k=read();
    b[n+1]=s[0]=1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        s[i]=(s[i-1]*a[i])%mod;
    }
    b[n+1]=ksm(s[n],mod-2);
    for(int i=n;i>=1;i--) b[i]=(b[i+1]*a[i])%mod;
    int tmp=k;
    for(int i=1;i<=n;i++){
        ans=(ans+((b[i+1]*s[i-1])%mod)*tmp)%mod;
        tmp=(tmp*k)%mod;
    }
    put(ans);putchar('\n');
    return 0;
}
