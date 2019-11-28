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
inline int read(){
	int x=0,y=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
signed main(){
	vector<int> v;
    int t=read();
    while(t--){
        int opt=read(),x=read();
        int pos1=lower_bound(v.begin(),v.end(),x)-v.begin();
        int pos2=upper_bound(v.begin(),v.end(),x)-v.begin();
        if(opt==1) {v.insert(v.begin()+pos1,x);}
        if(opt==2) {v.erase(v.begin()+pos1,v.begin()+pos1+1);}
        if(opt==3) {cout<<pos1+1<<"\n";}
        if(opt==4) {cout<<v[x-1]<<"\n";}
        if(opt==5) {cout<<v[pos1-1]<<"\n";}
        if(opt==6) {cout<<v[pos2]<<"\n";}
    }
	return 0;
}

