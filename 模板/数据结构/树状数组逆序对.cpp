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
#define N 500010
inline int read(){
	int x=0,y=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
int a[N],b[N],tree[N];
int n,ans;
int lowbit(int x){return x&-x;}
inline void insert(int i,int x){
    while(i<=n) tree[i]+=x,i+=lowbit(i);
}
inline int ask(int x){
    int s=0;
    while(x){
        s+=tree[x];
        x-=lowbit(x);
    }
    return s;
}
signed main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=b[i]=read();
    }
    sort(a+1,a+n+1);
    int QAQ=n;
    for(int i=1,t;i<=n;i++){
    	t=lower_bound(a+1,a+QAQ+1,b[i])-a;
    	insert(t,1);
    	ans+=i-ask(t);
    }
//	for(int i=1;i<=n;i++) cout<<tree[i]<<"\n";
    cout<<ans<<"\n";
    return 0;
}

