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
int n,a[N],set[N],sa[N],rk[N],ht[N],fir[N],sec[N],tmp[N],buc[N];
char s[N];
inline void Suffix_Sort(){
	copy(s+1,s+n+1,set+1);
	sort(set+1,set+n+1);
	int *end=unique(set+1,set+n+1);
	for(int i=1;i<=n;i++) a[i]=lower_bound(set+1,end,s[i])-set;
	for(int i=1;i<=n;i++) buc[a[i]]++;
	for(int i=1;i<=n;i++) buc[i]+=buc[i-1];
	for(int i=1;i<=n;i++) rk[i]=buc[a[i]-1]+1;
	for(int t=1;t<=n;t<<=1){
		for(int i=1;i<=n;i++) fir[i]=rk[i];
		for(int i=1;i<=n;i++) sec[i]=i+t>n?0:rk[i+t];
		fill(buc,buc+n+1,0);
		for(int i=1;i<=n;i++) buc[sec[i]]++;
		for(int i=1;i<=n;i++) buc[i]+=buc[i - 1];
		for(int i=1;i<=n;i++) tmp[n-(--buc[sec[i]])]=i;
		fill(buc,buc+n+1,0);
		for(int i=1;i<=n;i++) buc[fir[i]]++;
		for(int i=1;i<=n;i++) buc[i]+=buc[i-1];
		for(int i=1;i<=n;i++) sa[buc[fir[tmp[i]]]--]=tmp[i];
		bool unique=true;
		for(int i=1,last=0;i<=n;i++){
			if (!last) rk[sa[i]]=1;
			else if (fir[sa[i]]==fir[last]&&sec[sa[i]]==sec[last]) rk[sa[i]]=rk[last],unique=false;
			else rk[sa[i]]=rk[last]+1;
			last=sa[i];
		}
		if (unique) break;
	}
	for(int i=1,k=0;i<=n;i++){
		if(rk[i]==1) k=0;
		else{
			if(k>0) k--;
			while(i+k<=n&&sa[rk[i]-1]+k<=n&&a[i+k]==a[sa[rk[i]-1]+k]) k++;
		}
		ht[rk[i]]=k;
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	Suffix_Sort();
	for(int i=1;i<=n;i++) cout<<sa[i]<<" ";
	cout<<"\n";
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
