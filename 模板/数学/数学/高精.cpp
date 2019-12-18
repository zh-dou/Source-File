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
#define N 100010
namespace Big_num{
    #define maxn 10005
    using std::sprintf;
    using std::string;
    using std::max;
    using std::istream;
    using std::ostream;
    struct Big_int{
        int d[maxn],len;
        void clean(){
            while(len>1&&!d[len-1]) len--;
        }
        Big_int(){
            memset(d,0,sizeof(d));
            len=1;
        }
        Big_int(int num){*this=num;}
        Big_int(char* num){*this=num;}
        Big_int operator = (const char* num){
            memset(d,0,sizeof(d));
            len=strlen(num);
            for(int i=0;i<len;i++)
              d[i]=num[len-1-i]-'0';
            clean();
            return *this;
        }
        Big_int operator = (int num){
            char s[10005];
            sprintf(s,"%d",num);
            *this=s;
            return *this;
        }
        Big_int operator + (const Big_int& b){
            Big_int c=*this;
            int i;
            for(i=0;i<b.len;i++){
                c.d[i]+=b.d[i];
                if(c.d[i]>9){
                    c.d[i]%=10;
                    c.d[i+1]++;
                }
            }
            while(c.d[i]>9){
                c.d[i++]%=10;
                c.d[i]++;
            }
            c.len=max(len,b.len);
            if(c.d[i]&&c.len<=i)
              c.len=i+1;
            return c;
        }
        Big_int operator - (const Big_int& b){
            Big_int c=*this;
            int i;
            for(i=0;i<b.len;i++){
                c.d[i]-=b.d[i];
                if(c.d[i]<0){
                    c.d[i]+=10;
                    c.d[i+1]--;
                }
            }
            while(c.d[i]<0){
                c.d[i++]+=10;
                c.d[i]--;
            }
            c.clean();
            return c;
        }
        Big_int operator * (const Big_int& b) const{
            int i,j;
            Big_int c;
            c.len=len+b.len;
            for(j=0;j<b.len;j++)
              for(i=0;i<len;i++)
                c.d[i+j]+=d[i]*b.d[j];
            for(i=0;i<c.len-1;i++){
                c.d[i+1]+=c.d[i]/10;
                c.d[i]%=10;
            }
            c.clean();
            return c;
        }
        Big_int operator % (const Big_int& b){
            int i,j;
            Big_int a;
            for(i=len-1;i>=0;i--){
                a=a*10+d[i];
                for(j=0;j<10;j++)
                	if(a<b*(j+1)) break;
            	a=a-b*j;
            }
            return a;
        }
        bool operator < (const Big_int& b) const{
            if(len != b.len) return len<b.len;
            for(int i=len-1;i>=0;i--)
              if(d[i]!=b.d[i])
                return d[i]<b.d[i];
            return false;
        }
        bool operator <= (const Big_int& b) const{
            if(len != b.len) return len<b.len;
            for(int i=len-1;i>=0;i--)
              if(d[i]!=b.d[i])
                return d[i]<b.d[i];
            return true;
        }
        bool operator > (const Big_int& b) const{
            if(len != b.len) return len>b.len;
            for(int i=len-1;i>=0;i--)
              if(d[i]!=b.d[i])
                return d[i]>b.d[i];
            return false;
        }
        bool operator >= (const Big_int& b) const{
            if(len != b.len) return len<b.len;
            for(int i=len-1;i>=0;i--)
              if(d[i]!=b.d[i])
                return d[i]>b.d[i];
            return true;
        }
        bool operator == (const Big_int& b) const{
            if(len != b.len) return 0;
            for(int i=len-1;i>=0;i--)
              if(d[i]!=b.d[i])
                return false;
            return true;
        }
        string str()const{
            char s[maxn]={};
            for(int i=0;i<len;i++)
            	s[len-1-i]=d[i]+'0';
            return s;
        }
    };
    istream& operator >> (istream& in,Big_int& x){
        string s;
        in>>s;
        x=s.c_str();
        return in;
    }
    ostream& operator << (ostream& out,const Big_int& x){
        out<<x.str();
        return out;
    }
}
inline int read(){
	int x=0,y=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
using namespace Big_num;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

