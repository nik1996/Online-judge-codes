Problem statement : //http://www.spoj.com/problems/BRCKTS/

***********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

char c[40000];
struct node{
   int ob,cb;
};
node tree[4*4*10000];

void merg(node &res,node &le,node &ri)
{
    res.ob=ri.ob+max(0,le.ob-ri.cb);
    res.cb=le.cb+max(0,ri.cb-le.ob);
}

void check(node &root)
{
    if((root.ob==0)&&(root.cb==0))
    printf("YES\n");
    else
    printf("NO\n");
}

void build(int s,int e,int i)
{
    if(s==e)
    {
        if(c[s-1]=='(')
        {
            tree[i].ob=1;
            tree[i].cb=0;
        }
        else if(c[s-1]==')')
        {
            tree[i].cb=1;
            tree[i].ob=0;
        }
        return;
    }
    int l,r,m;
    l=i<<1;
    r=l|1;
    m=(s+e)>>1;
    build(s,m,l);
    build(m+1,e,r);
    merg(tree[i],tree[l],tree[r]);
}

void update(int s,int e,int i,int p)
{
    if(s==e&&s==p)
    {
        if(c[s-1]=='(')
        {
            c[s-1]=')';
            tree[i].cb=1;
            tree[i].ob=0;
        }
        else if(c[s-1]==')')
        {
            c[s-1]='(';
            tree[i].cb=0;
            tree[i].ob=1;
        }
        return;
    }
    int l,r,m;
    l=i<<1;
    r=l|1;
    m=(s+e)>>1;
    if(p<=m)
     update(s,m,l,p);
    else if(p>m)
     update(m+1,e,r,p);
    merg(tree[i],tree[l],tree[r]);
}

int main()
{
    int j,n,k,m;
    for(j=1;j<=10;j++)
    {
        scanf("%d",&n);
        cin.ignore();
        scanf("%s",c);
        cin.ignore();
        build(1,n,1);
        scanf("%d",&m);
        printf("Test %d:\n",j);
        while(m--)
        {
            scanf("%d",&k);
            if(k==0)
             {
             	check(tree[1]);
             }
            else
            {
                update(1,n,1,k);
            }
        }
    }
    return 0;
}
