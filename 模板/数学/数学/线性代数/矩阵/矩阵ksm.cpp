#include<set>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
inline int read(){
	int x=0,y=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
#define N 205
#define mod 1000000007
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n,k;
struct Matrix{
    int a[105][105];
}e,ans,res;
inline Matrix mul(Matrix a,Matrix b){
	Matrix c;
	for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c.a[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j]%mod)%mod;
	return c;
}
Matrix ksm(Matrix a,int b){
    memset(res.a,0,sizeof res.a);
    for(int i=1;i<=n;i++)
        res.a[i][i]=1;
    while(b){
        if(b&1) res=mul(res,a);
        a=mul(a,a);
        b>>=1;
    }
    return res;
}
signed main(){
    n=read();k=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            e.a[i][j]=read();
    ans=ksm(e,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<ans.a[i][j]<<" ";
        puts("");
    }
    return 0;
}


