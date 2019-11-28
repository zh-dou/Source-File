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
struct Stack{
    int tp,s[80505];
    void pop(){tp--;}
    int top(){return s[tp];}
    bool empty(){return tp==0;}
    void push(int x){s[++tp]=x;}
    int size(){return tp;}
    void clear(){tp=0;}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);

//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

