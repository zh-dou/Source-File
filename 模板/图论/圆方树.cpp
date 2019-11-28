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
#define N 2000010
#define int long long
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"

inline int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*y;
}
void put(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) put(x/10);
	putchar((x%10)+48);
}
vector<int> E[N<<1];
struct Edge{
	int u,v,nxt;
}edge[N<<2];
int head[N],tot;
void add(int u,int v){
	edge[++tot].nxt=head[u];
	edge[tot].u=u;
	edge[tot].v=v;
	head[u]=tot;
}
int top,sta[N];
int n,m,Q,cnt,dfn[N],low[N];
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	sta[++top]=u;
	for(int i=head[u];i;i=edge[i].nxt) {
		int v=edge[i].v;
//		if(v == father) continue;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				++n;
				E[u].push_back(n);
				E[n].push_back(u);
				while(sta[top+1]!=v) {
					E[sta[top]].push_back(n);
					E[n].push_back(sta[top]);
					--top;
				}
			}
		}
		else low[u] = min(low[u],dfn[v]);
	}
}
int dep[N],fa[N][20],sum[N];
void dfs(int u){
	dep[u]=dep[fa[u][0]]+1;
	for(int i=1;i<20;++i)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=0;i<E[u].size();++i){
		int v=E[u][i];
		if(v==fa[u][0]) continue;
		fa[v][0]=u;
		dfs(v);
	}
}
int lca(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;--i){
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	}
	for(int i=19;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];y=fa[y][i];
		}
	}
	if(x!=y) x=fa[x][0];
	return x;
}
void dfs2(int u){
	for(int i=0;i<E[u].size();++i){
		int v=E[u][i];
		if(v==fa[u][0]) continue;
		dfs2(v);
		sum[u]+=sum[v];
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),m=read(),Q=read();
	int res=n;
	for(int i=1,u,v;i<=m;++i) {
		u=read();v=read();
		add(u,v);add(v,u);
	}
	tarjan(1);
	dfs(1);
	for(int i = 1,u,v,L;i <= Q;++i) {
		u=read();v=read();L=lca(u,v);
		sum[u]++;sum[v]++;sum[L]--;sum[fa[L][0]]--;
	}
	dfs2(1);
	for(int i=1;i<=res;++i) cout<<sum[i]<<"\n";
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

