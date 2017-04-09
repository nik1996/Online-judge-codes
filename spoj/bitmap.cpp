//Problem Link : http://www.spoj.com/problems/BITMAP/

*************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
#include <utility>

using namespace std;

int a[185][185],m,n;
vector <pair <int,int> > v;

void bfs(int i)
{
    int x,y,d,k,l;
    queue < pair <int,int> > q;
    q.push(v[i]);
    k=v[i].first;
    l=v[i].second;
    a[k][l]=0;
    while(q.empty()==false)
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        d=a[x][y]+1;
        if((y-1)>=0&&(d<a[x][y-1]))
        {
            a[x][y-1]=d;
            q.push(make_pair(x,y-1));
        }
        if((y+1)<m&&(d<a[x][y+1]))
        {
            a[x][y+1]=d;
            q.push(make_pair(x,y+1));
        }
        if((x-1)>=0&&(d<a[x-1][y]))
        {
            a[x-1][y]=d;
            q.push(make_pair(x-1,y));
        }
        if((x+1)<n&&(d<a[x+1][y]))
        {
            a[x+1][y]=d;
            q.push(make_pair(x+1,y));
        }
    }
}

int main()
{
    char ch;
    long int t;
    int i,j;
    scanf("%ld",&t);
    while(t--)
    {
        v.clear();
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>ch;
                if(ch=='1')
                {
                    v.push_back(make_pair(i,j));
                    a[i][j]=0;
                }
                else
                  a[i][j]=INT_MAX;
            }
        }
        for(i=0;i<v.size();i++)
        {
            bfs(i);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
