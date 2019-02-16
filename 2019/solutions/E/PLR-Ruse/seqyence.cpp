#include<iostream>
using namespace std;
int main()
{
    long long k,n,p,br=0,l;
    cin>>n;
    k = 0;
    k++;
    l = n-1;
    p = k+1;
    
    
    for(k=1;k<=p;k++)
{
    
    br++;
    if(k==n)
    {
        
        cout<<br<<endl;
        if(n!=1&&n!=3)cout<<br+l<<endl;
        return 0;
    }
    if(k==p)
    {
        for(k==p;k==p;k--)
        {
            br++;
            

            if(k=1)
            {
                p++;
                for(k=1;k<=p;k++)
                {
                    br++;
                    
                    if(k==n)
                    {

                        break;
                    }
                }
            }
        }
    }
}

 return 0;
}