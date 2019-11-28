#include<ctime>
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

inline int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*y;
}
int cnt,root;
struct Tree{
	int val,key,siz,ch[2];
}tree[N];
void Add(int val){
	tree[++cnt].val=val;
	tree[cnt].ch[0]=tree[cnt].ch[1]=0;
	tree[cnt].siz=1;
	tree[cnt].key=rand();
}
void Update(int x){
	tree[x].siz=tree[tree[x].ch[0]].siz+tree[tree[x].ch[1]].siz+1;
}
int Rk(int x){
	return (tree[x].ch[0]?tree[tree[x].ch[0]].siz+1:1);
}
void Split(int a,int &b,int &c,int val){
	if(!a){b=c=0;return;}
	if(tree[a].val<=val) b=a,Split(tree[a].ch[1],tree[b].ch[1],c,val),Update(b);
	else c=a,Split(tree[a].ch[0],b,tree[c].ch[0],val),Update(c);
}
void Merge(int &a,int b,int c){
	if(!b||!c) return (void)(a=b?b:c);
	if(tree[b].key<=tree[c].key) a=b,Merge(tree[a].ch[1],tree[b].ch[1],c);
	else a=c,Merge(tree[a].ch[0],b,tree[c].ch[0]);
	Update(a);
}
void Insert(int val){
	int x=0,y=0;
	Add(val);
	Split(root,x,y,val);
	Merge(x,x,cnt);
	Merge(root,x,y);
}
void Delete(int val){
	int x=0,y=0,z=0;
	Split(root,x,y,val);
	Split(x,x,z,val-1);
	Merge(z,tree[z].ch[0],tree[z].ch[1]);
	Merge(x,x,z);
	Merge(root,x,y);
}
int Rnk(int val){
	int x=0,y=0;
	Split(root,x,y,val-1);
//	cout<<tree[x].siz<<" "<<tree[y].siz<<"    fuck\n";
	int t=tree[x].siz+1;
	Merge(root,x,y);
	return t;
}
int Kth(int k){
	int u=root;
	while(k){
		if(Rk(u)==k) return tree[u].val;
		if(Rk(u)>k) u=tree[u].ch[0];
		else{
			k-=Rk(u);u=tree[u].ch[1];
		}
	}
	return tree[u].val;
}
int Pre(int val){
	int x,y,u,ans;
	Split(root,x,y,val-1);
	u=x;ans=tree[u].val;
	while(tree[u].ch[1]) u=tree[u].ch[1],ans=max(ans,tree[u].val);
	Merge(root,x,y);
	return ans;
}
int Nxt(int val){
	int x,y,u,ans;
	Split(root,x,y,val);
	u=y;ans=tree[u].val;
	while(tree[u].ch[0]) u=tree[u].ch[0],ans=min(ans,tree[u].val);
	Merge(root,x,y);
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	srand(2.17);
	int n=read();
	for(int i=1,opt,x;i<=n;i++){
		opt=read();x=read();
		if(opt==1) Insert(x);
		if(opt==2) Delete(x);
		if(opt==3) cout<<Rnk(x)<<"\n";
		if(opt==4) cout<<Kth(x)<<"\n";
		if(opt==5) cout<<Pre(x)<<"\n";
		if(opt==6) cout<<Nxt(x)<<"\n";
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

