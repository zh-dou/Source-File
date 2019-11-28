#include<map>
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
#define int long long
const int maxn = 5e5+5;
inline int read(){
	int x=0,y=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
int gcd(int n,int m){return m? gcd(m,n%m):n;}
struct BinaryIndexTree{
	int n,a[maxn];
	
	void clear(){ memset(a,0,sizeof(a)); }

	BinaryIndexTree(){n=0;clear();}

	void setn(int n){this->n=n;}

	void addval(int pos,int val){
		for(;pos<=n;pos+=pos&-pos)
			a[pos]+=val;
	}

	int getPreFixSum(int pos,int ans=0){
		for(;pos;pos&=pos-1)
			ans+=a[pos];
		return ans;
	}
}t;
int n,m;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	t.setn(n=read());m=read();
	for(int i=1;i<=n;++i)
		t.addval(i,read());
	for(int i=0;i<m;++i){
		int op=read(),l=read(),r=read();
		if(op==1)t.addval(l,r);
		if(op==2)printf("%d\n",t.getPreFixSum(r)-t.getPreFixSum(l-1));
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

