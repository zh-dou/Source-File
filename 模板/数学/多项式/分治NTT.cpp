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
#define G 3
#define N 200010
#define int long long
#define mod 998244353
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
int n,f[N],g[N],A[N],B[N];
inline void Change(int *y,int len){
	int i,j,k;
	for(i=1,j=len/2;i<len-1;i++){
		if(i<j) swap(y[i],y[j]);
		k=len/2;
		while(j>=k){
			j=j-k;k=k/2;
		}
		j+=k;
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
void NTT(int *y,int len,int on){
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
void CDQ(int l,int r){
	if(l==r) return ;
	int mid=(l+r)>>1;
	CDQ(l,mid);
	for(int i=0;i<r-l+1;i++) A[i]=B[i]=0;
	for(int i=l;i<=mid;i++) A[i-l]=f[i];
	for(int i=1;i<r-l+1;i++) B[i]=g[i];
	NTT(A,r-l+1,1);NTT(B,r-l+1,1);
	for(int i=0;i<r-l+1;i++) A[i]=(A[i]*B[i])%mod;
	NTT(A,r-l+1,-1);
	for(int i=mid+1;i<=r;i++) f[i]=(f[i]+A[i-l])%mod;
	CDQ(mid+1,r);
//	cout<<l<<" "<<r<<"\n";
//	for(int i=l;i<=r;i++) cout<<f[i]<<" ";
//	cout<<"\n";
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();f[0]=1;
	for(int i=1;i<n;i++) g[i]=read();
	int lim=1;
	while(lim<n) lim<<=1;
	CDQ(0,lim-1);
	for(int i=0;i<n;i++) cout<<f[i]<<" ";
	cout<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

