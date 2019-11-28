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
#define N 1000010
inline int read(){
    int x=0,y=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*y;
}
int c[N],n,m;
int lowbit(int x){return x&-x;}
inline void update(int x,int y){//	c[x]+y
    while(x<=n){
        c[x]+=y;
        x+=lowbit(x);
    }
}
inline int add(int x){
    int s=0;
    while(x){
        s+=c[x];
        x-=lowbit(x);
    }
    return s;
}
signed main(){
    memset(c,0,sizeof(c));
    n=read();m=read();
    for(int i=1,re=0,re2=0;i<=n;i++){re2=read();update(i,re2-re);re=re2;}
    for(int i=1,p0,p1,p2,p3;i<=m;i++){
        p0=read();
        if(p0==1){
            p1=read();p2=read();p3=read();
        	update(p1,p3);update(p2+1,-p3);
        }
        if(p0==2){
            p1=read();
            cout<<add(p1)<<"\n";
        }
    }
    return 0;
}
