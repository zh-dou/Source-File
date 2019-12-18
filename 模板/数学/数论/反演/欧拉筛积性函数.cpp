#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define N 5000010
int prime[N>>2],n,cnt;
bool ispri[N];
int mn[N],C[N],S[N];
int d[N],si[N];
int phi[N];
int mu[N];
inline int read(){
	int x=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x;
}
inline int solve(int pos){
	return (S[pos]*mn[pos]-1)/(mn[pos]-1);
}
inline void pri(){
	for(int i=2;i<=n;i++){
		if(!ispri[i]){
			prime[++cnt]=i;
			phi[i]=i-1;
			mn[i]=i;C[i]=1;S[i]=i;
			d[i]=2;
			si[i]=i+1;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt&&(i*prime[j]<=n);j++){
			if(i*prime[j]<=n) ispri[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				mn[i*prime[j]]=prime[j];//最小质数
				C[i*prime[j]]=C[i]+1;//最小质数的个数 
				S[i*prime[j]]=S[i]*prime[j];//p1^k1 
				d[i*prime[j]]=d[(i*prime[j])/S[i*prime[j]]]*(C[i]+2);
				si[i*prime[j]]=si[(i*prime[j])/S[i*prime[j]]]*solve(S[i]*prime[j]);
				break;
			}else{
				mn[i*prime[j]]=prime[j];
				C[i*prime[j]]=1;
				S[i*prime[j]]=prime[j];
				d[i*prime[j]]=d[i]*2;
				si[i*prime[j]]=si[i]*(prime[j]+1);
				phi[i*prime[j]]=phi[i]*phi[prime[j]];
				mu[i*prime[j]]=-mu[i];
			}
		}
	} 
}
signed main(){
	n=read();
	phi[1]=1;d[1]=1;si[1]=1;mu[1]=1;
	pri();
	for(int i=1;i<=n;i++){
		cout<<d[i]<<" "<<si[i]<<" "<<phi[i]<<" "<<mu[i]<<"\n";//个数  约数和  欧拉函数  莫比乌斯 
	}
	return 0;
}

