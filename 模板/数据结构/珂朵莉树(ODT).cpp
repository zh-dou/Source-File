#include<set>
#include<cmath>
#include<vector>
#include<cstdio>
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
struct Node{
	int l,r;
	mutable int val;
	Node(int L,int R=-1,int V=0):l(L),r(R),val(V){}
	friend bool operator <(const Node &a,const Node &b){
		return a.l<b.l;
	}
};
inline int ksm(int x,int y,int mod){
	int ans=1;x=x%mod;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans%mod;
}
set<Node> s;
#define IT set<Node>::iterator
inline IT Split(int pos){
	IT it=s.lower_bound(Node(pos));
	if(it!=s.end()&&it->l==pos) return it;
	it--;
	int l=it->l,r=it->r,val=it->val;
	s.erase(it);
	s.insert(Node(l,pos-1,val));
	return s.insert(Node(pos,r,val)).first;
}
inline void Assign(int l,int r,int val){
	IT it2=Split(r+1),it1=Split(l);
	s.erase(it1,it2);
	s.insert(Node(l,r,val));
}
inline void Add(int l,int r,int val){
	for(IT it2=Split(r+1),it1=Split(l);it1!=it2;it1++)
		it1->val+=val;
}
inline int Rank(int l,int r,int k){
	vector<pair<int,int> >vec;
	vec.clear();
    for(IT it2=Split(r+1),it1=Split(l);it1!=it2;++it1)
        vec.push_back(pair<int,int>(it1->val,it1->r-it1->l+1));
    sort(vec.begin(),vec.end());
    for(vector<pair<int,int> >::iterator it=vec.begin();it!=vec.end();++it){
        k-=it->second;
        if(k<=0) return it->first;
    }
}
inline int Sum(int l,int r,int ex,int mod){
    int res=0;
    for(IT it2=Split(r+1),it1=Split(l);it1!=it2;++it1)
        res=(res+(it1->r-it1->l+1)*ksm(it1->val,ex,mod))%mod;
    return res;
}
int n,m,seed,vmax;
int Make(){
    int ret=seed;
    seed=(seed*7+13)%1000000007;
    return ret;
}
int a[N];
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();m=read();seed=read();vmax=read();
    for(int i=1;i<=n;i++){
        a[i]=Make()%vmax+1;
        s.insert(Node(i,i,a[i]));
    }
    s.insert(Node(n+1,n+1,0));
    for(int i=1,opt,l,r,x,y;i<=m;i++){
        opt=Make()%4+1;l=Make()%n+1;r=Make()%n+1;
        if(l>r) swap(l,r);
        if(opt==3) x=Make()%(r-l+1)+1;
        else x=Make()%vmax+1;
        if(opt==4) y=Make()%vmax+1;
        if(opt==1) Add(l,r,x);
        if(opt==2) Assign(l,r,x);
        if(opt==3) cout<<Rank(l,r,x)<<"\n";
        if(opt==4) cout<<Sum(l,r,x,y)<<"\n";
    }
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

