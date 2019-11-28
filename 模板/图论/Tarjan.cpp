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
#define N 200010
//#define int long long
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
struct Node{
	int nxt,to;
}edge[N];
int n,m,u[N],v[N],cnt,num,tot,f[N],ans;
int col[N],vis[N],dfn[N],low[N],sum[N],val[N],head[N];
void add(int u,int v){
	edge[++tot].nxt=head[u];
	edge[tot].to=v;
	head[u]=tot;
}
struct stack{
protected:
	int tp,st[N];
public:
	void push(int val){st[++tp]=val;}
	void pop(){tp--;}
	int top(){return st[tp];}
	bool empty(){return tp==0;}
	int size(){return tp;}
}s;
void tarjan(int x){
	vis[x]=1;
	s.push(x);
	low[x]=dfn[x]=++num;
	for(int i=head[x];i;i=edge[i].nxt){
		int to=edge[i].to;
		if(!dfn[to]){
			tarjan(to);
			low[x]=min(low[to],low[x]);
		}
		else if(vis[to])low[x]=min(low[x],dfn[to]);
	}
	if(dfn[x]==low[x]){
		cnt++;
		int now=-1;
		while(now!=x){
			now=s.top();
			s.pop();
			col[now]=cnt;
			sum[cnt]+=val[now];
			vis[now]=0;
		}
	}
}
void search(int x){                  
	if(f[x]) return;
	f[x]=sum[x];
	int maxsum=0;
	for(int i=head[x];i;i=edge[i].nxt){
		int to=edge[i].to;
		if(!f[to])search(to);
		maxsum=max(maxsum,f[to]);
	}
	f[x]+=maxsum;
} 
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) val[i]=read();
	for(int i=1;i<=m;i++){
		u[i]=read();v[i]=read();
		add(u[i],v[i]);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	memset(vis,0,sizeof(vis));
	memset(head,0,sizeof(head));
	memset(edge,0,sizeof(edge));
	tot=0;
	for(int i=1;i<=m;i++){
		if(col[u[i]]!=col[v[i]]){
			add(col[u[i]],col[v[i]]);
		}
	}
	for(int i=1;i<=cnt;i++){
		if(!f[i]){
			search(i);
			ans=max(ans,f[i]);
		}
	}
	cout<<ans<<"\n";
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}/*
6 8
1 1 1 1 1 1
1 3
3 5
5 6
3 4
4 6
2 4
1 2
4 1
*/

