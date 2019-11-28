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
#define N 100010
#define int long long
#define DB double
#define mod 100000007
inline int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*y;
}
struct node{
    char a[1600];
    int len;
    char &operator [](int s){
        return a[s];
    }
    inline int hash(){
        int ha=0;
        for(int i=1;i<=len;i++)
            ha=((ha<<1)+(ha<<3)+(int)a[i])%mod;
        return ha;
    }
}b[10202];
set<int>p;
int cnt;
signed main(){
    int n=read();
    for(int i=1;i<=n;i++){
        scanf("%s",b[i].a+1);
        b[i].len=strlen(b[i].a+1);
    }
    for(int i=1;i<=n;i++){
        int ha=b[i].hash();
        if(!p.count(ha)){
            p.insert(ha);
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
