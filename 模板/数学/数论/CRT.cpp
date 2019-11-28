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
#define N 100010
#define int long long
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"
int a[N],b[N],n,mod=1,ans=0;
inline int read(){
    int x=0;char ch=getchar();
    while(ch>'9'||ch<'0'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x;
}
void exgcd(int a,int b,int &d,int &x,int &y){
    if(b==0) d=a,x=1,y=0;
    else{
        exgcd(b,a%b,d,x,y);
        int temp=x;x=y;y=temp-a/b*y;
    }
}
void china(){
    int each,x,y,d;
    for(int i=1;i<=n;i++){
        each=mod/a[i];
        exgcd(each,a[i],d,x,y);
        ans=((ans+each*x*b[i])%mod+mod)%mod; 
    }
    cout<<ans<"\n";
}
signed main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();b[i]=read();
        mod*=a[i];
    }
    china();
	return 0;
}
