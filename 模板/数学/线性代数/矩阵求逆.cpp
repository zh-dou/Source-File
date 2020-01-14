#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 410
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
int n,a[N][N<<1];
inline int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans%mod;
}
inline bool Agreater(int k,int x,int y){
    if(a[x][k]!=a[y][k]) return a[x][k]>a[y][k];
    for(int i=k+1;i<=n;i++)
        if(a[x][i]!=a[y][i]) return a[x][i]<a[y][i];
    return 0;
}
inline void Gauss(){
	int i,j,k,mx,res;
//	cout<<"----------------------------------\n"<<0<<"\n";
//	for(j=1;j<=n;j++){
//		for(k=1;k<=n+n;k++) cout<<a[j][k]<<" ";
//		cout<<"\n";
//	}
	for(i=1;i<=n;i++){
		mx=i;
		for(j=i+1;j<=n;j++){
			if(Agreater(i,j,mx)) mx=j;
		}
		if(mx!=i) swap(a[i],a[mx]);
		if(a[i][i]==0){
			puts("No Solution");
			return ;
		}
		res=a[i][i];
		for(j=i;j<=n+n;j++) a[i][j]=(a[i][j]*ksm(res,mod-2))%mod;
		for(j=i+1;j<=n;j++){
			res=a[j][i];
			for(k=i;k<=n+n;k++) a[j][k]=((a[j][k]-res*a[i][k]%mod)%mod+mod)%mod;
		}
//		cout<<"----------------------------------\n"<<i<<"\n";
//		for(j=1;j<=n;j++){
//			for(k=1;k<=n+n;k++) cout<<a[j][k]<<" ";
//			cout<<"\n";
//		}
	}
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n+1;j++) cout<<a[i][j]<<" ";
//		cout<<"\n";
//	}
	for(i=n;i>=1;i--){
		if(a[i][i]==0){
			puts("No Solution");
			return ;
		}
		for(j=1;j<i;j++){
			for(k=n+1;k<=n+n;k++) a[j][k]=((a[j][k]-a[j][i]*a[i][k]%mod)%mod+mod)%mod;
			a[j][i]=0;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) put(a[i][n+j]),putchar(' ');
		putchar('\n');
	}
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
//	cout<<ksm(5,mod-2)<<"\n";
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) a[i][j]=(read()%mod+mod)%mod;
		a[i][i+n]=1;
	}
	Gauss();
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
