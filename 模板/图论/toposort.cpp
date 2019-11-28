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
inline int read(){
	int x=0,y=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
int n,m,cnt;
bool a[N][N];
int indeg[N],ans[N];
queue <int> q;
inline void input(){
    n=read();m=read();
    for(int i=1,x,y;i<=m;i++){
        x=read();y=read();
        a[x][y]=1;
        indeg[y]++;
    }
} 
inline void topo_sort(){
    for(int i=1;i<=n;i++)
    	if(indeg[i]==0)
    		q.push(i);
    while(!q.empty()){
        const int u=q.front();
        ans[++cnt]=u;
        q.pop();
        for(int i=1;i<=n;i++)
        	if(a[u][i]){
        		indeg[i]--;
        		if(indeg[i]==0)
        			q.push(i); 
         	}
    }
}
inline void output(){
    for(int i=1;i<=n;i++)
    	cout<<ans[i]<<" ";
}
signed main(){
    input();
    topo_sort();
    output();
    return 0;
}
