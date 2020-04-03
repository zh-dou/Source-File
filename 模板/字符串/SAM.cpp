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
#define N 1000010
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
int n,m,ans;
char s[N];
int cnt,head[N<<1];
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int x,int y){
	edge[++cnt].nxt=head[x];
	edge[cnt].to=y;
	head[x]=cnt;
}
struct SAM{
	int tot,last,siz[N<<1],len[N<<1],lin[N<<1],ch[N<<1][26];
	SAM(){tot=last=1;}
	void Insert(int c){
		int cur=++tot,p;len[cur]=len[last]+1;siz[cur]=1;
		for(p=last;p&&ch[p][c]==0;p=lin[p]) ch[p][c]=cur;
		last=cur;
		if(!p){
			lin[cur]=1;
			return ;
		}
		int q=ch[p][c],r;
		if(len[q]==len[p]+1){
			lin[cur]=q;
		}else{
			r=++tot;lin[r]=lin[q];len[r]=len[p]+1;
			for(int i=0;i<26;i++) ch[r][i]=ch[q][i];
			lin[cur]=lin[q]=r;
			for(;p&&ch[p][c]==q;p=lin[p]) ch[p][c]=r;
		}
	}
	void Build(){
		for(int i=1;i<=tot;i++) add(lin[i],i);
	}
	void dfs(int x){
		for(int i=head[x];i;i=edge[i].nxt){
			dfs(edge[i].to);
			siz[x]+=siz[edge[i].to];
		}
		if(siz[x]!=1) ans=max(ans,siz[x]*len[x]);
	}
}sam;
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++) sam.Insert(s[i]-'a');
	sam.Build();
	sam.dfs(1);
	cout<<ans<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

