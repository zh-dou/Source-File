/*
最长链与次长链长度  
*/
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 1610
inline int read(){
 	int x=0,y=1;
 	char ch=getchar();
 	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
 	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
 	return x*y;
}
int n;
struct Node{
    int nxt,to,dis;
}edge[N<<2];
int head[N],tot,val[N];
inline void add(int u,int v){
    edge[++tot].nxt=head[u];edge[tot].to=v;head[u]=tot;
    swap(u,v);
    edge[++tot].nxt=head[u];edge[tot].to=v;head[u]=tot;
}
int Fir[N],Sec[N],in[N],s;
void dfs(int x,int fa){
	int to;
	for(int i=head[x];i;i=edge[i].nxt){
		to=edge[i].to;
		if(to==fa) continue;
		dfs(to,x);
		if(Fir[to]+edge[i].dis>Fir[x]){
			Sec[x]=Fir[x];
			Fir[x]=Fir[to]+edge[i].dis;
		}else{
			Sec[x]=Fir[to]+edge[i].dis;
		}
	}
}
signed main(){
	int n=read();
	int tt,num,son;
	for(int i=1;i<=n;i++){
		tt=read();
		val[tt]=read();
		num=read();
		for(int j=1;j<=num;j++){
			son=read();in[son]++;
			add(tt,son);
		}
	}
	for(int i=1;i<=n;i++) if(!in[i]) s=i;
	dfs(s,0);
//	for(int i=1;i<=n;i++) cout<<i<<" "<<H[i]<<"\n";
	cout<<Fir[s]+Sec[s]<<"\n";
	return 0;
}

