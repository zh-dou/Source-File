#include<map>
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
#define int long long
int A,B;
inline int read(){
    int x=0,y=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*y;
}
inline int ksm(int x,int y){
    int ans=1;
    while(y){
        if(y&1) ans=(ans*x)%9901;
        x=(x*x)%9901;
        y>>=1;
    }
    return ans;
}
int ans[100010],pri[10010],cnt;
signed main(){
    A=read();B=read();
    if(A==0){
        cout<<"0\n";return 0;
    }
    if(B==0){
        cout<<"1\n";return 0;
    }
    for(int i=2;i<=A;i++){
        if(A%i==0){
            pri[++cnt]=i;
            while(A%i==0){
                A/=i;ans[cnt]++;
            }
            ans[cnt]*=B;
        }
    }
    if(A!=1) ans[++cnt]=B,pri[cnt]=A;
    int sum=1;
    for(int i=1;i<=cnt;i++){
        if((pri[i]-1)%9901==0){sum=(sum+ans[i]+1)%9901;}
        else{
            int res=ksm(pri[i],ans[i]+1)-1,res2=ksm(pri[i]-1,9899);
//          cout<<res<<" "<<res2<<"\n";
            sum=(sum*((res*res2)%9901))%9901;
        }
    }
    cout<<sum<<"\n";
    return 0;
}
