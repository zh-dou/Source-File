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
#define N 300010
inline int read(){
	int x=0,y=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
int depth[N],f[N][20];
int cnt,head[N];
struct Node{
    int nxt,to,dis;
}edge[N<<1];
inline void dfs(int u){
	depth[u]=depth[f[u][0]]+1;
	for(int i=1;(1<<i)<=depth[u];i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].nxt){
		if(edge[i].to==f[u][0])continue;
		f[edge[i].to][0]=u;dfs(edge[i].to);
	}
}
inline int lca(int x,int y){
	if(depth[x]>depth[y])swap(x,y);
	for(int i=17;i>=0;i--)
		if(depth[x]+(1<<i)<=depth[y]) y=f[y][i];
	if(x==y) return x;
	for(int i=17;i>=0;i--){
		if(f[x][i]==f[y][i]) continue;
		x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);

//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

