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
#define N 200010
#define ls(node) (tree[node].lson)
#define rs(node) (tree[node].rson)
int n,m,mod,cnt,a[N];
inline int read(){
    int x=0;char ch=getchar();
    while(ch>'9'||ch<'0'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x;
}
struct Segment_tree{
	int lson,rson;
	int val,add,mul;
}tree[N<<1];
inline void pushup(int node){
    tree[node].val=(tree[ls(node)].val+tree[rs(node)].val);
}
inline void build(int l,int r,int &node){
	if(!node) node=++cnt;
	tree[node].mul=1;tree[node].add=0;
    if(l==r){
		tree[node].val=a[l];
		return;
	}
    int mid=(l+r)>>1;
    build(l,mid,ls(node));build(mid+1,r,rs(node));
    pushup(node);
}
inline void solve(int node,int k,int b,int len){
	tree[node].mul=(tree[node].mul*k)%mod;
	tree[node].add=(tree[node].add*k+b)%mod;
	tree[node].val=(tree[node].val*k+(b*len)%mod)%mod;
}
inline void pushdown(int node,int ln,int rn){
    solve(ls(node),tree[node].mul,tree[node].add,ln);
    solve(rs(node),tree[node].mul,tree[node].add,rn);
    tree[node].mul=1,tree[node].add=0;
}
void update(int l,int r,int L,int R,int k,int b,int node){
	if(l>R||r<L) return;
    if(L<=l&&r<=R){solve(node,k,b,r-l+1);return;}
    int mid=(l+r)>>1;
    if(tree[node].mul!=1||tree[node].add) pushdown(node,mid-l+1,r-mid);
    update(l,mid,L,R,k,b,ls(node));update(mid+1,r,L,R,k,b,rs(node));
    pushup(node);
}
inline int qu_sum(int l,int r,int L,int R,int node){
    if(l>R||r<L) return 0;
    if(L<=l&&r<=R) return tree[node].val%mod;
    int mid=(l+r)>>1;
    if(tree[node].mul!=1||tree[node].add) pushdown(node,mid-l+1,r-mid);
    return ((qu_sum(l,mid,L,R,tree[node].lson)%mod)+(qu_sum(mid+1,r,L,R,tree[node].rson)%mod))%mod;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int root=0;
	n=read();m=read();mod=read();
	for(int i=1;i<=n;i++) a[i]=read()%mod;
	build(1,n,root);
	for(int i=1;i<=m;i++){
		int opt=read(),l=read(),r=read();
		if(opt==3) cout<<qu_sum(1,n,l,r,root)<<"\n";
		else{
			int val=read();
			if(opt==1) update(1,n,l,r,val,0,root);
			if(opt==2) update(1,n,l,r,1,val,root);
		}
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

