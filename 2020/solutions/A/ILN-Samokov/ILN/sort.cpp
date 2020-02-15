#include <iostream>

using namespace std;

int main()
{
    const int m=100000;
    int  a[m],n,i,pm,l=0,br=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {

        if(i=n-1)
        {
            while(a[i]<pm)
            {
                a[i]=a[i]+1;
                br++;
            }
        }
    else
        {
        if(a[i]>a[i+1])
        {
            if(l=0)
            {
                pm=a[i+1];
            while(a[i]>pm)
        {
            a[i]=a[i]-1;
            br++;
        }
        l++;
            }
        else
        {
            if(a[i]!=pm)

        {
            while(a[i]<pm)
        {


            a[i]=a[i]+1;
            br++;
        }
          if(a[i]!=pm)

        {
            while(a[i]>pm)
        {


            a[i]=a[i]-1;
            br++;
        }
        }
        }
        }
        }
        }
    }
    cout<<br;
    return 0;
}

