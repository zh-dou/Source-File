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
struct Edge{
    int to,flow,cost,nxt;
}edge[N];
int n,m,s,t,tot=1;
int flow[N],dep[N],last[N],pre[N],vis[N],head[N];//pre: point   last:edge
int maxflow,mincost;
inline void add(int from,int to,int flow,int cost){
    edge[++tot].nxt=head[from];
    edge[tot].to=to;
    edge[tot].flow=flow;
    edge[tot].cost=cost;
    head[from]=tot;
}
bool spfa(){
    memset(flow,0x3f,sizeof(flow));
    memset(dep,0x3f,sizeof(dep));
    memset(vis,0,sizeof(vis));
    dep[s]=0;
    pre[t]=-1;
    vis[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].to;
            if(dep[v]>dep[u]+edge[i].cost&&edge[i].flow){
                flow[v]=min(flow[u],edge[i].flow);
                dep[v]=dep[u]+edge[i].cost;
                pre[v]=u;last[v]=i;
                if(!vis[v]){
                    vis[v]=1;q.push(v);
                }
            }
        }
    }
    return pre[t]!=-1;
}
inline void Dinic(){
    while(spfa()){
        maxflow+=flow[t];
        mincost+=flow[t]*dep[t];
        int x=t;
        while(x!=s){
            edge[last[x]].flow-=flow[t];
            edge[last[x]^1].flow+=flow[t];
            x=pre[x];
        }
    }
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    n=read();m=read();s=read();t=read();
    for(int i=1,x,y,w,f;i<=m;i++){
    	x=read();y=read();w=read();f=read();
    	add(x,y,w,f);add(y,x,0,-f);
    }
    Dinic();
    cout<<maxflow<<" "<<mincost<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

