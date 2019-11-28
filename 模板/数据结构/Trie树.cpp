#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define N 5000010
inline int read(){
	int x=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x;
}
struct Trie{
protected:
	int son[N][28];
	int cnt,siz[N],end[N];
public:
	Trie(){
		cnt=1;
		memset(son,0,sizeof(son));
		memset(siz,0,sizeof(siz));
		memset(end,0,sizeof(end));
	}
	void insert(char str[],int len){
		int p=1;
		for(int i=0;i<len;i++){
			if(!son[p][str[i]-'a']) son[p][str[i]-'a']=++cnt;
			p=son[p][str[i]-'a'];siz[p]++;
		}
		end[p]++;
	}
	int find(char str[],int len){
		int p=1;
		for(int i=0;i<len;i++){
			p=son[p][str[i]-'a'];
		}
		return end[p];
	}
}trie;
signed main(){
	int n=read();
	char str[100010];
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		trie.insert(str,strlen(str));
		cout<<trie.find(str,strlen(str))<<"\n";
	}
    return 0;
}

