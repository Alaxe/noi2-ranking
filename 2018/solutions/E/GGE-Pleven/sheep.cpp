#include<iostream>
using namespace std;
int main ()
{
long long n,l,i,p,k,x,y,j;
cin>>n>>l;
for(i=1;i<=l;i++)
{
    cin>>x;
    for(j=1;j<=n;j++)
    {
        p=j;
        while(1)
        {
            if(p==0)
            {
                break;
            }
            if(p<10)
            {
               if(p==x)
            {
                n++;
            }
            }
            else
            {
            k=p%10;
            if(k==x)
            {
                n++;
            }
            }
            p=p/10;
        }
    }
}
cout<<n-1<<endl;
    return 0;
}
