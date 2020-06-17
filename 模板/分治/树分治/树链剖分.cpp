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
inline int read(){
 	int x=0,y=1;
 	char ch=getchar();
 	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
 	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
 	return x*y;
}
struct Edge{
    int nxt,to;
}edge[N<<1];
int n,m,root,rt,mod,val[N],head[N],cnt,tot,fa[N],dep[N],son[N],size[N],top[N],dfn[N],id[N];
inline void add(int x,int y){
    edge[++cnt].nxt=head[x];edge[cnt].to=y;head[x]=cnt;
    swap(x,y);
    edge[++cnt].nxt=head[x];edge[cnt].to=y;head[x]=cnt;
}
void dfs1(int x){
    size[x]=1,dep[x]=dep[fa[x]]+1;
    for(int v,i=head[x];i;i=edge[i].nxt)
        if((v=edge[i].to)!=fa[x]){
            fa[v]=x,dfs1(v),size[x]+=size[v];
            if(size[son[x]]<size[v])
                son[x]=v;
        }
}
void dfs2(int x,int tp){
    top[x]=tp,dfn[x]=++cnt,id[cnt]=x;
    if(son[x]) dfs2(son[x],tp);
    for(int v,i=head[x];i;i=edge[i].nxt){
    	if((v=edge[i].to)!=fa[x]&&v!=son[x])
            dfs2(v,v);
    }
}
struct Segment_Tree{
	struct Node{
	    int l,r,ls,rs,sum,lazy;
	}tree[N<<1];
	inline void pushup(int x){
	    tree[x].sum=(tree[tree[x].ls].sum+tree[tree[x].rs].sum)%mod;
	}
	void build(int l,int r,int x){
	    if(l==r){
	        tree[x].sum=val[id[l]],tree[x].l=tree[x].r=l;
	        return;
	    }
	    int mid=(l+r)>>1;
	    tree[x].ls=tot++;tree[x].rs=tot++;
	    build(l,mid,tree[x].ls);build(mid+1,r,tree[x].rs);
	    tree[x].l=l;tree[x].r=r;
	    pushup(x);
	}
	inline int len(int x){
	    return tree[x].r-tree[x].l+1;
	}
	inline void pushdown(int x){
	    if(tree[x].lazy){
	        int lz=tree[x].lazy;
	        (tree[tree[x].ls].lazy+=lz)%=mod;(tree[tree[x].rs].lazy+=lz)%=mod;
	        (tree[tree[x].ls].sum+=lz*len(tree[x].ls))%=mod;(tree[tree[x].rs].sum+=lz*len(tree[x].rs))%=mod;
	        tree[x].lazy=0;
	    }
	}
	void update(int l,int r,int c,int x){
	    if(tree[x].l>=l&&tree[x].r<=r){
	        (tree[x].lazy+=c)%=mod;(tree[x].sum+=len(x)*c)%=mod;
	        return;
	    }
	    pushdown(x);
	    int mid=(tree[x].l+tree[x].r)>>1;
	    if(mid>=l) update(l,r,c,tree[x].ls);
	    if(mid<r) update(l,r,c,tree[x].rs);
	    pushup(x);
	}
	int query(int l,int r,int x){
	    if(tree[x].l>=l&&tree[x].r<=r)
	        return tree[x].sum;
	    pushdown(x);
	    int mid=(tree[x].l+tree[x].r)>>1,tot=0;
	    if(mid>=l)
	        tot+=query(l,r,tree[x].ls);
	    if(mid<r)
	        tot+=query(l,r,tree[x].rs);
	    return tot%mod;
	}
	inline int sum(int x,int y){
	    int ret=0;
	    while(top[x]!=top[y]){
	        if(dep[top[x]]<dep[top[y]])
	            swap(x,y);
	        (ret+=query(dfn[top[x]],dfn[x],rt))%=mod;
	        x=fa[top[x]];
	    }
	    if(dfn[x]>dfn[y])
	        swap(x,y);
	    return (ret+query(dfn[x],dfn[y],rt))%mod;
	}
	inline void updates(int x,int y,int c){
	    while(top[x]!=top[y]){
	        if(dep[top[x]]<dep[top[y]])
	            swap(x,y);
	        update(dfn[top[x]],dfn[x],c,rt);
	        x=fa[top[x]];
	    }
	    if(dfn[x]>dfn[y])
	        swap(x,y);
	    update(dfn[x],dfn[y],c,rt);
	}
}Tree;
signed main(){
    n=read();m=read();root=read();mod=read();
    for(int i=1;i<=n;i++) val[i]=read();
    for(int x,y,i=1;i<n;i++){
        x=read();y=read();
        add(x,y);
    }
    cnt=0;
	dfs1(root);dfs2(root,root);
    Tree.build(1,n,rt=tot++);
    for(int op,x,y,k,i=1;i<=m;i++){
        op=read();
        if(op==1){
            x=read();y=read();k=read();
            Tree.updates(x,y,k);
        }
        if(op==2){
            x=read();y=read();
            cout<<Tree.sum(x,y)<<"\n";
        }
        if(op==3){
            x=read();y=read();
            Tree.update(dfn[x],dfn[x]+size[x]-1,y,rt);
        }
        if(op==4){
            x=read();
            cout<<Tree.query(dfn[x],dfn[x]+size[x]-1,rt)<<"\n";
        }
    }
    return 0;
}
