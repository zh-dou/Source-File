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
int n;
char str[1000010];
struct Trie{
protected:
	int son[N][28];
	int cnt,end[N],fail[N];
public:
	Trie(){
		cnt=0;
		memset(son,0,sizeof(son));
//		memset(siz,0,sizeof(siz));
		memset(end,0,sizeof(end));
		memset(fail,0,sizeof(end));
	}
	void insert(char str[],int len){
		int p=0;
		for(int i=0;i<len;i++){
			if(!son[p][str[i]-'a']) son[p][str[i]-'a']=++cnt;
//			cout<<p<<"->"<<son[p][str[i]-'a']<<"\n";
			p=son[p][str[i]-'a'];
		}
		end[p]++;
	}
	int find(char str[],int len){
		int p=0,res,ans=0;
		for(int i=0;i<len;i++){
			res=son[p][str[i]-'a'];
			while(res&&end[res]!=-1){
				ans+=end[res];
				end[res]=-1;
				res=fail[res];
			}
			p=son[p][str[i]-'a'];
		}
		return ans;
	}
	void init_fail(){
//		debug;
		queue<int> q;
		int pos,i;
		for(i=0;i<26;i++){
			if(son[0][i]){
				q.push(son[0][i]);
			}
		}
		while(!q.empty()){
			pos=q.front();q.pop();
//			cout<<pos<<"->"<<fail[pos]<<"\n";
			for(int i=0;i<26;i++){
				if(!son[pos][i]){
					son[pos][i]=son[fail[pos]][i];
					continue;
				}
				fail[son[pos][i]]=son[fail[pos]][i];
				q.push(son[pos][i]);
			}
		}
	}
}trie;
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		trie.insert(str,strlen(str));
	}
	trie.init_fail();
	scanf("%s",str);
	cout<<trie.find(str,strlen(str))<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
