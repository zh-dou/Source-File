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

inline int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*y;
}
void put(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) put(x/10);
	putchar((x%10)+48);
}
struct Linear_Basis{
    int d[60],p[60];
    int cnt;
    Linear_Basis(){
        memset(d,0,sizeof(d));
        memset(p,0,sizeof(p));
        cnt=0;
    }
    void insert(int val){
        for (int i=50;i>=0;i--)
            if (val&(1LL<<i)){
                if (!d[i]){
                    d[i]=val;
                    break;
                }
                val^=d[i];
            }
    }
    int query_max(){
        int ret=0;
        for (int i=50;i>=0;i--)
            if ((ret^d[i])>ret)
                ret^=d[i];
        return ret;
    }
    int query_min(){
        for (int i=0;i<=50;i++)
            if (d[i])
                return d[i];
        return 0;
    }
    void rebuild(){
        for (int i=50;i>=0;i--)
            for (int j=i-1;j>=0;j--)
                if (d[i]&(1LL<<j))
                    d[i]^=d[j];
        for (int i=0;i<=50;i++)
            if (d[i])
                p[cnt++]=d[i];
    }
    int kthquery(int k){
        int ret=0;
        if(k>=(1LL<<cnt)) return -1;
        for(int i=50;i>=0;i--)
            if(k&(1LL<<i))
                ret^=p[i];
        return ret;
    }
}basis;
Linear_Basis merge(const Linear_Basis &n1,const Linear_Basis &n2){
    Linear_Basis ret=n1;
    for(int i=50;i>=0;i--)
        if(n2.d[i]) ret.insert(n1.d[i]);
    return ret;
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++) basis.insert(read());
	cout<<basis.query_max()<<"\n";  
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

