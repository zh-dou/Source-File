#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int n,m,s;
int dis[1000010],vis[1000010];
vector<pair<int,int> > a[1000010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
inline int read(){
    int x=0,y=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*y;
}
inline void dij(int s){
    for(int i=1;i<=n;i++) dis[i]=2147483647;
    q.push(make_pair(0,s));
    dis[s]=0;
    while(!q.empty()){
        int front=q.top().second;q.pop();
        if(vis[front]) continue;
        vis[front]=1;
        for(int i=0;i<a[front].size();i++){
            int to=a[front][i].first,w=a[front][i].second;
            if(!vis[to]&&dis[to]>dis[front]+w){
                dis[to]=dis[front]+w;
                q.push(make_pair(dis[to],to));
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    n=read();m=read();s=read();
    for(int u,v,w,i=1;i<=m;i++){
        u=read();v=read();w=read();
        a[u].push_back(make_pair(v,w));
    }
    dij(s);
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

