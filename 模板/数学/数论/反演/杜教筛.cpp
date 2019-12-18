#include<cmath>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define int long long
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"

inline int read(){
	int x=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x;
}
#define N 8000000
signed mu[N+10], prime[N+10], cnt;
bool vis[N+10];
int phi[N+10];
unordered_map<signed,signed> ansmu;
unordered_map<signed,int> ansphi;
#define RS register signed
signed chumu(RS x){
    if(x<=N) return mu[x];
    if(ansmu.count(x)) return ansmu[x];
    RS res=1;
    for(RS l=2,r;l<= x;l=r+1)
        r=x/(x/l),res-=(r-l+1)*chumu(x/l);
    return ansmu[x]=res;
}
int chuphi(RS x){
    if(x<=N) return phi[x];
    if(ansphi.count(x)) return ansphi[x];
    register int res=x*(x+1)/2;
    for(RS l=2,r;l<=x;l=r+1)
        r=x/(x/l),res-=(r-l+1)*chuphi(x/l);
    return ansphi[x]=res;
}
inline void pri(){
	for(RS i=2,j;i<=N;i++){
        if(!vis[i]){
			prime[++cnt]=i;
			phi[i]=i-1;
			mu[i]=-1;
    	}
        for(j=1;j<=cnt&&i*prime[j]<=N;j++){
            vis[i*prime[j]]=true;
            if (i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
            phi[i*prime[j]]=phi[i]*(prime[j]-1),mu[i*prime[j]]=-mu[i];
        }
        phi[i]+=phi[i-1],mu[i]+=mu[i-1];
    }
} 
signed main(){
	RS t=read(),x;
    mu[1]=phi[1]=1;
    pri();
    while(t-->0){
        x=read();
        cout<<chuphi(x)<<" "<<chumu(x)<<"\n";
    }
    return 0;
}
/*
10
1912910059
24829485
37211804
63017503
998531846
393462162
1291448794
1358938348
46636000
1846330377

*/
 
