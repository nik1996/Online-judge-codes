//Problem Link : http://www.spoj.com/problems/INVCNT/

*************************************************************************************************************************************

#include <stdio.h>
 
int a[200005],tmp[200005];
long long int mer(int l,int m,int r)
{
    int i,j,k;
    long long int c=0;
    i=l;
    j=m;
    k=l;
    while(i<=(m-1)&&j<=r)
    {
        if(a[i]<=a[j])
        {
            tmp[k++]=a[i++];
        }
        else
        {
          tmp[k++]=a[j++];
          c+=(m-i);
        }
    }
    while(i<=m-1)
    tmp[k++]=a[i++];
    while(j<=r)
    tmp[k++]=a[j++];
    for(i=l;i<=r;i++)
    a[i]=tmp[i];
    return c;
}
long long int inv(int l,int h)
{
    int m;
    long long int c=0;
    if(l<h)
    {
        m=(l+h)>>1;
        c+=inv(l,m);
        c+=inv(m+1,h);
        c+=mer(l,m+1,h);
    }
    return c;
}
int main()
{
    int t,n,i;
    long long int x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
         scanf("%d",&a[i]);
        x=inv(0,n-1);
        printf("%lld\n",x);
    }
    return 0;
}   
