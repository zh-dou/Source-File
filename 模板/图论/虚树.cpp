#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"

inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}
int n,tim,dfn[N],fa[N][17],dep[N];
int m,sum,tag[N],col[N];
inline bool cmp(const int &a,const int &b){
	return dfn[a]<dfn[b];
}
int head[N],cnt;
struct Edge{
	int nxt,to;
}edge[N<<1];
inline void add(int x,int y){
	edge[++cnt].nxt=head[x];
	edge[cnt].to=y;
	head[x]=cnt;
}
void dfs(int x){
	dfn[x]=++tim;dep[x]=dep[fa[x][0]]+1;
	for(int i=head[x];i;i=edge[i].nxt){
		if(edge[i].to==fa[x][0]) continue;
		fa[edge[i].to][0]=x;dfs(edge[i].to);
	}
}
#define calc(x,y) (dep[x]<dep[y]?x:y)
inline int LCA(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
    for(int i=16;i>=0;i--)
        if(dep[x]<=dep[y]-(1<<i))y=fa[y][i];
    if(x==y) return x;
    for(int i=16;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int top,sta[N];
void Build(){
	sort(col+1,col+sum+1,cmp);
	if(col[1] != 1) sta[top=1]=1;
	for(int i=1,lca;i<=sum;i++){
//		cout<<i<<" : ";for(int j=1;j<=top;j++) cout<<sta[j]<<" ";
//		cout<<"\n";
//		if(!top){
//			sta[++top]=a[i];continue;
//		}
		if(sta[top]==col[i]) continue;
		if(top <= 1) { sta[++ top] = col[i]; continue; }
		lca=LCA(col[i],sta[top]);
		if(lca==sta[top]){sta[++top]=col[i];continue;}
		while(top-1>0&&dep[lca]<=dep[sta[top-1]]){
			add(sta[top-1],sta[top]);
			top--;
		}
		if(sta[top]!=lca){
			add(lca,sta[top]);
			sta[top]=lca;
		}
		sta[++top]=col[i];
	}
//	cout<<"5 : ";for(int j=1;j<=top;j++) cout<<sta[j]<<" ";
//	cout<<"\n";
//	puts("-1-1-1");
	while(top>1){add(sta[top-1],sta[top]);--top;}
}
int f[N],g[N];
void DP(int x){
//	cout<<x<<"\n";
	f[x]=g[x]=0;
	for(int i=head[x];i;i=edge[i].nxt){
		if(edge[i].to==fa[x][0]) continue;
		DP(edge[i].to);
		f[x]+=f[edge[i].to];g[x]+=g[edge[i].to];
	}
	if(tag[x]){f[x]+=g[x];g[x]=1;}
	else{
		f[x]+=(g[x]>1);g[x]=(g[x]==1);
	}
	head[x]=0;
}
inline void Solve(){
	for(int j=1;j<=sum;j++){
		if(tag[col[j]]&&tag[fa[col[j]][0]]){
			puts("-1");
			return ;
		}
	}
	Build(); DP(1);
//	for(int i=1;i<=n;i++) cout<<f[i]<<" "<<g[i]<<"\n";
	cout<<f[1]<<"\n";
	
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();
	for(int i=1,x,y;i<n;i++){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	dfs(1);
	for(int i=1;i<=16;i++){
		for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	for(int i=1;i<=n;i++) head[i]=0;cnt=0;
	m=read();
	for(int i=1;i<=m;i++){
		sum=read();
		for(int j=1;j<=sum;j++){
			col[j]=read();tag[col[j]]=1;
		}
		Solve();
		for(int j=1;j<=sum;j++) tag[col[j]]=0;cnt=0;
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
