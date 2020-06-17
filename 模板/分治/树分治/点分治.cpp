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
#define N 40010
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
struct edge{
    int to,nxt,dis;
}edge[N<<1];
int n,k,root,ans,sum,tot,head[N],siz[N],f[N],dep[N],dis[N];
bool vis[N];
inline void add(int x,int y,int z){
	edge[++tot].nxt=head[x];
	edge[tot].dis=z;
	edge[tot].to=y;
	head[x]=tot;
}
void getroot(int x,int fa){
    siz[x]=1;f[x]=0;
    for(int i=head[x];i;i=edge[i].nxt){
        if(vis[edge[i].to]||edge[i].to==fa) continue;
        getroot(edge[i].to,x);
        siz[x]+=siz[edge[i].to];
        f[x]=max(f[x],siz[edge[i].to]);
    }
    f[x]=max(f[x],sum-siz[x]);
    if(f[x]<f[root]) root=x;
}
void getdep(int x,int fa){
    dep[++dep[0]]=dis[x];
    for(int i=head[x];i;i=edge[i].nxt){
        if(vis[edge[i].to]||edge[i].to==fa) continue;
        dis[edge[i].to]=dis[x]+edge[i].dis;
        getdep(edge[i].to,x);
    }
}
int calc(int x,int now){
    dep[0]=0;dis[x]=now;
    getdep(x,0);
    sort(dep+1,dep+dep[0]+1);
    int t=0;
    for(int l=1,r=dep[0];l<r;){
    	if(dep[l]+dep[r]<=k){
            t+=r-l;
            l++;
        }
        else r--;
	}
    return t;
}
void work(int x){
    vis[x]=1;
    ans+=calc(x,0);
    for(int i=head[x];i;i=edge[i].nxt){
        if(vis[edge[i].to]) continue;
        ans-=calc(edge[i].to,edge[i].dis);
        sum=siz[edge[i].to];
        root=0;
        getroot(edge[i].to,0);
        work(root);
    }
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
    for(int i=1,x,y,z;i<n;i++){
        x=read();y=read();z=read();
        add(x,y,z);add(y,x,z);
    }
    k=read();
    sum=n;f[root]=2147483647;
    getroot(1,0);
    work(root);
    cout<<ans<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

