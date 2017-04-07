//Problem Link : http://www.spoj.com/problems/BISHOPS/

*************************************************************************************************************************************

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    long long int n,i,tmp,val,l,j,c,res[200];
    char s[110];
    for(n=0;n<1024;n++)
    {
       scanf("%s",s);
       l=i=0;
       while(s[i]!='\0')
       {
           i++;
           l++;
       }
       val=s[0]-'0';
       if(l==1&&val==1)
        cout<<"1\n";
       else
       {
           j=c=0;

           for(i=l-1;i>=0;i--)
           {
               //cout<<s[i]<<"\n";
              val=s[i]-'0';
              tmp=(val*2)+c;
              res[j]=tmp%10;
              if(tmp>9)
                c=1;
              else
                c=0;
              //cout<<c<<"\n";
              j++;
           }
           if(c==1)
           {
               res[j]=1;
               j++;
           }
          i=0;
           while(i<j)
           {

               if(res[i]==0)
               {
                  //while(res[i]==0)
                  //{

                      if(i==0)
                      {
                       res[0]=8;
                       i++;
                      }
                      else
                      {
                       res[i]=9;
                       i++;
                      }
                 //}
                if(res[i]!=0)
               {
                   res[i]-=1;
                   break;}
               }
               else
               {
                res[0]-=2;
                break;
               }
           }
           for(i=j-1;i>=0;i--)
           if(res[j-1]==0)
             {
                 cout<<res[0];
                 break;
             }
            else
              cout<<res[i];
           cout<<"\n";
       }
    }
    return 0;
}
