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
#define N 300010
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
struct LCT{
	struct Node{
		int fa,ch[2],val,rev,num;
		Node(){fa=ch[0]=ch[1]=val=num=rev=0;}
	}tree[N];
	int top,res[N];
	#define ls(x) tree[x].ch[0]
	#define rs(x) tree[x].ch[1]
	inline int Nroot(int x){return tree[x].fa&&(ls(tree[x].fa)==x||rs(tree[x].fa)==x);}
	inline void Rev(int x){swap(ls(x),rs(x));tree[x].rev^=1;}
	inline void Pushup(int x){
		tree[x].num=tree[x].val;
		if(ls(x)) tree[x].num^=tree[ls(x)].num;
		if(rs(x)) tree[x].num^=tree[rs(x)].num;
	}
	inline void Pushdown(int x){
		if(!tree[x].rev) return;
		if(ls(x)) Rev(ls(x));
		if(rs(x)) Rev(rs(x));
		tree[x].rev=0;
	}
	inline void Rotate(int x){
		int y=tree[x].fa,z=tree[y].fa,k=(x==ls(tree[x].fa)),w=tree[x].ch[k];
		if(Nroot(y)) tree[z].ch[y==rs(tree[y].fa)]=x;
		tree[x].ch[k]=y;tree[y].ch[!k]=w;
		tree[y].fa=x;tree[x].fa=z;
		if(w) tree[w].fa=y;
		Pushup(y);Pushup(x);
	}
	inline void Splay(int x){
		int tmp=x;
		res[top=1]=tmp;
		while(Nroot(tmp)) res[++top]=tree[tmp].fa,tmp=tree[tmp].fa;
		while(top) Pushdown(res[top]),--top;
		while(Nroot(x)){
			if(Nroot(tree[x].fa)) Rotate((x==rs(tree[x].fa))^(tree[x].fa==rs(tree[tree[x].fa].fa))?x:tree[x].fa);
			Rotate(x);
		} 
	}
	inline void Access(int x){
		int y=0;
		while(x){
			Splay(x);rs(x)=y;Pushup(x);y=x;x=tree[x].fa;
		}
	}
	inline void Makeroot(int x){
		Access(x);Splay(x);Rev(x);
	}
	inline int Findroot(int x){
		Access(x);Splay(x);Pushdown(x);
		while(ls(x)){
			x=ls(x);Pushdown(x);
		}
		return x;
	}
	inline void Link(int x,int y){
		if(Findroot(x)==Findroot(y)) return;
		Makeroot(x);tree[x].fa=y;
	}
	inline void Cut(int x,int y){
		Makeroot(x);Access(y);Splay(y);
		if(ls(y)==x) tree[x].fa=ls(y)=0;
	}
	inline void Change(int x,int val){
		Splay(x);tree[x].val=val;
		Pushup(x);
	}
	inline int Query(int x,int y){
		Makeroot(x);Access(y);Splay(y);
		return tree[y].num;
	}
}Tree;
int n,m;
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		Tree.tree[i].val=read();
	}
	for(int i=1,opt,x,y;i<=m;i++){
		opt=read();x=read();y=read();
		if(opt==0) cout<<Tree.Query(x,y)<<"\n";
		if(opt==1) Tree.Link(x,y);
		if(opt==2) Tree.Cut(x,y);
		if(opt==3) Tree.Change(x,y);
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

