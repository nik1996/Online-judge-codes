//Problem URL : http://www.spoj.com/problems/HORRIBLE/

**************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

long long int a[100010],la[4*100010],t[4*100010];
void bu(long long int ss,long long int se,long long int i)
{
    if(ss==se)
    {
        t[i]=a[ss];
        return;
    }
    long long int m,lc,rc;
    m=(ss+se)>>1;
    lc=i<<1;
    rc=lc+1;
    bu(ss,m,lc);
    bu(m+1,se,rc);
    t[i]=t[lc]+t[rc];
    return;
}
void up(long long int ss,long long int se,long long int i,long long int l,long long int r,long long int d)
{
    long long int m,lc,rc;
    m=(ss+se)>>1;
    lc=i<<1;
    rc=lc+1;
    if(la[i]!=0)
    {
       t[i]+=(se-ss+1)*la[i];
       if(ss!=se)
       {
           la[lc]+=(la[i]);
           la[rc]+=(la[i]);
       }
       la[i]=0;
    }
    if(ss>r||se<l)
    return;
    if(l<=ss&&r>=se)
    {
        t[i]+=(se-ss+1)*d;
        if(ss!=se)
        {
            la[lc]+=(d);
            la[rc]+=(d);
        }
        return;
    }
    up(ss,m,lc,l,r,d);
    up(m+1,se,rc,l,r,d);
    t[i]=t[lc]+t[rc];
    return;
}
long long int su(long long int ss,long long int se,long long int i,long long int l,long long int r)
{
    long long int m,lc,rc;
    if(se<l||ss>r)
     return 0;
    if(la[i]!=0)
    {
       t[i]+=(se-ss+1)*la[i];
       if(ss!=se)
       {
           la[lc]+=la[i];
           la[rc]+=la[i];
       }
       la[i]=0;
    }
    if(ss==l&&se==r)
     return t[i];
    else
    {
        m=(ss+se)>>1;
        lc=i<<1;
        rc=lc+1;
        if(r<=m)
         return su(ss,m,lc,l,r);
        else if(l>m)
         return su(m+1,se,rc,l,r);
        else
         return (su(ss,m,lc,l,m)+su(m+1,se,rc,m+1,r));
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    long long int t,c,v,s,i,j;
    long long int n,y,z,x;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&c);
        memset(a,0,sizeof(a));
        bu(1,n,1);
        memset(la,0,sizeof(la));
        for(i=1;i<=c;i++)
        {
            //fflush(stdin);
            scanf("%lld",&x);
            if(x==0)
            {
                scanf("%lld%lld%lld",&y,&z,&v);
                for(j=y;j<=z;j++)
                  a[j]+=v;
                up(1,n,1,y,z,v);
            }
            else if(x==1)
            {
                scanf("%lld%lld",&y,&z);
                s=su(1,n,1,y,z);
                printf("%lld\n",s);
            }
        }
    }
    return 0;
}
