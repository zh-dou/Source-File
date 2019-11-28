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
char s[N];
int n,m,SA[N],rank[N],height[N];
inline void Suffix_Array(){
    static int set[N],a[N];
    copy(s+1,s+n+1,set+1);
    sort(set+1,set+n+1);
    int end=unique(set+1,set+n+1)-set;
    for(int i=1;i<=n;i++){
    	a[i]=lower_bound(set+1,set+end,s[i])-set;
    }
    static int fir[N],sec[N],tmp[N],buc[N];
    for(int i=1;i<=n;i++) buc[a[i]]++;
    for(int i=1;i<=n;i++) buc[i]+=buc[i-1];
    for(int i=1;i<=n;i++) rank[i]=buc[a[i]-1]+1;
    for(int t=1;t<=n;t<<=1){
        for(int i=1;i<=n;i++) fir[i]=rank[i];
        for(int i=1;i<=n;i++) sec[i]=i+t>n?0:rank[i+t];
        fill(buc,buc+n+1,0);
        for(int i=1;i<=n;i++) buc[sec[i]]++;
        for(int i=1;i<=n;i++) buc[i]+=buc[i-1];
        for(int i=1;i<=n;i++) tmp[n-(--buc[sec[i]])]=i;
        fill(buc,buc+n+1,0);
        for(int i=1;i<=n;i++) buc[fir[i]]++;
        for(int i=1;i<=n;i++) buc[i]+=buc[i-1];
        for(int j=1,i;j<=n;j++) i=tmp[j],SA[buc[fir[i]]--]=i;
        bool flag=true;
        for(int j=1,i,last=0;j<=n;j++){
            i=SA[j];
            if(!last){
				rank[i]=1;
			}else{
            	if(fir[i]==fir[last]&&sec[i]==sec[last]){
            		rank[i]=rank[last];flag=false;
            	}else{
					rank[i]=rank[last]+1;
				}
            }
            last=i;
        }
        if(flag) break;
    }
    for(int i=1,k=0;i<=n;i++){
        if(rank[i]==1){
			k=0;
		}else{
            if(k>0) k--;
            int j=SA[rank[i]-1];
            while(i+k<=n&&j+k<=n&&a[i+k]==a[j+k]) k++;
        }
        height[rank[i]]=k;
    }
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);

//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

