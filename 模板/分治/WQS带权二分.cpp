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
#define N 100010
#define int long long
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"
int n,m,num,t,Need,ans;
int fa[N];
inline int read(){
    int x=0,y=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*y;
}
struct node{
    int l,r,w,col;
}a[N<<2];
bool comp(const node &a,const node &b){
	if(a.w==b.w) return a.col>b.col;
	return a.w<b.w;
}
inline int finds(int x){
    if(x==fa[x])return x;
    return fa[x]=finds(fa[x]);
} 
inline int Kruskal(){
	int tot_white=0;
	sort(a+1,a+1+m,comp);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int x=a[i].l,y=a[i].r;
        if(finds(x)==finds(y)) continue;
        int fx=finds(x),fy=finds(y);
        fa[fx]=fy;
        t+=a[i].w;
        tot_white+=a[i].col;
    }
//    cout<<t<<" "<<tot_white<<" ";debug;
    return tot_white;
}
inline int check(int x){
	for(int i=1;i<=m;i++) if(a[i].col) a[i].w+=x;
	int res=Kruskal();
	for(int i=1;i<=m;i++) if(a[i].col) a[i].w-=x;
	return res>=Need;
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();m=read();Need=read();
	for(int i=1;i<=m;i++){
		a[i].l=read()+1;a[i].r=read()+1;a[i].w=read();a[i].col=!read();
	}
	int l=-150,r=150,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;ans=t-mid*Need;
		}else{
			r=mid-1;
		}
		t=0;
//		cout<<l<<" "<<r<<" "<<mid<<"\n";
	}
	cout<<ans<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

