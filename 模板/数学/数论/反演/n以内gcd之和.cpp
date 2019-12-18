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
#define N 4000010
#define int long long
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"

int prime[N>>2],n,cnt;
bool ispri[N];
int phi[N];
int ans[N];
inline int read(){
	int x=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x;
}
inline void pri(){
	for(int i=2;i<=n;i++){
		if(!ispri[i]){
			prime[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt&&(i*prime[j]<=n);j++){
			if(i*prime[j]<=n) ispri[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}else{
				phi[i*prime[j]]=phi[i]*phi[prime[j]];
			}
		}
	}
	for(int i=1;i<=n;i++) ans[i]=phi[i];
	for(int i=2;i*i<=n;i++){
		ans[i*i]+=phi[i]*i;
		for(int j=i+1;j*i<=n;j++)
    		ans[j*i]+=phi[i]*j+phi[j]*i;
	}
	ans[1]=0;
	for(int i=2;i<=n;i++) ans[i]+=ans[i-1];
}
signed main(){
	n=4000001;
	int l,r;
	phi[1]=1;
	pri();
//	for(int i=1;i<=10;i++) cout<<phi[i]<<" ";
//	cout<<"\n";
	while(n=read()){
		cout<<ans[n]<<"\n";
	}
	return 0;
}
