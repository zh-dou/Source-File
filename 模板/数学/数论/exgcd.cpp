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
inline void exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1;y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);

//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

