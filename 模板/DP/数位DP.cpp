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
inline int read(){
 	int x=0,y=1;
 	char ch=getchar();
 	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
 	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
 	return x*y;
}
int dp[12][10];
inline void work(){
	register int i,j,k;
	for(i=0;i<10;i++)
		dp[1][i]=1;
	for(i=2;i<12;i++){
		for(j=0;j<10;j++){
			for(k=0;k<10;k++){
				if(abs(j-k)>=2) dp[i][j]+=dp[i-1][k];
			}
		}
	}
}
inline int calc(int x){
	int b[12],cnt=0,ans=0;
	register int i,j;
	while(x){b[++cnt]=x%10;x/=10;}
	for(i=0;i<cnt;i++)
		for(j=1;j<10;j++)
			ans+=dp[i][j];
	for(i=1;i<b[cnt];i++) ans+=dp[cnt][i];
	for(i=cnt-1;i>=1;i--){
		for(j=0;j<b[i];j++){
			if(abs(j-b[i+1])>=2) ans+=dp[i][j];
		}
		if(abs(b[i]-b[i+1])<2) break;
	}
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int a=read(),b=read();
	work();
	cout<<(calc(b+1)-calc(a))<<"\n";
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

