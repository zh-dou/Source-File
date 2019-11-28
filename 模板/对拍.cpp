#include<ctime>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
signed main(){
	system("g++ date.cpp -o date.exe -g -Wall");
	system("g++ baoli.cpp -o baoli.exe -g -Wall");
	system("g++ std.cpp -o std.exe -g -Wall");
	int cnt=0;
	double a,b;
	while(1){
		++cnt;
		system("date.exe > 01.in");
		system("std.exe < 01.in > 01.out");
		a=1.0*clock();
		system("baoli.exe < 01.in > 01.ans");
		b=1.0*clock();
		if(system("fc 01.out 01.ans > NULL")){//file compare
			printf("WA: #%lld",cnt);
			return 0;
		}else{
			printf("AC: #%lld,time=%.3f\n",cnt,1.0*(b-a)/CLOCKS_PER_SEC);
		}
	}
	return 0;
}

