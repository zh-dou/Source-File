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

inline int read(){
	int x=0,y=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
inline int build(){
	for(int j=1;j<=21;j++)
		for(int i=1;(i+(1<<j)-1)<=n;i++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

