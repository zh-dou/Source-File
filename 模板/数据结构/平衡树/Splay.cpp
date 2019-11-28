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
#define N 500010
#define int long long
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"

inline int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*y;
}
int root,tot;
struct Node{
	int val,fa,siz,cnt,ch[2];
}tree[N];
inline void Pushup(int u){
	tree[u].siz=tree[tree[u].ch[0]].siz+tree[tree[u].ch[1]].siz+tree[u].cnt;
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
	if(x) tree[x].cnt++;
	else{
		x=++tot;
		if(fa) tree[fa].ch[val>tree[fa].val]=x;
		tree[x].ch[0]=tree[x].ch[1]=0;
		tree[x].fa=fa;
		tree[x].val=val;
		tree[x].cnt=tree[x].siz=1;
	}
	Splay(x,0);
}
inline void Find(int val){
	int x=root;
	if(!x)return;
	while(tree[x].ch[val>tree[x].val]&&val!=tree[x].val)
		x=tree[x].ch[val>tree[x].val];
	Splay(x,0);
}
inline int Next(int val,int f){
	Find(val);
	if(tree[root].val>val&&f) return root;
	if(tree[root].val<val&&!f) return root;
	int x=tree[root].ch[f];
	while(tree[x].ch[f^1]) x=tree[x].ch[f^1];
	return x;
}
inline void Delete(int val){
	int last=Next(val,0);
	int next=Next(val,1);
	Splay(last,0);Splay(next,last);
	int del=tree[next].ch[0];
	if(tree[del].cnt>1){
		tree[del].cnt--;
		Splay(del,0);
	}
	else tree[next].ch[0]=0;
}
inline int kth(int val){
	int x=root,y;
	if(tree[x].siz<val) return 0;
	while(1){
		y=tree[x].ch[0];
		if(val>tree[y].siz+tree[x].cnt){
			val-=tree[y].siz+tree[x].cnt;
			x=tree[x].ch[1];
		}else{
			if(tree[y].siz>=val) x=y;
			else return tree[x].val;
		}
	}
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	int n=read(),opt,x;
	Insert(+2147483647);
	Insert(-2147483647);
	while(n --> 0){
		opt=read();x=read();
		if(opt==1) Insert(x);
		if(opt==2) Delete(x);
		if(opt==3) Find(x),cout<<tree[tree[root].ch[0]].siz<<"\n";
		if(opt==4) cout<<kth(x+1)<<"\n";
		if(opt==5) cout<<tree[Next(x,0)].val<<"\n";
		if(opt==6) cout<<tree[Next(x,1)].val<<"\n";
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

