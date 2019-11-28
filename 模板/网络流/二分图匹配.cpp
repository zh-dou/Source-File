#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 1000010
#define int long long
inline int read(){
 	int x=0,y=1;
 	char ch=getchar();
 	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
 	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
 	return x*y;
}
int n,m,e,ans,vis[2010],to[2010];
struct Node{
	int nxt,to;
}edge[N<<1];
int head[2010],cnt=1;
inline void add(int u,int v){
	edge[++cnt].nxt=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
}
int dfs(int s){
	for(int i=head[s];i;i=edge[i].nxt){
		if(vis[edge[i].to]) continue;
		vis[edge[i].to]=1;
		if(!to[edge[i].to]||dfs(to[edge[i].to])){
			to[edge[i].to]=s;return 1;
		}
	}
	return 0;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();m=read();e=read();
	for(int i=1,u,v;i<=e;i++){
		u=read();v=read();
		if(u>n||v>m) continue;
		add(u,v);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) vis[j]=0;
		if(dfs(i)) ans++;
	}
//	for(int i=1;i<=m;i++) cout<<to[i]<<" ";
//	cout<<"\n";
	cout<<ans<<"\n";
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

