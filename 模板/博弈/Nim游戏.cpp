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

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read(),ans,n;
	while(T--){
		ans=0;n=read();
		for(int i=1;i<=n;i++) ans^=read();
		if(ans) puts("Yes");
		else puts("No"); 
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

