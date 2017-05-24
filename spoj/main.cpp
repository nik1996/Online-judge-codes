#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
long long int c=1000000007;
void mul(long long int f[2][2],long long int m[2][2])
{
    long long int x,y,z,w;
    x=f[0][0]*m[0][0]+f[0][1]*m[1][0];
    y=f[0][0]*m[0][1]+f[0][1]*m[1][1];
    z=f[1][0]*m[0][0]+f[1][1]*m[1][0];
    w=f[1][0]*m[0][1]+f[1][1]*m[1][1];
    f[0][0]=x%c;
    f[0][1]=y%c;
    f[1][0]=z%c;
    f[1][1]=w%c;
}
void po(long long int f[2][2],long long int n)
{
    if(n==0||n==1)
    return;
    long long int m[2][2]={{1,1},{1,0}};
    po(f,n/2);
    mul(f,f);
    if(n&1)
    mul(f,m);
}
long long int fibo(long long int n)
{
    long long int f[2][2]={{1,1},{1,0}};
    if(n==0)
     return 0;
    po(f,n-1);
    return (f[0][0])%c;
}
int main()
{
    long long int n,m,t,x,a;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        x=fibo(m+2)-fibo(n+1);
        if(x<0)
        a=(x+c)%c;
        else
        a=x%c;
        printf("%lld\n",a);
    }
    return 0;
}
