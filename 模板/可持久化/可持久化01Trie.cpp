#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 800010
//#define int long long
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
int n,m,cnt;
int sum[N],root[N];
struct Tree{
	int son[2],siz;
}tree[N*25];
inline void insert(int A,int &B,int val){
	int tmp=B=++cnt;
	for(int i=24;i>=0;i--){
		tree[tmp]=tree[A];++tree[tmp].siz;
		tree[tmp].son[(val>>i)&1]=++cnt;
		tmp=tree[tmp].son[(val>>i)&1];A=tree[A].son[(val>>i)&1];
	}
	tree[tmp].siz=tree[A].siz+1;
}
inline int qurry(int A,int B,int val){
	int tmp=0;
	for(int i=24;i>=0;i--){
		if(tree[tree[B].son[((val>>i)&1)^1]].siz-tree[tree[A].son[((val>>i)&1)^1]].siz>0){
			tmp+=(1<<i);A=tree[A].son[((val>>i)&1)^1];B=tree[B].son[((val>>i)&1)^1];
		}else{
			A=tree[A].son[(val>>i)&1];B=tree[B].son[(val>>i)&1];
		}
	}
	return tmp;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read()+1,m=read();
	for(int i=2;i<=n;++i) sum[i]=sum[i-1]^read();
	for(int i=1;i<=n;++i) insert(root[i-1],root[i],sum[i]);
	char s[3];
    for(int i=1,l,r,x;i<=m;++i){
        scanf("%s",s);
        if(s[0]=='A'){
            x=read();++n;
            sum[n]=sum[n-1]^x;
            insert(root[n-1],root[n],sum[n]);
        }else{
            l=read();r=read();x=read();
            cout<<qurry(root[l-1],root[r],sum[n]^x)<<"\n";
        }
    }
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

