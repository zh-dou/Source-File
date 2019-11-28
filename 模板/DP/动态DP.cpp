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
#define N 200010
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
int n,m,val[N],f[N][2],g[N][2];

int head[N],tot;
struct Edge{
	int nxt,to;
}edge[N<<1];

struct Matrix{
	int a[3][3];
	Matrix(int a_11=0,int a_12=0,int a_21=0,int a_22=0){
		a[1][1]=a_11;a[1][2]=a_12;
		a[2][1]=a_21;a[2][2]=a_22;
	}
};

int root,cnt;
struct Node{
	int lson,rson;
	Matrix M;
}tree[N<<1];

int num,son[N],fa[N],siz[N],dfn[N],id[N],top[N],bot[N];

char ch[3];
/*----------  Edge  ----------*/
inline void add(int u,int v){
	edge[++tot].nxt=head[u];
	edge[tot].to=v;
	head[u]=tot;
}
/*---------- Matrix ----------*/
inline Matrix mul(const Matrix &a,const Matrix &b){
	Matrix c;
	for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++) c.a[i][j]=-2147483647;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            for(int k=1;k<=2;k++)
                c.a[i][j]=max(c.a[i][j],a.a[i][k]+b.a[k][j]);
	return c;
}
/*----------Seg_Tree----------*/
#define mid ((l+r)>>1)
#define Update {tree[node].M=mul(tree[tree[node].rson].M,tree[tree[node].lson].M);}
void Tree_Build(int &node,int l,int r){
	node=++cnt;
	if(l==r){
		tree[node].M=Matrix(g[id[l]][0],g[id[l]][1],g[id[l]][0],-2147483647);
//		cout<<node<<" "<<l<<" "<<r<<":\n";
//		cout<<tree[node].M.a[1][1]<<" "<<tree[node].M.a[1][2]<<"\n";
//		cout<<tree[node].M.a[2][1]<<" "<<tree[node].M.a[2][2]<<"\n";
		return;
	}
	Tree_Build(tree[node].lson,l,mid);
	Tree_Build(tree[node].rson,mid+1,r);
	Update;
//	cout<<node<<" "<<l<<" "<<r<<":\n";
//	cout<<tree[node].M.a[1][1]<<" "<<tree[node].M.a[1][2]<<"\n";
//	cout<<tree[node].M.a[2][1]<<" "<<tree[node].M.a[2][2]<<"\n";
}
void Tree_Change(int node,int l,int r,int pos){
	if(l==r){
		tree[node].M=Matrix(g[id[l]][0],g[id[l]][1],g[id[l]][0],-2147483647);
		return;
	}
	if(pos<=mid) Tree_Change(tree[node].lson,l,mid,pos);
	else Tree_Change(tree[node].rson,mid+1,r,pos);
	Update;
}
Matrix Tree_Query(int node,int l,int r,int L,int R){
	if(L<=l&&r<=R) return tree[node].M;
	Matrix res=Matrix(0,(-2147483647),(-2147483647),0);
	if(R>mid) res=mul(res,Tree_Query(tree[node].rson,mid+1,r,L,R));
	if(L<=mid) res=mul(res,Tree_Query(tree[node].lson,l,mid,L,R));
	return res;
}
//void bian(int node,int l,int r){
//	if(l==r){
//		cout<<node<<" "<<l<<" "<<r<<":\n";
//		cout<<tree[node].M.a[1][1]<<" "<<tree[node].M.a[1][2]<<"\n";
//		cout<<tree[node].M.a[2][1]<<" "<<tree[node].M.a[2][2]<<"\n";
//		return;
//	}
//	bian(tree[node].lson,l,mid);
//	bian(tree[node].rson,mid+1,r);
//	cout<<node<<" "<<l<<" "<<r<<":\n";
//	cout<<tree[node].M.a[1][1]<<" "<<tree[node].M.a[1][2]<<"\n";
//	cout<<tree[node].M.a[2][1]<<" "<<tree[node].M.a[2][2]<<"\n";
//}
#undef mid
#undef Update
/*----------Tree_Div----------*/
void dfs1(int x){
	siz[x]=1;
	f[x][1]=val[x];
	for(int i=head[x];i;i=edge[i].nxt){
		if(edge[i].to==fa[x]) continue;
		fa[edge[i].to]=x;
		dfs1(edge[i].to);
		siz[x]+=siz[edge[i].to];
		f[x][1]+=f[edge[i].to][0];
		f[x][0]+=max(f[edge[i].to][0],f[edge[i].to][1]);
		if(siz[edge[i].to]>siz[son[x]]) son[x]=edge[i].to;
	}
}
void dfs2(int x,int tp){
	top[x]=tp;
	dfn[x]=++num;id[num]=x;
	g[x][1]=val[x];
	if(son[x]){
		dfs2(son[x],tp);
		bot[x]=bot[son[x]];
	}else{
		bot[x]=x;
		return;
	}
	for(int i=head[x];i;i=edge[i].nxt){
		if(edge[i].to==fa[x]||edge[i].to==son[x]) continue;
		dfs2(edge[i].to,edge[i].to);
		g[x][1]+=f[edge[i].to][0];
		g[x][0]+=max(f[edge[i].to][0],f[edge[i].to][1]);
	}
}
inline int Query(int x){
//	x=top[x];
	Matrix ans=Tree_Query(root,1,n,dfn[x],dfn[bot[x]]);
//	x=fa[top[x]];
//	while(x){
//		ans=mul(ans,Tree_Query(root,1,n,dfn[top[x]],dfn[x]));
//		x=fa[top[x]];
//	}
	return max(ans.a[1][1],ans.a[1][2]);
}
inline void Change(int x){
	Matrix res;
	while(x){
		res=Tree_Query(root,1,n,dfn[top[x]],dfn[bot[x]]);
		g[fa[top[x]]][0]-=max(res.a[1][1],res.a[1][2]);
		g[fa[top[x]]][1]-=res.a[1][1];
		Tree_Change(root,1,n,dfn[x]);
		res=Tree_Query(root,1,n,dfn[top[x]],dfn[bot[x]]);
		g[fa[top[x]]][0]+=max(res.a[1][1],res.a[1][2]);
		g[fa[top[x]]][1]+=res.a[1][1];
		x=fa[top[x]];
	}
}
/*----------  Main  ----------*/
signed main(){
// 	freopen("c.in","r",stdin);
// 	freopen("c.out","w",stdout);
	n=read();m=read();
	register int x,y,i;
	for(i=1;i<=n;i++)
		val[i]=read();
	for(i=1;i<n;i++){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	dfs1(1);dfs2(1,1);
//	for(int i=1;i<=n;i++){
//		cout<<i<<" "<<f[i][0]<<" "<<f[i][1]<<" "<<g[i][0]<<" "<<g[i][1]<<"\n";
//	}
	Tree_Build(root,1,n);
	for(i=1;i<=m;i++){
		x=read();y=read();
		g[x][1]=g[x][1]-val[x]+y;
		val[x]=y;
		Change(x);
		cout<<Query(1)<<"\n";
//		for(int i=1;i<=n;i++) cout<<Query(i)<<" ";
//		cout<<"\n";
//		for(int i=1;i<=n;i++) cout<<g[i]<<" ";
//		cout<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}

