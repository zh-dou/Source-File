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
#define inf 0x7ffffffffffff
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
int n,ans1,ans2,now;
struct Point{
	int p[2];
	bool friend operator <(const Point &x,const Point &y){
		return x.p[now]==y.p[now]?x.p[!now]<y.p[!now]:x.p[now]<y.p[now];
	}
}a[N];
struct Node{
	int ch[2],mx[2],mn[2];
}tree[N];
#define mid ((l+r)>>1)
#define ls(x) tree[x].ch[0]
#define rs(x) tree[x].ch[1]
inline void Pushup(int p,int x){
	tree[p].mx[0]=max(tree[p].mx[0],tree[x].mx[0]);
	tree[p].mn[0]=min(tree[p].mn[0],tree[x].mn[0]);
	tree[p].mx[1]=max(tree[p].mx[1],tree[x].mx[1]);
	tree[p].mn[1]=min(tree[p].mn[1],tree[x].mn[1]);
}
int Build(int l,int r,int type){
	now=type;
	nth_element(a+l,a+mid,a+r+1);
	tree[mid].mx[0]=tree[mid].mn[0]=a[mid].p[0];
	tree[mid].mx[1]=tree[mid].mn[1]=a[mid].p[1];
	if(l<mid) ls(mid)=Build(l,mid-1,!type),Pushup(mid,ls(mid));
	if(r>mid) rs(mid)=Build(mid+1,r,!type),Pushup(mid,rs(mid));
	return mid;
}
inline int Min(int x,int y,int p){
	return max(tree[p].mn[0]-x,0ll)+max(x-tree[p].mx[0],0ll)+max(tree[p].mn[1]-y,0ll)+max(y-tree[p].mx[1],0ll);
}
inline int Max(int x,int y,int p){
	return max(abs(x-tree[p].mx[0]),abs(x-tree[p].mn[0]))+max(abs(y-tree[p].mx[1]),abs(y-tree[p].mn[1]));
}
int Get_min(int x,int y,int p){
	int res=abs(x-a[p].p[0])+abs(y-a[p].p[1]),dl,dr;
	if(res&&res<ans1) ans1=res;
	dl=ls(p)?Min(x,y,ls(p)):inf;
	dr=rs(p)?Min(x,y,rs(p)):inf;
	if(dl<dr){
		if(dl<ans1) Get_min(x,y,ls(p));
		if(dr<ans1) Get_min(x,y,rs(p));
	}else{
		if(dr<ans1) Get_min(x,y,rs(p));
		if(dl<ans1) Get_min(x,y,ls(p));
	}
}
int Get_max(int x,int y,int p){
	int res=abs(x-a[p].p[0])+abs(y-a[p].p[1]),dl,dr;
	if(res>ans2) ans2=res;
	dl=ls(p)?Max(x,y,ls(p)):-inf;
	dr=rs(p)?Max(x,y,rs(p)):-inf;
	if(dl>dr){
		if(dl>ans2) Get_max(x,y,ls(p));
		if(dr>ans2) Get_max(x,y,rs(p));
	}else{
		if(dr>ans2) Get_max(x,y,rs(p));
		if(dl>ans2) Get_max(x,y,ls(p));
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i].p[0]=read(),a[i].p[1]=read();
	int root=Build(1,n,0);
	int ans=inf;
	for(int i=1;i<=n;i++){
		ans1=inf;Get_min(a[i].p[0],a[i].p[1],root);
		ans2=  0;Get_max(a[i].p[0],a[i].p[1],root);
		ans =min(ans,ans2-ans1);
	}
	cout<<ans<<"\n";
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
