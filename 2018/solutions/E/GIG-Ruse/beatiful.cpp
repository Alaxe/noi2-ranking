#include <iostream>
using namespace std;
int main()
{
    long long n,k;
    cin>>n>>k;
if(n==1) n=1;
else if(n==2) n=10;
     else if(n==3) n=100;
          else if(n==4) n=1000;
               else if(n==5) n=10000;
                    else if(n==6) n=100000;
                         else if(n==7) n=1000000;
                              else if(n==8) n=10000000;
                                   else if(n==9) n=100000000;
                                        else if(n==10)n=1000000000;
                                             else if(n==11)n=10000000000;
                                                  else if(n==12)n=100000000000;
                                                       else if(n==13)n=1000000000000;
                                                            else if(n==14)n=10000000000000;
                                                                 else if(n==15)n=100000000000000;
                                                                      else if(n==16)n=1000000000000000;
                                                                           else if(n==17)n=10000000000000000;
                                                                                else if(n==18) n=100000000000000000;
                          
    do 
    {
      if(n%k==0) ;
      else n++;
    }while(n%k!=0);
    cout<<n;
    return 0;
}