#include<stack>
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
signed main(){
	int pre=read(),base=read();
	char s[]="0123456789ABCDEFGHIJ";
	cout<<pre<<"=";
	std::stack<int> q;
	while(pre){
		int tmp=pre%base;
		pre/=base;
		if(tmp<0)
			tmp-=base,pre++;
		q.push(tmp);
	}
	while(!q.empty()){
		printf("%c",s[q.top()]);
		q.pop();
	}
	cout<<"(base"<<base<<")\n";
	return 0;
}
