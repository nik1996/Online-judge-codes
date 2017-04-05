#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map <long long int,long long int> v;
long long int m(long long int a,long long int b)
{
    if(a>b)
     return a;
    else
     return b;
}
long long int cal(long long int n)
{
    if(n>=0&&n<=11)
    {
        v[n]=n;
        return v[n];
    }
    if(v.find(n)==v.end())
    {
        v[n]=m(n,(cal(n/2)+cal(n/3)+cal(n/4)));
    }
    return v[n];
}
int main()
{
    int i;
    long long int n,x;
    for(i=0;i<10;i++)
    {
        scanf("%lld",&n);
        x=cal(n);
        printf("%lld\n",x);
    }
    return 0;
}
