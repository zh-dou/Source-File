void query_min(int x,int y,int p) {
    int re=Abs(x-a[p].p[0])+Abs(y-a[p].p[1]),dl,dr;
    if(re&&re<ans1) ans1=re;
    dl=ls?dismin(x,y,ls):inf;
    dr=rs?dismin(x,y,rs):inf;
    if(dl<dr) {
        if(dl<ans1) query_min(x,y,ls);
        if(dr<ans1) query_min(x,y,rs);
    }else {
        if(dr<ans1) query_min(x,y,rs);
        if(dl<ans1) query_min(x,y,ls);
    }
}
void query_max(int x,int y,int p) {
    int re=Abs(x-a[p].p[0])+Abs(y-a[p].p[1]),dl,dr;
    if(re>ans2) ans2=re;
    dl=ls?dismax(x,y,ls):-inf;
    dr=rs?dismax(x,y,rs):-inf;
    if(dl>dr) {
        if(dl>ans2) query_max(x,y,ls);
        if(dr>ans2) query_max(x,y,rs);
    }else {
        if(dr>ans2) query_max(x,y,rs);
        if(dl>ans2) query_max(x,y,ls);
    }
}
