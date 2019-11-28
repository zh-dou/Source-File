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
int n,m;
struct Node{
  int lson,rson,fa,dep;
}tree[N*40];
int root[N],tot;
void Build(int &node,int l,int r){
    node=++tot;
    if(l==r){
        tree[node].fa=l;
        return;
    }
    int mid=l+r>>1;
    Build(tree[node].lson,l,mid);
    Build(tree[node].rson,mid+1,r);
}
void Insert(int &node,int last,int l,int r,int pos,int val){
    node=++tot;
    if(l==r){
        tree[node].fa=val;
        tree[node].dep=tree[last].dep;
        return;
    }
    tree[node].lson=tree[last].lson;tree[node].rson=tree[last].rson;
    int mid=l+r>>1;
    if(pos<=mid) Insert(tree[node].lson,tree[last].lson,l,mid,pos,val);
    else Insert(tree[node].rson,tree[last].rson,mid+1,r,pos,val);
}
int query(int node,int l,int r,int pos){
    if(l==r) return node;
    int mid=l+r>>1;
    if(pos<=mid) return query(tree[node].lson,l,mid,pos);
    else return query(tree[node].rson,mid+1,r,pos);
}
void Add(int node,int l,int r,int pos){
    if(l==r){
        ++tree[node].dep;
        return;    
    }
    int mid=l+r>>1;
    if(pos<=mid) Add(tree[node].lson,l,mid,pos);
    else Add(tree[node].rson,mid+1,r,pos);
}
int Find(int node,int x){
    int fa=query(node,1,n,x);
    if(x==tree[fa].fa) return fa;
    return Find(node,tree[fa].fa);
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read(),m=read();
    Build(root[0],1,n);
    for(int opt,k,a,b,i=1;i<=m;++i) {
        opt=read();
        if(opt==1) {
            root[i]=root[i-1];
            a=read(),b=read();
            int f1=Find(root[i],a);
            int f2=Find(root[i],b);
            if(tree[f1].fa==tree[f2].fa) continue;
            if(tree[f1].dep>tree[f2].dep) swap(f1,f2); 
            Insert(root[i],root[i-1],1,n,tree[f1].fa,tree[f2].fa);
            if(tree[f1].dep==tree[f2].dep) Add(root[i],1,n,tree[f2].fa);
        }
        if(opt==2){
            k=read();
            root[i]=root[k];
        }
        if(opt==3){
            root[i]=root[i-1];
            a=read(),b=read();
            int f1=Find(root[i],a);
            int f2=Find(root[i],b);
            if(tree[f1].fa==tree[f2].fa) puts("1");
            else puts("0");
        }
    }
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

