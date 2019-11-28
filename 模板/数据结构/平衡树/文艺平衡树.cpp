#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
//#define int long long
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
int n,m,root,tot;
struct Node{
	int val,fa,siz,rev,ch[2];
	Node(){
		ch[0]=ch[1]=fa=siz=val=rev=0;
	}
}tree[N];
inline void Pushup(int x){
	tree[x].siz=tree[tree[x].ch[0]].siz+tree[tree[x].ch[1]].siz+1;
}
inline void Pushdown(int x){
	if(tree[x].rev){
		swap(tree[x].ch[0],tree[x].ch[1]);
		tree[tree[x].ch[0]].rev^=1;tree[tree[x].ch[1]].rev^=1;
		tree[x].rev=0;
	}
}
inline void Rotate(int x){
	int y=tree[x].fa;
	int z=tree[y].fa;
	int k=(tree[y].ch[1]==x);
	tree[z].ch[tree[z].ch[1]==y]=x;
	tree[x].fa=z;
	tree[y].ch[k]=tree[x].ch[k^1];
	tree[tree[x].ch[k^1]].fa=y;
	tree[x].ch[k^1]=y;
	tree[y].fa=x;
	Pushup(y);Pushup(x);
}
inline void Splay(int x,int goal){
	while(tree[x].fa!=goal){
		int y=tree[x].fa;
		int z=tree[y].fa;
		if(z!=goal)
			(tree[y].ch[0]==x)^(tree[z].ch[0]==y)?Rotate(x):Rotate(y);
		Rotate(x);
	}
	if(goal==0) root=x;
}
inline void Insert(int val){
	int x=root,fa=0;
	while(x&&tree[x].val!=val){
		fa=x;
		x=tree[x].ch[val>tree[x].val];
	}
	x=++tot;
	if(fa) tree[fa].ch[val>tree[fa].val]=x;
	tree[x].fa=fa;
	tree[x].val=val;
	tree[x].siz=1;
	Splay(x,0);
}
inline int Find(int val){
	int x=root,y;
	while(1){
		Pushdown(x);
		y=tree[x].ch[0];
		if(val>tree[y].siz+1){
			val-=tree[y].siz+1;
			x=tree[x].ch[1];
		}else{
			if(tree[y].siz>=val) x=y;
			else return x;
		}
	}
}
inline void Reverse(int l,int r){
	int x=Find(l),y=Find(r+2);
//	cout<<tree[x].val<<" "<<tree[y].val<<"\n";
    Splay(x,0);Splay(y,root);
    tree[tree[y].ch[0]].rev^=1;
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();m=read();
	Insert(0);Insert(n+1);
	for(int i=1;i<=n;i++) Insert(i);
	for(int l,r,i=1;i<=m;i++){
//		for(int i=1;i<=n;i++) cout<<tree[Find(i+1)].val<<" ";
//		cout<<"\n";
		l=read();r=read();
		Reverse(l,r);
	}
	for(int i=1;i<=n;i++) cout<<tree[Find(i+1)].val<<" ";
	cout<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

