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
map<int,int> M;
int x,y,mod;
inline int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans%mod;
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	while(scanf("%lld%lld%lld",&mod,&x,&y)!=EOF){
		x%=mod;y%=mod;
		if(!x){
			puts("no solution");
			continue;
		}
		M.clear();
		int res=ceil(sqrt(mod)),smul=y,flag=0;
		for(int i=0;i<=res;i++){
			M[smul]=i;
			smul=(smul*x)%mod;
	//		cout<<smul<<" ";
		}
	//	cout<<"\n233333333333\n";
		y=smul=ksm(x,res);
	//	cout<<y<<"\n";
		for(int i=1;i<=res;i++){
	//		cout<<i<<" "<<smul<<"\n";
			if(M.count(smul)){
				cout<<i*res-M[smul]<<"\n";
				flag=1;break;
			}
			smul=(smul*y)%mod;
		}
		if(!flag) puts("no solution");
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

