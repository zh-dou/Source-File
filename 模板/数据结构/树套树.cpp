//有N个位置，M个操作。操作有两种，每次操作如果是：
//1 a b c：表示在第a个位置到第b个位置，每个位置插上一个数c
//2 a b c：表示询问从第a个位置到第b个位置，第C大的数是多少。
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 50010
//#define int long long
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"
inline int read(){
	int x = 0,y = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){if(ch == '-') y = -1;ch = getchar();}
	while(ch >= '0'&&ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}
	return x * y;
}
int n,m,node,cnt;
int ql[N],qr[N],op[N],b[N],a[N];
int rt[N<<2],lazy[N*400];
struct Tnode{
    int l,r;
    long long size;
}T[N*400];
#define RI register int
inline void update(RI k) { T[k].size = T[T[k].l].size + T[T[k].r].size; }
inline void down(RI k,RI l,RI r){
	RI mid = (l + r) >> 1;
	RI &v = lazy[k];
	if(!T[k].l) T[k].l = ++ node;
	if(!T[k].r) T[k].r = ++ node;
	lazy[T[k].l] += v;
	lazy[T[k].r] += v;
	T[T[k].l].size += v * (mid - l + 1);
	T[T[k].r].size += v * (r - mid);
	v = 0;
}
inline void change(RI &k,RI l,RI r,RI x,RI y){
	if(!k) k = ++ node;
	if(l >= x && r <= y) {
		lazy[k] ++;T[k].size += r - l + 1;
		return;
	}
	if(lazy[k]) down(k,l,r);
	RI mid = (l + r) >> 1;
	if(x <= mid) change(T[k].l,l,mid,x,y);
	if(y > mid) change(T[k].r,mid+1,r,x,y);
	update(k);
}
inline long long query(RI &k,RI l,RI r,RI x,RI y){
	if(!k) return 0;
	if(l >= x && r <= y) return T[k].size;
	if(lazy[k]) down(k,l,r);
	RI mid = (l + r) >> 1;
	long long res = 0;
	if(x <= mid) res += query(T[k].l,l,mid,x,y);
	if(y > mid) res += query(T[k].r,mid+1,r,x,y);
	return res;
}
inline void insert(RI k,RI l,RI r,RI x,RI y,RI v){
	change(rt[k],1,n,x,y);
	if(l == r) return;
	RI mid = (l + r) >> 1;
	if(v <= mid) insert(k << 1,l,mid,x,y,v);
	else insert(k << 1 | 1,mid+1,r,x,y,v);
}

inline int ask(RI k,RI l,RI r,RI x,RI y,register long long v){
	if(l == r) return b[l];
	RI mid = (l + r) >> 1;
	long long res = query(rt[k << 1 | 1],1,n,x,y);
	if(res < v) return ask(k << 1,l,mid,x,y,v - res);
	else return ask(k << 1 | 1,mid+1,r,x,y,v); 
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n = read();m = read();
	for(RI i = 1;i <= m;++ i) {
		op[i] = read();
		ql[i] = read(),qr[i] = read();
		a[i] = read();
		if(op[i] == 1) b[++cnt] = a[i];
	}
	sort(b + 1,b + cnt + 1);
	cnt = unique(b + 1,b + cnt + 1) - b - 1;
	for(RI i = 1;i <= m;++ i)
		if(op[i] == 1)
			a[i] = lower_bound(b + 1,b + cnt + 1,a[i]) - b;
	for(RI i = 1;i <= m;++ i) {
		if(op[i] == 1) insert(1,1,cnt,ql[i],qr[i],a[i]);
		else printf("%d\n",ask(1,1,cnt,ql[i],qr[i],a[i]));
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
