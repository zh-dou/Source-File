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
int n,m,val[N],root[N],cnt,discretization[N<<1],tot_num,tmp_l[N],tmp_r[N];
struct Pro{
	int opt,l,r,val;
}que[N];
#define lowbit(x) (x&(-x))
struct Node{
	int lson,rson,siz;
}tree[N*800];

#define mid ((l+r)>>1)
#define ls(node) tree[node].lson 
#define rs(node) tree[node].rson 
void Update(int &node,int l,int r,int pos,int opt){
	if(!node) node=++cnt;
	tree[node].siz+=opt;
	if(l==r) return;
	if(pos<=mid) Update(ls(node),l,mid,pos,opt);
	else Update(rs(node),mid+1,r,pos,opt);
}
inline void Modify(int pos,int res_val){
	int res_pos=pos;
	while(res_pos<=n){
		Update(root[res_pos],1,tot_num,val[pos],-1);
		Update(root[res_pos],1,tot_num,res_val,1);
		res_pos+=lowbit(res_pos);
	}
}
inline int Ask(int l,int r,int val){
	int res_r=0,res_l=0,sum_r=0,sum_l=0;
//	cout<<"________________________________\n"<<l<<" "<<r<<" "<<val<<"\n";
	--l;
	while(r){
		tmp_r[++res_r]=root[r];
		r-=lowbit(r);
	}
	while(l){
		tmp_l[++res_l]=root[l];
		l-=lowbit(l);
	}
	l=1,r=tot_num;
	for(int i=1;i<=res_l;i++) sum_l+=tree[tmp_l[i]].siz;
	for(int i=1;i<=res_r;i++) sum_r+=tree[tmp_r[i]].siz;
//	cout<<sum_l<<" "<<sum_r<<"\n";
//	for(int i=1;i<=res_l;i++) cout<<tmp_l[i]<<" ";
//	cout<<"End_l\n";
//	for(int i=1;i<=res_r;i++) cout<<tmp_r[i]<<" ";
//	cout<<"End_r\n";
	while(l!=r){
		sum_l=0;sum_r=0;
		for(int i=1;i<=res_l;i++) sum_l+=tree[ls(tmp_l[i])].siz;
		for(int i=1;i<=res_r;i++) sum_r+=tree[ls(tmp_r[i])].siz;
//		cout<<sum_l<<" "<<sum_r<<"\n";
//		for(int i=1;i<=res_l;i++) cout<<tmp_l[i]<<" ";
//		cout<<"End_l\n";
//		for(int i=1;i<=res_r;i++) cout<<tmp_r[i]<<" ";
//		cout<<"End_r\n";
		if(sum_r-sum_l>=val){
			for(int i=1;i<=res_l;i++) tmp_l[i]=ls(tmp_l[i]);
			for(int i=1;i<=res_r;i++) tmp_r[i]=ls(tmp_r[i]);
			r=mid;
		}else{
			for(int i=1;i<=res_l;i++) tmp_l[i]=rs(tmp_l[i]);
			for(int i=1;i<=res_r;i++) tmp_r[i]=rs(tmp_r[i]);
			val-=sum_r-sum_l;l=mid+1;
		}
	}
//	cout<<sum_l<<" "<<sum_r<<" "<<l<<" "<<r<<"\n";
	return l;
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();m=read();
	tot_num=0;
	for(int i=1;i<=n;i++){
		val[i]=read();
		discretization[++tot_num]=val[i];
	}
	char ch[4];
	for(int i=1;i<=m;i++){
		scanf("%s",ch);
		que[i].opt=(ch[0]=='C');
		if(que[i].opt==0){
			que[i].l=read();que[i].r=read();que[i].val=read();
		}else{
			que[i].l=read();que[i].val=read();
			discretization[++tot_num]=que[i].val;
		}
//		cout<<ch[0]<<" "<<i<<" "<<tot_num<<"\n";
	}
//	cerr<<tot_num<<"\n";
	sort(discretization+1,discretization+tot_num+1);
	tot_num=unique(discretization+1,discretization+tot_num+1)-discretization-1;
	for(int i=1;i<=n;i++)
		val[i]=lower_bound(discretization+1,discretization+tot_num+1,val[i])-discretization;
	for(int i=1;i<=m;i++){
		if(que[i].opt==1)
			que[i].val=lower_bound(discretization+1,discretization+tot_num+1,que[i].val)-discretization;
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<":\n";
		for(int j=i-lowbit(i)+1;j<=i;j++){
//			cout<<j<<" ";
			Update(root[i],1,tot_num,val[j],1);
		}
//		cout<<root[i]<<"\n";
	}
	for(int i=1;i<=m;i++){
		if(que[i].opt==0){
			cout<<discretization[Ask(que[i].l,que[i].r,que[i].val)]<<"\n";
		}else{
			Modify(que[i].l,que[i].val);
			val[que[i].l]=que[i].val;
		}
//		for(int i=1;i<=n;i++) cout<<val[i]<<" ";
//		cout<<"\n";
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
/*
5 3
3 2 1 4 7
Q 2 5 3
C 2 6
Q 2 5 3
*/
