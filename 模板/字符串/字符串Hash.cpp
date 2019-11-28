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
#define ull usigned long long
inline int read(){
	int x=0,y=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
inline ull has(char *s){
	int len=strlen(s);
	ull res=1;
	for(int i=0;i<len;i++)
		res=res*base+(ull)s[i];
	return res;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

