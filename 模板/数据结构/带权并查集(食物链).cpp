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
#define N 150010
#define int long long
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"

inline int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*y;
}
int fa[N],rel[N];
int find(int x){
    if(x!=fa[x]){
        int tmp=fa[x];
        fa[x]=find(tmp);
        rel[x]=(rel[x]+rel[tmp])%3;
    }
    return fa[x];
}
signed main(){
    int n=read(),m=read(),ans=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1,opt,x,y;i<=m;i++){
        opt=read();x=read();y=read();
        if(x>n||y>n){
        	ans++;continue;
        }
        if(opt==1){
            if(find(x)==find(y)){
                if(rel[x]!=rel[y]) ans++;
                continue;
            }
            int fx=find(x),fy=find(y);
            fa[fx]=fy;rel[fx]=(3-rel[x]+rel[y])%3;
        }
        if(opt==2){
        	if(x==y){
        		ans++;continue;
        	}
        	int fx=find(x),fy=find(y);
            if(fx==fy){
                if((rel[x]-rel[y]+3)%3!=1) ans++;
                continue;
            }
            fa[fx]=fy;
            rel[fx]=(3-rel[x]+rel[y]+1)%3;;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
