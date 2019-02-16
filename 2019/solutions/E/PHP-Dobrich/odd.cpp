#include<iostream>
using  namespace std;

int main()
{
    long long int a, b, br=0, x, d, brd;
    cin>>a>>b;
    for(x=a; x<=b; x++)
    {
       for( d=1; d<=x ; d++)
       {
           for( br=0 ; br<=b ; br++)
          {
            if(x%d==0)
          {
            brd ++;
          
          }    
          }
          
       }
       
    }
    cout<< br<<endl;
}