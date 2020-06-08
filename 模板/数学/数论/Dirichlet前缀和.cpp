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
#define N 20000010
#define int unsigned int
#define debug cerr<<__LINE__<<" "<<__FUNCTION__<<"\n"

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
int n,seed,t[N],ans;
inline int getnext(){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
int tot,prime[N>>2],ispri[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();seed=read();
	for(int i=2;i<=n;i++){
		if(ispri[i]) continue;
		prime[++tot]=i;
		for(int j=2*i;j<=n;j+=i) ispri[j]=1;
	}
	for(int i=1;i<=n;i++) t[i]=getnext();
	for(int i=1;i<=tot;i++){
		for(int j=1;prime[i]*j<=n;j++) t[j*prime[i]]+=t[j];
	}
	for(int i=1;i<=n;i++) ans^=t[i];
	cout<<ans<<"\n";
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

