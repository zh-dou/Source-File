#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
#define N 50010
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
int n,m,cnt,tot,Seg_root,a[N];
struct fhq_Treap{
	int val,key,siz,ch[2]; 
}tree[N*400];
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
void Insert(int &root,int val){
	int x=0,y=0;
	Add(val);
	Split(root,x,y,val);
	Merge(x,x,cnt);
	Merge(root,x,y);
}
void Delete(int &root,int val){
	int x=0,y=0,z=0;
	Split(root,x,y,val);
	Split(x,x,z,val-1);
	Merge(z,tree[z].ch[0],tree[z].ch[1]);
	Merge(x,x,z);
	Merge(root,x,y);
}
int Rank(int root,int val){
	int x=0,y=0;
	Split(root,x,y,val-1);
//	cout<<tree[root].val<<" "<<tree[root].siz<<" "<<tree[x].siz<<" "<<tree[y].siz<<"    fuck\n";
	int t=tree[x].siz+1;
	Merge(root,x,y);
	return t;
}
//Segment_Tree : Seg_root
struct Node{
	int root,lson,rson;
}Tree[N*20];
#define mid ((l+r)>>1)
void Build(int &node,int l,int r){
	if(!node) node=++tot;
	for(int i=l;i<=r;i++) Insert(Tree[node].root,a[i]);
	if(l==r) return;
	Build(Tree[node].lson,l,mid);Build(Tree[node].rson,mid+1,r);
}
int Query_rnk(int node,int l,int r,int L,int R,int val){
	if(l>R||L>r){/*cout<<l<<" "<<r<<" "<<val<<":"<<"0\n";*/return 0;}
	if(L<=l&&r<=R){/*cout<<l<<" "<<r<<" "<<val<<":"<<Rank(Tree[node].root,val)-1<<"\n";*/return Rank(Tree[node].root,val)-1;}
//	int res=Query_rnk(Tree[node].lson,l,mid,L,R,val)+Query_rnk(Tree[node].rson,mid+1,r,L,R,val);
//	cout<<l<<" "<<r<<" "<<val<<":"<<res<<"\n";
	return Query_rnk(Tree[node].lson,l,mid,L,R,val)+Query_rnk(Tree[node].rson,mid+1,r,L,R,val);
}
inline int Lib(int L,int R,int rnk){
	int l=0,r=100000000,ans,res;
	while(l<=r){
		res=Query_rnk(Seg_root,1,n,L,R,mid)+1;
//		cout<<l<<" "<<r<<" "<<mid<<" : "<<res<<"\n";
//		system("pause");
		if(res<=rnk){
			ans=mid;l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
void Change(int node,int l,int r,int pos,int val){
	Delete(Tree[node].root,a[pos]);
	Insert(Tree[node].root,val);
	if(l==r){a[l]=val;return;}
	if(pos<=mid) Change(Tree[node].lson,l,mid,pos,val);
	else Change(Tree[node].rson,mid+1,r,pos,val);
}
inline int Query_pre(int L,int R,int val){
	int rnk=Query_rnk(Seg_root,1,n,L,R,val);
//	debug;cout<<val<<" "<<rnk<<"\n";
	if(rnk==0) return -2147483647;
	return Lib(L,R,rnk);
}
inline int Query_nxt(int L,int R,int val){
	int rnk=Query_rnk(Seg_root,1,n,L,R,val+1);
//	debug;cout<<val<<" "<<rnk<<"\n";
	if(rnk==R-L+1) return 2147483647;
	return Lib(L,R,rnk+1);
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();m=read();
	srand(233);
	for(int i=1;i<=n;i++) a[i]=read();
	Build(Seg_root,1,n);
	for(int opt,l,r,k,i=1;i<=m;i++){
		opt=read();l=read();
		if(opt==1){
			r=read();k=read();
			cout<<Query_rnk(Seg_root,1,n,l,r,k)+1<<"\n";
		}
		if(opt==2){
			r=read();k=read();
			cout<<Lib(l,r,k)<<"\n";
		}
		if(opt==3){
			k=read();
			Change(Seg_root,1,n,l,k);
		}
		if(opt==4){
			r=read();k=read();
			cout<<Query_pre(l,r,k)<<"\n";
		}
		if(opt==5){
			r=read();k=read();
			cout<<Query_nxt(l,r,k)<<"\n";
		}
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
/*

9 6
4 2 2 1 9 4 0 1 1
2 1 4 3
3 4 10
2 1 4 3
1 2 5 9
4 3 9 5
5 2 8 5

*/
