#include <cmath>
#include <queue>
#include <cctype>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define N 1000010
inline int read(){
	int x=0,y=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
int a[N],c[N],n,m,p1,p2,p3;
int lowbit(int x){return x&-x;}
inline void insert(int x,int y){//	c[x]+y
    while(x<=n){
        c[x]+=y;
        x+=lowbit(x);
    }
    return;
}
inline int ask(int x){
    int s=0;
    while(x>0){
        s+=c[x];
        x-=lowbit(x);
    }
    return s;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){a[i]=read();insert(i,a[i]);}
    for(int i=1;i<=m;i++){
        p1=read();p2=read();p3=read();
        if(p1==1) insert(p2,p3);
        if(p1==2) cout<<ask(p3)-ask(p2-1)<<"\n";
    }
    return 0;
}
