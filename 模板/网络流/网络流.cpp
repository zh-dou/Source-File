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
int n,m,s,t,dep[N];
int head[N],used[N],tot=1,front;
int ans;
struct Node{
    int nxt,to,dis;
}edge[N<<1];
inline void add(int x,int y,int z){
    edge[++tot].nxt=head[x];
    edge[tot].to=y;
    edge[tot].dis=z;
    head[x]=tot;
}
queue<int> q;
inline int bfs(){
	register int i;
	for(i=0;i<=n;i++) dep[i]=-1,used[i]=head[i];
	dep[s]=0;
	q.push(s);
	while(!q.empty()){
		front=q.front();q.pop();
//		debug;
		for(i=head[front];i;i=edge[i].nxt){
			if(edge[i].dis&&dep[edge[i].to]==-1){
				dep[edge[i].to]=dep[front]+1;q.push(edge[i].to);
			}
		}
	}
//	debug;
	return dep[t]!=-1;
}
int dfs(int now,int limit){
	if(!limit||now==t) return limit;
	int flow=0;
	for(int &i=used[now],pro;i;i=edge[i].nxt){
		if(dep[edge[i].to]==dep[now]+1&&(pro=dfs(edge[i].to,min(limit,edge[i].dis)))){
			edge[i].dis-=pro;
			edge[i^1].dis+=pro;
			flow+=pro;
			limit-=pro;
		}
	}
//	cout<<flow<<" ";debug;
	return flow;
}
inline void Dinic(){
	while(bfs()) ans+=dfs(s,100000001);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();m=read();s=read();t=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read();v=read();w=read();
		add(u,v,w);add(v,u,0);
	}
	Dinic();
	cout<<ans<<"\n";
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

