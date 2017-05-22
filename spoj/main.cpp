#include <iostream>
#include <cstdio>
#include <deque>
#include <cstdlib>

using namespace std;

int main()
{
    int i,n,k,a[100005];
    scanf("%d",&n);
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
    scanf("%d",&k);
    deque <int> q;
    for(i=0;i<k;i++)
    {
        while((!q.empty())&&a[i]>=a[q.back()])
         q.pop_back();
        q.push_back(i);
    }
    for(;i<n;i++)
    {
        cout<<a[q.front()]<<" ";
        while((!q.empty())&&q.front()<=i-k)
         q.pop_front();
        while((!q.empty())&&a[i]>=a[q.back()])
         q.pop_back();
        q.push_back(i);
    }
    printf("%d",a[q.front()]);
    return 0;
}
