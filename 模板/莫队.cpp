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
#define N 50010
#define int long long
inline int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*y;
}
int tong[N],a[N],pos[N],ans[N];
struct Qurry{
	int l,r,id,ans;
}que[N];
inline bool cmp(const Qurry &a,const Qurry &b){
	if(pos[a.l]==pos[b.l]){
		return a.r<b.r;
	}
	return pos[a.l]<pos[b.l];
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	register int i;
	int n,m,len;
	n=read();m=read();read();len=sqrt(n);
	for(i=1;i<=n;i++){
		a[i]=read();
	}
	for(i=1;i<=m;i++){
		que[i].id=i;
		que[i].l=read();que[i].r=read();
		pos[i]=(que[i].l-1)/len+1;
	}
	sort(que+1,que+m+1,cmp);
	int l=1,r=0,now=0;
	for(int i=1;i<=m;i++){
		while(l>que[i].l) --l,now+=tong[a[l]]*2+1,tong[a[l]]++;
		while(r<que[i].r) ++r,now+=tong[a[r]]*2+1,tong[a[r]]++;
		while(l<que[i].l) now-=tong[a[l]]*2-1,tong[a[l]]--,++l;
		while(r>que[i].r) now-=tong[a[r]]*2-1,tong[a[r]]--,--r;
		ans[que[i].id]=now;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

