#include<set>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 11000010
//#define int long long
inline int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*y;
}
char s1[N<<1],s[N];
int RL[N<<1],ans;
inline void Manacher(){
	int len=strlen(s1),id=0,Max_right=0;//RL 回文半径 id 回文中心  
	register int i;
	for(i=0;i<len;i++){
		s[i<<1]='#';s[i<<1|1]=s1[i];
	}
	len=len<<1|1;
	s[len-1]='#';
	RL[0]=1;
//	cout<<s<<"\n";
	for(i=1;i<len;i++){
		if(i<=Max_right) RL[i]=min(Max_right-i+1,RL[(id<<1)-i]);
		else RL[i]=1;
//		cout<<RL[i]<<" ";
		while(i-RL[i]>=0&&i+RL[i]<len&&s[i+RL[i]]==s[i-RL[i]]) RL[i]++;
		if(i+RL[i]-1>Max_right){
			Max_right=i+RL[i]-1;id=i;
		}
//		cout<<i<<" "<<s[i]<<" "<<RL[i]<<" "<<Max_right<<"\n";
	}
//	cout<<len<<" "<<s<<"\n";
	for(i=0;i<len;i++) ans=max(ans,RL[i]);
	cout<<ans-1<<"\n";
}
signed main(){
	scanf("%s",s1);
	Manacher();
	return 0;
}
