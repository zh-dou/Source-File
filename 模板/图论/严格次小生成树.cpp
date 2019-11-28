#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define M 300005
#define N 100005
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
signed n,m,head[N],belong[N],cnt,dep[N],vis[N];
int fa[N][22],maxdis[N][22],mindis[N][22],ans=0x7ffffffffffff,treetot,tot;
struct Segment{
    int u,v,w;
}a[M];
struct Edge{
    int nxt,to,dis;
}edge[M<<1];
inline void add(int u,int v,int w){
    edge[++tot].nxt=head[u];
    edge[tot].to=v;
    edge[tot].dis=w;
    head[u]=tot;
}
inline int find(int x){
    if(belong[x]!=x) belong[x]=find(belong[x]);
    return belong[x];
}
inline void dfs(int x){
    for(int i=head[x];i;i=edge[i].nxt){
        if(edge[i].to==fa[x][0])continue;
        dep[edge[i].to]=dep[x]+1;
        fa[edge[i].to][0]=x;
        maxdis[edge[i].to][0]=edge[i].dis;
        dfs(edge[i].to);
    }
}
inline void pre(){
    for(int j=1;j<=21;j++){
        for(int i=1;i<=n;i++){
            fa[i][j]=fa[fa[i][j-1]][j-1];
            maxdis[i][j]=max(maxdis[i][j-1],maxdis[fa[i][j-1]][j-1]);
            mindis[i][j]=max(mindis[i][j-1],mindis[fa[i][j-1]][j-1]);
            if(maxdis[i][j-1]>maxdis[fa[i][j-1]][j-1])
                mindis[i][j]=max(mindis[i][j],maxdis[fa[i][j-1]][j-1]);
            else if(maxdis[i][j-1]<maxdis[fa[i][j-1]][j-1])
                mindis[i][j]=max(mindis[i][j],maxdis[i][j-1]);
        }
    }
}
inline int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=21;i>=0;i--)
        if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
    if(x==y)return x;
    for(int i=21;i>=0;i--)
        if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
inline bool cmp(Segment x,Segment y){
    return x.w<y.w;
}
inline void kruskal(){
    for(int i=1;i<=n;i++) belong[i]=i;
    sort(a+1,a+1+m,cmp);
    treetot=0,cnt=0;
    int xx,yy;
    for(int i=1;i<=m;i++){
        xx=find(a[i].u);yy=find(a[i].v);
        if(xx!=yy){
            treetot+=a[i].w;
            cnt++;
            add(a[i].u,a[i].v,a[i].w);
    		add(a[i].v,a[i].u,a[i].w);
            belong[xx]=yy;
            vis[i]=1;
            if(cnt==n-1)break;
        }
    }
}
inline int findmax(int x,int lc,int val){
    int res=0;
    for(int i=21;i>=0;i--){
        if(dep[fa[x][i]]>=dep[lc]){
            if(maxdis[x][i]==val)res=max(res,mindis[x][i]);
            else res=max(res,maxdis[x][i]);
            x=fa[x][i];
        }
    }
    return res;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=m;i++) a[i].u=read(),a[i].v=read(),a[i].w=read();
    kruskal();
    dep[1]=1;
    dfs(1);
    pre();
    for(int i=1,LCA,ls,rs;i<=m;i++){
        if(vis[i])continue;
        LCA=lca(a[i].u,a[i].v);
        ls=findmax(a[i].u,LCA,a[i].w);rs=findmax(a[i].v,LCA,a[i].w);
        ans=min(ans,treetot+a[i].w-max(ls,rs));
    }
    cout<<ans<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

