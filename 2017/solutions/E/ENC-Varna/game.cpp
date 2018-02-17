#include <iostream>
using namespace std;
int main ()
{
    int n,m[100000],sum=0,l,sum1,sum2,sum3=9999999999,br;
    cin>>n>>l;
    for (int i=1;i<=100000;i++)
    {
        cin>>m[i];
        if (n-m[i]<0)
        {
            sum1=(n-m[i])*(-1);
            if (sum1<=sum3){br=i;sum3=sum1;}
        }
        else
        {
            sum2=n-m[i];
            if (sum2<=sum3){br=i;sum3=sum2;}
    }

        if (m[i]%2==0)sum=sum+m[i];
        if (sum>=l)break;
    }
    cout<<br<<" "<<sum<<endl;

    return 0;
}
