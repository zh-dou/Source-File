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
int a1,p1,ans,M,n,flag;
inline int ksm(int n,int m,int p){
	int ans=0;
	while(m){
		if(m&1)	ans=(ans+n)% p;
		m>>=1;
		n=(n+n)%p;
	}
	return ans;
}
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	int d=exgcd(b,a%b,x,y),c=x;
	x=y;
	y=c-(a/b)*y;
	return d;
}
void ExCRT(){
	int x,y,c=(a1-ans%p1+p1)%p1,d=exgcd(M,p1,x,y);
	if(c%d==0){
		ans+=ksm(x,c/d,p1/d)*M;
		M*=p1/d;
		ans=(ans%M+M)%M;
	}else{
		flag=1;
	}
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();
	M=read();ans=read();
	for(int i=2;i<=n;i++){
		p1=read();a1=read();
		ExCRT();
		if(flag){puts("-1");return 0;}
	}
	cout<<ans<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
