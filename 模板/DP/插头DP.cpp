#include<unordered_map>
#include<bitset>
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
int n,m,tx,ty,ans,a[20][20],bit[20];
unordered_map<int,int> M1,M2;
unordered_map<int,int>::iterator k;
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
	n=read();m=read();
//	getchar();//Linux
	bit[0]=1;
	for(int i=1;i<=13;i++) bit[i]=bit[i-1]<<2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=(getchar()=='.');
			if(a[i][j]){tx=i;ty=j;}
		}
		getchar();
//		getchar();//Linux
	}
	M1[0]=1;
	for(int i=1,j,b1,b2,val,res,num;i<=n;i++){
		for(k=M1.begin();k!=M1.end();k++){
			M2[((*k).first)<<2]=(*k).second;
		}
//		cout<<"\n";
		swap(M1,M2);M2.clear();
		for(j=1;j<=m;j++){
			for(k=M1.begin();k!=M1.end();k++){
				val=(*k).first;
				b1=(val>>(2*j-2))&3;b2=(val>>(2*j))&3;
//				cout<<bitset<12>(val)<<" "<<b1<<" "<<b2<<" "<<j<<"      fuck\n";
				if(!a[i][j]){
					if((!b1)&&(!b2)) M2[val]+=(*k).second;
					continue;
				}
				if((!b1)&&(!b2)){
					if(a[i+1][j]&&a[i][j+1]) M2[val+bit[j-1]+(bit[j]<<1)]+=(*k).second;
					continue;
				}
				if(b1&&(!b2)){
					if(a[i+1][j]) M2[val]+=(*k).second;
					if(a[i][j+1]) M2[val-b1*bit[j-1]+b1*bit[j]]+=(*k).second;
					continue;
				}
				if((!b1)&&b2){
					if(a[i][j+1]) M2[val]+=(*k).second;
					if(a[i+1][j]) M2[val-b2*bit[j]+b2*bit[j-1]]+=(*k).second;
					continue;
				}
				if(b1==1&&b2==1){
					res=2*j+2;num=1;
					for(;res<=(m<<1);res+=2){
						if(((val>>res)&3)==1) ++num;
						if(((val>>res)&3)==2) --num;
//						cout<<(res>>1)<<" "<<num<<"\n";
						if(!num){
							M2[val-bit[j-1]-bit[j]-bit[res>>1]]+=(*k).second;
							break;
						}
					}
					continue;
				}
				if(b1==2&&b2==2){
					res=2*j-4;num=1;
					for(;res>=0;res-=2){
						if(((val>>res)&3)==1) --num;
						if(((val>>res)&3)==2) ++num;
						if(!num){
							M2[val-2*bit[j-1]-2*bit[j]+bit[res>>1]]+=(*k).second;
							break;
						}
					}
					continue;
				}
				if(b1==2&&b2==1){
					M2[val-2*bit[j-1]-bit[j]]+=(*k).second;
					continue;
				}
				if(b1==1&&b2==2){
					if(i==tx&&j==ty) ans+=(*k).second;
					continue;
				}
			}
//			cout<<M2.size()<<" ";
			swap(M1,M2);
//			cout<<M1.size()<<" ";
			M2.clear();
//			cout<<M2.size()<<" "<<M1.size()<<"     233\n";
		}
	}
	cout<<ans<<"\n";
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

