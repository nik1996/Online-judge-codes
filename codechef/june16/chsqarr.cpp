//Problem URL : https://www.codechef.com/JUNE16/problems/CHSQARR

***********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <deque>
#include <climits>
#include <cstring>
 
using namespace std;
 
int arr[1010][1010],ma1[1010][1010];
long long int sum[1010][1010];
deque<int> q;
int main()
{
    int n,m,t,a,b,i,j;
    long long int s,c,res,x;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        scanf("%d",&arr[i][j]);
    }
    scanf("%d",&t);
    while(t--)
    {
        res=INT_MAX;
        memset(ma1,0,sizeof(ma1));
        memset(sum,0,sizeof(sum));
        scanf("%d%d",&a,&b);
        for(i=0;i<n;i++)
        {
            q.clear();
            s=0;
            for (j = 0; j < b; j++)
            {
                while (!q.empty() && arr[i][j] >= arr[i][q.back()])
                   q.pop_back();
                q.push_back(j);
                s+=arr[i][j];
            }
            for (j = b; j < m; j++)
            {
                ma1[i][j-b] = arr[i][q.front()];
                sum[i][j-b]=s;
                s=s-arr[i][j-b]+arr[i][j];
                while (!q.empty() && arr[i][j] >= arr[i][q.back()])
                  q.pop_back();
                while (!q.empty() && q.front() <= (j-b))
                  q.pop_front();
                q.push_back(j);
            }
            ma1[i][m-b] = arr[i][q.front()];
            sum[i][m-b]=s;
        }
        for(i=0;i<(m-b+1);i++)
        {
            q.clear();
            s=0;
            for (j = 0; j < a; j++)
            {
                while (!q.empty() && ma1[j][i] >= ma1[q.back()][i])
                   q.pop_back();
                q.push_back(j);
                s+=sum[j][i];
            }
            for (j=a;j<n;j++)
            {
                x= ma1[q.front()][i];
                 c=(a*b*x)-s;
                if(c<res)
                res=c;
                s=s-sum[j-a][i]+sum[j][i];
                while (!q.empty() && ma1[j][i] >= ma1[q.back()][i])
                  q.pop_back();
                while (!q.empty() && q.front() <= (j-a))
                  q.pop_front();
                q.push_back(j);
            }
            x= ma1[q.front()][i];
                 c=(a*b*x)-s;
                if(c<res)
                res=c;
        }
        printf("%lld\n",res);
    }
    return 0;
}
