#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 30010
#define int long long
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
int n,m,cnt,a[N],b[N],root[N],ans;
struct Tree{
	int lson,rson,siz;
	Tree(){lson=rson=siz=0;}
}tree[N*40];
#define mid ((l+r)>>1)
void Build(int A,int &B,int l,int r,int d){
	B=++cnt;tree[B]=tree[A];++tree[B].siz;
	if(l==r) return;
	if(d<=mid) Build(tree[A].lson,tree[B].lson,l,mid,d);
	else Build(tree[A].rson,tree[B].rson,mid+1,r,d);
}
void query(int pre,int now,int l,int r,int k){
    if(l==r){
        if(b[l]<=k) ans+=tree[now].siz-tree[pre].siz;
        return;
    }
    if(k<=b[mid]) query(tree[pre].lson,tree[now].lson,l,mid,k);
    else ans+=tree[tree[now].lson].siz-tree[tree[pre].lson].siz,query(tree[pre].rson,tree[now].rson,mid+1,r,k);
}
signed main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) b[i]=a[i]=read();
    sort(b+1,b+n+1);
    int t=unique(b+1,b+1+n)-b-1;
	for(int d,i=1;i<=n;i++){
		d=lower_bound(b+1,b+t+1,a[i])-b;
        Build(root[i-1],root[i],1,t,d);
//		cout<<d<<" ";
	}
//	cout<<"\n";
//	for(int i=1;i<=n;i++) cout<<root[i]<<" ";
//	cout<<"\n";
	m=read();
	for(int l,r,k,i=1;i<=m;i++){
		l=read()^ans;r=read()^ans;k=read()^ans;ans=0;
		if(l<1) l=1;
        if(r>n) r=n;
		if(l>r){
			puts("0");continue;
		}
		query(root[l-1],root[r],1,t,k);
		cout<<(ans=r-l+1-ans)<<"\n";
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

