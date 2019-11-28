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
char a[N],b[N];
int nxt[N],extend[N],lena,lenb;
inline void get_nxt(){
	lena=strlen(a);lenb=strlen(b);
	nxt[0]=lenb;
	int now=0,p0=1;
	while(b[now]==b[now+1]&&now+1<lenb) ++now;
	nxt[1]=now;
	for(int i=2;i<lenb;i++){
		if(i+nxt[i-p0]<nxt[p0]+p0) nxt[i]=nxt[i-p0];
		else{
            now=max(nxt[p0]+p0-i,0LL);
            while(b[now]==b[i+now]&&i+now<lenb) ++now;
            nxt[i]=now;
            p0=i;
        }
	}
}
void exKMP(){
    get_nxt();
    int now=0,p0=0;
    while(a[now]==b[now]&&now<min(lena,lenb)) ++now;
    extend[0]=now;
    for(int i=1;i<lena;i++){
        if(i+nxt[i-p0]<extend[p0]+p0)extend[i]=nxt[i-p0];
        else{
            now=max(extend[p0]+p0-i,0LL);
            while(b[now]==a[i+now]&&now<lenb&&now+i<lena) ++now;
            extend[i]=now;
            p0=i;
        }
    }
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	scanf("%s", a);scanf("%s", b);
	exKMP();
	for(int i=0;i<lenb;i++) cout<<nxt[i]<<" ";
	cout<<"\n";
	for(int i=0;i<lena;i++) cout<<extend[i]<<" ";
	cout<<"\n";
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

