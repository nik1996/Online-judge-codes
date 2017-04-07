#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>

#define INF 2000000000
#define INF_LL 2000000000000000000ll
#define MOD_7 1000000007
#define MOD_9 1000000009

typedef long long ll;

using namespace std;

int a[100010],tmp[100010];
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
        m=(l+h)/2;
        c+=inv(l,m);
        c+=inv(m+1,h);
        c+=mer(l,m+1,h);
    }
    return c;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i;
    long long int x;
    for(i=0;i<100000;i++)
     scanf("%d",&a[i]);
    x=inv(0,100000-1);
    printf("%lld\n",x);
    return 0;
}
