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
#define N 40010
//#define int long long
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"
int prime[N>>2],n,cnt,ans;
bool ispri[N];
int phi[N];
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
}
signed main(){
//	POJ
    int T=read();
    n=40000;
    phi[1]=1;
    pri();
    for(int i=1;i<=T;i++){
    	n=read();ans=0;
    	cout<<i<<" "<<n<<" ";
	    for(int i=1;i<=n;i++){
	        ans+=phi[i];
	    }
	    cout<<ans*2+1<<"\n";
    }
//	luogu
//	n=read()-1;
//	if(n==0){
//	    puts("0");return 0;
//	}
//	phi[1]=1;
//	pri();
//	for(int i=1;i<=n;i++){
//	    ans+=phi[i];
//	}
//	cout<<ans*2+1;
    return 0;
}
