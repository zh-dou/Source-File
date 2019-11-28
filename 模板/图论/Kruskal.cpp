#include <map>
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
#define R register
#define int long long
#define N 1000010
int n,m,num,t;
int fa[N];
inline int read(){
    int x=0,y=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*y;
}
struct node{
    int l,r,w;//左端点,右端点,权值 
}a[N*2];
bool comp(const node &a,const node &b){return a.w<b.w;}
int cnt,head[N];
struct Node{
    int nxt,to;
}edge[N<<1];
inline void add(int x,int y){
    edge[++cnt].nxt=head[x];
    edge[cnt].to=y;
    head[x]=cnt;
}
inline int finds(int x){
    if(x==fa[x])return x;
    return fa[x]=finds(fa[x]);
} 
inline void Kruskal(){
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int fx=finds(a[i].l),fy=finds(a[i].r);
        if(fx==fy) continue;
        fa[fx]=fy;
        t+=a[i].w;
//		add(x,y);add(x,y);
    }
}
signed main(){
    n=read();m=read();
    for(int i=1,x,y,z;i<=m;i++){
        x=read();y=read();z=read();
        a[i].l=x;a[i].r=y;a[i].w=z;
    } 
    sort(a+1,a+1+m,comp);
    Kruskal();
    printf("%d\n",t);
    return 0;
}
