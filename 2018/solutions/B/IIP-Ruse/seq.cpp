#include <iostream>
using namespace std;
int main()
{
    int n,m,br=0;
    cin>>n>>m;
    int nums,check[n];
    int i,j=0,q;
    for(i=0;i<n;i++)
    {
            nums=m-i;
                if(n-nums>=2)
                  {
                      
                      check[j]=n-nums;
                      if(check[j]>check[j+1])
                      {
                        check[j]-=1;
                        check[j+1]+=1;
                      }
                      else if (check[j]==check[j+1]+1)
                      {
                        check[j]-=1;
                        q=j+2;
                        while(true)
                        {
                          if(check[q]==0)
                          {
                            check[q]+=1;
                            break;
                          }
                          q++;
                        }
                      }
                      else if (check[j]==check[j+1])
                      {
                        if(check[j]!=1 & check[j+1]!=1)
                        {
                           check[j+1]-=1;
                           check[j+2]+=1;
                        }
                        else
                        {
                           br++;
                           break;
                        }
                      }
                     
                    }
                     else
                    {
                        j++;
                        break;
                    }
    }  
     cout<<br;
}
     

