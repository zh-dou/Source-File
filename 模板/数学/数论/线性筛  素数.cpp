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
int prime[N],n,cnt;
bool ispri[N*10];
inline int read(){
	int x=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x;
}
inline void pri(){
	for(int i=2;i<=n;i++){
		if(!ispri[i]){prime[++cnt]=i;}
		for(int j=1;j<=cnt&&(i*prime[j]<=n);j++){
			if(i*prime[j]<=n) ispri[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
signed main(){
	n=read();
	pri();
	return 0;
}

