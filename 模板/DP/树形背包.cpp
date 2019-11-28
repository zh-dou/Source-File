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
#define N 580
inline int read(){
	int x=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x;
}
int n,m;
int head[N],tot,cost[N],val[N];
struct Node{
    int nxt,to;
}edge[N<<2];
int f[4][100100];
inline void add(int u,int v){
    edge[++tot].nxt=head[u];edge[tot].to=v;head[u]=tot;
    swap(u,v);
    edge[++tot].nxt=head[u];edge[tot].to=v;head[u]=tot;
}
void dfs(int now,int fa,int v,int flag){
	if(v==0) return;
	register int i,j;
	for(i=head[now];i;i=edge[i].nxt){
		int to=edge[i].to;
		if(to==fa) return;
		for(j=0;j<v;j++) f[flag+1][j]=f[flag][j];
		dfs(to,now,v-cost[now],flag+1);
		for(j=v;j>=cost[to];j--){
			f[flag][j]=max(f[flag][j],f[flag+1][j-cost[to]]+val[to]);
		}
	}
}
signed main(){
	n=read();m=read();
	register int i,j;
	int res=n;
	for(i=1;i<=n;i++){
		add(0,i);cost[i]=read();
		int game=read();
		for(j=1;j<=game;j++){
			add(i,res+j);cost[res+j]=read();val[res+j]=read();
		}
		res+=game;
	}
	dfs(0,0,m,0);
	cout<<f[0][m]<<"\n";
	return 0;
}

