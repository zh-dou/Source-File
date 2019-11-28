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
#define int long long
inline int read(){
 	int x=0,y=1;
 	char ch=getchar();
 	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
 	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
 	return x*y;
}
char s1[N],s2[N];
int nex[N];
inline void KMP(){
	int k=0,len1=strlen(s1+1),len2=strlen(s2+1);
	nex[1]=0;
	for(int i=2;i<=len1;i++){
		while(k&&s1[i]!=s1[k+1]) k=nex[k];
		if(s1[i]==s1[k+1]) k++;
		nex[i]=k;
	}
	k=0;
	for(int i=1;i<=len2;i++){
		while(k&&s1[k+1]!=s2[i]) k=nex[k];
		if(s1[k+1]==s2[i]) k++;
		if(k==len1) cout<<i-len1+1<<"\n";
	}
	for(int i=1;i<=len1;i++)
		cout<<nex[i]<<" ";
	cout<<"\n";
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s\n%s",s2+1,s1+1);
	KMP();
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

