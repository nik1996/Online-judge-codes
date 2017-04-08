#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <algorithm>

using namespace std;
int a[50010];
struct seg
{
    int le;int ri;int ssum;int bsum;
};
seg tree[4*50010];
int ma(int p,int q,int r)
{
    return max(max(p,q),r);
}
void mer(seg &i,seg &sl,seg &sr)
{
    i.ssum=sl.ssum+sr.ssum;
    i.le=max(sl.ssum+sr.le,sl.le);
    i.ri=max(sr.ri,sr.ssum+sl.ri);
    i.bsum=ma(sl.bsum,sr.bsum,sl.ri+sr.le);
}
void cnst(int i,int ss,int se)
{
    if(ss==se)
    {
       tree[i].bsum=tree[i].le=tree[i].ri=tree[i].ssum=a[ss];
       return;
    }
    int m,lc,rc;
    lc=2*i;
    rc=2*i+1;
    m=(ss+se)/2;
    cnst(lc,ss,m);
    cnst(rc,m+1,se);
    mer(tree[i],tree[lc],tree[rc]);
}
void sum(seg &res,int ss,int se,int i,int qs,int qe)
{
    //int x,y;
    if(qs==ss&&qe==se)
     res=tree[i];
    else
    {int m,lc,rc;
    lc=i*2;
    rc=lc+1;
    m=(ss+se)/2;
    if(qe<=m)
     sum(res,ss,m,lc,qs,qe);
    else if(qs>m)
     sum(res,m+1,se,rc,qs,qe);
    else
    {
        seg ln,lr;
        sum(ln,ss,m,lc,qs,m);
        sum(lr,m+1,se,rc,m+1,qe);
        mer(res,ln,lr);
    }
    }
}
int main()
{
    int n,m,x,y,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    cnst(1,1,n);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&x,&y);
        seg res;
        sum(res,1,n,1,x,y);
        printf("%d\n",res.bsum);
    }
    //free(st);
    return 0;
}
