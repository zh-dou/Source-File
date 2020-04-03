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
#define N 5000010
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
int n,a[N],tmp;
char s[N];
struct PAM{
	int cnt,last;
	struct Node{
		int fail,len,num,ch[26];
	}tree[N];
	PAM(){
		cnt=1;last=0;
		tree[1].len=-1;tree[0].len=0;
		tree[1].fail=tree[0].fail=1;
	}
	inline int Jump(int pos,int x){
		while(a[pos-tree[x].len-1]!=a[pos]){
			x=tree[x].fail;
//			cout<<pos<<" "<<x<<"\n";
		}
		return x;
	}
	inline void Insert(int pos){
		int p=Jump(pos,last);
		if(!tree[p].ch[a[pos]]){
			tree[++cnt].len=tree[p].len+2;
			int res=Jump(pos,tree[p].fail);
			tree[cnt].fail=tree[res].ch[a[pos]];
			tree[cnt].num=tree[tree[cnt].fail].num+1;
			tree[p].ch[a[pos]]=cnt;
		}
		last=tree[p].ch[a[pos]];
		tmp=tree[last].num;
	}
}pam;
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	cin>>(s+1);
	n=strlen(s+1);
	a[0]=2333;
	for(int i=1;i<=n;i++){
		s[i]=(s[i]-97+tmp)%26+97;
		a[i]=s[i]-'a';
		pam.Insert(i);
		cout<<tmp<<" ";
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

