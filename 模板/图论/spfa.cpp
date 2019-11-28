#include<map>
#include<cmath>
#include<queue>
#include<cctype>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define N 500010
#define R register
inline int read(){
	int x=0,y=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
int n,m,s,dis[N],vis[N];
int head[N],tot;
struct Node{
    int nxt,to,dis;
}edge[N<<1];
inline void add(int x,int y,int z){
    edge[++tot].nxt=head[x];
    edge[tot].to=y;
    edge[tot].dis=z;
    head[x]=tot;
}
inline void spfa(int s){
    for(R int i=1;i<=n;i++)
        dis[i]=2147483647;
    queue<int>q;
    q.push(s);
    dis[s]=0;vis[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(R int i=head[u];i;i=edge[i].nxt){
            R int to=edge[i].to;
            if(dis[to]>dis[u]+edge[i].dis){
                dis[to]=dis[u]+edge[i].dis;
                if(!vis[to]){
                    vis[to]=1;
                    q.push(to);
                }
            }
        }
    }
    for(R int i=1;i<=n;i++)printf("%d ",dis[i]);
}
signed main(){
    n=read();m=read();s=read();
    for(R int i=1,x,y,z;i<=m;i++){
        x=read();y=read();z=read();
        add(x,y,z);
    }
    spfa(s);
    return 0;
}
