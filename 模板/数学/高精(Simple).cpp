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
struct Bignum{
    int len,zheng;//len：长度 zheng：正负标记0为负1为正 
    int v[6000];
    Bignum(){len=0;memset(v,0,sizeof(v));zheng=1;}
    Bignum(int x){
        if(x>=0)zheng=1;
        else x=-x,zheng=0;
        len=0;memset(v,0,sizeof(v));
        while(x){
            v[++len]=x%10;
            x/=10;
        }
    }
    friend bool operator <(const Bignum &a,const Bignum &b){
    	if(a.zheng!=b.zheng) return a.zheng<b.zheng;
        if(a.len<b.len)return 1;
        if(a.len>b.len)return 0;
        for(int i=a.len;i>=1;--i){
            if(a.v[i]<b.v[i])return 1;
            if(a.v[i]>b.v[i])return 0;
        }
        return 0;
    }
    friend bool operator ==(const Bignum &a,const Bignum &b){
    	return !((a<b)||(b<a));
    }
    friend bool operator <=(const Bignum &a,const Bignum &b){
        return (a<b)||(a==b);
    }
}n,mid;
ostream& operator << (ostream &out,const Bignum &a);
istream& operator >> (istream &in,Bignum &a);
Bignum operator -(Bignum a,Bignum b);
Bignum operator +(Bignum a,Bignum b);
Bignum operator *(Bignum a,Bignum b);
Bignum operator +(Bignum a,Bignum b){
    if(!a.zheng&&!b.zheng){
        a.zheng=b.zheng=1;
        Bignum c=a+b;
        c.zheng=0;
        return c;
    }
    if(!a.zheng&&b.zheng){
        a.zheng=b.zheng=1;
        return b-a;
    }
    if(a.zheng&&!b.zheng){
        a.zheng=b.zheng=1;
        return a-b;
    }
    int len=a.len+b.len;
    Bignum c;
    c.len=len;
    for(int i=1;i<=len;++i)c.v[i]=a.v[i]+b.v[i];
    for(int i=1;i<=len;++i){
        if(c.v[i]>=10){
            ++c.v[i+1];
            c.v[i]-=10;
        }
    }
    while(c.len&&!c.v[c.len])c.len--;
    return c;
}
Bignum operator -(Bignum a,Bignum b){
    if(!a.zheng&&!b.zheng){
        a.zheng=b.zheng=1;
        return b-a;
    }
    if(!a.zheng&&b.zheng){
        a.zheng=1;
        Bignum c=a+b;
        c.zheng=0;
        return c;
    }
    if(a.zheng&&!b.zheng){
        b.zheng=1;
        Bignum c=a+b;
        return c;
    }
    if(a.zheng&&b.zheng&&a<b){
        Bignum c=b-a;
        c.zheng=0;
        return c;
    }
    int len=max(a.len,b.len);
    Bignum c;
    for(int i=1;i<=len;++i)c.v[i]=a.v[i]-b.v[i];
    c.len=len;
    for(int i=1;i<=c.len;++i){
        if(c.v[i]<0){
            c.v[i+1]--;
            c.v[i]+=10;
        }
    }
    while(c.len&&!c.v[c.len])c.len--;
    return c;
}
Bignum operator *(Bignum a,Bignum b){
    Bignum c;
    for(int i=1;i<=a.len;++i)
	    for(int j=1;j<=b.len;++j)
	    	c.v[i+j-1]+=a.v[i]*b.v[j];
    c.len=a.len+b.len;
    for(int i=1;i<=c.len-1;++i){
        if(c.v[i]>=10){
            c.v[i+1]+=c.v[i]/10;
            c.v[i]%=10;
        }
    }
    while(c.v[c.len]==0&&c.len>1)--c.len;
    if(a.zheng!=b.zheng)c.zheng=0;
    else c.zheng=1;
    return c;
}
Bignum operator /(Bignum a,long long b){
    Bignum c;int d=0;
    for(int i=a.len;i>=1;--i)
    c.v[++c.len]=((d*10+a.v[i])/b),d=(d*10+a.v[i])%b;
    for(int i=1;i<=c.len/2;++i)swap(c.v[i],c.v[c.len-i+1]);
    if(!a.len||!b||(a.zheng&&b>0)||(!a.zheng&&b<0))c.zheng=1;
    else c.zheng=0;
    while(c.v[c.len]==0&&c.len>1)--c.len;
    return c;
}
Bignum operator %(Bignum a,long long b){
    Bignum c;
    c=a-a/b*Bignum(b);
    return c;
}
istream& operator >> (istream &in,Bignum &a){
    char lin[5010];int len;
    scanf("%s",lin+1);
    len=a.len=strlen(lin+1);
    if(lin[1]=='-')a.zheng=0,a.len--;
    else a.zheng=1;
    for(int i=1;i<=a.len;++i)a.v[i]=lin[len-i+1]-'0';
    return in;
}
ostream& operator << (ostream &out,const Bignum &a){ 
    if(!a.len){ 
        cout<<"0";
        return out;
    }
    if(!a.zheng) cout<<"-";
    for(int i=a.len;i>=1;i--) printf("%lld",a.v[i]);
    return out;
}
Bignum ksm(Bignum a,int b){
    Bignum ans=Bignum(1);
    for(;b;b>>=1,a=a*a)
    if(b&1)ans=ans*a;
    return ans;
}
Bignum Max(Bignum a,Bignum b){
    if(a.zheng==1&&b.zheng==0) return a;
    else
    if(a.zheng==0&&b.zheng==1) return b;
    else{
       if(a.zheng==1){
            if(a<b) return b;
            else return a;
        }else{
            if(a<b) return a;
            else return b;
        }
    }
}
Bignum Min(Bignum a,Bignum b){
    if(a.zheng==1&&b.zheng==0) return b;
    else
    if(a.zheng==0&&b.zheng==1) return a;
    else{
         if(a.zheng==1){
            if(a<b) return a;
            else return b;
        }else{
            if(a<b) return b;
            else return a;
        }
    }
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);

//	fclose(stdin);
//	fclose(stdout);
    return 0;
}

