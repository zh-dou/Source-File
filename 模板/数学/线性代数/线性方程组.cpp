#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 110
#define eps 1e-10
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
int n,flag_less,flag_more/*,rank_A=0,rank_B=0*/;
double a[N][N],ans[N];
bool Agreater(int k,int x,int y){
    if(fabs(fabs(a[x][k])-fabs(a[y][k]))>eps) return fabs(a[x][k])>fabs(a[y][k]);
    for(int i=k+1;i<=n;i++)
        if(fabs(fabs(a[x][i])-fabs(a[y][i]))>eps) return fabs(a[x][i])<fabs(a[y][i]);
    return 0;
}
inline void Gauss(){
	int i,j,k,mx;
	double res;
	for(i=1;i<=n;i++){
		mx=i;
		for(j=i+1;j<=n;j++){
			if(Agreater(i,j,mx)) mx=j;
		}
		if(mx!=i) swap(a[i],a[mx]);
		if(fabs(a[i][i])<=eps) continue ;
		res=a[i][i];
		for(j=i;j<=n+1;j++) a[i][j]/=res;
		for(j=i+1;j<=n;j++){
			res=a[j][i];
			for(k=i;k<=n+1;k++) a[j][k]-=res*a[i][k];
		}
//		cout<<"----------------------------------\n"<<i<<"\n";
//		for(j=1;j<=n;j++){
//			for(k=1;k<=n+1;k++) cout<<a[j][k]<<" ";
//			cout<<"\n";
//		}
	}
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n+1;j++) cout<<a[i][j]<<" ";
//		cout<<"\n";
//	}
	for(i=n;i>=1;i--){
		if(a[i][i]==0) continue;
		for(j=i-1;j>=1;j--){
			a[j][n+1]-=a[j][i]*a[i][n+1];
			a[j][i]=0;
		}
	}
	for(i=1;i<=n;i++){
		if(fabs(a[i][i])<eps&&fabs(a[i][n+1])>eps) flag_less=1; 
        if(fabs(a[i][i])<eps&&fabs(a[i][n+1])<eps) flag_more=1;
	}
	if(flag_less) return (void)puts("-1");
	if(flag_more) return (void)puts("0");
	for(i=1;i<=n;i++){
		if(fabs(a[i][n+1])<=eps) printf("x%d=0\n",i);
		else printf("x%d=%.2f\n",i,a[i][n+1]+eps);
	}
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++) cin>>a[i][j];
	}
	Gauss();
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
