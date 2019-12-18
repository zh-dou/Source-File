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
#define G 3
#define N 5000010
#define mod 998244353
#define int long long
#define Ginv 332748118
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
int n,m,a[N],b[N];
inline void Change(int y[],int len){
	int i,j,k;
	for(i=1,j=len/2;i<len-1;i++){
		if(i<j) swap(y[i],y[j]);
		k=len/2;
		while(j>=k){
			j=j-k;k=k/2;
		}
		if(j<k)j+=k;
	}
}
inline int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
inline void NTT(int y[],int len,int on){
	Change(y,len);
	for(int h=1,mul,u,t;h<=len;h<<=1){
		if(on==1) mul=ksm(G,(mod-1)/h);
		else mul=ksm(Ginv,(mod-1)/h);
		for(int j=0,w;j<len;j+=h){
			w=1;
			for(int k=j;k<j+(h>>1);k++){
				u=y[k];t=(w*y[k+(h>>1)])%mod;
				y[k]=(u+t)%mod;y[k+(h>>1)]=(u-t+mod)%mod;
				w=(w*mul)%mod;
			}
		}
	}
	if(on==-1){
		int mul=ksm(len,mod-2);
		for(int i=0;i<len;i++) y[i]=(y[i]*mul)%mod;
	}
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read()+1;m=read()+1;
	int lim=1;
	while(lim<=(n+m)) lim<<=1;
	for(int i=0;i<n;i++) a[i]=read();
	for(int i=0;i<m;i++) b[i]=read();
	NTT(a,lim,1);NTT(b,lim,1);
	for(int i=0;i<lim;i++) a[i]=(a[i]*b[i])%mod;
	NTT(a,lim,-1);
	for(int i=0;i<n+m-1;i++) cout<<a[i]<<" ";
	cout<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

