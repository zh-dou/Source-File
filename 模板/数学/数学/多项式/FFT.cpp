#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 4000010
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
const double PI=acos(-1.0);
struct Complex{
	double x,y;
	Complex(double _x=0.0,double _y=0.0){x=_x;y=_y;}
	Complex operator - (const Complex &b)const{return Complex(x-b.x,y-b.y);}
	Complex operator + (const Complex &b)const{return Complex(x+b.x,y+b.y);}
	Complex operator * (const Complex &b)const{return Complex(x*b.x-y*b.y,x*b.y+y*b.x);}
}x1[N],x2[N];
inline void change(Complex y[],int len){
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
inline void FFT(Complex y[],int len,int on){
	change(y,len);
	for(int h=1;h<=len;h<<=1){
		Complex wn(cos(2*PI/h),sin(on*2*PI/h));
		for(int j=0;j<len;j+=h){
			Complex w(1,0);
			for(int k=j;k<j+h/2;k++){
				Complex u=y[k];
				Complex t=w*y[k+h/2];
				y[k]=u+t;y[k+h/2]=u-t;
				w=w*wn;
			}
		}
	}
	if(on==-1){
		for(int i=0;i<len;i++){
			y[i].x/=len;
		}
	}
}
int str1[N],str2[N],sum[N];
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	int len1=read()+1,len2=read()+1,len=1;
	for(int i=0;i<len1;i++) str1[i]=read();
	for(int i=0;i<len2;i++) str2[i]=read();
	while(len<=(len1+len2)) len<<=1;
	for(int i=0;i<len1;i++) x1[i]=Complex(str1[i],0);
	for(int i=0;i<len2;i++) x2[i]=Complex(str2[i],0);
	FFT(x1,len,1);FFT(x2,len,1);
	for(int i=0;i<len;i++) x1[i]=x1[i]*x2[i];
	FFT(x1,len,-1);
	for(int i=0;i<len;i++) sum[i]=(int)(x1[i].x+0.5);
	len=len1+len2-1;
//	while(sum[len]==0&&len>0) len--;
	for(int i=0;i<len;i++) cout<<sum[i]<<" ";
	cout<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

