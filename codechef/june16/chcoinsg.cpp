//Problem URL : https://www.codechef.com/JUNE16/problems/CHCOINSG

************************************************************************************************************************************

#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main()
{
    long t,n;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        if(n%6)
         printf("Chef\n");
        else
         printf("Misha\n");
    }
    return 0;
}
