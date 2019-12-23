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
#define N 1000010
//#define int long long
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
int n,m,fa[N],del[N],val[N];
char s[3];
inline int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
struct Node{
	int lson,rson,fa,dep;
}tree[N];
int Merge(int x,int y){
	if(!x||!y) return x+y;
	if(val[x]>val[y]) swap(x,y);
	tree[x].rson=Merge(tree[x].rson,y);
	if(tree[tree[x].lson].dep>tree[tree[x].rson].dep) swap(tree[x].lson,tree[x].rson);
	tree[x].dep=tree[tree[x].rson].dep+1;
	return x;
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();val[0]=2147483646;
	for(int i=1;i<=n;i++){val[i]=read();fa[i]=i;}
	m=read();
	for(int i=1,x,y,fx,fy;i<=m;i++){
		scanf("%s",s);
		if(s[0]=='M'){
			x=read();y=read();
			if(del[x]||del[y]) continue;
			fx=find(x);fy=find(y);
			if(fx==fy) continue;
			if(val[fx]>val[fy]){
				fa[fx]=fy;
				tree[fy]=tree[Merge(fx,fy)];
			}else{
				fa[fy]=fx;
				tree[fx]=tree[Merge(fx,fy)];
			}
		}
		if(s[0]=='K'){
			x=read();
			if(del[x]){puts("0");continue;}
			fx=find(x);
			cout<<val[fx]<<"\n";
			del[fx]=1;
			if(val[tree[fx].lson]<=val[tree[fx].rson]){
				fa[tree[fx].lson]=tree[fx].lson;
				fa[fx]=tree[fx].lson;
				tree[fx]=tree[Merge(tree[fx].lson,tree[fx].rson)];
			}else{
				fa[tree[fx].rson]=tree[fx].rson;
				fa[fx]=tree[fx].rson;
				tree[fx]=tree[Merge(tree[fx].lson,tree[fx].rson)];
			}
		}
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

