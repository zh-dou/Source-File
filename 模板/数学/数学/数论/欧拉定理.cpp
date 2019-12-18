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
int a,m,phi=1,bm,flag;
inline int ksm(int x,int y){
    int ans=1;
    while(y){
    	if(y&1) ans=ans*x%m;
    	x=x*x%m;
    	y>>=1;
    }
    return ans;
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	a=read();m=read();
    a%=m;
    int mm=m;
    for(int i=2;i*i<=mm;i++){
        if(mm%i) continue;
        phi*=i-1;
        mm/=i;
        while(mm%i==0) phi*=i,mm/=i;
    }
	if(mm!=1) phi*=mm-1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
    	bm=(bm<<1)+(bm<<3)+(ch^48);ch=getchar();
    	if(bm>=phi) flag=1,bm%=phi;
    }
    if(bm>=phi) flag=1,bm%=phi;
    if(flag) bm+=phi;
    cout<<ksm(a,bm)<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

