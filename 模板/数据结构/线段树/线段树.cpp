#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define N 1000010
inline int read(){
    int x=0,y=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*y;
}
#define ls(x) tree[(x)].lson
#define rs(x) tree[(x)].rson
int n,m,a[N],cnt;
struct Segement_tree{
    int lson,rson,lazy;
    int val;
}tree[N<<1];
inline void pushup(int node){
    tree[node].val=tree[ls(node)].val+tree[rs(node)].val;
}
inline void build(int l,int r,int &node){
    if(!node) node=++cnt;
    if(l==r){tree[node].val=a[l];return;}
    int m=(l+r)>>1;
    build(l,m,ls(node));build(m+1,r,rs(node));
    pushup(node);
}
inline void pushdown(int node,int ln,int rn){
    if(tree[node].lazy){
        tree[ls(node)].lazy+=tree[node].lazy;
        tree[rs(node)].lazy+=tree[node].lazy;
        tree[ls(node)].val+=tree[node].lazy*ln;
        tree[rs(node)].val+=tree[node].lazy*rn;
        tree[node].lazy=0;
    }
}
inline void qu_update(int l,int r,int L,int R,int z,int node){
    if(l>R||r<L) return;
    if(L<=l&&r<=R){tree[node].val+=z*(r-l+1);tree[node].lazy+=z;return;}
    int mid=(l+r)>>1;
    pushdown(node,mid-l+1,r-mid);
    qu_update(l,mid,L,R,z,ls(node));qu_update(mid+1,r,L,R,z,rs(node));
    pushup(node);
}
inline int qu_sum(int l,int r,int L,int R,int node){
    if(l>R||r<L) return 0;
    if(L<=l&&r<=R) return tree[node].val;
    int mid=(l+r)>>1;
    pushdown(node,mid-l+1,r-mid);
    return (qu_sum(l,mid,L,R,ls(node))+qu_sum(mid+1,r,L,R,rs(node)));
}
signed main(){
    int root=0;
    n=read();m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build(1,n,root);
    for(int i=1,q,w,e,r;i<=m;i++){
        q=read();w=read();e=read();
        if(q==1) {r=read();qu_update(1,n,w,e,r,root);}
        if(q==2) cout<<qu_sum(1,n,w,e,root)<<"\n";
    }
    return 0;
}
