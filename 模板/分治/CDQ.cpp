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
#define N 200010
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
int n,k,len,tot;
int tree[N];
int ans[N];
struct node{
    int a,b,c,num,ans;
    friend bool operator == (const node&a,const node&b){
        return (a.a==b.a&&a.b==b.b&&a.c==b.c);
    }
}a[N],b[N];
int lowbit(int x){return x&-x;}
inline void add(int x,int val){
    while(x<=k){
        tree[x]+=val;
        x+=lowbit(x);
    }
}
inline int ask(int x){
    int ans=0;
    while(x>0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
bool cmp1(node a,node b){
    if(a.a!=b.a) return a.a<b.a;
    if(a.b!=b.b) return a.b<b.b;
    return a.c<b.c;
}
bool cmp2(node a,node b){
    if(a.b!=b.b) return a.b<b.b;
    return a.c<b.c;
}
void CDQ(int l,int r){
    if(l==r) return ;
    int mid=(l+r)>>1;
    CDQ(l,mid),CDQ(mid+1,r);
    sort(a+l,a+mid+1,cmp2);
    sort(a+mid+1,a+r+1,cmp2);
    int j=l;
    for(int i=mid+1;i<=r;i++){
        while(a[i].b>=a[j].b&&j<=mid)
            add(a[j].c,a[j].num),j++;
        a[i].ans+=ask(a[i].c);
    }
    for(int i=l;i<j;i++) add(a[i].c,-a[i].num);
}
signed main(){
    n=read(),k=read();
    for(int i=1;i<=n;i++)
        b[i].a=read(),b[i].b=read(),b[i].c=read();
    sort(b+1,b+1+n,cmp1);
    for(int i=1;i<=n;i++){
        if(b[i]==b[i-1]) a[len].num++;
        else{
            a[++len]=b[i];
            a[len].num++;
        }
    }
    CDQ(1,len);
    for(int i=1;i<=len;i++)
        ans[a[i].ans+a[i].num-1]+=a[i].num;
    for(int i=0;i<n;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
