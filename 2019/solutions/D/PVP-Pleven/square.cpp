#include<iostream>
using namespace std;
int a[10000];
int main()
{
    int n,i,s=1,b=0,c=0;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
        s=s*a[i];
    }
    i=0;
    b=s;
    for(i=1; i<=10000; i++)
    {
        for(i=1; i<=s/2; i++)
        {
            if(i*i==b && b%s==0)
            {
                c=i;
                break;
            }
        }
        if(c==0 || b%s!=0)
        {
            b++;
        }
        else
        {
            break;
        }

    }
    cout<<c/2;
    return 0;
}
