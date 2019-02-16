#include<iostream>
using  namespace std;

int main()
{
    long long int n, m, br=0;
    cin>>n>>m;
    do
    {
        if(n<10)
        {
            if(n>=10)
            {
                if(n>=100)
                {
                  if(n==1000)
                  {
                      br++;
                  }  
                }else{
                n+=(n/100+n/10%10+n%10);
                br++;}
            }else{
            n+=(n/10+n%10);
            br++;}
        }else{
       n+=(n%10);
        br++;}
        
    }while(n<=m);
    cout<<br/2;
    return 0;
}
