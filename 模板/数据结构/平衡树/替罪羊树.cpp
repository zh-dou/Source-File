#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
//#define int long long
#define alpha 0.80
#define N 2000010
inline int read(){
    int x=0,y=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*y;
}
struct scape_goat{
    int son[2],val,valid,total;
    int trust;
}tree[N];
int memory[N],pool,cur[N],tot;
int root,cnt,to_rebuild;
inline int isbad(int now){
    if((double)tree[now].valid*alpha <= (double)max(tree[tree[now].son[0]].valid, tree[tree[now].son[1]].valid)) return true;
    return false;
}
inline void dfs(int now){
    if(!now) return;
    dfs(tree[now].son[0]);
    if(tree[now].trust) cur[++tot] = now;
    else memory[++pool] = now;
    dfs(tree[now].son[1]);
}
inline void build(int l, int r, int &now){
    int mid=(l+r)>>1; 
    now=cur[mid]; 
    if(l==r){
        tree[now].son[0] = tree[now].son[1] = 0;
        tree[now].total = tree[now].valid = 1;
        return; 
    }
    if(l<mid) build(l,mid-1,tree[now].son[0]);
    else tree[now].son[0]=0;
    build(mid+1,r,tree[now].son[1]); 
    tree[now].total=tree[tree[now].son[0]].total+tree[tree[now].son[1]].total+1; 
    tree[now].valid=tree[tree[now].son[0]].valid+tree[tree[now].son[1]].valid+1;
}
inline void rebuild(int &now){
    tot=0;
    dfs(now);
    if(tot) build(1,tot,now);
    else now=0;
}
inline int find_rank(int k){
    int now=root,ans=1;
    while(now){
        if(tree[now].val>=k) now=tree[now].son[0];
        else{
            ans+=tree[tree[now].son[0]].valid + tree[now].trust;
            now=tree[now].son[1];
        }
    }
    return ans;
}
inline int find_kth(int k){
    int now=root;
    while(now){
        if(tree[now].trust&&tree[tree[now].son[0]].valid+1==k) return tree[now].val;
        else if(tree[tree[now].son[0]].valid>=k) now=tree[now].son[0];
        else{
            k-=tree[tree[now].son[0]].valid+tree[now].trust;
            now=tree[now].son[1];
        }
    }
    return 0;
}
inline void insert(int &now, int val){
    if(!now){
        now=memory[pool--];tree[now].val=val;
        tree[now].trust =tree[now].total=tree[now].valid=1;
        tree[now].son[0]=tree[now].son[1]=0;
        return;
    }
    ++tree[now].total;++tree[now].valid;
    if(tree[now].val >= val) insert(tree[now].son[0], val); 
    else insert(tree[now].son[1], val);
    if(!isbad(now))
    {
        if(to_rebuild)
        {
            if(tree[now].son[0] == to_rebuild) rebuild(tree[now].son[0]);
            else rebuild(tree[now].son[1]);
            to_rebuild = 0;
        }
    }
    else to_rebuild = now;
}
inline void delete_rank(int &now, int tar){
    if(tree[now].trust&&tree[tree[now].son[0]].valid+ 1==tar){
        tree[now].trust=0;tree[now].valid--;return;
    }
    --tree[now].valid;
    if(tree[tree[now].son[0]].valid + tree[now].trust >= tar) delete_rank(tree[now].son[0], tar);
    else delete_rank(tree[now].son[1],tar-tree[tree[now].son[0]].valid-tree[now].trust);
//    if(isbad(now)) to_rebuild=now;
}
inline void delete_val(int tar){
    delete_rank(root, find_rank(tar));
    if(isbad(root)) rebuild(root);
}
signed main(){
    int opt, x, m;
    for(int i=2000000;i>=1;i--) memory[++pool] = i;
    m=read();
    while(m--){
        opt=read();x=read();
        if(opt==1) {insert(root,x);}
        if(opt==2) {delete_val(x);}
        if(opt==3) {cout<<find_rank(x)<<"\n";}
        if(opt==4) {cout<<find_kth(x)<<"\n";}
        if(opt==5) {cout<<find_kth(find_rank(x)-1)<<"\n";}
        if(opt==6) {cout<<find_kth(find_rank(x+1))<<"\n";}
    }
    return 0;
}
