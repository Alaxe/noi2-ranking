#include<iostream>
using namespace std;
int main()
{
    long long n,i;
    int x;
    cin>>n>>x;
    for(i=n;i>=1;i--)
    {
        if(i%2==0)
        {
            if(x==2)
            {
                x=1;
            }
            else
            {
                if(x==1)
                {
                    x=2;
                }
            }
        }
        else
        {
            if(x==0)
            {
                x=1;
            }
            else
            {
                if(x==1)
                {
                    x=0;
                }
            }
        }
    }
    cout<<x;
    return 0;
}
