#include<iostream>
using namespace std;
int main()
{

    long long n,i0=0,i1=0,pal;
    cin>>n;
    i0=n-1;
    i1=n-1;
    while(true)
    {
    pal=i1*i0;
    cout<<pal<<i0<<i1<<endl;
        if(i1-1==0)
        {
            i1=n-1;
            i0--;
        }
        else
        {
        i1--;
        }
        if(i0==0)
            {
              break;
            }
    }
    return 0;
}
