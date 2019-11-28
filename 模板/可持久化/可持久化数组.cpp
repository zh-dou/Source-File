#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 1000010
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
int n,m,cnt,a[N],root[N*20];
struct Tree{
	int lson,rson,val;
	Tree(){lson=rson=val=0;}
}tree[N*20];
void Build(int &A,int l,int r){
	if(!A) A=++cnt;
	if(l==r){tree[A].val=a[l];return;}
	int mid=(l+r)>>1;
	Build(tree[A].lson,l,mid);Build(tree[A].rson,mid+1,r);
}
void Change(int A,int &B,int l,int r,int pos,int val){
	if(!B) B=++cnt;
	if(l==r){tree[B].val=val;return;}
	int mid=(l+r)>>1;
	if(pos<=mid) Change(tree[A].lson,tree[B].lson,l,mid,pos,val),tree[B].rson=tree[A].rson;
	else Change(tree[A].rson,tree[B].rson,mid+1,r,pos,val),tree[B].lson=tree[A].lson;
}
int Query(int A,int l,int r,int pos){
	if(l==r) return tree[A].val;
	int mid=(l+r)>>1;
	if(pos<=mid) return Query(tree[A].lson,l,mid,pos);
	else return Query(tree[A].rson,mid+1,r,pos);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
//	for(int i=1;i<=n;i++) cout<<a[i]<<"\n";
	Build(root[0],1,n);
	for(int k,opt,loc,val,i=1;i<=m;i++){
		k=read();opt=read();
		if(opt==1){
			loc=read();val=read();
			Change(root[k],root[i],1,n,loc,val);
		}
		if(opt==2){
			loc=read();
			cout<<Query(root[k],1,n,loc)<<"\n";
			root[i]=root[k];
		}
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
