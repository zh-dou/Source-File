#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
//#define int long long
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"
int n,m,root,cnt,b[N];
inline int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*y;
}
struct Opt{
	int opt,num;
}a[N];
struct Node{
	int lson,rson,siz;
}tree[N<<1];
#define ls(node) tree[node].lson
#define rs(node) tree[node].rson
void build(int l,int r,int &node){
	if(!node) node=++cnt;
	if(l==r) return; 
	int mid=(l+r)>>1;
	build(l,mid,ls(node));build(mid+1,r,rs(node));
}
void update(int x,int val,int l,int r,int node){
	tree[node].siz+=val;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(x<=mid) update(x,val,l,mid,ls(node));
	else update(x,val,mid+1,r,rs(node));
}
int query(int x,int l,int r,int node){
	if(x<l) return 0;
	if(x>=r) return tree[node].siz;
	int mid=(l+r)>>1;
	return query(x,l,mid,ls(node))+query(x,mid+1,r,rs(node));
}
int lib(int rank,int l,int r,int node){
	if(l==r) return l;
	int mid=(l+r)>>1;
	if(rank<=tree[ls(node)].siz) return lib(rank,l,mid,ls(node));
	else return lib(rank-tree[ls(node)].siz,mid+1,r,rs(node));
}
signed main(){
// 	freopen("in","r",stdin);
// 	freopen("out","w",stdout);
	m=read();
	for(int i=1;i<=m;i++){
		a[i].opt=read();a[i].num=read();
		if(a[i].opt!=4) b[++n]=a[i].num;
	}
	sort(b+1,b+n+1);
	n=unique(b+1,b+n+1)-b-1;
	build(1,n,root);
	for(int x,i=1;i<=m;i++){
		if(a[i].opt!=4) x=lower_bound(b+1,b+n+1,a[i].num)-b;
		if(a[i].opt==1) update(x,1,1,n,root);
		if(a[i].opt==2) update(x,-1,1,n,root);
		if(a[i].opt==3) printf("%d\n",query(x-1,1,n,root)+1);
		if(a[i].opt==4) printf("%d\n",b[lib(a[i].num,1,n,root)]);
		if(a[i].opt==5) printf("%d\n",b[lib(query(x-1,1,n,root),1,n,root)]);
		if(a[i].opt==6) printf("%d\n",b[lib(query(x,1,n,root)+1,1,n,root)]);
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
 
