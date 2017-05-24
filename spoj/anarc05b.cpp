//Problem URL : http://www.spoj.com/problems/ANARC05B/

*********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[10010],b[10010],m,n;
vector <int> v;

int bs(int l,int h,int e)
{
    int mid,x;
    if(l>h)
    return -1;
    mid=(l+h)/2;
    if(b[mid]==e)
      return mid;
    else if(b[mid]>e)
    {
        x=bs(l,mid-1,e);
    }
    else if(b[mid]<e)
    {
        x=bs(mid+1,h,e);
    }
    return x;
}

int main()
{
    int i,x,y,p,q;
    long long int s1,s2,ans;
    while(1)
    {
        v.clear();
        scanf("%d",&n);
        if(n==0)
        break;
        for(i=0;i<n;i++)
          scanf("%d",&a[i]);
         scanf("%d",&m);
        for(i=0;i<m;i++)
          scanf("%d",&b[i]);
        for(i=0;i<n;i++)
        {
            x=bs(0,m-1,a[i]);
            if(x!=-1)
            {
                v.push_back(i);
                v.push_back(x);
            }
        }
        p=q=ans=0;
        while(v.empty()==false)
        {
            s1=s2=0;
            x=v.front();
            v.erase(v.begin());
            y=v.front();
            v.erase(v.begin());
            for(i=p;i<x;i++)
            {
                s1+=a[i];
            }
            for(i=q;i<y;i++)
            {
                s2+=b[i];
            }
            ans=ans+b[y]+max(s1,s2);
            p=x+1;
            q=y+1;
        }
        s1=s2=0;
        for(i=p;i<n;i++)
        {
            s1=s1+a[i];
        }
        for(i=q;i<m;i++)
        {
            s2=s2+b[i];
        }
        ans=ans+max(s1,s2);
        printf("%lld\n",ans);
    }
    return 0;
}
