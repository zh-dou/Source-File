#include<map>
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
#define N 10010
inline int read(){
	int x=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x;
}
int n,m;
int dp[N],a[N],from[N],ans[N];
signed main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(dp[i]<dp[j]+1&&a[i]>=a[j]){dp[i]=dp[j]+1;from[i]=j;}
		}
	}
	int fir,mx=-1,cnt=0;
	for(int i=n;i>=1;i--) 
		if(dp[i]>mx){
			mx=dp[i];fir=i;
		}
	while(fir){
		ans[++cnt]=a[fir];
		fir=from[fir];
	}
	for(int i=cnt;i>1;i--) cout<<ans[i]<<" ";
	cout<<ans[1];
	return 0;
}

