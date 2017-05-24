#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int block;

struct que{
  int le,ri,ind;
};
que query[200010];

int a[35000],n,ans[200010],co[1000010];

bool comp(que x,que y)
{
    if((x.le/block)!=(y.le/block))
     return ((x.le/block)<(y.le/block));
    return (x.ri<y.ri);
}

void solve(int s)
{
   int c,cl,cr,l,r,i;
   memset(co,0,sizeof(co));
   cl=cr=c=0;
   for(i=0;i<s;i++)
   {
       l=query[i].le;
       r=query[i].ri;
       while(cl<l)
       {
           co[a[cl]]--;
           if(co[a[cl]]==0)
            c--;
           cl++;
       }
       while(cl>l)
       {
           if(co[a[cl-1]]==0)
           c++;
           co[a[cl-1]]++;
           cl--;
       }
       while(cr>r+1)
       {
           co[a[cr-1]]--;
           if(co[a[cr-1]]==0)
           c--;
           cr--;
       }
       while(cr<=r)
       {
           if(co[a[cr]]==0)
           c++;
           co[a[cr]]++;
           cr++;
       }
       ans[query[i].ind]=c;
   }
}

int main()
{
    int i,q;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&query[i].le,&query[i].ri);
        query[i].le--;
        query[i].ri--;
        query[i].ind=i;
    }
    block=(int)sqrt(n);
    sort(query,query+q,comp);
    solve(q);
    for(i=0;i<q;i++)
     printf("%d\n",ans[i]);
    return 0;
}
