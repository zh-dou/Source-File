#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
#define int long long
#define debug cerr<<__LINE__<<" "<<__FUNCTION__<<"\n"

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
int n,L,R,num;
struct Line{
	double k,b;
}a[N];
int tree[N<<2];
#define mid ((l+r)>>1)
inline double val(int p,int x){
	return a[p].k*x+a[p].b;
}
inline double cross(int x,int y){
	return ((a[x].b-a[y].b)*1.0)/((a[y].k-a[x].k)*1.0);
}
void Insert(int node,int l,int r,int x){
//	cout<<l<<" "<<r<<"\n";
	if(L<=l&&r<=R){
//		cout<<node<<" "<<l<<" "<<r<<" "<<tree[node]<<" "<<x<<"\n";
		if(!tree[node]) return (void)(tree[node]=x);
		if(val(x,l)<=val(tree[node],l)&&val(x,r)<=val(tree[node],r)) return ;
		if(val(x,l)> val(tree[node],l)&&val(x,r)> val(tree[node],r)) return (void)(tree[node]=x);
		double c=cross(x,tree[node]);
		if(val(x,l)<=val(tree[node],l)){
			if(c>mid){
				Insert(node<<1|1,mid+1,r,x);
			}else{
				Insert(node<<1,l,mid,tree[node]);
				tree[node]=x;
			}
		}else{
			if(c<=mid){
				Insert(node<<1,l,mid,x);
			}else{
				Insert(node<<1|1,mid+1,r,tree[node]);
				tree[node]=x;
			}
		}
		return ;
	}
	if(mid>=L) Insert(node<<1,l,mid,x);
	if(R>mid) Insert(node<<1|1,mid+1,r,x);
}
int Query(int node,int l,int r,int pos){
	if(l==r) return tree[node];
	int x;
	if(pos<=mid) x=Query(node<<1,l,mid,pos);
	else x=Query(node<<1|1,mid+1,r,pos);
	if(!tree[node]) return x;
	if(val(x,pos)==val(tree[node],pos)) x=min(x,tree[node]);
	if(val(x,pos)<val(tree[node],pos)) x=tree[node];
//	cout<<l<<","<<r<<" : "<<x<<"\n";
	return x;
}
int ans=0;
void h(int&x,int mod){x=(x+ans-1)%mod+1;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=1,op,xa,ya,xb,yb;i<=n;i++){
		op=read();
		if(op){
			++num;
			xa=(read()+ans-1)%39989+1;ya=(read()+ans-1)%1000000000ll+1;xb=(read()+ans-1)%39989+1;yb=(read()+ans-1)%1000000000ll+1;
			a[num].k=(xa==xb?0:double(yb-ya)/(xb-xa));
			a[num].b=(xa==xb?double(max(ya,yb)):-double(yb-ya)/(xb-xa)*xa+ya);
			L=min(xa,xb);R=max(xa,xb);
			Insert(1,1,39989,num);
		} else {
			xa=(read()+ans-1)%39989+1;
			ans=Query(1,1,39989,xa);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
