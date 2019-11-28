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
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"

inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}
double Gauss[111][111];
double ans[111];
const double eps=1e-7;
signed main(){
    int n=read(),r;
    register int i,j,k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n+1;j++)
            cin>>Gauss[i][j];
    double div;
    for(i=1;i<=n;i++){
        r=i;
        for(j=i+1;j<=n;j++)
            if(fabs(Gauss[r][i])<fabs(Gauss[j][i]))
                r=j;
        if(fabs(Gauss[r][i])<eps){
            printf("No Solution");
            return 0;
        }
        if(i!=r) swap(Gauss[i],Gauss[r]);
        div=Gauss[i][i];
        for(j=i;j<=n+1;j++)
            Gauss[i][j]/=div;
        for(j=i+1;j<=n;j++){
            div=Gauss[j][i];
            for(k=i;k<=n+1;k++)
                Gauss[j][k]-=Gauss[i][k]*div;
        }
    }
    ans[n]=Gauss[n][n+1];
    for(int i=n-1;i>=1;i--){
        ans[i]=Gauss[i][n+1];
        for(int j=i+1;j<=n;j++)
            ans[i]-=(Gauss[i][j]*ans[j]);
    }
    for(int i=1;i<=n;i++)
        printf("%.2lf\n",ans[i]);
    return 0;
}
