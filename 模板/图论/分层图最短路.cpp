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
#define N 10010
#define M 50010
inline int read(){
    int x=0;char ch=getchar();
    while(ch>'9'||ch<'0'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x;
}
int n,m,a,b,c,dis[110][110][20],vis[110][110][20];
struct Point{int x,y,z;};
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int Map[110][110];
inline void spfa(){
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++)
    		for(int k=0;k<=m;k++) dis[i][j][k]=2147483647;
    queue<Point> q;
    q.push(Point{1,1,m});
    dis[1][1][m]=0;vis[1][1][m]=1;
    int X,Y,K,len;
    while(!q.empty()){
        X=q.front().x;
        Y=q.front().y;
        K=q.front().z;q.pop();
        vis[X][Y][K]=0;
        if(Map[X][Y]&&K!=m){
            if(dis[X][Y][m]>dis[X][Y][K]+a){
                dis[X][Y][m]=dis[X][Y][K]+a;
                if(!vis[X][Y][m]){
                	vis[X][Y][m]=1;q.push((Point){X,Y,m});
                }
            }
            continue;
        }
    	if(dis[X][Y][m]>dis[X][Y][K]+a+c){
            dis[X][Y][m]=dis[X][Y][K]+a+c;
            if(!vis[X][Y][m]){
            	vis[X][Y][m]=1;q.push((Point){X,Y,m});
            }
        }
        if(K>0){
        	for(int i=0;i<4;++i){
	            if(X+dx[i]<1||X+dx[i]>n||Y+dy[i]<1||Y+dy[i]>n) continue;
	            len=0;
	            if(dx[i]<0||dy[i]<0) len=b;
	            if(dis[X+dx[i]][Y+dy[i]][K-1]>dis[X][Y][K]+len){
	                dis[X+dx[i]][Y+dy[i]][K-1]=dis[X][Y][K]+len;
	                if(!vis[X+dx[i]][Y+dy[i]][K-1])
	                vis[X+dx[i]][Y+dy[i]][K-1]=1,q.push((Point){X+dx[i],Y+dy[i],K-1});
	            }
	        }
        }
    }
}
signed main(){
    n=read();m=read();a=read();b=read();c=read();
    for(int i=1,j;i<=n;i++){
        for(j=1;j<=n;j++){
        	Map[i][j]=read();
        }
    }
    spfa();
    int ans=2147483647;
    for(int i=0;i<=m;i++) ans=min(ans,dis[n][n][i]);
    cout<<ans<<"\n";
    return 0;
}
