#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200010
#define M 500010
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"

inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}
void put(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) put(x/10);
	putchar((x%10)+48);
}
int n,m,q,tot,num,a[N],b[N],root[N],dfn[N],id[N],fa[N][20],siz[N];
int find(int x){return (x==id[x])?x:id[x]=find(id[x]);}
struct Seg{int l,r,w;}line[M];
inline bool cmp(const Seg &A,const Seg &B){return A.w<B.w;}
int head[N],cnt;
struct Edge{
	int nxt,to;
}edge[N];
inline void add(int x,int y){
	edge[++cnt].nxt=head[x];
	edge[cnt].to=y;
	head[x]=cnt;
}
struct Node{
	int lson,rson,siz;
}tree[N*30];
#define mid ((l+r)>>1)
void Insert(int A,int &B,int l,int r,int val){
	B=++num;tree[B]=tree[A];tree[B].siz++;
	if(l==r) return ;
	if(val<=mid) Insert(tree[A].lson,tree[B].lson,l,mid,val);
	else Insert(tree[A].rson,tree[B].rson,mid+1,r,val);
}
int Ask(int A,int B,int l,int r,int k){
	while(l!=r){
		if(tree[B].siz-tree[A].siz<k) return -1;
		if(tree[tree[B].rson].siz-tree[tree[A].rson].siz>=k){
//			cout<<l<<" "<<r<<" "<<mid<<" "<<tree[tree[B].rson].siz-tree[tree[A].rson].siz<<" "<<k<<" ";puts("fuck : 1");
			A=tree[A].rson;B=tree[B].rson;l=mid+1;
		}else{
//			cout<<l<<" "<<r<<" "<<mid<<" "<<tree[tree[B].rson].siz-tree[tree[A].rson].siz<<" "<<k<<" ";puts("fuck : 2");
			k-=tree[tree[B].rson].siz-tree[tree[A].rson].siz;
			A=tree[A].lson;B=tree[B].lson;r=mid;
		}
	}
	if(tree[B].siz-tree[A].siz<k) return -1;
	return l;
}
inline void Kruskal(){
	sort(line+1,line+m+1,cmp);
	for(int i=1,fx,fy;i<=m;i++){
		fx=find(line[i].l);fy=find(line[i].r);
		if(fx==fy) continue;
		++tot;
		id[fx]=id[fy]=tot;
		a[tot]=line[i].w;
		add(tot,fx);add(tot,fy);
//		cout<<tot<<"------>"<<fx<<"\n";
//		cout<<tot<<"------>"<<fy<<"\n";
	}
}
void dfs(int x){
	dfn[++tot]=x;id[x]=tot;siz[x]=1;
	for(int i=1;i<=19;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=edge[i].nxt){
		fa[edge[i].to][0]=x;dfs(edge[i].to);
		siz[x]+=siz[edge[i].to];
	}
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();m=read();q=read();
	int nn,i,j,ans=0,v,x,k;
	for(i=1;i<=n;i++){
		a[i]=b[i]=read();
	}
	sort(b+1,b+n+1);
	nn=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+nn+1,a[i])-b;
	}
	for(i=1;i<=(n<<1);i++) id[i]=i;
	for(i=1;i<=m;i++){
		line[i].l=read();line[i].r=read();line[i].w=read();
	}
	tot=n;
	Kruskal();
	j=tot;tot=0;
	dfs(j);
//	puts("fuck");
//	for(int i=1;i<=tot;i++) cout<<i<<" : "<<id[i]<<"\n";
//	puts("fuck");
	for(i=1;i<=tot;i++){
		if(dfn[i]>n) Insert(root[i-1],root[i],1,nn+1,1);
		else Insert(root[i-1],root[i],1,nn+1,a[dfn[i]]+1);
	}
	for(i=1;i<=q;i++){
		v=read()^ans;x=read()^ans;k=read()^ans;
		for(j=19;j>=0;j--){
			if(fa[v][j]&&a[fa[v][j]]<=x) v=fa[v][j];
		}
		ans=Ask(root[id[v]-1],root[id[v]+siz[v]-1],1,nn+1,k)-1;
		if(ans==-2||ans==0){
			puts("-1");ans=0;
		}else{
			put(b[ans]);putchar('\n');ans=b[ans];
		}
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

