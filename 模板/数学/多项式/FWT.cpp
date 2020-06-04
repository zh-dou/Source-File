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
#define N 2000010
#define int long long
#define mod 998244353
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
int n,a[N],b[N],A[N],B[N];
inline void OR(int* y,int len,int on){
	for(int i=0;i<len;i++){
		for(int j=0;j<=(1<<len);j++){
			if(j&(1<<i)) y[j]=(y[j]+on*y[j^(1<<i)]+mod)%mod;
		}
	}
}
inline void AND(int* y,int len,int on){
	for(int i=0;i<len;i++){
		for(int j=0;j<=(1<<len);j++){
			if(!(j&(1<<i))) y[j]=(y[j]+on*y[j^(1<<i)]+mod)%mod;
		}
	}
}
inline void XOR(int *y,int len,int on){
	for(int k=2,res1,res2;k<=(1<<len);k<<=1){
		for(int i=0;i<(1<<len);i+=k){
			for(int j=0;j<(k>>1);j++){
				res1=(y[i+j]+y[i+j+(k>>1)])%mod;res2=(y[i+j]-y[i+j+(k>>1)]+mod)%mod;
				if(on==-1){
					res1=res1*499122177%mod;
					res2=res2*499122177%mod;
				}
				y[i+j]=res1;y[i+j+(k>>1)]=res2;
			}
		}
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	int len=(1<<n);
	for(int i=0;i<len;i++) a[i]=read();
	for(int i=0;i<len;i++) b[i]=read();
	
	for(int i=0;i<len;i++) A[i]=a[i];
	for(int i=0;i<len;i++) B[i]=b[i];
	OR(A,n,1);OR(B,n,1);
	for(int i=0;i<len;i++) A[i]=(A[i]*B[i])%mod;
	OR(A,n,-1);
	for(int i=0;i<len;i++) cout<<A[i]<<" ";
	cout<<"\n";
	
	for(int i=0;i<len;i++) A[i]=a[i];
	for(int i=0;i<len;i++) B[i]=b[i];
	AND(A,n,1);AND(B,n,1);
	for(int i=0;i<len;i++) A[i]=(A[i]*B[i])%mod;
	AND(A,n,-1);
	for(int i=0;i<len;i++) cout<<A[i]<<" ";
	cout<<"\n";
	
	for(int i=0;i<len;i++) A[i]=a[i];
	for(int i=0;i<len;i++) B[i]=b[i];
	XOR(A,n,1);XOR(B,n,1);
	for(int i=0;i<len;i++) A[i]=(A[i]*B[i])%mod;
	XOR(A,n,-1);
	for(int i=0;i<len;i++) cout<<A[i]<<" ";
	cout<<"\n";
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

